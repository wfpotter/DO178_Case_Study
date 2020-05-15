%   Copyright 2016 The MathWorks, Inc.

load_system('doLib');
doBlks = find_system('doLib', 'Type', 'block');
doBlks = strrep(doBlks, 'doLib', '');
load_system('slcilib');
slciBlks = find_system('slcilib', 'LookUnderMasks', 'functional', 'Type', 'block');
slciBlks = strrep(slciBlks, 'slcilib', '');
newBlks = setdiff(slciBlks, doBlks);
if ~isempty(newBlks)
    disp('Found the following new SLCI compatible blocks:');
    for i = 1:length(newBlks)
        disp([' ', strrep(newBlks{i}, sprintf('\n'), ' ')]);
    end
else
    disp('No new SLCI compatible blocks found.');
end
