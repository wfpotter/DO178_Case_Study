/*
 * File: Heli_outer_loop.c
 *
 * Code generated for Simulink model 'Heli_outer_loop'.
 *
 * Model version                  : 1.32
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Wed May 13 13:52:39 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-32 (Windows32)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Heli_outer_loop.h"

MdlrefDW_Heli_outer_loop_T Heli_outer_loop_MdlrefDW;

/* Disable for referenced model: 'Heli_outer_loop' */
void Heli_outer_loop_Disable(void)
{
  /* Disable for DiscreteIntegrator: '<Root>/Integrator'
   *
   * Block requirements for '<Root>/Integrator':
   *  1. HLR_6: Pitch Outer Loop Control (HelicopterSoftwareRequirements#10)
   */
  Heli_outer_loop_MdlrefDW.rtdw.Integrator_DSTATE =
    Heli_outer_loop_MdlrefDW.rtb.Integrator;

  /* Disable for DiscreteIntegrator: '<Root>/Integrator1'
   *
   * Block requirements for '<Root>/Integrator1':
   *  1. HLR_7: Roll Outer Loop Control (HelicopterSoftwareRequirements#11)
   */
  Heli_outer_loop_MdlrefDW.rtdw.Integrator1_DSTATE =
    Heli_outer_loop_MdlrefDW.rtb.Integrator1;

  /* Disable for DiscreteIntegrator: '<Root>/Integrator2'
   *
   * Block requirements for '<Root>/Integrator2':
   *  1. HLR_8: Yaw Outer Loop Control (HelicopterSoftwareRequirements#12)
   */
  Heli_outer_loop_MdlrefDW.rtdw.Integrator2_DSTATE =
    Heli_outer_loop_MdlrefDW.rtb.Integrator2;
}

/* Output and update for referenced model: 'Heli_outer_loop' */
void Heli_outer_loop(const int16_T *rtu_Pilot_theta_cmd, const int16_T
                     *rtu_Pilot_phi_cmd, const int16_T *rtu_Pilot_r_cmd, const
                     real_T rtu_voted_fb[5], real_T *rty_theta_cmd, real_T
                     *rty_phi_cmd, real_T *rty_r_cmd)
{
  real_T rtb_Sum;
  real_T rtb_Scaling2;
  real_T rtb_Sum5;
  real_T y;
  real_T u0;
  real_T y_0;
  real_T u0_0;
  real_T y_1;
  real_T u0_1;

  /* Sum: '<Root>/Sum' incorporates:
   *  DataTypeConversion: '<Root>/TypeConversion'
   *  Gain: '<Root>/Scaling'
   *
   * Block requirements for '<Root>/Sum':
   *  1. HLR_6: Pitch Outer Loop Control (HelicopterSoftwareRequirements#10)
   *
   * Block requirements for '<Root>/TypeConversion':
   *  1. HLR_1: Pilot Input Signal Processing (HelicopterSoftwareRequirements#5)
   *
   * Block requirements for '<Root>/Scaling':
   *  1. HLR_1: Pilot Input Signal Processing (HelicopterSoftwareRequirements#5)
   */
  rtb_Sum = (0.00091555528427991577 * ((real_T)(*rtu_Pilot_theta_cmd))) -
    rtu_voted_fb[0];

  /* Sum: '<Root>/Sum1' incorporates:
   *  DataTypeConversion: '<Root>/TypeConversion1'
   *  Gain: '<Root>/Scaling1'
   *
   * Block requirements for '<Root>/Sum1':
   *  1. HLR_7: Roll Outer Loop Control (HelicopterSoftwareRequirements#11)
   *
   * Block requirements for '<Root>/TypeConversion1':
   *  1. HLR_1: Pilot Input Signal Processing (HelicopterSoftwareRequirements#5)
   *
   * Block requirements for '<Root>/Scaling1':
   *  1. HLR_1: Pilot Input Signal Processing (HelicopterSoftwareRequirements#5)
   */
  rtb_Scaling2 = (0.00091555528427991577 * ((real_T)(*rtu_Pilot_phi_cmd))) -
    rtu_voted_fb[1];

  /* Sum: '<Root>/Sum2' incorporates:
   *  DataTypeConversion: '<Root>/TypeConversion2'
   *  Gain: '<Root>/Scaling2'
   *
   * Block requirements for '<Root>/Sum2':
   *  1. HLR_8: Yaw Outer Loop Control (HelicopterSoftwareRequirements#12)
   *
   * Block requirements for '<Root>/TypeConversion2':
   *  1. HLR_1: Pilot Input Signal Processing (HelicopterSoftwareRequirements#5)
   *
   * Block requirements for '<Root>/Scaling2':
   *  1. HLR_1: Pilot Input Signal Processing (HelicopterSoftwareRequirements#5)
   */
  rtb_Sum5 = (0.00045777764213995788 * ((real_T)(*rtu_Pilot_r_cmd))) -
    rtu_voted_fb[2];

  /* DiscreteIntegrator: '<Root>/Integrator'
   *
   * Block requirements for '<Root>/Integrator':
   *  1. HLR_6: Pitch Outer Loop Control (HelicopterSoftwareRequirements#10)
   */
  Heli_outer_loop_MdlrefDW.rtb.Integrator =
    Heli_outer_loop_MdlrefDW.rtdw.Integrator_DSTATE;

  /* DiscreteIntegrator: '<Root>/Integrator1'
   *
   * Block requirements for '<Root>/Integrator1':
   *  1. HLR_7: Roll Outer Loop Control (HelicopterSoftwareRequirements#11)
   */
  Heli_outer_loop_MdlrefDW.rtb.Integrator1 =
    Heli_outer_loop_MdlrefDW.rtdw.Integrator1_DSTATE;

  /* DiscreteIntegrator: '<Root>/Integrator2'
   *
   * Block requirements for '<Root>/Integrator2':
   *  1. HLR_8: Yaw Outer Loop Control (HelicopterSoftwareRequirements#12)
   */
  Heli_outer_loop_MdlrefDW.rtb.Integrator2 =
    Heli_outer_loop_MdlrefDW.rtdw.Integrator2_DSTATE;

  /* Sum: '<Root>/Sum3' incorporates:
   *  Gain: '<Root>/Gain'
   *
   * Block requirements for '<Root>/Sum3':
   *  1. HLR_6: Pitch Outer Loop Control (HelicopterSoftwareRequirements#10)
   *
   * Block requirements for '<Root>/Gain':
   *  1. HLR_6: Pitch Outer Loop Control (HelicopterSoftwareRequirements#10)
   */
  u0 = Heli_outer_loop_MdlrefDW.rtb.Integrator + (1.33 * rtb_Sum);

  /* Saturate: '<Root>/Saturation'
   *
   * Block requirements for '<Root>/Saturation':
   *  1. HLR_6: Pitch Outer Loop Control (HelicopterSoftwareRequirements#10)
   */
  if (u0 > 30.0) {
    y = 30.0;
  } else if (u0 < (-30.0)) {
    y = (-30.0);
  } else {
    y = u0;
  }

  *rty_theta_cmd = y;

  /* End of Saturate: '<Root>/Saturation' */

  /* Sum: '<Root>/Sum4' incorporates:
   *  Gain: '<Root>/Gain1'
   *
   * Block requirements for '<Root>/Sum4':
   *  1. HLR_7: Roll Outer Loop Control (HelicopterSoftwareRequirements#11)
   *
   * Block requirements for '<Root>/Gain1':
   *  1. HLR_7: Roll Outer Loop Control (HelicopterSoftwareRequirements#11)
   */
  u0_0 = Heli_outer_loop_MdlrefDW.rtb.Integrator1 + ((-0.086) * rtb_Scaling2);

  /* Saturate: '<Root>/Saturation1'
   *
   * Block requirements for '<Root>/Saturation1':
   *  1. HLR_7: Roll Outer Loop Control (HelicopterSoftwareRequirements#11)
   */
  if (u0_0 > 30.0) {
    y_0 = 30.0;
  } else if (u0_0 < (-30.0)) {
    y_0 = (-30.0);
  } else {
    y_0 = u0_0;
  }

  *rty_phi_cmd = y_0;

  /* End of Saturate: '<Root>/Saturation1' */

  /* Sum: '<Root>/Sum5' incorporates:
   *  Gain: '<Root>/Gain4'
   *
   * Block requirements for '<Root>/Sum5':
   *  1. HLR_8: Yaw Outer Loop Control (HelicopterSoftwareRequirements#12)
   *
   * Block requirements for '<Root>/Gain4':
   *  1. HLR_8: Yaw Outer Loop Control (HelicopterSoftwareRequirements#12)
   */
  u0_1 = Heli_outer_loop_MdlrefDW.rtb.Integrator2 + (0.133 * rtb_Sum5);

  /* Saturate: '<Root>/Saturation2'
   *
   * Block requirements for '<Root>/Saturation2':
   *  1. HLR_8: Yaw Outer Loop Control (HelicopterSoftwareRequirements#12)
   */
  if (u0_1 > 30.0) {
    y_1 = 30.0;
  } else if (u0_1 < (-30.0)) {
    y_1 = (-30.0);
  } else {
    y_1 = u0_1;
  }

  *rty_r_cmd = y_1;

  /* End of Saturate: '<Root>/Saturation2' */

  /* Update for DiscreteIntegrator: '<Root>/Integrator' incorporates:
   *  Gain: '<Root>/Gain2'
   *
   * Block requirements for '<Root>/Integrator':
   *  1. HLR_6: Pitch Outer Loop Control (HelicopterSoftwareRequirements#10)
   *
   * Block requirements for '<Root>/Gain2':
   *  1. HLR_6: Pitch Outer Loop Control (HelicopterSoftwareRequirements#10)
   */
  Heli_outer_loop_MdlrefDW.rtdw.Integrator_DSTATE =
    Heli_outer_loop_MdlrefDW.rtdw.Integrator_DSTATE + (0.01 * (2.25 * rtb_Sum));
  if (Heli_outer_loop_MdlrefDW.rtdw.Integrator_DSTATE >= 10.0) {
    Heli_outer_loop_MdlrefDW.rtdw.Integrator_DSTATE = 10.0;
  } else {
    if (Heli_outer_loop_MdlrefDW.rtdw.Integrator_DSTATE <= (-10.0)) {
      Heli_outer_loop_MdlrefDW.rtdw.Integrator_DSTATE = (-10.0);
    }
  }

  /* End of Update for DiscreteIntegrator: '<Root>/Integrator' */

  /* Update for DiscreteIntegrator: '<Root>/Integrator1' incorporates:
   *  Gain: '<Root>/Gain3'
   *
   * Block requirements for '<Root>/Integrator1':
   *  1. HLR_7: Roll Outer Loop Control (HelicopterSoftwareRequirements#11)
   *
   * Block requirements for '<Root>/Gain3':
   *  1. HLR_7: Roll Outer Loop Control (HelicopterSoftwareRequirements#11)
   */
  Heli_outer_loop_MdlrefDW.rtdw.Integrator1_DSTATE =
    Heli_outer_loop_MdlrefDW.rtdw.Integrator1_DSTATE + (0.01 * ((-1.19) *
    rtb_Scaling2));
  if (Heli_outer_loop_MdlrefDW.rtdw.Integrator1_DSTATE >= 10.0) {
    Heli_outer_loop_MdlrefDW.rtdw.Integrator1_DSTATE = 10.0;
  } else {
    if (Heli_outer_loop_MdlrefDW.rtdw.Integrator1_DSTATE <= (-10.0)) {
      Heli_outer_loop_MdlrefDW.rtdw.Integrator1_DSTATE = (-10.0);
    }
  }

  /* End of Update for DiscreteIntegrator: '<Root>/Integrator1' */

  /* Update for DiscreteIntegrator: '<Root>/Integrator2' incorporates:
   *  Gain: '<Root>/Gain5'
   *
   * Block requirements for '<Root>/Integrator2':
   *  1. HLR_8: Yaw Outer Loop Control (HelicopterSoftwareRequirements#12)
   *
   * Block requirements for '<Root>/Gain5':
   *  1. HLR_8: Yaw Outer Loop Control (HelicopterSoftwareRequirements#12)
   */
  Heli_outer_loop_MdlrefDW.rtdw.Integrator2_DSTATE =
    Heli_outer_loop_MdlrefDW.rtdw.Integrator2_DSTATE + (0.01 * ((-2.33) *
    rtb_Sum5));
  if (Heli_outer_loop_MdlrefDW.rtdw.Integrator2_DSTATE >= 10.0) {
    Heli_outer_loop_MdlrefDW.rtdw.Integrator2_DSTATE = 10.0;
  } else {
    if (Heli_outer_loop_MdlrefDW.rtdw.Integrator2_DSTATE <= (-10.0)) {
      Heli_outer_loop_MdlrefDW.rtdw.Integrator2_DSTATE = (-10.0);
    }
  }

  /* End of Update for DiscreteIntegrator: '<Root>/Integrator2' */
}

/* Model initialize function */
void Heli_outer_loop_initialize(void)
{
  /* Registration code */

  /* block I/O */
  {
    Heli_outer_loop_MdlrefDW.rtb.Integrator = 0.0;
    Heli_outer_loop_MdlrefDW.rtb.Integrator1 = 0.0;
    Heli_outer_loop_MdlrefDW.rtb.Integrator2 = 0.0;
  }

  /* states (dwork) */
  Heli_outer_loop_MdlrefDW.rtdw.Integrator_DSTATE = 0.0;
  Heli_outer_loop_MdlrefDW.rtdw.Integrator1_DSTATE = 0.0;
  Heli_outer_loop_MdlrefDW.rtdw.Integrator2_DSTATE = 0.0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
