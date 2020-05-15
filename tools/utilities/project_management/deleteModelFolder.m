function deleteModelFolder(modelName)
%deleteModelFolder Delete model folder
%   Delete the model folder.
%
%   deleteModelFolder(ModelName)

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

% % Check if the model folder exists.
% if ~exist(modelName, 'dir')
%     error(['Model folder ''', modelName, ''' does not exists.']);
% end

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
    % Delete folders from project.
    if exist(modelDir, 'dir')
        rmdir(modelDir, 's');
    end
    for dirIdx = 1:length(codeDirs)
        if exist(codeDirs{dirIdx}, 'dir')
            rmdir(codeDirs{dirIdx}, 's');
        end
    end
catch
    error(['Unable to delete ''', modelDir, ''' from project.']);
end

end
