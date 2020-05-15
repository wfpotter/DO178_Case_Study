function checkModelStds(modelName, varargin)
%checkModelStds Check model against model standards
%   Check the model against model standards, and then generate the Model
%   Advisor report.
%
%   checkModelStds(ModelName)
%   checkModelStds(ModelName, 'TreatAsMdlRef')

%   Copyright 2016 The MathWorks, Inc.

% Close all models.
bdclose('all');

% Delete the old report if it exists.
pdfFile = fullfile(fileparts(which(modelName)), '..', 'verification', 'design_standard_checks', [modelName, '_SMS_Conformance_Report.pdf']);
if exist(pdfFile, 'file')
    delete(pdfFile);
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

% Inspect the model against enabled checks in the Model Advisor configuration.
if nargin > 1
    ModelAdvisor.run(modelName, 'Configuration', 'doChecks.mat', 'TreatAsMdlRef', 'on');
else
    ModelAdvisor.run(modelName, 'Configuration', 'doChecks.mat', 'TreatAsMdlRef', 'off');
end

% Create a configuration for Modl Advisor report generation.
rptCfg = ModelAdvisor.ExportPDFDialog.getInstance;
rptCfg.TaskNode = Simulink.ModelAdvisor.getModelAdvisor(modelName).TaskAdvisorRoot;
rptCfg.ReportFormat = 'pdf';
rptCfg.ReportName = [modelName, '_SMS_Conformance_Report'];
rptCfg.ReportPath = fullfile(fileparts(which(modelName)), '..', 'verification', 'design_standard_checks');

% Generate the report.
rptCfg.Generate;

% Close the model.
disp(['Closing Simulink model ', modelName, '.']);
close_system(modelName, 0);

end
