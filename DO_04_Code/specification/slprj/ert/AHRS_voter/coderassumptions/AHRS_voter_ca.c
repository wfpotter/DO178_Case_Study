/*
 * File: AHRS_voter_ca.c
 *
 * Abstract: Tests assumptions in the generated code.
 */

#include "AHRS_voter_ca.h"

CA_HWImpl_TestResults CA_AHRS_voter_HWRes;
CA_PWS_TestResults CA_AHRS_voter_PWSRes;
const CA_HWImpl CA_AHRS_voter_ExpHW = {

#ifdef PORTABLE_WORDSIZES

  8,                                   /* BitPerChar */
  16,                                  /* BitPerShort */
  32,                                  /* BitPerInt */
  32,                                  /* BitPerLong */
  64,                                  /* BitPerLongLong */
  32,                                  /* BitPerFloat */
  64,                                  /* BitPerDouble */
  64,                                  /* BitPerPointer */
  64,                                  /* BitPerSizeT */
  64,                                  /* BitPerPtrDiffT */
  CA_LITTLE_ENDIAN,                    /* Endianess */
  CA_ZERO,                             /* IntDivRoundTo */
  1,                                   /* ShiftRightIntArith */

#else

  8,                                   /* BitPerChar */
  16,                                  /* BitPerShort */
  32,                                  /* BitPerInt */
  32,                                  /* BitPerLong */
  64,                                  /* BitPerLongLong */
  32,                                  /* BitPerFloat */
  64,                                  /* BitPerDouble */
  32,                                  /* BitPerPointer */
  32,                                  /* BitPerSizeT */
  32,                                  /* BitPerPtrDiffT */
  CA_LITTLE_ENDIAN,                    /* Endianess */
  CA_ZERO,                             /* IntDivRoundTo */
  1,                                   /* ShiftRightIntArith */

#endif

  0,                                   /* LongLongMode */
  1,                                   /* PortableWordSizes */
  "Intel->x86-32 (Windows32)",         /* HWDeviceType */
  0,                                   /* MemoryAtStartup */
  0,                                   /* DenormalFlushToZero */
  0                                    /* DenormalAsZero */
};

CA_HWImpl CA_AHRS_voter_ActHW;
void AHRS_voter_caRunTests(void)
{
  /* verify hardware implementation */
  caVerifyPortableWordSizes(&CA_AHRS_voter_ActHW, &CA_AHRS_voter_ExpHW,
    &CA_AHRS_voter_PWSRes);
  caVerifyHWImpl(&CA_AHRS_voter_ActHW, &CA_AHRS_voter_ExpHW,
                 &CA_AHRS_voter_HWRes);
}
