function libs = getLibDependency(modelName)
%getLibDependency Get user libraries depended by model
%   Return all user libraries that the model depends on.
%
%   getLibDependency(ModelName)

%   Copyright 2016 The MathWorks, Inc.

files = dependencies.fileDependencyAnalysis(modelName);
libs = {};
numLibs = 0;
if ischar(files)
    files = cellstr(files);
end
for i = 1:length(files)
    if (exist(files{i}) == 4) && (Simulink.MDLInfo(files{i}).IsLibrary)
        numLibs = numLibs + 1;
        libs{numLibs,1} = files{i};
    end
end

end
