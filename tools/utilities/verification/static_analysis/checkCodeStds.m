function checkCodeStds(modelName, varargin)
%checkCodeStds Check source code against code standards
%   Check the generated code against code standards, and then generate the
%   Bug Finder report.
%
%   checkCodeStds(ModelName)
%   checkCodeStds(ModelName, 'TreatAsMdlRef')

%   Copyright 2016 The MathWorks, Inc.

% Close all models.
bdclose('all');

% Capture useful folder/file paths and names.
verifyDir = fullfile(Simulink.fileGenControl('get', 'CodeGenFolder'), '..', 'verification');
verifyDir = erase(verifyDir, [filesep, fullfile('specification', '..')]); % To avoid \.. in the path.
psprjDir = fullfile(verifyDir, 'code_standard_checks', modelName);
resultDir = fullfile(psprjDir, modelName);
tmplDir = fullfile(polyspaceroot, 'toolbox', 'polyspace', 'psrptgen', 'templates', 'bug_finder');
rptgenExe = fullfile(polyspaceroot, 'polyspace', 'bin', 'polyspace-report-generator');

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
% Bug Finder automatically checks if the generated code exist.

% Open the model.
disp(['Opening Simulink model ', modelName, '.']);
evalin('base', ['open_', modelName]);

% Bring the MATLAB Command Window into focus.
commandwindow;

% Create a configuration for Bug Finder (Coding Rules only).
disp(['Analyzing code of Simulink model ', modelName, '.']);
prj = simulinkproject;
prjRoot = prj.RootFolder;
psprjCfg = polyspace.ModelLinkBugFinderOptions();
if contains(get_param(modelName, 'TargetLangStandard'), 'C90')
    psprjCfg.TargetCompiler.NoLanguageExtensions = true; % Respect C90 standard if true.
else
    psprjCfg.TargetCompiler.NoLanguageExtensions = false; % Otherwise default to C99.
end
psprjCfg.BugFinderAnalysis.EnableCheckers = false;
psprjCfg.CodingRulesCodeMetrics.CodeMetrics = false;
psprjCfg.CodingRulesCodeMetrics.EnableMisraC3 = true;
psprjCfg.CodingRulesCodeMetrics.Misra3AgcMode = true;
psprjCfg.CodingRulesCodeMetrics.MisraC3Subset = fullfile(prjRoot, 'tools', 'checks', 'MISRA_C_2012_ACG');
psprjCfg.CodingRulesCodeMetrics.BooleanTypes = {'boolean_T'};
psprjCfg.Macros.DefinedMacros = {'main=main_rtwec', '__restrict__='};
psprjFile = psprjCfg.generateProject(fullfile(psprjDir, 'CodingRulesOnly_config.psprj'));
psCfg = pslinkoptions(modelName);
psCfg.VerificationMode = 'BugFinder';
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
psCfg.ModelRefVerifDepth = 'Current model only';
psCfg.ModelRefByModelRefVerif = false;
psCfg.ResultDir = psprjDir;
psCfg.AddSuffixToResultDir = false;
psCfg.AddToSimulinkProject = false;
psCfg.OpenProjectManager = false;
psCfg.CheckconfigBeforeAnalysis = 'OnWarn';

% Inspect the generated code against enabled checks in the Bug Finder configuration.
if nargin > 1
    pslinkrun(modelName, psCfg, true);
else
    pslinkrun(modelName, psCfg, false);
end

% May have to be suspended due to bug in R2017a (when no violations are detected).
% Generate the summary report.
tmplFile = fullfile(tmplDir, 'BugFinderSummary.rpt');
rptFile = fullfile(psprjDir, [modelName, '_Bug_Finder_Summary.pdf']);
rptCmd = ['"', rptgenExe, '"', ...
    ' -template "', tmplFile, '"', ...
    ' -format PDF', ...
    ' -output-name "', rptFile, '"', ...
    ' -results-dir "', resultDir, '"'];
system(rptCmd);
docDir = fullfile(psprjDir, [modelName, '_Bug_Finder_Summary_pdf_files']);
if exist(docDir, 'dir')
    rmdir(docDir, 's');
end
open(rptFile);

% Generate the coding rules report.
tmplFile = fullfile(tmplDir, 'CodingStandards.rpt');
% tmplFile = fullfile(tmplDir, 'BugFinder.rpt');
rptFile = fullfile(psprjDir, [modelName, '_SCS_Conformance_Report.pdf']);
rptCmd = ['"', rptgenExe, '"', ...
    ' -template "', tmplFile, '"', ...
    ' -format PDF', ...
    ' -output-name "', rptFile, '"', ...
    ' -results-dir "', resultDir, '"'];
system(rptCmd);
docDir = fullfile(psprjDir, [modelName, '_SCS_Conformance_Report_pdf_files']);
if exist(docDir, 'dir')
    rmdir(docDir, 's');
end
open(rptFile);

% Close the model.
disp(['Closing Simulink model ', modelName, '.']);
close_system(modelName, 0);

end
