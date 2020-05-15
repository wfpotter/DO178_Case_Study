function genLowLevelTests(modelName, varargin)
%genLowLevelTests Generate low-level test for model
%   Generate low-level tests for the model based on existing coverage data,
%   and then generate the Design Verifier report.
%
%   genLowLevelTests(ModelName)
%   genLowLevelTests(ModelName, 'AbsTol', 1e-6)
%   genLowLevelTests(ModelName, 'RelTol', 1e-6)
%   genLowLevelTests(ModelName, 'AbsTol', 1e-6, 'RelTol', 1e-3)

%   Copyright 2016 The MathWorks, Inc.

% Close all models.
bdclose('all');

% Administer options.
absTol = 1e-6;
relTol = 1e-3;
if nargin > 1
    options = varargin(1:end);
    numOptions = numel(options)/2;
    for k = 1:numOptions
        opt = options{2*k-1};
        val = options{2*k};
        if strcmpi(opt,'AbsTol') && isa(val,'double') && isscalar(val)
            absTol = val;
        elseif strcmpi(opt,'RelTol') && isa(val,'double') && isscalar(val)
            relTol = val;
        else
            error('Incorrect option-value pair.');
        end
    end
end

% Capture useful folder/file paths and names.
cvtFile = fullfile(fileparts(which(modelName)), '..', 'verification', 'model_coverages', 'high_level_tests', [modelName, '_REQ_Based_Model_Coverage.cvt']);
outputDir = fullfile(fileparts(which(modelName)), '..', 'verification', 'simulation_tests', 'low_level_tests');
% rptFileName = '$ModelName$_Test_Generation_Report';
rptFileName = [modelName, '_Test_Generation_Report'];
% testFileName = '$ModelName$_SLDV_Based_Test';
testFileName = [modelName, '_SLDV_Based_Test'];
% harnessName = '$ModelName$_Harness_SLDV';
harnessName = [modelName, '_Harness_SLDV'];

% Delete the old test file and baseline data if they exist.
% harness = fullfile(fileparts(which(modelName)), [harnessName, '.slx']);
% if exist(harness, 'file')
%     delete(harness);
% end
testFile = fullfile(outputDir, [testFileName, '.mldatx']);
if exist(testFile, 'file')
    delete(testFile);
end
bslDir = fullfile(outputDir, 'sl_test_baselines');
if exist(bslDir, 'dir')
    rmdir(bslDir, 's');
end

% Bring the MATLAB Command Window into focus.
commandwindow;

% Check for prerequisites.
if ~exist(['open_', modelName], 'file')
    error(['Model startup script ''open_', modelName, ''' not found.']);
end

% Open the model.
disp(['Opening Simulink model ', modelName, '.']);
evalin('base', ['open_', modelName]);

% Bring the MATLAB Command Window into focus.
commandwindow;

% Remove the old harness if it exists.
if ~isempty(sltest.harness.find(modelName, 'Name', harnessName))
    sltest.harness.delete(modelName, harnessName);
end

% Create a configuration for Design Verifier Test Generation.
sldvCfg = sldvoptions;
sldvCfg.Mode = 'TestGeneration';
sldvCfg.DisplayUnsatisfiableObjectives = 'on';
sldvCfg.OutputDir = outputDir;
sldvCfg.MakeOutputFilesUnique = 'off';

sldvCfg.ModelCoverageObjectives = 'MCDC';
sldvCfg.TestConditions = 'UseLocalSettings';
sldvCfg.TestObjectives = 'UseLocalSettings';
sldvCfg.MaxTestCaseSteps = 10000;
sldvCfg.TestSuiteOptimization = 'IndividualObjectives';
sldvCfg.ExtendExistingTests = 'off';
sldvCfg.ExistingTestFile = '';
sldvCfg.IgnoreExistTestSatisfied = 'on';
if exist(cvtFile, 'file')
    % Existing coverage data is available.
    sldvCfg.IgnoreCovSatisfied = 'on';
    sldvCfg.CoverageDataFile = cvtFile;
else
    % Existing coverage data is not available.
    sldvCfg.IgnoreCovSatisfied = 'off';
    sldvCfg.CoverageDataFile = '';
end
sldvCfg.CovFilter = 'off';
sldvCfg.CovFilterFileName = '';
sldvCfg.IncludeRelationalBoundary = 'on';
sldvCfg.AbsoluteTolerance = 1e-05;
sldvCfg.Relativetolerance = 0.01;
sldvCfg.SaveExpectedOutput = 'on';
sldvCfg.SlTestFileName = testFileName;
sldvCfg.SlTestHarnessName = harnessName;
sldvCfg.SaveReport = 'on';
sldvCfg.ReportPDFFormat = 'on';
sldvCfg.ReportFileName = rptFileName;
sldvCfg.DisplayReport = 'off';

% Generate tests from the model based on coverage objectives in the Design Verifier configuration.
[status, files] = sldvrun(modelName, sldvCfg);

% If results exist, export results to a test file with a new test harness.
if status
    sltest.testmanager.clear();
    sltest.testmanager.clearResults();
    [~, newHarness] = sltest.import.sldvData(files.DataFile, ...
        'CreateHarness', true, ...
        'TestHarnessName', harnessName, ...
        'TestFileName', testFile);
    load_system(newHarness);
    set_param(newHarness, 'Description', 'Test harness for SLDV generated test cases.');
    save_system(newHarness);
    movefile(which(newHarness), fullfile(fileparts(which(modelName)), [harnessName, '.slx']));

    % Resolve G1467475 (R2016b).
    testFile = sltest.testmanager.TestFile(testFile, false);
    testSuite = testFile.getTestSuites;
    testCase = testSuite.getTestCases;
    bslCriteria = testCase.getBaselineCriteria;
    for bslIdx = 1:length(bslCriteria)
      bslCriteria(bslIdx).remove();
    end
    currentDir = pwd();
    cd(outputDir);
    bslFiles = dir(fullfile('sl_test_baselines', '*.mat'));
    for bslIdx = 1:length(bslFiles)
      testCase.addBaselineCriteria(fullfile('.', 'sl_test_baselines', bslFiles(bslIdx).name));
    end
    cd(currentDir);

    % Rename the test suite.
    testSuite.Name = 'SLDV-Based Test';

    % Rename the test case.
    testCase.Name = 'LLR_SLDV';

    % Modify DESCRIPTION of the test case.
    testCase.Description = 'Simulation test for LLR from SLDV.';

    % Modify CALLBACKS of the test case.
    if exist(['DD_', modelName], 'file')
        % Insert command to load data dictionary if it exists.
        callback = testCase.getProperty('PreloadCallback');
        callback = [callback, sprintf(['\nDD_', modelName, ';\n'])];
        testCase.setProperty('PreloadCallback', callback);
    end

    % Modify BASELINE CRITERIA of the test case.
    bslCriteria = testCase.getBaselineCriteria;
    for bslIdx = 1:length(bslCriteria)
        bslCriteria(bslIdx).AbsTol = absTol;
        bslCriteria(bslIdx).RelTol = relTol;
    end

    % Modify ITERATIONS of the test case.
    testCase.setProperty('FastRestart', false);

    % Modify COVERAGE SETTINGS of the test case.
    covSettings = testFile.getCoverageSettings;
    covSettings.RecordCoverage = false;
    covSettings.MdlRefCoverage = true;
    covSettings.MetricSettings = 'dcmtroib';

    % Write changes back to test file.
    testFile.saveToFile();
end

% Open the report.
open(files.PDFReport);

% Close the model.
disp(['Closing Simulink model ', modelName, '.']);
close_system(modelName, 0);

end
