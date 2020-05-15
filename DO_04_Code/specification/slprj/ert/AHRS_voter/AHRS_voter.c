/*
 * File: AHRS_voter.c
 *
 * Code generated for Simulink model 'AHRS_voter'.
 *
 * Model version                  : 1.69
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Wed May 13 13:52:17 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-32 (Windows32)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "AHRS_voter.h"

/* Constant parameters (default storage) */
const ConstP_AHRS_voter_T AHRS_voter_ConstP = {
  /* Pooled Parameter (Expression: [0 0 0 0 0])
   * Referenced by:
   *   '<Root>/Constant' (Parameter: Value)
   *   '<S1>/Constant' (Parameter: Value)
   *   '<S4>/Constant' (Parameter: Value)
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0 }
};

/* Output and update for referenced model: 'AHRS_voter' */
void AHRS_voter(const AHRS_Bus *rtu_AHRS1, const AHRS_Bus *rtu_AHRS2, const
                AHRS_Bus *rtu_AHRS3, real_T rty_voted_fb[5])
{
  real_T rtb_Switch1[5];
  real_T rtb_Switch2[5];
  int32_T i;
  int32_T i_0;
  int32_T i_1;
  int32_T i_2;
  int32_T i_3;
  int32_T i_4;
  int32_T i_5;
  int32_T i_6;
  int32_T i_7;

  /* MultiPortSwitch: '<Root>/MultiportSwitch' incorporates:
   *  Constant: '<Root>/Constant'
   *  Gain: '<S1>/Gain'
   *  MinMax: '<S2>/MinMax'
   *  MinMax: '<S2>/MinMax1'
   *  MinMax: '<S2>/MinMax2'
   *  MinMax: '<S2>/MinMax3'
   *  Sum: '<Root>/Sum'
   *  Sum: '<S1>/Sum'
   *  Sum: '<S4>/Sum'
   *
   * Block requirements for '<Root>/MultiportSwitch':
   *  1. HLR_9 : AHRS Validity Check (HelicopterSoftwareRequirements#13)
   *  2. HLR_11: AHRS Voting for Triple Sensors (HelicopterSoftwareRequirements#15)
   *  3. HLR_12: AHRS Voting for Dual Sensors (HelicopterSoftwareRequirements#16)
   *  4. HLR_13: AHRS Usage of Single Sensor (HelicopterSoftwareRequirements#17)
   *
   * Block requirements for '<S1>/Gain':
   *  1. HLR_12: AHRS Voting for Dual Sensors (HelicopterSoftwareRequirements#16)
   *
   * Block requirements for '<S2>/MinMax':
   *  1. HLR_11: AHRS Voting for Triple Sensors (HelicopterSoftwareRequirements#15)
   *
   * Block requirements for '<S2>/MinMax1':
   *  1. HLR_11: AHRS Voting for Triple Sensors (HelicopterSoftwareRequirements#15)
   *
   * Block requirements for '<S2>/MinMax2':
   *  1. HLR_11: AHRS Voting for Triple Sensors (HelicopterSoftwareRequirements#15)
   *
   * Block requirements for '<S2>/MinMax3':
   *  1. HLR_11: AHRS Voting for Triple Sensors (HelicopterSoftwareRequirements#15)
   *
   * Block requirements for '<Root>/Sum':
   *  1. HLR_9 : AHRS Validity Check (HelicopterSoftwareRequirements#13)
   *
   * Block requirements for '<S1>/Sum':
   *  1. HLR_12: AHRS Voting for Dual Sensors (HelicopterSoftwareRequirements#16)
   *
   * Block requirements for '<S4>/Sum':
   *  1. HLR_13: AHRS Usage of Single Sensor (HelicopterSoftwareRequirements#17)
   */
  switch ((uint32_T)(((uint32_T)(((uint32_T)(rtu_AHRS1->valid ? 1U : 0U)) +
             ((uint32_T)(rtu_AHRS2->valid ? 1U : 0U)))) + ((uint32_T)
            (rtu_AHRS3->valid ? 1U : 0U)))) {
   case 0:
    for (i = 0; i < 5; i = i + 1) {
      rty_voted_fb[i] = AHRS_voter_ConstP.pooled1[(i)];
    }
    break;

   case 1:
    /* Outputs for Atomic SubSystem: '<Root>/Single_Value'
     *
     * Block requirements for '<Root>/Single_Value':
     *  1. HLR_13: AHRS Usage of Single Sensor (HelicopterSoftwareRequirements#17)
     */
    /* Switch: '<S4>/Switch' incorporates:
     *  Constant: '<S4>/Constant'
     *
     * Block requirements for '<S4>/Switch':
     *  1. HLR_13: AHRS Usage of Single Sensor (HelicopterSoftwareRequirements#17)
     *
     * Block requirements for '<S4>/Constant':
     *  1. HLR_13: AHRS Usage of Single Sensor (HelicopterSoftwareRequirements#17)
     */
    if (rtu_AHRS1->valid) {
      rty_voted_fb[0] = rtu_AHRS1->theta;
      rty_voted_fb[1] = rtu_AHRS1->phi;
      rty_voted_fb[2] = rtu_AHRS1->r;
      rty_voted_fb[3] = rtu_AHRS1->q;
      rty_voted_fb[4] = rtu_AHRS1->p;
    } else {
      for (i_0 = 0; i_0 < 5; i_0 = i_0 + 1) {
        rty_voted_fb[i_0] = AHRS_voter_ConstP.pooled1[(i_0)];
      }
    }

    /* End of Switch: '<S4>/Switch' */

    /* Switch: '<S4>/Switch1' incorporates:
     *  Constant: '<S4>/Constant'
     *
     * Block requirements for '<S4>/Switch1':
     *  1. HLR_13: AHRS Usage of Single Sensor (HelicopterSoftwareRequirements#17)
     *
     * Block requirements for '<S4>/Constant':
     *  1. HLR_13: AHRS Usage of Single Sensor (HelicopterSoftwareRequirements#17)
     */
    if (rtu_AHRS2->valid) {
      rtb_Switch1[0] = rtu_AHRS2->theta;
      rtb_Switch1[1] = rtu_AHRS2->phi;
      rtb_Switch1[2] = rtu_AHRS2->r;
      rtb_Switch1[3] = rtu_AHRS2->q;
      rtb_Switch1[4] = rtu_AHRS2->p;
    } else {
      for (i_2 = 0; i_2 < 5; i_2 = i_2 + 1) {
        rtb_Switch1[i_2] = AHRS_voter_ConstP.pooled1[(i_2)];
      }
    }

    /* End of Switch: '<S4>/Switch1' */

    /* Switch: '<S4>/Switch2' incorporates:
     *  Constant: '<S4>/Constant'
     *
     * Block requirements for '<S4>/Switch2':
     *  1. HLR_13: AHRS Usage of Single Sensor (HelicopterSoftwareRequirements#17)
     *
     * Block requirements for '<S4>/Constant':
     *  1. HLR_13: AHRS Usage of Single Sensor (HelicopterSoftwareRequirements#17)
     */
    if (rtu_AHRS3->valid) {
      rtb_Switch2[0] = rtu_AHRS3->theta;
      rtb_Switch2[1] = rtu_AHRS3->phi;
      rtb_Switch2[2] = rtu_AHRS3->r;
      rtb_Switch2[3] = rtu_AHRS3->q;
      rtb_Switch2[4] = rtu_AHRS3->p;
    } else {
      for (i_4 = 0; i_4 < 5; i_4 = i_4 + 1) {
        rtb_Switch2[i_4] = AHRS_voter_ConstP.pooled1[(i_4)];
      }
    }

    /* End of Switch: '<S4>/Switch2' */
    /* End of Outputs for SubSystem: '<Root>/Single_Value' */
    for (i_6 = 0; i_6 < 5; i_6 = i_6 + 1) {
      /* Outputs for Atomic SubSystem: '<Root>/Single_Value'
       *
       * Block requirements for '<Root>/Single_Value':
       *  1. HLR_13: AHRS Usage of Single Sensor (HelicopterSoftwareRequirements#17)
       */
      rty_voted_fb[i_6] = (rty_voted_fb[i_6] + rtb_Switch1[i_6]) +
        rtb_Switch2[i_6];

      /* End of Outputs for SubSystem: '<Root>/Single_Value' */
    }
    break;

   case 2:
    /* Outputs for Atomic SubSystem: '<Root>/Avg_Value'
     *
     * Block requirements for '<Root>/Avg_Value':
     *  1. HLR_12: AHRS Voting for Dual Sensors (HelicopterSoftwareRequirements#16)
     */
    /* Switch: '<S1>/Switch' incorporates:
     *  Constant: '<S1>/Constant'
     *
     * Block requirements for '<S1>/Switch':
     *  1. HLR_12: AHRS Voting for Dual Sensors (HelicopterSoftwareRequirements#16)
     *
     * Block requirements for '<S1>/Constant':
     *  1. HLR_12: AHRS Voting for Dual Sensors (HelicopterSoftwareRequirements#16)
     */
    if (rtu_AHRS1->valid) {
      rty_voted_fb[0] = rtu_AHRS1->theta;
      rty_voted_fb[1] = rtu_AHRS1->phi;
      rty_voted_fb[2] = rtu_AHRS1->r;
      rty_voted_fb[3] = rtu_AHRS1->q;
      rty_voted_fb[4] = rtu_AHRS1->p;
    } else {
      for (i_1 = 0; i_1 < 5; i_1 = i_1 + 1) {
        rty_voted_fb[i_1] = AHRS_voter_ConstP.pooled1[(i_1)];
      }
    }

    /* End of Switch: '<S1>/Switch' */

    /* Switch: '<S1>/Switch1' incorporates:
     *  Constant: '<S1>/Constant'
     *
     * Block requirements for '<S1>/Switch1':
     *  1. HLR_12: AHRS Voting for Dual Sensors (HelicopterSoftwareRequirements#16)
     *
     * Block requirements for '<S1>/Constant':
     *  1. HLR_12: AHRS Voting for Dual Sensors (HelicopterSoftwareRequirements#16)
     */
    if (rtu_AHRS2->valid) {
      rtb_Switch1[0] = rtu_AHRS2->theta;
      rtb_Switch1[1] = rtu_AHRS2->phi;
      rtb_Switch1[2] = rtu_AHRS2->r;
      rtb_Switch1[3] = rtu_AHRS2->q;
      rtb_Switch1[4] = rtu_AHRS2->p;
    } else {
      for (i_3 = 0; i_3 < 5; i_3 = i_3 + 1) {
        rtb_Switch1[i_3] = AHRS_voter_ConstP.pooled1[(i_3)];
      }
    }

    /* End of Switch: '<S1>/Switch1' */

    /* Switch: '<S1>/Switch2' incorporates:
     *  Constant: '<S1>/Constant'
     *
     * Block requirements for '<S1>/Switch2':
     *  1. HLR_12: AHRS Voting for Dual Sensors (HelicopterSoftwareRequirements#16)
     *
     * Block requirements for '<S1>/Constant':
     *  1. HLR_12: AHRS Voting for Dual Sensors (HelicopterSoftwareRequirements#16)
     */
    if (rtu_AHRS3->valid) {
      rtb_Switch2[0] = rtu_AHRS3->theta;
      rtb_Switch2[1] = rtu_AHRS3->phi;
      rtb_Switch2[2] = rtu_AHRS3->r;
      rtb_Switch2[3] = rtu_AHRS3->q;
      rtb_Switch2[4] = rtu_AHRS3->p;
    } else {
      for (i_5 = 0; i_5 < 5; i_5 = i_5 + 1) {
        rtb_Switch2[i_5] = AHRS_voter_ConstP.pooled1[(i_5)];
      }
    }

    /* End of Switch: '<S1>/Switch2' */
    /* End of Outputs for SubSystem: '<Root>/Avg_Value' */
    for (i_7 = 0; i_7 < 5; i_7 = i_7 + 1) {
      /* Outputs for Atomic SubSystem: '<Root>/Avg_Value'
       *
       * Block requirements for '<Root>/Avg_Value':
       *  1. HLR_12: AHRS Voting for Dual Sensors (HelicopterSoftwareRequirements#16)
       */
      rty_voted_fb[i_7] = 0.5 * ((rty_voted_fb[i_7] + rtb_Switch1[i_7]) +
        rtb_Switch2[i_7]);

      /* End of Outputs for SubSystem: '<Root>/Avg_Value' */
    }
    break;

   default:
    /* Outputs for Atomic SubSystem: '<Root>/Mid_Value'
     *
     * Block requirements for '<Root>/Mid_Value':
     *  1. HLR_11: AHRS Voting for Triple Sensors (HelicopterSoftwareRequirements#15)
     */
    rty_voted_fb[0] = fmax(fmax(fmin(rtu_AHRS1->theta, rtu_AHRS2->theta), fmin
      (rtu_AHRS2->theta, rtu_AHRS3->theta)), fmin(rtu_AHRS3->theta,
      rtu_AHRS1->theta));
    rty_voted_fb[1] = fmax(fmax(fmin(rtu_AHRS1->phi, rtu_AHRS2->phi), fmin
      (rtu_AHRS2->phi, rtu_AHRS3->phi)), fmin(rtu_AHRS3->phi, rtu_AHRS1->phi));
    rty_voted_fb[2] = fmax(fmax(fmin(rtu_AHRS1->r, rtu_AHRS2->r), fmin
      (rtu_AHRS2->r, rtu_AHRS3->r)), fmin(rtu_AHRS3->r, rtu_AHRS1->r));
    rty_voted_fb[3] = fmax(fmax(fmin(rtu_AHRS1->q, rtu_AHRS2->q), fmin
      (rtu_AHRS2->q, rtu_AHRS3->q)), fmin(rtu_AHRS3->q, rtu_AHRS1->q));
    rty_voted_fb[4] = fmax(fmax(fmin(rtu_AHRS1->p, rtu_AHRS2->p), fmin
      (rtu_AHRS2->p, rtu_AHRS3->p)), fmin(rtu_AHRS3->p, rtu_AHRS1->p));

    /* End of Outputs for SubSystem: '<Root>/Mid_Value' */
    break;
  }

  /* End of MultiPortSwitch: '<Root>/MultiportSwitch' */
}

/* Model initialize function */
void AHRS_voter_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
