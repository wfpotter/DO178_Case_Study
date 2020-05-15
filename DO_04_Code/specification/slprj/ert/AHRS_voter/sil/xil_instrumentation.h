/*
 * File: xil_instrumentation.h
 *
 * Code generated for instrumentation.
 *
 */

#include "rtwtypes.h"

/* Upload code instrumentation data point */
void xilUploadCodeInstrData(
  void* pData, uint32_T numMemUnits, uint32_T sectionId);

/* Indicate that instrumentation point was hit */
void __MW_INSTRUM_RECORD_HIT(uint32_T sectionId);
void xilUploadCoverageSynthesis(void);

/* Code instrumentation method(s) for model AHRS_voter (ModelRefSIL) */
void _MW_INSTRUM_R_3aff621cc5d290c6(uint32_T sectionId);

/* Callback called when the simulation is paused */
void PauseEvent (void);

/* Callback called when the simulation ends */
void TerminateEvent (void);

/* Callback called when a step ends */
void StepCompletedEvent (void);
