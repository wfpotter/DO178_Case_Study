/*
 * File: FCC.c
 *
 * Code generated for Simulink model 'FCC'.
 *
 * Model version                  : 1.71
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Wed May 13 13:32:12 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-32 (Windows32)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FCC.h"

/* Block signals (default storage) */
B_FCC_T FCC_B;

/* Block states (default storage) */
DW_FCC_T FCC_DW;

/* External inputs (root inport signals with default storage) */
ExtU_FCC_T FCC_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_FCC_T FCC_Y;

/* Real-time model */
RT_MODEL_FCC_T FCC_M_;
RT_MODEL_FCC_T *const FCC_M = &FCC_M_;
const AHRS_Bus FCC_rtZAHRS_Bus = { 0.0,/* theta */
  0.0,                                 /* phi */
  0.0,                                 /* psi */
  0.0,                                 /* q */
  0.0,                                 /* p */
  0.0,                                 /* r */
  false                                /* valid */
};

/* Model step function for TID0 */
void FCC_step0(void)                   /* Sample time: [0.001s, 0.0s] */
{
  /* Update the flag to indicate when data transfers from
   *  Sample time: [0.001s, 0.0s] to Sample time: [0.01s, 0.0s]  */
  FCC_M->Timing.RateInteraction.b_TID0_1 = (FCC_M->Timing.RateInteraction.TID0_1
    == 0);
  (FCC_M->Timing.RateInteraction.TID0_1)++;
  if ((FCC_M->Timing.RateInteraction.TID0_1) > 9) {
    FCC_M->Timing.RateInteraction.TID0_1 = 0;
  }

  /* RateTransition: '<Root>/RateTransition1' */
  if (FCC_M->Timing.RateInteraction.TID0_1 == 1) {
    FCC_B.RateTransition1 = FCC_DW.RateTransition1_Buffer0;
  }

  /* End of RateTransition: '<Root>/RateTransition1' */

  /* ModelReference: '<Root>/ActuatorControl1' incorporates:
   *  Inport: '<Root>/Act_Pos1'
   *  Outport: '<Root>/Actuator1'
   *
   * Block requirements for '<Root>/ActuatorControl1':
   *  1. HLR_4: Hydraulic Actuator Loop Control (HelicopterSoftwareRequirements#8)
   *
   * Block requirements for '<Root>/Act_Pos1':
   *  1. HLR_2 : Hydraulic Actuator Feedback (HelicopterSoftwareRequirements#6)
   *
   * Block requirements for '<Root>/Actuator1':
   *  1. HLR_3: Hydraulic Actuator Drive (HelicopterSoftwareRequirements#7)
   */
  ActuatorLoop(&FCC_U.Act_Pos1, &FCC_B.RateTransition1, &FCC_Y.Actuator1,
               &(FCC_DW.ActuatorControl1_InstanceData.rtb),
               &(FCC_DW.ActuatorControl1_InstanceData.rtdw), 0.339, 0.00272,
               2.73);

  /* RateTransition: '<Root>/RateTransition2' */
  if (FCC_M->Timing.RateInteraction.TID0_1 == 1) {
    FCC_B.RateTransition2 = FCC_DW.RateTransition2_Buffer0;
  }

  /* End of RateTransition: '<Root>/RateTransition2' */

  /* ModelReference: '<Root>/ActuatorControl2' incorporates:
   *  Inport: '<Root>/Act_Pos2'
   *  Outport: '<Root>/Actuator2'
   *
   * Block requirements for '<Root>/ActuatorControl2':
   *  1. HLR_4: Hydraulic Actuator Loop Control (HelicopterSoftwareRequirements#8)
   *
   * Block requirements for '<Root>/Act_Pos2':
   *  1. HLR_2 : Hydraulic Actuator Feedback (HelicopterSoftwareRequirements#6)
   *
   * Block requirements for '<Root>/Actuator2':
   *  1. HLR_3: Hydraulic Actuator Drive (HelicopterSoftwareRequirements#7)
   */
  ActuatorLoop(&FCC_U.Act_Pos2, &FCC_B.RateTransition2, &FCC_Y.Actuator2,
               &(FCC_DW.ActuatorControl2_InstanceData.rtb),
               &(FCC_DW.ActuatorControl2_InstanceData.rtdw), 0.339, 0.00272,
               2.73);

  /* RateTransition: '<Root>/RateTransition3' */
  if (FCC_M->Timing.RateInteraction.TID0_1 == 1) {
    FCC_B.RateTransition3 = FCC_DW.RateTransition3_Buffer0;
  }

  /* End of RateTransition: '<Root>/RateTransition3' */

  /* ModelReference: '<Root>/ActuatorControl3' incorporates:
   *  Inport: '<Root>/Act_Pos3'
   *  Outport: '<Root>/Actuator3'
   *
   * Block requirements for '<Root>/ActuatorControl3':
   *  1. HLR_4: Hydraulic Actuator Loop Control (HelicopterSoftwareRequirements#8)
   *
   * Block requirements for '<Root>/Act_Pos3':
   *  1. HLR_2 : Hydraulic Actuator Feedback (HelicopterSoftwareRequirements#6)
   *
   * Block requirements for '<Root>/Actuator3':
   *  1. HLR_3: Hydraulic Actuator Drive (HelicopterSoftwareRequirements#7)
   */
  ActuatorLoop(&FCC_U.Act_Pos3, &FCC_B.RateTransition3, &FCC_Y.Actuator3,
               &(FCC_DW.ActuatorControl3_InstanceData.rtb),
               &(FCC_DW.ActuatorControl3_InstanceData.rtdw), 0.339, 0.00272,
               2.73);
}

/* Model step function for TID1 */
void FCC_step1(void)                   /* Sample time: [0.01s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_Model2[5];
  real_T rtb_Model1_o1;
  real_T rtb_Model1_o2;
  real_T rtb_Model1_o3;
  real_T rtb_Model[3];

  /* ModelReference: '<Root>/Model2' incorporates:
   *  Inport: '<Root>/AHRS1'
   *  Inport: '<Root>/AHRS2'
   *  Inport: '<Root>/AHRS3'
   *
   * Block requirements for '<Root>/Model2':
   *  1. HLR_9 : AHRS Validity Check (HelicopterSoftwareRequirements#13)
   *  2. HLR_11: AHRS Voting for Triple Sensors (HelicopterSoftwareRequirements#15)
   *  3. HLR_12: AHRS Voting for Dual Sensors (HelicopterSoftwareRequirements#16)
   *  4. HLR_13: AHRS Usage of Single Sensor (HelicopterSoftwareRequirements#17)
   *
   * Block requirements for '<Root>/AHRS1':
   *  1. HLR_10: AHRS Input Signal Processing (HelicopterSoftwareRequirements#14)
   *
   * Block requirements for '<Root>/AHRS2':
   *  1. HLR_10: AHRS Input Signal Processing (HelicopterSoftwareRequirements#14)
   *
   * Block requirements for '<Root>/AHRS3':
   *  1. HLR_10: AHRS Input Signal Processing (HelicopterSoftwareRequirements#14)
   */
  AHRS_voter(&FCC_U.AHRS1, &FCC_U.AHRS2, &FCC_U.AHRS3, &rtb_Model2[0]);

  /* ModelReference: '<Root>/Model1' incorporates:
   *  Inport: '<Root>/Pilot_phi_cmd'
   *  Inport: '<Root>/Pilot_r_cmd'
   *  Inport: '<Root>/Pilot_theta_cmd'
   *
   * Block requirements for '<Root>/Model1':
   *  1. HLR_6: Pitch Outer Loop Control (HelicopterSoftwareRequirements#10)
   *  2. HLR_7: Roll Outer Loop Control (HelicopterSoftwareRequirements#11)
   *  3. HLR_8: Yaw Outer Loop Control (HelicopterSoftwareRequirements#12)
   *
   * Block requirements for '<Root>/Pilot_phi_cmd':
   *  1. HLR_1: Pilot Input Signal Processing (HelicopterSoftwareRequirements#5)
   *
   * Block requirements for '<Root>/Pilot_r_cmd':
   *  1. HLR_1: Pilot Input Signal Processing (HelicopterSoftwareRequirements#5)
   *
   * Block requirements for '<Root>/Pilot_theta_cmd':
   *  1. HLR_1: Pilot Input Signal Processing (HelicopterSoftwareRequirements#5)
   */
  Heli_outer_loop(&FCC_U.Pilot_theta_cmd, &FCC_U.Pilot_phi_cmd,
                  &FCC_U.Pilot_r_cmd, &rtb_Model2[0], &rtb_Model1_o1,
                  &rtb_Model1_o2, &rtb_Model1_o3);

  /* ModelReference: '<Root>/Model'
   *
   * Block requirements for '<Root>/Model':
   *  1. HLR_5: Multi-Variable Inner Loop Control (HelicopterSoftwareRequirements#9)
   */
  Heli_inner_loop(&rtb_Model1_o1, &rtb_Model1_o2, &rtb_Model1_o3, &rtb_Model2[0],
                  &rtb_Model[0]);

  /* RateTransition: '<Root>/RateTransition1' */
  FCC_DW.RateTransition1_Buffer0 = rtb_Model[0];

  /* RateTransition: '<Root>/RateTransition2' */
  FCC_DW.RateTransition2_Buffer0 = rtb_Model[1];

  /* RateTransition: '<Root>/RateTransition3' */
  FCC_DW.RateTransition3_Buffer0 = rtb_Model[2];
}

/* Model initialize function */
void FCC_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)FCC_M, 0,
                sizeof(RT_MODEL_FCC_T));

  /* block I/O */
  {
    FCC_B.RateTransition1 = 0.0;
    FCC_B.RateTransition2 = 0.0;
    FCC_B.RateTransition3 = 0.0;
  }

  /* states (dwork) */
  (void) memset((void *)&FCC_DW, 0,
                sizeof(DW_FCC_T));
  FCC_DW.RateTransition1_Buffer0 = 0.0;
  FCC_DW.RateTransition2_Buffer0 = 0.0;
  FCC_DW.RateTransition3_Buffer0 = 0.0;

  /* external inputs */
  (void)memset((void *)(&FCC_U), 0, sizeof(ExtU_FCC_T));
  FCC_U.AHRS1 = FCC_rtZAHRS_Bus;
  FCC_U.AHRS2 = FCC_rtZAHRS_Bus;
  FCC_U.AHRS3 = FCC_rtZAHRS_Bus;

  /* external outputs */
  (void) memset((void *)&FCC_Y, 0,
                sizeof(ExtY_FCC_T));

  /* Model Initialize function for ModelReference Block: '<Root>/ActuatorControl1' */
  ActuatorLoop_initialize(&(FCC_DW.ActuatorControl1_InstanceData.rtb),
    &(FCC_DW.ActuatorControl1_InstanceData.rtdw));

  /* Model Initialize function for ModelReference Block: '<Root>/ActuatorControl2' */
  ActuatorLoop_initialize(&(FCC_DW.ActuatorControl2_InstanceData.rtb),
    &(FCC_DW.ActuatorControl2_InstanceData.rtdw));

  /* Model Initialize function for ModelReference Block: '<Root>/ActuatorControl3' */
  ActuatorLoop_initialize(&(FCC_DW.ActuatorControl3_InstanceData.rtb),
    &(FCC_DW.ActuatorControl3_InstanceData.rtdw));

  /* Model Initialize function for ModelReference Block: '<Root>/Model' */
  Heli_inner_loop_initialize();

  /* Model Initialize function for ModelReference Block: '<Root>/Model1' */
  Heli_outer_loop_initialize();

  /* Model Initialize function for ModelReference Block: '<Root>/Model2' */
  AHRS_voter_initialize();
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
