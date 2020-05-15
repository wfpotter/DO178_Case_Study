function checksum = getModelChecksum(modelName, varargin)
%getModelChecksum Get checksum of model
%   Return checksum of the model.
%
%   getModelChecksum(ModelName)
%   getModelChecksum(ModelName, 'TreatAsMdlRef')

%   Copyright 2016 The MathWorks, Inc.

if nargin > 1
    checksum = slci.internal.getModelChecksum(modelName, false);
else
    checksum = slci.internal.getModelChecksum(modelName, true);
end

end
