function verifyObjCode2Reqs(modelName, varargin)
%verifyObjCode2Reqs Verify executable object code against requirements
%   Verify if the target code complies with the high-level software
%   requirements. All tests exercise the compiled code on the target
%   computer via PIL simulations.
%
%   verifyObjCode2Reqs(ModelName)
%   verifyObjCode2Reqs(ModelName, AuthorNames)

%   Copyright 2016 The MathWorks, Inc.

% Close all models.
bdclose('all');

% Capture useful folder/file paths and names.
testDir = fullfile(Simulink.fileGenControl('get', 'CodeGenFolder'), '..', 'verification', 'executable_tests', modelName, 'target', 'high_level_tests');
covDir = fullfile(Simulink.fileGenControl('get', 'CodeGenFolder'), '..', 'verification', 'code_coverages', modelName, 'high_level_tests');
resultFile = fullfile(testDir, [modelName, '_PIL_REQ_Based_Test_Results.mldatx']);
rptFile = fullfile(testDir, [modelName, '_PIL_REQ_Based_Test_Report.pdf']);
cvtFile = fullfile(covDir, [modelName '_PIL_REQ_Based_Code_Coverage.cvt']);
htmlFile = fullfile(covDir, [modelName '_PIL_REQ_Based_Code_Coverage_Report.html']);

% Delete the old result folder if it exists, then recreate the folder.
if exist(testDir, 'dir')
    rmdir(testDir, 's');
end
mkdir(testDir);
if exist(covDir, 'dir')
   rmdir(covDir, 's');
end
mkdir(covDir);

% Bring the MATLAB Command Window into focus.
commandwindow;

% Check for prerequisites.
if ~exist([modelName, '_REQ_Based_Test.mldatx'], 'file')
    error(['Test file ''', modelName, '_REQ_Based_Test.mldatx'' not found.']);
end

% Get model checksum information.
% If any of the test case in the test file needs to perform a load_system
% on the test harness, querying the checksum after loading the test file
% leads to an error. To avoid the potential error, get the checksum
% information before loading the test file.
if exist(['DD_', modelName], 'file')
    % Load data dictionary if it exists.
    evalin('base', ['DD_', modelName]);
end
checksumStr = sprintf(['Checksum when compiled as referenced model: ', ...
    num2str(getModelChecksum(modelName, 'TreatAsMdlRef')'), '\n\n', ...
    'Checksum when compiled as top model: ', ...
    num2str(getModelChecksum(modelName)')]);

% Verify the target code against HLR test cases in the test file without coverage analysis.
disp(['Running PIL tests on source code of Simulink model ', modelName, '.']);
% load_system(modelName);
% set_param(modelName,'HardwareBoard', 'ZedBoard');
% set_param(modelName,'HardwareBoardFeatureSet', 'EmbeddedCoderHSP');
sltest.testmanager.clear();
sltest.testmanager.clearResults();
testFile = sltest.testmanager.load([modelName, '_REQ_Based_Test.mldatx']);
testSuite = testFile.getTestSuites;
testCases = testSuite.getTestCases;
for caseIdx = 1:length(testCases)
    testCases(caseIdx).Description = strrep(testCases(caseIdx).Description, 'Simulation test', 'PIL test');
    testCases(caseIdx).setProperty('SimulationMode', 'Processor-in-the-Loop (PIL)');
end
% testFile.getCoverageSettings.MdlRefCoverage = false;
testResult = testFile.run;

% Attach model checksum information to test results.
% checksumStr = sprintf(['Checksum when compiled as referenced model: ', ...
%     num2str(getModelChecksum(modelName, 'TreatAsMdlRef')'), '\n\n', ...
%     'Checksum when compiled as top model: ', ...
%     num2str(getModelChecksum(modelName)')]);
testResult.getTestFileResults.Description = checksumStr;

% Save test results.
sltest.testmanager.exportResults(testResult, resultFile);

% Save coverage results.
if ~isempty(testResult.CoverageResults)
    cvsave(cvtFile, cv.cvdatagroup(testResult.CoverageResults));
end

% Generate the test report.
if nargin > 1
    authors = varargin{1};
else
    authors = '';
end
sltest.testmanager.report(testResult, rptFile, ...
    'Author', authors, ...
    'Title',[modelName, ' PIL REQ-Based Tests'], ...
    'IncludeMLVersion', true, ...
    'IncludeTestRequirement', true, ...
    'IncludeSimulationSignalPlots', true, ...
    'IncludeComparisonSignalPlots', false, ...
    'IncludeErrorMessages', true, ...
    'IncludeTestResults', 0, ...
    'IncludeCoverageResult', true, ...
    'IncludeSimulationMetadata', true, ...
    'LaunchReport', true);

% Generate the coverage report.
if ~isempty(testResult.CoverageResults)
    cvhtml(htmlFile, cv.cvdatagroup(testResult.CoverageResults));
end
% close_system(modelName);
end

