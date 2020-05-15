%Limitations:
% 1. Subjected to the accuracy/reliability of Polyspace engine employed by
%    the fixed-point tool API.
% 2. Has dependency on Simulink Fixed-Point license.
function [ResultDescription, ResultHandles] = hisl_0028(system)

ResultDescription = {};
ResultHandles = {};
deviantBlocks = {};
derivedMin = {};
derivedMax = {};
hasFixedPointLicense = true;

modelAdvisorObject = Simulink.ModelAdvisor.getModelAdvisor(system);
modelAdvisorObject.setCheckResultStatus(false);

blockTypes = { 'Sqrt' };

% Find all Reciprocal Sqrt blocks.
blks = find_system(system, 'FollowLinks', 'on', 'LookUnderMasks', 'all', 'BlockType', blockTypes{1}, 'Operator', 'rSqrt');

% Note: Exclusion of Reciprocal Sqrt block with complex output signal type
% is unnecessary because it is not supported.

if ~isempty(blks)
    if license('test', 'fixed_point_toolbox')
        % If system is a virtual subsystem, perform range analysis on the entire model.
        if strcmp(get_param(system, 'Type'), 'block') && strcmp(get_param(system, 'BlockType'), 'SubSystem')
            sys = bdroot(system);
        else
            sys = system;
        end
        % Compute derived ranges.
        converter = DataTypeWorkflow.Converter(sys);
        converter.CurrentRunName = 'DerivedRanges';
        converter.deriveMinMax();
        % Check for the input range to all Reciprocal Sqrt blocks.
        for j = 1:length(blks)
            portHandles = get_param(blks{j}, 'PortHandles');
            line = get_param(portHandles.Inport, 'Line');
            srcOutputPorts = get_param(line, 'NonVirtualSrcPorts');
            line = get_param(srcOutputPorts(1), 'line');
            srcBlockHandle = get_param(line, 'SrcBlockHandle');
            srcBlockObj = get_param(srcBlockHandle, 'Object');
            result = converter.results(converter.CurrentRunName,@(r) (strcmp(r.ResultName, [srcBlockObj.Path,'/',srcBlockObj.Name])));
            % For some reasons, certain blocks like the Add block is named
            % Add : Output in the result set, so if result is empty, must check
            % again for BlockName : Output.
            if isempty(result)
                result = converter.results(converter.CurrentRunName,@(r) (strcmp(r.ResultName, [srcBlockObj.Path,'/',srcBlockObj.Name,' : Output'])));
            end
            if isempty(result) || result.DerivedMin <= 0.0
                deviantBlocks{end+1} = blks{j}; %#ok<AGROW>
                if ~isempty(result)
                    derivedMin{end+1} = num2str(result.DerivedMin); %#ok<AGROW>
                else
                    derivedMin{end+1} = 'unknown'; %#ok<AGROW>
                end
                if ~isempty(result)
                    derivedMax{end+1} = num2str(result.DerivedMax); %#ok<AGROW>
                else
                    derivedMax{end+1} = 'unknown'; %#ok<AGROW>
                end
            end
        end
    else
        hasFixedPointLicense = false;
    end
    
end

%% 
if ~isempty(deviantBlocks)  
%     ft = ModelAdvisor.FormatTemplate('ListTemplate');
%     ft.setSubResultStatus('Warn');
%     ft.setSubResultStatusText('Found following Reciprocal Sqrt block(s) with potential zero or negative input(s):');
%     ft.setListObj(deviantBlocks);
%     setRecAction(ft, 'Consider constraining the input signal(s) of the block(s) to avoid zero or negative values.');
%     ResultDescription{end+1} = ft;

    ft = ModelAdvisor.FormatTemplate('TableTemplate');
    ft.setSubResultStatus('Warn');
    ft.setSubResultStatusText('Found following Reciprocal Sqrt block(s) with potential zero or negative input(s):');
    ft.setColTitles({'Block', 'Minimum Input', 'Maximum Input'});
    for idx = 1:length(deviantBlocks)
        ft.addRow({deviantBlocks(idx),derivedMin{idx},derivedMax{idx}})
    end
    setRecAction(ft, 'Consider constraining the input signal(s) of the block(s) to avoid zero or negative values.');
    ResultDescription{end+1} = ft;
elseif ~hasFixedPointLicense
    modelAdvisorObject.setCheckResultStatus(false);
    ResultDescription{end+1} = ModelAdvisor.Text('No Fixed-Point Designer license is available.');
else  
    % No violation.
    modelAdvisorObject.setCheckResultStatus(true);
    ResultDescription{end+1} = ModelAdvisor.Text('Passed.',{'bold','pass'});
end