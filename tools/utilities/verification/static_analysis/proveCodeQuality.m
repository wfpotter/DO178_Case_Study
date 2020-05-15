function proveCodeQuality(modelName, varargin)
%proveCodeQuality Prove the absence of defects in source code
%   Prove the absence of defects in the generated code, and then generate
%   the Code Prover report.
%
%   proveCodeQuality(ModelName)
%   proveCodeQuality(ModelName, 'TreatAsMdlRef')
%   proveCodeQuality(ModelName, 'IncludeAllChildMdls')
%   proveCodeQuality(ModelName, 'TreatAsMdlRef', 'IncludeAllChildMdls')

%   Copyright 2016 The MathWorks, Inc.

% Close all models.
bdclose('all');

% Capture useful folder/file paths and names.
verifyDir = fullfile(Simulink.fileGenControl('get', 'CodeGenFolder'), '..', 'verification');
verifyDir = erase(verifyDir, [filesep, fullfile('specification', '..')]); % To avoid \.. in the path.
psprjDir = fullfile(verifyDir, 'code_proving', modelName);
resultDir = fullfile(psprjDir, modelName);

% Create model specific folder if it does not exist.
if ~exist(psprjDir, 'dir')
    mkdir(psprjDir);
end

% Bring the MATLAB Command Window into focus.
commandwindow;

% Check for prerequisites.
if ~exist(['open_', modelName], 'file')
    error(['Model startup script ''open_', modelName, ''' not found.']);
end
% Code Prover automatically checks if the generated code exist.

% Open the model.
disp(['Opening Simulink model ', modelName, '.']);
evalin('base', ['open_', modelName]);

% Bring the MATLAB Command Window into focus.
commandwindow;

% Create a configuration for Code Prover.
disp(['Analyzing code of Simulink model ', modelName, '.']);
psprjCfg = polyspace.ModelLinkCodeProverOptions('C');
if contains(get_param(modelName, 'TargetLangStandard'), 'C90')
    psprjCfg.TargetCompiler.NoLanguageExtensions = true; % Respect C90 standard if true.
else
    psprjCfg.TargetCompiler.NoLanguageExtensions = false; % Otherwise default to C99.
end
psprjCfg.CodingRulesCodeMetrics.CodeMetrics = true;
psprjCfg.CodingRulesCodeMetrics.EnableMisraC3 = true;
psprjCfg.CodingRulesCodeMetrics.Misra3AgcMode = true;
psprjCfg.CodingRulesCodeMetrics.BooleanTypes = {'boolean_T'};
psprjCfg.ChecksAssumption.SignedIntegerOverflows = 'warn-with-wrap-around';
psprjCfg.ChecksAssumption.UnsignedIntegerOverflows = 'warn-with-wrap-around';
psprjCfg.Macros.DefinedMacros = {'main=main_rtwec', '__restrict__='};
psprjCfg.Advanced.Additional = ['-report-output-name ' modelName '_Code_Prover_Report.pdf'];
psprjCfg.MergedReporting.BugFinderReportTemplate = 'BugFinder';
psprjCfg.MergedReporting.CodeProverReportTemplate = 'Developer';
psprjCfg.MergedReporting.EnableReportGeneration = true;
psprjCfg.MergedReporting.ReportOutputFormat = 'PDF';
psprjFile = psprjCfg.generateProject(fullfile(psprjDir, 'CompleteCodeAnalysis_config.psprj'));
psCfg = pslinkoptions(modelName);
psCfg.VerificationMode = 'CodeProver';
psCfg.VerificationSettings = 'PrjConfig';
psCfg.CxxVerificationSettings = 'PrjConfig';
psCfg.EnablePrjConfigFile = true;
psCfg.PrjConfigFile = psprjFile;
psCfg.EnableAdditionalFileList = false;
psCfg.AdditionalFileList = {};
psCfg.AutoStubLUT = true;
psCfg.InputRangeMode = 'DesignMinMax';
psCfg.ParamRangeMode = 'None';
psCfg.OutputRangeMode = 'None';
if any(strcmp(varargin, 'IncludeAllChildMdls'))
    psCfg.ModelRefVerifDepth = 'All';
else
    psCfg.ModelRefVerifDepth = 'Current model only';
end
psCfg.ModelRefByModelRefVerif = false;
psCfg.ResultDir = psprjDir;
psCfg.AddSuffixToResultDir = false;
psCfg.AddToSimulinkProject = false;
psCfg.OpenProjectManager = false;
psCfg.CheckconfigBeforeAnalysis = 'OnWarn';

% Inspect the generated code against enabled analysis in the Code Prover configuration.
if any(strcmp(varargin, 'TreatAsMdlRef'))
    pslinkrun(modelName, psCfg, true);
else
    pslinkrun(modelName, psCfg, false);
end

% Move the report to the results folder and open it.
docDir = fullfile(resultDir, 'Polyspace-Doc');
if exist(docDir, 'dir')
    rptFile = fullfile(docDir, [modelName, '_Code_Prover_Report.pdf']);
    movefile(rptFile, psprjDir);
    open(fullfile(psprjDir, [modelName, '_Code_Prover_Report.pdf']));
    rmdir(docDir, 's');
end

% Close the model.
disp(['Closing Simulink model ', modelName, '.']);
close_system(modelName, 0);

end
