function resetWorkspace()
%resetWorkspace Reset workspace to startup condition
%   Clear all variables in the workspace except the default model
%   configurations.
%
%   resetWorkspace()

%   Copyright 2016 The MathWorks, Inc.

% Clear the workspace.
evalin('base', 'clear;');

% Load default model configurations.
evalin('base', 'nonreusableModelConfig;');
evalin('base', 'reusableModelConfig;');

end
