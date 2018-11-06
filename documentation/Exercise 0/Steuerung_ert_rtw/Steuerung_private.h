/*
 * Academic Student License -- for use by students to meet course
 * requirements and perform academic research at degree granting
 * institutions only.  Not for government, commercial, or other
 * organizational use.
 *
 * File: Steuerung_private.h
 *
 * Code generated for Simulink model 'Steuerung'.
 *
 * Model version                  : 1.301
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Tue Nov  6 15:07:26 2018
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Steuerung_private_h_
#define RTW_HEADER_Steuerung_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void RPI_Init_Start_wrapper(void);
  extern void RPI_Init_Outputs_wrapper(void);
  extern void RPI_Init_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void PCA6585_Start_wrapper(real_T *xD);
  extern void PCA6585_Outputs_wrapper(const boolean_T *IN_1,
    const boolean_T *IN_2,
    const uint16_T *PWM,
    const uint16_T *SERVO,
    const real_T *xD);
  extern void PCA6585_Update_wrapper(const boolean_T *IN_1,
    const boolean_T *IN_2,
    const uint16_T *PWM,
    const uint16_T *SERVO,
    real_T *xD);
  extern void PCA6585_Terminate_wrapper(real_T *xD);

#ifdef __cplusplus

}
#endif

extern real_T rt_roundd_snf(real_T u);

#endif                                 /* RTW_HEADER_Steuerung_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
