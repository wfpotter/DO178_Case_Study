function genSrcCode(modelName, varargin)
%genSrcCode Generate source code from model
%   Generate source code from the model.
%
%   genSrcCode(ModelName)
%   genSrcCode(ModelName, 'TreatAsMdlRef')

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

% Bring the MATLAB Command Window into focus.
commandwindow;

% Generate code.
if nargin > 1
    slbuild(modelName, 'ModelReferenceRTWTargetOnly');
else
    slbuild(modelName);
end

% Close the model.
disp(['Closing Simulink model ', modelName, '.']);
close_system(modelName, 0);

end
