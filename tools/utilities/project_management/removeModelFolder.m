function removeModelFolder(modelName)
%removeModelFolder Remove model folder
%   Remove the model folder from the current project.
%
%   removeModelFolder(ModelName)

%   Copyright 2016 The MathWorks, Inc.

% Query for the model name if none is provided.
if nargin < 1
    modelName = char(inputdlg('Enter model name.'));
end
if ~isvarname(modelName)
    errordlg('Invalid model name.');
    return;
end

% Bring the MATLAB Command Window into focus.
commandwindow;

% Check if the model folder exists.
if ~exist(modelName, 'dir')
    error(['Model folder ''', modelName, ''' does not exists.']);
end

% Get the model folder.
prj = simulinkproject;
prjRoot = prj.RootFolder;
modelDir = fullfile(prjRoot, 'DO_03_Design', modelName);

% Get code verification folders for the model.
verifyDir = fullfile(Simulink.fileGenControl('get', 'CodeGenFolder'), '..', 'verification');
verifyDir = erase(verifyDir, [filesep, fullfile('specification', '..')]); % To avoid \.. in the path.
codeDirs = {'code_coverages', 'code_metrics', 'code_proving', 'code_reviews', ...
    'code_standard_checks', 'coding_error_detections', 'executable_tests'};
for dirIdx = 1:length(codeDirs)
    codeDirs{dirIdx} = fullfile(verifyDir, codeDirs{dirIdx}, modelName);
end

try
    % Remove folders from project path.
    modelRecDirStr = genpath(modelDir);
    modelRecDirs = regexp(modelRecDirStr, ';', 'split');
    modelRecDirs = modelRecDirs(~cellfun('isempty', modelRecDirs));
    for recDirIdx = 1:length(modelRecDirs)
        prj.removePath(modelRecDirs{recDirIdx});
    end
    for dirIdx = 1:length(codeDirs)
        codeRecDirStr = genpath(codeDirs{dirIdx});
        codeRecDirs = regexp(codeRecDirStr, ';', 'split');
        codeRecDirs = codeRecDirs(~cellfun('isempty', codeRecDirs));
        for recDirIdx = 1:length(codeRecDirs)
            prj.removePath(codeRecDirs{recDirIdx});
        end
    end
    
    % Remove folders from project.
    prj.removeFile(modelDir);
    for dirIdx = 1:length(codeDirs)
        prj.removeFile(codeDirs{dirIdx});
    end
catch
    error(['Unable to remove ''', modelDir, ''' from project.']);
end

end
