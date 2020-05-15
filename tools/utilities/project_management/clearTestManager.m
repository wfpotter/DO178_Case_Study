function clearTestManager()
%clearTestManager Clear Test Manager
%   Clear all test files and result sets loaded in Test Manager.
%
%   clearTestManager()

%   Copyright 2016 The MathWorks, Inc.

sltest.testmanager.clear();
sltest.testmanager.clearResults();
