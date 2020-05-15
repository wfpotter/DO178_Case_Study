function genSDD(modelName, varargin)
%genSDD Generate a System Design Description (SDD) report from model
%   Generate a System Design Description (SDD) report from the model.
%
%   genSDD(ModelName)
%   genSDD(ModelName, AuthorNames)

%   Copyright 2016 The MathWorks, Inc.

% Close all models.
bdclose('all');

% Bring the MATLAB Command Window into focus.
commandwindow;

% Check for prerequisites.
if ~exist(['open_', modelName], 'file')
    error(['Model startup script ''open_', modelName, ''' not found.']);
end

% Open the model.
disp(['Opening Simulink model ', modelName, '.']);
evalin('base', ['open_', modelName]);

% % Load libraries in the dependency to avoid warnings in the requirement
% % section.
% libs = getLibDependency(modelName);
% load_system(libs);

% Bring the MATLAB Command Window into focus.
commandwindow;

% Create a configuration for SDD report generation.
sddCfg = StdRpt.SDD(modelName);
% sddCfg.rootSystem = modelName;
sddCfg.title = modelName;
sddCfg.subtitle = 'Design Description';
if nargin > 1
    sddCfg.authorNames = varargin{1};
else
    % Leave it at default.
end
sddCfg.titleImgPath = ''; % To be customized.
sddCfg.legalNotice = ''; % To be customized.
sddCfg.timeFormat = ''; % To be customized.
sddCfg.includeDetails = true;
sddCfg.includeModelRefs = false;
sddCfg.includeCustomLibraries = false; % To be customized.
sddCfg.includeLookupTables = true;
sddCfg.includeRequirementsLinks = true;
sddCfg.includeGlossary = true;
sddCfg.outputFormat = 1;
sddCfg.stylesheetIndex = 8;
sddCfg.outputName = [modelName, '_SDD']; % To be customized.
sddCfg.outputDir = fullfile(fileparts(which(modelName)), 'documents');
sddCfg.incrOutputName = 0;
sddCfg.packageType = 1;
sddCfg.UseStatusWindow = false;
sddCfg.displayReport = true;

% Generate the report.
sddCfg.run();

% Close the model.
disp(['Closing Simulink model ', modelName, '.']);
close_system(modelName, 0);

end
