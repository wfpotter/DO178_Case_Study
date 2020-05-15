/*
 * File: ActuatorLoop.c
 *
 * Code generated for Simulink model 'ActuatorLoop'.
 *
 * Model version                  : 1.45
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Wed May 13 13:52:25 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-32 (Windows32)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ActuatorLoop.h"

/* Disable for referenced model: 'ActuatorLoop' */
void ActuatorLoop_Disable(B_ActuatorLoop_caua_T *localB, DW_ActuatorLoop_fwu4_T *
  localDW)
{
  /* Disable for DiscreteIntegrator: '<Root>/Integrator'
   *
   * Block requirements for '<Root>/Integrator':
   *  1. HLR_4: Hydraulic Actuator Loop Control (HelicopterSoftwareRequirements#8)
   */
  localDW->Integrator_DSTATE = localB->Integrator;
}

/* Output and update for referenced model: 'ActuatorLoop' */
void ActuatorLoop(const int16_T *rtu_PositionFeedback, const real_T
                  *rtu_PositionCommand, int16_T *rty_ActuatorCommand,
                  B_ActuatorLoop_caua_T *localB, DW_ActuatorLoop_fwu4_T *localDW,
                  real_T rtp_Kp, real_T rtp_Kd, real_T rtp_Ki)
{
  real_T rtb_Sum;
  real_T y;
  real_T u0;

  /* Sum: '<Root>/Sum' incorporates:
   *  DataTypeConversion: '<Root>/TypeConversion'
   *  Gain: '<Root>/Scaling'
   *
   * Block requirements for '<Root>/Sum':
   *  1. HLR_4: Hydraulic Actuator Loop Control (HelicopterSoftwareRequirements#8)
   *
   * Block requirements for '<Root>/TypeConversion':
   *  1. HLR_2 : Hydraulic Actuator Feedback (HelicopterSoftwareRequirements#6)
   *
   * Block requirements for '<Root>/Scaling':
   *  1. HLR_2 : Hydraulic Actuator Feedback (HelicopterSoftwareRequirements#6)
   */
  rtb_Sum = (*rtu_PositionCommand) - (3.0518509475997192E-6 * ((real_T)
    (*rtu_PositionFeedback)));

  /* DiscreteIntegrator: '<Root>/Integrator'
   *
   * Block requirements for '<Root>/Integrator':
   *  1. HLR_4: Hydraulic Actuator Loop Control (HelicopterSoftwareRequirements#8)
   */
  localB->Integrator = localDW->Integrator_DSTATE;

  /* Sum: '<Root>/Sum1' incorporates:
   *  Gain: '<Root>/Gain'
   *  Gain: '<Root>/Gain1'
   *  Sum: '<S1>/Diff'
   *  UnitDelay: '<S1>/UD'
   *
   * Block requirements for '<Root>/Sum1':
   *  1. HLR_4: Hydraulic Actuator Loop Control (HelicopterSoftwareRequirements#8)
   *
   * Block requirements for '<Root>/Gain':
   *  1. HLR_4: Hydraulic Actuator Loop Control (HelicopterSoftwareRequirements#8)
   *
   * Block requirements for '<Root>/Gain1':
   *  1. HLR_4: Hydraulic Actuator Loop Control (HelicopterSoftwareRequirements#8)
   */
  u0 = (localB->Integrator + (rtp_Kp * rtb_Sum)) - (rtp_Kd * (rtb_Sum -
    localDW->UD_DSTATE));

  /* Saturate: '<Root>/Saturation'
   *
   * Block requirements for '<Root>/Saturation':
   *  1. HLR_4: Hydraulic Actuator Loop Control (HelicopterSoftwareRequirements#8)
   */
  if (u0 > 0.3) {
    y = 0.3;
  } else if (u0 < (-0.3)) {
    y = (-0.3);
  } else {
    y = u0;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* DataTypeConversion: '<Root>/TypeConversion6' incorporates:
   *  Gain: '<Root>/Scaling6'
   *
   * Block requirements for '<Root>/TypeConversion6':
   *  1. HLR_3: Hydraulic Actuator Drive (HelicopterSoftwareRequirements#7)
   *
   * Block requirements for '<Root>/Scaling6':
   *  1. HLR_3: Hydraulic Actuator Drive (HelicopterSoftwareRequirements#7)
   */
  *rty_ActuatorCommand = (int16_T)floor(109223.33333333334 * y);

  /* Update for UnitDelay: '<S1>/UD' */
  localDW->UD_DSTATE = rtb_Sum;

  /* Update for DiscreteIntegrator: '<Root>/Integrator' incorporates:
   *  Gain: '<Root>/Gain2'
   *
   * Block requirements for '<Root>/Integrator':
   *  1. HLR_4: Hydraulic Actuator Loop Control (HelicopterSoftwareRequirements#8)
   *
   * Block requirements for '<Root>/Gain2':
   *  1. HLR_4: Hydraulic Actuator Loop Control (HelicopterSoftwareRequirements#8)
   */
  localDW->Integrator_DSTATE = localDW->Integrator_DSTATE + (0.001 * (rtp_Ki *
    rtb_Sum));
  if (localDW->Integrator_DSTATE >= 0.1) {
    localDW->Integrator_DSTATE = 0.1;
  } else {
    if (localDW->Integrator_DSTATE <= (-0.1)) {
      localDW->Integrator_DSTATE = (-0.1);
    }
  }

  /* End of Update for DiscreteIntegrator: '<Root>/Integrator' */
}

/* Model initialize function */
void ActuatorLoop_initialize(B_ActuatorLoop_caua_T *localB,
  DW_ActuatorLoop_fwu4_T *localDW)
{
  /* Registration code */

  /* block I/O */
  {
    localB->Integrator = 0.0;
  }

  /* states (dwork) */
  localDW->UD_DSTATE = 0.0;
  localDW->Integrator_DSTATE = 0.0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
