function detectDesignErrs(modelName, varargin)
%detectDesignErrs Detect design errors or dead logic in model
%   Detect design errors or dead logic in the model, and then generate the
%   Design Verifier report.
%
%   detectDesignErrs(ModelName)
%   detectDesignErrs(ModelName, 'DetectDeadLogic')

%   Copyright 2016 The MathWorks, Inc.

% Close all models.
bdclose('all');

% Capture useful folder/file paths and names.
if nargin > 1
    % DetectDeadLogic is enabled.
    outputDir = fullfile(fileparts(which(modelName)), '..', 'verification', 'design_error_detections', 'dead_logic');
%     rptFileName = '$ModelName$_Dead_Logic_Detection_Report';
    rptFileName = [modelName, '_Dead_Logic_Detection_Report'];
else
    % DetectDeadLogic is disabled.
    outputDir = fullfile(fileparts(which(modelName)), '..', 'verification', 'design_error_detections', 'design_error');
%     rptFileName = '$ModelName$_Design_Error_Detection_Report';
    rptFileName = [modelName, '_Design_Error_Detection_Report'];
end

% Bring the MATLAB Command Window into focus.
commandwindow;

% Check for prerequisites.
if ~exist(['open_', modelName], 'file')
    error(['Model startup script ''open_', modelName, ''' not found.']);
end

% Open the model.
disp(['Opening Simulink model ', modelName, '.']);
evalin('base', ['open_', modelName]);

% Bring the MATLAB Command Window into focus.
commandwindow;

% Create a configuration for Design Verifier Design Error Detection.
sldvCfg = sldvoptions;
sldvCfg.Mode = 'DesignErrorDetection';
sldvCfg.OutputDir = outputDir;
sldvCfg.MakeOutputFilesUnique = 'off';
if nargin > 1
    % DetectDeadLogic is enabled.
    sldvCfg.DetectDeadLogic = 'on';
else
    % DetectDeadLogic is disabled.
    sldvCfg.DetectDeadLogic = 'off';
end
sldvCfg.DetectActiveLogic = 'off';
sldvCfg.DetectIntegerOverflow = 'on'; % Ignored if DetectDeadLogic is enabled.
sldvCfg.DetectDivisionByZero = 'on'; % Ignored if DetectDeadLogic is enabled.
sldvCfg.DesignMinMaxCheck = 'on'; % Ignored if DetectDeadLogic is enabled.
sldvCfg.DetectOutOfBounds = 'on'; % Ignored if DetectDeadLogic is enabled.
sldvCfg.SaveReport = 'on';
sldvCfg.ReportPDFFormat = 'on';
sldvCfg.ReportFileName = rptFileName;
sldvCfg.DisplayReport = 'off';

% Inspect the model against enabled analysis in the Design Verifier configuration.
[~, files] = sldvrun(modelName, sldvCfg);

% Open the report.
open(files.PDFReport);

% Close the model.
disp(['Closing Simulink model ', modelName, '.']);
close_system(modelName, 0);

end
