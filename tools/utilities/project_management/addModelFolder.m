function addModelFolder(modelName)
%addModelFolder Create a new model folder
%   Create a new model folder based on a design folder template.
%
%   addModelFolder(ModelName)

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

% Check if the model folder already exists.
if exist(modelName, 'dir')
    error(['Model folder ''', modelName, ''' already exists.']);
end

% Create a new model folder with a new model file.
prj = simulinkproject;
prjRoot = prj.RootFolder;
dirName = fullfile(prjRoot, 'DO_03_Design');
srcDirName = fullfile(dirName, 'sample_model');
dstDirName = fullfile(dirName, modelName);
copyfile(srcDirName, dstDirName);
% model = load_system('doModelTemplate'); % R2015b.
model = Simulink.createFromTemplate('doModelTemplate.sltx', 'Name', modelName); % R2016a.
Reference = Simulink.ConfigSetRef;
Reference.SourceName = 'csMultiInstance';
attachConfigSet(modelName, Reference);
setActiveConfigSet(modelName, 'Reference');
save_system(model, fullfile(dstDirName, 'specification', modelName));
disp(['Created new model folder ', dstDirName, '.']);

% Add code verification folders for the new model.
verifyDir = fullfile(Simulink.fileGenControl('get', 'CodeGenFolder'), '..', 'verification');
verifyDir = erase(verifyDir, [filesep, fullfile('specification', '..')]); % To avoid \.. in the path.
codeDirs = {'code_coverages', 'code_metrics', 'code_proving', 'code_reviews', ...
    'code_standard_checks', 'coding_error_detections', 'executable_tests'};
for dirIdx = 1:length(codeDirs)
    codeDirs{dirIdx} = fullfile(verifyDir, codeDirs{dirIdx}, modelName);
    mkdir(codeDirs{dirIdx});
end

try
    % Add new folders to project.
    prj.addFolderIncludingChildFiles(dstDirName);
    for dirIdx = 1:length(codeDirs)
        prj.addFolderIncludingChildFiles(codeDirs{dirIdx});
    end
    
    % Add new folders to project path.
    ctrlSet = com.mathworks.toolbox.slproject.project.controlset.store.implementations.SingletonProjectStore.getFirstRoot();
%     prjManager = ctrlSet.getProjectManager(); % R2015b.
    prjManager = ctrlSet.getProjectControlSet.getProjectManager(); % R2016a.
    pathManager = prjManager.getProjectPathManager();
    projectRoot = prjManager.getProjectRoot();
    refFactory = com.mathworks.toolbox.slproject.project.references.types.RelativeFolderReferenceFactory();
    modelPaths = genpath(dstDirName);
    dirList = regexp(modelPaths, pathsep, 'split');
    dirList = union(dirList, codeDirs);
    for dirIdx = 1:length(dirList)
        if isdir(dirList{dirIdx})
            referenceLocation = java.io.File(dirList{dirIdx});
            if ~pathManager.isReference(referenceLocation)
                reference = refFactory.createFor(referenceLocation, projectRoot);
                referenceDefinitionList = java.util.Collections.singleton(reference);
                pathManager.addReferences(referenceDefinitionList);
            end
        end
    end
catch
    error(['Unable to add ''', dstDirName, ''' to project.']);
end

end
