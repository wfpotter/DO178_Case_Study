/*
 * File: ActuatorLoop.h
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

#ifndef RTW_HEADER_ActuatorLoop_h_
#define RTW_HEADER_ActuatorLoop_h_
#include <math.h>
#ifndef ActuatorLoop_COMMON_INCLUDES_
# define ActuatorLoop_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ActuatorLoop_COMMON_INCLUDES_ */

/* Block signals for model 'ActuatorLoop' */
typedef struct {
  real_T Integrator;                   /* '<Root>/Integrator' (Output 1)  */
} B_ActuatorLoop_caua_T;

/* Block states (default storage) for model 'ActuatorLoop' */
typedef struct {
  real_T UD_DSTATE;                    /* '<S1>/UD' (DWork 1)  */
  real_T Integrator_DSTATE;            /* '<Root>/Integrator' (DWork 1)  */
} DW_ActuatorLoop_fwu4_T;

typedef struct {
  B_ActuatorLoop_caua_T rtb;
  DW_ActuatorLoop_fwu4_T rtdw;
} MdlrefDW_ActuatorLoop_T;

/* Model reference registration function */
extern void ActuatorLoop_initialize(B_ActuatorLoop_caua_T *localB,
  DW_ActuatorLoop_fwu4_T *localDW);
extern void ActuatorLoop_Disable(B_ActuatorLoop_caua_T *localB,
  DW_ActuatorLoop_fwu4_T *localDW);
extern void ActuatorLoop(const int16_T *rtu_PositionFeedback, const real_T
  *rtu_PositionCommand, int16_T *rty_ActuatorCommand, B_ActuatorLoop_caua_T
  *localB, DW_ActuatorLoop_fwu4_T *localDW, real_T rtp_Kp, real_T rtp_Kd, real_T
  rtp_Ki);

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
 * '<Root>' : 'ActuatorLoop'
 * '<S1>'   : 'ActuatorLoop/Difference'
 * '<S2>'   : 'ActuatorLoop/Model Info'
 */

/*-
 * Requirements for '<Root>': ActuatorLoop
 */
#endif                                 /* RTW_HEADER_ActuatorLoop_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
