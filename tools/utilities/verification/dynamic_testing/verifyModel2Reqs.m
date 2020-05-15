function verifyModel2Reqs(modelName, varargin)
%verifyModel2Reqs Verify model against requirements
%   Verify if the model complies with the high-level software requirements,
%   and then perform model coverage analysis. All tests exercise the
%   compiled model on the host computer via standard simulations.
%
%   verifyModel2Reqs(ModelName)
%   verifyModel2Reqs(ModelName, AuthorNames)

%   Copyright 2016 The MathWorks, Inc.

% Close all models.
bdclose('all');

% Delete the old results and reports if they exist.
resultFile = fullfile(fileparts(which(modelName)), '..', 'verification', 'simulation_tests', 'high_level_tests', [modelName, '_REQ_Based_Test_Results.mldatx']);
if exist(resultFile, 'file')
    delete(resultFile);
end
rptFile = fullfile(fileparts(which(modelName)), '..', 'verification', 'simulation_tests', 'high_level_tests', [modelName, '_REQ_Based_Test_Report.pdf']);
if exist(rptFile, 'file')
    delete(rptFile);
end
docDir = fullfile(fileparts(which(modelName)), '..', 'verification', 'simulation_tests', 'high_level_tests', [modelName, '_REQ_Based_Test_Report']);
if exist(docDir, 'dir')
    rmdir(docDir, 's');
end
cvtFile = fullfile(fileparts(which(modelName)), '..', 'verification', 'model_coverages', 'high_level_tests', [modelName, '_REQ_Based_Model_Coverage.cvt']);
if exist(cvtFile, 'file')
    delete(cvtFile);
end
htmlFile = fullfile(fileparts(which(modelName)), '..', 'verification', 'model_coverages', 'high_level_tests', [modelName, '_REQ_Based_Model_Coverage_Report.html']);
if exist(htmlFile, 'file')
    delete(htmlFile);
end
gifDir = fullfile(fileparts(which(modelName)), '..', 'verification', 'model_coverages', 'high_level_tests', 'scv_images');
if exist(gifDir, 'dir')
    rmdir(gifDir, 's');
end

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
% checksumStr = sprintf(['Checksum when compiled as top model: ', ...
%     num2str(getModelChecksum(modelName)'), '\n\n', ...
%     'Checksum when compiled as referenced model: ', ...
%     num2str(getModelChecksum(modelName, 'TreatAsMdlRef')')]);

% Verify the model against HLR test cases in the test file.
disp(['Running tests on Simulink model ', modelName, '.']);
sltest.testmanager.clear();
sltest.testmanager.clearResults();
testFile = sltest.testmanager.load([modelName, '_REQ_Based_Test.mldatx']);
testSuite = testFile.getTestSuites;
testCases = testSuite.getTestCases;
for caseIdx = 1:length(testCases)
    testCases(caseIdx).Description = strrep(testCases(caseIdx).Description, 'Simulation test', 'Sim test');
    testCases(caseIdx).setProperty('SimulationMode', 'Normal');
end
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
    'Title',[modelName, ' REQ-Based Tests'], ...
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

end
