% Helicopter tuning example
 
% Copyright 2016 The MathWorks, Inc.

% first, test for a Simulink Control Design, Control System Toolbox and
% Robust Control Toolbox licenses
if license('test','simulink_control_design')&&...
        license('test','control_toolbox')&&license('test','robust_toolbox')
    
    % bring command window to the front
    commandwindow;
    
    ST0 = slTuner('rct_helico_Sdomain',{'PI1','PI2','PI3','SOF'});
    
    addPoint(ST0,{'theta-ref','phi-ref','r-ref'});   % setpoint commands
    addPoint(ST0,{'theta','phi','r'});               % corresponding outputs
    addPoint(ST0,{'u','y'});
    
    % Less than 20% mismatch with reference model 1/(s+1)
    TrackReq = TuningGoal.StepTracking({'theta-ref','phi-ref','r-ref'},{'theta','phi','r'},1);
    TrackReq.RelGap = 0.2;
    
    % Gain and phase margins at plant inputs and outputs
    MarginReq1 = TuningGoal.Margins('u',5,40);
    MarginReq2 = TuningGoal.Margins('y',5,40);
    
    % Limit on fast dynamics
    MaxFrequency = 25;
    PoleReq = TuningGoal.Poles(0,0,MaxFrequency);
    
    AllReqs = [TrackReq,MarginReq1,MarginReq2,PoleReq];
    [ST1,fSoft,~,Info] = systune(ST0,AllReqs);
    
    T1 = getIOTransfer(ST1,{'theta-ref','phi-ref','r-ref'},{'theta','phi','r'});
    step(T1,5);
    
    figure('Position',[100,100,900,474]);
    viewSpec(AllReqs,ST1,Info);
    
    showTunable(ST1);
    % Clean up
    bdclose('all');
    clearvars;
    
else % open the pre-existing report and post a warning
    open('Heli-Tuning-Report.pdf');
    warndlg(['There is a license missing for Simulink Control Design '...
        'or Control System Toolbox or Robust Control Toolbox, a ' ...
        'pre-existing tuning report has been opened'],...
        'Missing Product License');
end


