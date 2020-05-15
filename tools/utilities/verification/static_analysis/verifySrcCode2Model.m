function verifySrcCode2Model(modelName, varargin)
%verifySrcCode2Model Verify source code against model
%   Verify if the generated code complies with and is traceable to the
%   model, and then generate the Code Inspector report.
%
%   verifySrcCode2Model(ModelName)
%   verifySrcCode2Model(ModelName, 'TreatAsMdlRef')
%   verifySrcCode2Model(ModelName, 'IncludeAllChildMdls')
%   verifySrcCode2Model(ModelName, 'TreatAsMdlRef', 'IncludeAllChildMdls')

%   Copyright 2016 The MathWorks, Inc.

% Close all models.
bdclose('all');

% Bring the MATLAB Command Window into focus.
commandwindow;

% Check for prerequisites.
if ~exist(['open_', modelName], 'file')
    error(['Model startup script ''open_', modelName, ''' not found.']);
end
% Code Inspector automatically checks if the generated code exist.

% Open the model.
disp(['Opening Simulink model ', modelName, '.']);
evalin('base', ['open_', modelName]);

% Bring the MATLAB Command Window into focus.
commandwindow;

% Create a configuration for Code Inspector.
slciCfg = slci.Configuration(modelName);
if any(strcmp(varargin, 'TreatAsMdlRef'))
    slciCfg.setTopModel(false);
else
    slciCfg.setTopModel(true);
end
if any(strcmp(varargin, 'IncludeAllChildMdls'))
    slciCfg.setFollowModelLinks(true);
else
    slciCfg.setFollowModelLinks(false);
end
slciCfg.setIncludeTopModelChecksumForRefModels(true);
slciCfg.setTerminateOnIncompatibility(false);
slciCfg.setGenerateCode(false);
slciCfg.setCodePlacement('Embedded Coder default');
slciCfg.setReportFolder(fullfile(Simulink.fileGenControl('get', 'CodeGenFolder'), '..', 'verification', 'code_reviews', modelName));
slciCfg.setShowReport(true);

% Inspect the generated code against the model.
slciCfg.inspect;

% Close the model.
disp(['Closing Simulink model ', modelName, '.']);
close_system(modelName, 0);

end
