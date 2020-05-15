classdef InterfaceDef < Simulink.IntEnumType
    % InterfaceDef Enumeration type definition for use with System Composer profile

    enumeration
        DigitalBus(0)
        AnalogDC(1)
        LVDT(2)
        Physical(3)
    end

end
