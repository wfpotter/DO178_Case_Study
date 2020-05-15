function viewModelDependency(modelName)
%viewModelDependency Display model dependency
%   Launch the Model Dependency Viewer to display model hierarchy.
%
%   viewModelDependency(ModelName)

%   Copyright 2016 The MathWorks, Inc.

[~] = depview(modelName, 'ModelReferenceInstance', true);

end
