/*
 * File: FCC.h
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

#ifndef RTW_HEADER_FCC_h_
#define RTW_HEADER_FCC_h_
#include "rtwtypes.h"
#include <string.h>
#ifndef FCC_COMMON_INCLUDES_
# define FCC_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* FCC_COMMON_INCLUDES_ */

/* Child system includes */
#include "ActuatorLoop.h"
#define AHRS_voter_MDLREF_HIDE_CHILD_
#include "AHRS_voter.h"
#define Heli_outer_loop_MDLREF_HIDE_CHILD_
#include "Heli_outer_loop.h"
#define Heli_inner_loop_MDLREF_HIDE_CHILD_
#include "Heli_inner_loop.h"

/* Macros for accessing real-time model data structure */

/* Forward declaration for rtModel */
typedef struct tag_RTM_FCC_T RT_MODEL_FCC_T;

#ifndef DEFINED_TYPEDEF_FOR_AHRS_Bus_
#define DEFINED_TYPEDEF_FOR_AHRS_Bus_

typedef struct {
  real_T theta;
  real_T phi;
  real_T psi;
  real_T q;
  real_T p;
  real_T r;
  boolean_T valid;
} AHRS_Bus;

#endif

/* Block signals (default storage) */
typedef struct {
  real_T RateTransition1;             /* '<Root>/RateTransition1' (Output 1)  */
  real_T RateTransition2;             /* '<Root>/RateTransition2' (Output 1)  */
  real_T RateTransition3;             /* '<Root>/RateTransition3' (Output 1)  */
} B_FCC_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T RateTransition1_Buffer0;      /* '<Root>/RateTransition1' (DWork 1)  */
  real_T RateTransition2_Buffer0;      /* '<Root>/RateTransition2' (DWork 1)  */
  real_T RateTransition3_Buffer0;      /* '<Root>/RateTransition3' (DWork 1)  */
  MdlrefDW_ActuatorLoop_T ActuatorControl1_InstanceData;
                                      /* '<Root>/ActuatorControl1' (DWork 1)  */
  MdlrefDW_ActuatorLoop_T ActuatorControl2_InstanceData;
                                      /* '<Root>/ActuatorControl2' (DWork 1)  */
  MdlrefDW_ActuatorLoop_T ActuatorControl3_InstanceData;
                                      /* '<Root>/ActuatorControl3' (DWork 1)  */
} DW_FCC_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  int16_T Act_Pos1;                    /* '<Root>/Act_Pos1' */
  int16_T Act_Pos2;                    /* '<Root>/Act_Pos2' */
  int16_T Act_Pos3;                    /* '<Root>/Act_Pos3' */
  int16_T Pilot_theta_cmd;             /* '<Root>/Pilot_theta_cmd' */
  int16_T Pilot_phi_cmd;               /* '<Root>/Pilot_phi_cmd' */
  int16_T Pilot_r_cmd;                 /* '<Root>/Pilot_r_cmd' */
  AHRS_Bus AHRS1;                      /* '<Root>/AHRS1' */
  AHRS_Bus AHRS2;                      /* '<Root>/AHRS2' */
  AHRS_Bus AHRS3;                      /* '<Root>/AHRS3' */
} ExtU_FCC_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  int16_T Actuator1;                   /* '<Root>/Actuator1' */
  int16_T Actuator2;                   /* '<Root>/Actuator2' */
  int16_T Actuator3;                   /* '<Root>/Actuator3' */
} ExtY_FCC_T;

/* Real-time Model Data Structure */
struct tag_RTM_FCC_T {
  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint32_T TID0_1;
      boolean_T b_TID0_1;
    } RateInteraction;
  } Timing;
};

/* Block signals (default storage) */
extern B_FCC_T FCC_B;

/* Block states (default storage) */
extern DW_FCC_T FCC_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_FCC_T FCC_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_FCC_T FCC_Y;

/* External data declarations for dependent source files */
extern const AHRS_Bus FCC_rtZAHRS_Bus; /* AHRS_Bus ground */

/* Model entry point functions */
extern void FCC_initialize(void);
extern void FCC_step0(void);
extern void FCC_step1(void);

/* Real-time Model object */
extern RT_MODEL_FCC_T *const FCC_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'FCC'
 * '<S1>'   : 'FCC/ModelInfo'
 */

/*-
 * Requirements for '<Root>': FCC
 */
#endif                                 /* RTW_HEADER_FCC_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
