% Script to run helicopter outer loop simulation using Simulink Test
 
% Copyright 2019 The MathWorks, Inc.

% first, test for a Simulink Test and Simulink Verification and Validation
% licenses
if license('test','simulink_test')&&...
        license('test','simulink_coverage')
    
    % this brings the command window to the front and displays a message
    commandwindow;
    disp('Running simulation tests for Helicopter Outer Loop');
    
    % make sure simulation results directory exists and clear old results if
    % they exist
    resultsDir = fullfile(fileparts(which('HeliLoopTest.mldatx')), 'simulation_results');
    if exist(resultsDir,'dir')
        if exist(fullfile(resultsDir,'HeliOuterLoopTestReport.pdf'),'file')
            delete(fullfile(resultsDir,'HeliOuterLoopTestReport.pdf'));
        end
        if exist(fullfile(resultsDir,'HeliOuterLoopTestResults.mldatx'),'file')
            delete(fullfile(resultsDir,'HeliOuterLoopTestResults.mldatx'));
        end
    else
        mkdir(resultsDir);
    end
    reportDir = fullfile(resultsDir, 'HeliOuterLoopTestReport');
    if exist(reportDir, 'dir')
        rmdir(reportDir, 's');
    end
    
    % run simulations
    testobj = sltest.testmanager.load('HeliLoopTest.mldatx');
    resultObj = testobj.run;
    
    % Save test results.
    sltest.testmanager.exportResults(resultObj, fullfile(resultsDir,'HeliOuterLoopTestResults.mldatx'));
    
    % Clean up
    bdclose('all');
    if exist(reportDir, 'dir')
        rmdir(reportDir, 's');
    end
    clearvars;
    
else % open the pre-existing report and post a warning
    open(fullfile(resultsDir, 'HeliOuterLoopTestReport.pdf'));
%     pause(1);
%     web('simulation_results\HeliOuterLoop_Model_Coverage_Report.html');
    warndlg(['There is a license missing for Simulink Test or '...
        'Simulink Verification and Validation, pre-existing  ' ...
        'simulation and coverage reports have been opened'],...
        'Missing Product License');
end