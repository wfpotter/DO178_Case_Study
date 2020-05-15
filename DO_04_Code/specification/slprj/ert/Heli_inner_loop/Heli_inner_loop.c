/*
 * File: Heli_inner_loop.c
 *
 * Code generated for Simulink model 'Heli_inner_loop'.
 *
 * Model version                  : 1.32
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Wed May 13 13:52:32 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-32 (Windows32)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Heli_inner_loop.h"

MdlrefDW_Heli_inner_loop_T Heli_inner_loop_MdlrefDW;

/* Constant parameters (default storage) */
const ConstP_Heli_inner_loop_T Heli_inner_loop_ConstP = {
  /* Expression: [2.395, -0.3609, -0.002145, 0.8087, -0.0205; -0.1427, -1.115, 0.04573, -0.04318, -0.1007; -0.02792, -0.02229, -2.025, -0.06152, 0.03151;]
   * Referenced by: '<Root>/SOF' (Parameter: Gain)
   */
  { 2.395, -0.1427, -0.02792, -0.3609, -1.115, -0.02229, -0.002145, 0.04573,
    -2.025, 0.8087, -0.04318, -0.06152, -0.0205, -0.1007, 0.03151 }
};

/* Output and update for referenced model: 'Heli_inner_loop' */
void Heli_inner_loop(const real_T *rtu_theta_cmd, const real_T *rtu_phi_cmd,
                     const real_T *rtu_r_cmd, const real_T rtu_voted_fb[5],
                     real_T rty_actuator_commands[3])
{
  real_T rtb_Gain[3];
  real_T rtb_SumA21;
  real_T rtb_SumA21_hsvt;
  real_T rtb_SumA21_fq5h;
  int32_T i;
  int32_T i_0;
  real_T y;
  real_T u0;
  real_T y_0;
  real_T u0_0;
  real_T y_1;
  real_T u0_1;

  /* Gain: '<Root>/SOF'
   *
   * Block requirements for '<Root>/SOF':
   *  1. HLR_5: Multi-Variable Inner Loop Control (HelicopterSoftwareRequirements#9)
   */
  for (i = 0; i < 3; i = i + 1) {
    rtb_Gain[i] = 0.0;
    for (i_0 = 0; i_0 < 5; i_0 = i_0 + 1) {
      rtb_Gain[i] = rtb_Gain[i] + (Heli_inner_loop_ConstP.SOF_Gain[(int32_T)(i +
        ((int32_T)(3 * i_0)))] * rtu_voted_fb[i_0]);
    }
  }

  /* End of Gain: '<Root>/SOF' */

  /* Sum: '<S2>/SumA21' incorporates:
   *  Gain: '<S2>/a_2_1'
   *  Gain: '<S2>/s_1'
   *  Sum: '<Root>/Sum5'
   *  UnitDelay: '<S2>/UnitDelay'
   *
   * Block requirements for '<Root>/Sum5':
   *  1. HLR_5: Multi-Variable Inner Loop Control (HelicopterSoftwareRequirements#9)
   */
  rtb_SumA21 = (0.16840424129937498 * ((*rtu_theta_cmd) - rtb_Gain[0])) -
    ((-0.66319151740124993) * Heli_inner_loop_MdlrefDW.rtdw.UnitDelay_DSTATE);

  /* Sum: '<S3>/SumA21' incorporates:
   *  Gain: '<S3>/a_2_1'
   *  Gain: '<S3>/s_1'
   *  Sum: '<Root>/Sum4'
   *  UnitDelay: '<S3>/UnitDelay'
   *
   * Block requirements for '<Root>/Sum4':
   *  1. HLR_5: Multi-Variable Inner Loop Control (HelicopterSoftwareRequirements#9)
   */
  rtb_SumA21_hsvt = (0.16840424129937498 * ((*rtu_phi_cmd) - rtb_Gain[1])) -
    ((-0.66319151740124993) *
     Heli_inner_loop_MdlrefDW.rtdw.UnitDelay_DSTATE_py2j);

  /* Sum: '<S4>/SumA21' incorporates:
   *  Gain: '<S4>/a_2_1'
   *  Gain: '<S4>/s_1'
   *  Sum: '<Root>/Sum6'
   *  UnitDelay: '<S4>/UnitDelay'
   *
   * Block requirements for '<Root>/Sum6':
   *  1. HLR_5: Multi-Variable Inner Loop Control (HelicopterSoftwareRequirements#9)
   */
  rtb_SumA21_fq5h = (0.16840424129937498 * ((*rtu_r_cmd) - rtb_Gain[2])) -
    ((-0.66319151740124993) *
     Heli_inner_loop_MdlrefDW.rtdw.UnitDelay_DSTATE_h2jd);

  /* Gain: '<Root>/Gain' incorporates:
   *  Sum: '<S2>/SumB21'
   *  UnitDelay: '<S2>/UnitDelay'
   *
   * Block requirements for '<Root>/Gain':
   *  1. HLR_5: Multi-Variable Inner Loop Control (HelicopterSoftwareRequirements#9)
   */
  u0 = 0.0033333333333333335 * (rtb_SumA21 +
    Heli_inner_loop_MdlrefDW.rtdw.UnitDelay_DSTATE);

  /* Saturate: '<Root>/Saturation'
   *
   * Block requirements for '<Root>/Saturation':
   *  1. HLR_5: Multi-Variable Inner Loop Control (HelicopterSoftwareRequirements#9)
   */
  if (u0 > 0.1) {
    y = 0.1;
  } else if (u0 < (-0.1)) {
    y = (-0.1);
  } else {
    y = u0;
  }

  rty_actuator_commands[0] = y;

  /* Gain: '<Root>/Gain' incorporates:
   *  Sum: '<S3>/SumB21'
   *  UnitDelay: '<S3>/UnitDelay'
   *
   * Block requirements for '<Root>/Gain':
   *  1. HLR_5: Multi-Variable Inner Loop Control (HelicopterSoftwareRequirements#9)
   */
  u0_0 = 0.0033333333333333335 * (rtb_SumA21_hsvt +
    Heli_inner_loop_MdlrefDW.rtdw.UnitDelay_DSTATE_py2j);

  /* Saturate: '<Root>/Saturation'
   *
   * Block requirements for '<Root>/Saturation':
   *  1. HLR_5: Multi-Variable Inner Loop Control (HelicopterSoftwareRequirements#9)
   */
  if (u0_0 > 0.1) {
    y_0 = 0.1;
  } else if (u0_0 < (-0.1)) {
    y_0 = (-0.1);
  } else {
    y_0 = u0_0;
  }

  rty_actuator_commands[1] = y_0;

  /* Gain: '<Root>/Gain' incorporates:
   *  Sum: '<S4>/SumB21'
   *  UnitDelay: '<S4>/UnitDelay'
   *
   * Block requirements for '<Root>/Gain':
   *  1. HLR_5: Multi-Variable Inner Loop Control (HelicopterSoftwareRequirements#9)
   */
  u0_1 = 0.0033333333333333335 * (rtb_SumA21_fq5h +
    Heli_inner_loop_MdlrefDW.rtdw.UnitDelay_DSTATE_h2jd);

  /* Saturate: '<Root>/Saturation'
   *
   * Block requirements for '<Root>/Saturation':
   *  1. HLR_5: Multi-Variable Inner Loop Control (HelicopterSoftwareRequirements#9)
   */
  if (u0_1 > 0.1) {
    y_1 = 0.1;
  } else if (u0_1 < (-0.1)) {
    y_1 = (-0.1);
  } else {
    y_1 = u0_1;
  }

  rty_actuator_commands[2] = y_1;

  /* Update for UnitDelay: '<S2>/UnitDelay' */
  Heli_inner_loop_MdlrefDW.rtdw.UnitDelay_DSTATE = rtb_SumA21;

  /* Update for UnitDelay: '<S3>/UnitDelay' */
  Heli_inner_loop_MdlrefDW.rtdw.UnitDelay_DSTATE_py2j = rtb_SumA21_hsvt;

  /* Update for UnitDelay: '<S4>/UnitDelay' */
  Heli_inner_loop_MdlrefDW.rtdw.UnitDelay_DSTATE_h2jd = rtb_SumA21_fq5h;
}

/* Model initialize function */
void Heli_inner_loop_initialize(void)
{
  /* Registration code */

  /* states (dwork) */
  Heli_inner_loop_MdlrefDW.rtdw.UnitDelay_DSTATE = 0.0;
  Heli_inner_loop_MdlrefDW.rtdw.UnitDelay_DSTATE_py2j = 0.0;
  Heli_inner_loop_MdlrefDW.rtdw.UnitDelay_DSTATE_h2jd = 0.0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
