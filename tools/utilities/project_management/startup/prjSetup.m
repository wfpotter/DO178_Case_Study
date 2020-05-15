function prjSetup()
%prjSetup Set up environment
%   Customize the environment for the current project. This function is set
%   to run at Startup.
%
%   prjSetup()

%   Copyright 2016 The MathWorks, Inc.

% Get the ProjectManager.
prj = simulinkproject;
prjRoot = prj.RootFolder;
workDir = fullfile(prjRoot, 'work');

% Specify the folders where simulation and code generation artifacts are
% placed. Simulation and code generation artifacts are placed in
% CacheFolder and CodeGenFolder, respectively. For convenience, set
% CacheFolder to the working directory.
cacheDir = fullfile(workDir, 'cache');
if ~exist(cacheDir, 'dir')
    mkdir(cacheDir);
end
codeGenDir = fullfile(prjRoot, 'DO_04_Code', 'specification');
if ~exist(codeGenDir, 'dir')
    mkdir(codeGenDir);
end
Simulink.fileGenControl('set', 'CacheFolder', cacheDir, 'CodeGenFolder', codeGenDir);

% CD to the working directory.
cd(workDir);

% Load model configurations.
evalin('base', 'nonreusableModelConfig;');
evalin('base', 'reusableModelConfig;');

% Set up RMI.
if license('test', 'sl_verification_validation')
    rmiSetup();
else
    warning('License for Simulink Verification and Validation not found. Setup of RMI skipped.')
end

% Clear all test files and result sets from Simulink Test manager.
if license('test', 'simulink_test')
    sltest.testmanager.clear();
    sltest.testmanager.clearResults();
else
    warning('License for Simulink Test not found. Clearing of Simulink Test manager skipped.')
end

% Apply all customizations.
sl_refresh_customizations;

end
