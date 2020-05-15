function rmiSetup()
%rmiSetup   Set up RMI
%   Configure the RMI settings for the current project.
%
%   rmiSetup()

%   Copyright 2016 The MathWorks, Inc.

% Set the Storage tab.
rmipref('StoreDataExternally', true);
rmipref('DuplicateOnCopy', false);

% Set the Selection Linking tab.
rmipref('SelectionLinkWord', true);
rmipref('SelectionLinkExcel', true);
rmipref('SelectionLinkDoors', true);
rmipref('DocumentPathReference', 'none');
rmipref('SelectionLinkTag','');
rmipref('BiDirectionalLinking', false);

% Set the Filters tab.
rmipref('FilterEnable', false);
% Set Disable synchronization item links.
filterSettings = rmi.settings_mgr('get', 'filterSettings');
filterSettings.filterSurrogateLinks = false;
rmi.settings_mgr('set', 'filterSettings', filterSettings);

end
