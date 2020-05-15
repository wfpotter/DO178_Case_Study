function rmiSync2Doors(modelName)
%rmiSync2Doors   Synchronize model with DOORS
%   Synchronize requirement links in the model with DOORS.
%
%   rmiSync2Doors(ModelName)

%   Copyright 2016 The MathWorks, Inc.

% Create a configuration for RMI DOORS synchronization.
syncCfg = rmidoors.synchronize(modelName, 'settings');
syncCfg.surrogatePath = './$ModelName$';
syncCfg.detailLevel = 1;
syncCfg.doorsToSl = false;
syncCfg.slToDoors = true;
syncCfg.purgeSimulink = 0;
syncCfg.purgeDoors = 1;
syncCfg.saveModel = 1;
syncCfg.saveSurrogate = 1;

% Synchronize the model with DOORS.
rmidoors.synchronize(modelName, syncCfg);

end
