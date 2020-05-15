/*
 * File: coder_assumptions.h
 *
 * Abstract: Coder assumptions header file
 */

#ifndef CODER_ASSUMPTIONS_H
#define CODER_ASSUMPTIONS_H

/* include model specific checks */
#include "AHRS_voter_ca.h"

/* global results variable mapping for static code */
#define CA_Expected_HWImpl             CA_AHRS_voter_ExpHW
#define CA_Actual_HWImpl               CA_AHRS_voter_ActHW
#define CA_HWImpl_Results              CA_AHRS_voter_HWRes
#define CA_PortableWordSizes_Results   CA_AHRS_voter_PWSRes

/* entry point function mapping for static code */
#define CA_Run_Tests                   AHRS_voter_caRunTests
#endif                                 /* CODER_ASSUMPTIONS_H */
