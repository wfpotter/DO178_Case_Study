/*
 * File: Heli_outer_loop.h
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

#ifndef RTW_HEADER_Heli_outer_loop_h_
#define RTW_HEADER_Heli_outer_loop_h_
#ifndef Heli_outer_loop_COMMON_INCLUDES_
# define Heli_outer_loop_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Heli_outer_loop_COMMON_INCLUDES_ */

/* Block signals for model 'Heli_outer_loop' */
#ifndef Heli_outer_loop_MDLREF_HIDE_CHILD_

typedef struct {
  real_T Integrator;                   /* '<Root>/Integrator' (Output 1)  */
  real_T Integrator1;                  /* '<Root>/Integrator1' (Output 1)  */
  real_T Integrator2;                  /* '<Root>/Integrator2' (Output 1)  */
} B_Heli_outer_loop_caua_T;

#endif                                 /*Heli_outer_loop_MDLREF_HIDE_CHILD_*/

/* Block states (default storage) for model 'Heli_outer_loop' */
#ifndef Heli_outer_loop_MDLREF_HIDE_CHILD_

typedef struct {
  real_T Integrator_DSTATE;            /* '<Root>/Integrator' (DWork 1)  */
  real_T Integrator1_DSTATE;           /* '<Root>/Integrator1' (DWork 1)  */
  real_T Integrator2_DSTATE;           /* '<Root>/Integrator2' (DWork 1)  */
} DW_Heli_outer_loop_fwu4_T;

#endif                                 /*Heli_outer_loop_MDLREF_HIDE_CHILD_*/

#ifndef Heli_outer_loop_MDLREF_HIDE_CHILD_

typedef struct {
  B_Heli_outer_loop_caua_T rtb;
  DW_Heli_outer_loop_fwu4_T rtdw;
} MdlrefDW_Heli_outer_loop_T;

#endif                                 /*Heli_outer_loop_MDLREF_HIDE_CHILD_*/

extern void Heli_outer_loop_Disable(void);
extern void Heli_outer_loop(const int16_T *rtu_Pilot_theta_cmd, const int16_T
  *rtu_Pilot_phi_cmd, const int16_T *rtu_Pilot_r_cmd, const real_T rtu_voted_fb
  [5], real_T *rty_theta_cmd, real_T *rty_phi_cmd, real_T *rty_r_cmd);

/* Model reference registration function */
extern void Heli_outer_loop_initialize(void);

#ifndef Heli_outer_loop_MDLREF_HIDE_CHILD_

extern MdlrefDW_Heli_outer_loop_T Heli_outer_loop_MdlrefDW;

#endif                                 /*Heli_outer_loop_MDLREF_HIDE_CHILD_*/

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
 * '<Root>' : 'Heli_outer_loop'
 * '<S1>'   : 'Heli_outer_loop/ModelInfo'
 */

/*-
 * Requirements for '<Root>': Heli_outer_loop
 */
#endif                                 /* RTW_HEADER_Heli_outer_loop_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
