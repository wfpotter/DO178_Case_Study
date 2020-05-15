/*
 * File: AHRS_voter_ca.h
 *
 * Abstract: Tests assumptions in the generated code.
 */

#ifndef AHRS_VOTER_CA_H
#define AHRS_VOTER_CA_H

/* preprocessor validation checks */
#include "AHRS_voter_ca_preproc.h"
#include "coder_assumptions_hwimpl.h"

/* variables holding test results */
extern CA_HWImpl_TestResults CA_AHRS_voter_HWRes;
extern CA_PWS_TestResults CA_AHRS_voter_PWSRes;

/* variables holding "expected" and "actual" hardware implementation */
extern const CA_HWImpl CA_AHRS_voter_ExpHW;
extern CA_HWImpl CA_AHRS_voter_ActHW;

/* entry point function to run tests */
void AHRS_voter_caRunTests(void);

#endif                                 /* AHRS_VOTER_CA_H */
