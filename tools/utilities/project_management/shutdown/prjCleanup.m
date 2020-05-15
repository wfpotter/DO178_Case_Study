function prjCleanup()
%prjCleanup Clean up environment
%   Restore the environment before exiting the current project. This
%   function is set to run at Shutdown.
%
%   prjCleanup()

%   Copyright 2016 The MathWorks, Inc.

% Reset the CacheFolder and CodeGenFolder back to the default.
Simulink.fileGenControl('reset');
clearTestManager();
slreq.clear;

end
