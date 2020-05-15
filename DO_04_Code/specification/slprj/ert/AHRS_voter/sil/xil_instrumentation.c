/*
 * File: xil_instrumentation.c
 *
 * Code generated for instrumentation.
 *
 * This file contains stub implementations of the instrumentation utility
 * functions. These stubs allow instrumented code to be compiled
 * into an executable that does not support collection of execution
 * instrumentation data.
 *
 */

#include "xil_instrumentation.h"

/* Code instrumentation offset(s) for model AHRS_voter (ModelRefSIL) */
#define _MW_INSTRUM_R_3aff621cc5d290c6_offset 0
#include <string.h>

void __MW_INSTRUM_RECORD_HIT(uint32_T sectionId)
{
  /* Send information that instrumentation point was hit to host */
  xilUploadCodeInstrData((void *)0, (uint32_T)(0), sectionId);
}

#ifdef __cplusplus

extern "C" {

#endif

  const unsigned int __mw_instrum_AHRS_voter_ModelRefSIL_hits_size = 69;

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  const unsigned int __mw_instrum_AHRS_voter_ModelRefSIL_truth_tables_size = 0;

#ifdef __cplusplus

}
#endif

unsigned int __mw_instrum_AHRS_voter_ModelRefSIL_hits[69];

#ifdef __cplusplus

extern "C" {

#endif

  unsigned int* __mw_instrum_AHRS_voter_ModelRefSIL_phits =
    &__mw_instrum_AHRS_voter_ModelRefSIL_hits[0];

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  unsigned int* __mw_instrum_AHRS_voter_ModelRefSIL_truth_tables =
    &__mw_instrum_AHRS_voter_ModelRefSIL_hits[69];

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  double __mw_instrum_AHRS_voter_ModelRefSIL_abs_tol = 1.000000e-05;

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  double __mw_instrum_AHRS_voter_ModelRefSIL_rel_tol = 1.000000e-02;

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C"
#endif

unsigned int *__MW_INSTRUM_AHRS_voter_ModelRefSIL_INIT_FILE(unsigned int
  decCovId)
{
  (void) decCovId;
  return &__mw_instrum_AHRS_voter_ModelRefSIL_truth_tables[0];
}

void xilUploadCoverageSynthesis(void)
{
  uint32_T sz;
  sz = (uint32_T)((__mw_instrum_AHRS_voter_ModelRefSIL_hits_size +
                   __mw_instrum_AHRS_voter_ModelRefSIL_truth_tables_size) *
                  sizeof(uint32_T));
  xilUploadCodeInstrData((void *)__mw_instrum_AHRS_voter_ModelRefSIL_hits, sz, 1);
  memset((void *) __mw_instrum_AHRS_voter_ModelRefSIL_hits, 0, sz);
}

/* Code instrumentation method(s) for model AHRS_voter (ModelRefSIL) */
void _MW_INSTRUM_R_3aff621cc5d290c6(uint32_T sectionId)
{
  __MW_INSTRUM_RECORD_HIT(_MW_INSTRUM_R_3aff621cc5d290c6_offset + sectionId);
}

void PauseEvent (void)
{
  /* callbacks executed when the sim is paused */
  xilUploadCoverageSynthesis();
}

void TerminateEvent (void)
{
  /* callbacks executed when the sim ends */
  xilUploadCoverageSynthesis();
}

void StepCompletedEvent (void)
{
  /* callbacks executed when a step ends */
  xilUploadCoverageSynthesis();
}
