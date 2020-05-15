/*
 * File: AHRS_voter.h
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

#ifndef RTW_HEADER_AHRS_voter_h_
#define RTW_HEADER_AHRS_voter_h_
#include "rtwtypes.h"
#include <math.h>
#ifndef AHRS_voter_COMMON_INCLUDES_
# define AHRS_voter_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* AHRS_voter_COMMON_INCLUDES_ */

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

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: [0 0 0 0 0])
   * Referenced by:
   *   '<Root>/Constant' (Parameter: Value)
   *   '<S1>/Constant' (Parameter: Value)
   *   '<S4>/Constant' (Parameter: Value)
   */
  real_T pooled1[5];
} ConstP_AHRS_voter_T;

#ifndef AHRS_voter_MDLREF_HIDE_CHILD_

/* Constant parameters (default storage) */
extern const ConstP_AHRS_voter_T AHRS_voter_ConstP;

#endif                                 /*AHRS_voter_MDLREF_HIDE_CHILD_*/

extern void AHRS_voter(const AHRS_Bus *rtu_AHRS1, const AHRS_Bus *rtu_AHRS2,
  const AHRS_Bus *rtu_AHRS3, real_T rty_voted_fb[5]);

/* Model reference registration function */
extern void AHRS_voter_initialize(void);

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
 * '<Root>' : 'AHRS_voter'
 * '<S1>'   : 'AHRS_voter/Avg_Value'
 * '<S2>'   : 'AHRS_voter/Mid_Value'
 * '<S3>'   : 'AHRS_voter/ModelInfo'
 * '<S4>'   : 'AHRS_voter/Single_Value'
 */

/*-
 * Requirements for '<Root>': AHRS_voter
 */
#endif                                 /* RTW_HEADER_AHRS_voter_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
