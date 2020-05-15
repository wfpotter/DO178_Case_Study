/*
 * File: Heli_inner_loop.h
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

#ifndef RTW_HEADER_Heli_inner_loop_h_
#define RTW_HEADER_Heli_inner_loop_h_
#ifndef Heli_inner_loop_COMMON_INCLUDES_
# define Heli_inner_loop_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Heli_inner_loop_COMMON_INCLUDES_ */

/* Block states (default storage) for model 'Heli_inner_loop' */
#ifndef Heli_inner_loop_MDLREF_HIDE_CHILD_

typedef struct {
  real_T UnitDelay_DSTATE;             /* '<S2>/UnitDelay' (DWork 1)  */
  real_T UnitDelay_DSTATE_py2j;        /* '<S3>/UnitDelay' (DWork 1)  */
  real_T UnitDelay_DSTATE_h2jd;        /* '<S4>/UnitDelay' (DWork 1)  */
} DW_Heli_inner_loop_fwu4_T;

#endif                                 /*Heli_inner_loop_MDLREF_HIDE_CHILD_*/

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: [2.395, -0.3609, -0.002145, 0.8087, -0.0205; -0.1427, -1.115, 0.04573, -0.04318, -0.1007; -0.02792, -0.02229, -2.025, -0.06152, 0.03151;]
   * Referenced by: '<Root>/SOF' (Parameter: Gain)
   */
  real_T SOF_Gain[15];
} ConstP_Heli_inner_loop_T;

#ifndef Heli_inner_loop_MDLREF_HIDE_CHILD_

typedef struct {
  DW_Heli_inner_loop_fwu4_T rtdw;
} MdlrefDW_Heli_inner_loop_T;

#endif                                 /*Heli_inner_loop_MDLREF_HIDE_CHILD_*/

#ifndef Heli_inner_loop_MDLREF_HIDE_CHILD_

/* Constant parameters (default storage) */
extern const ConstP_Heli_inner_loop_T Heli_inner_loop_ConstP;

#endif                                 /*Heli_inner_loop_MDLREF_HIDE_CHILD_*/

extern void Heli_inner_loop(const real_T *rtu_theta_cmd, const real_T
  *rtu_phi_cmd, const real_T *rtu_r_cmd, const real_T rtu_voted_fb[5], real_T
  rty_actuator_commands[3]);

/* Model reference registration function */
extern void Heli_inner_loop_initialize(void);

#ifndef Heli_inner_loop_MDLREF_HIDE_CHILD_

extern MdlrefDW_Heli_inner_loop_T Heli_inner_loop_MdlrefDW;

#endif                                 /*Heli_inner_loop_MDLREF_HIDE_CHILD_*/

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
 * '<Root>' : 'Heli_inner_loop'
 * '<S1>'   : 'Heli_inner_loop/ModelInfo'
 * '<S2>'   : 'Heli_inner_loop/RollOff1'
 * '<S3>'   : 'Heli_inner_loop/RollOff2'
 * '<S4>'   : 'Heli_inner_loop/RollOff3'
 */

/*-
 * Requirements for '<Root>': Heli_inner_loop
 */
#endif                                 /* RTW_HEADER_Heli_inner_loop_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
