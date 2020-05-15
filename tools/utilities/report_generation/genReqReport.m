function genReqReport(reqSetName, varargin)
%genReqReport Generate a Requirements Report report from a requirements set
%   Generate a requirements report from the requirements set.
%
%   genReqReport(reqSetName) 
%   genReqReport(reqSetName, AuthorNames)

%   Copyright 2019 The MathWorks, Inc.

% Determine if user included file extension or not in name
x = strfind(reqSetName,'.slreqx');
if ~isempty(x)
    reqSetName = reqSetName(1:x-1);
end

% Open the requirements set and get the object for it
myReqSet = slreq.open(reqSetName);

% Get the default report options configuration
myOptions = slreq.getReportOptions();

% Set the report folder path, name and type
myOptions.reportPath = fullfile(fileparts(which([reqSetName, '.slreqx'])), 'documents', [reqSetName, '_ReqReport.pdf']);

% Set the report title
myOptions.titleText = [reqSetName, ' Requirements Report'];

% Add author, if specified
if nargin > 1
    myOptions.authors = varargin{1};
else
    % Leave it at default.
end

% Bring the MATLAB Command Window into focus.
commandwindow;

% Generate the report
slreq.generateReport(myReqSet, myOptions);

% Close the requirements set
close(myReqSet);

