function viewFileDependency(modelName)
%viewFileDependency Display file dependency
%   Launch the Model Dependency Viewer to display model and library file
%   dependency.
%
%   viewFileDependency(ModelName)

%   Copyright 2016 The MathWorks, Inc.

[~] = depview(modelName, 'FileDependenciesIncludingLibraries', true);

end
