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
 * Model version                  : 1.300
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Thu Oct 25 19:24:36 2018
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

#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
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

#ifdef __cplusplus

extern "C" {

#endif

  extern void PCF8591_Start_wrapper(real_T *xD);
  extern void PCF8591_Outputs_wrapper(uint8_T *PCF8591_out,
    const real_T *xD);
  extern void PCF8591_Update_wrapper(uint8_T *PCF8591_out,
    real_T *xD);
  extern void PCF8591_Terminate_wrapper(real_T *xD);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void MCU6050_Start_wrapper(real_T *xD);
  extern void MCU6050_Outputs_wrapper(int16_T *ax,
    int16_T *ay,
    int16_T *az,
    int16_T *omx,
    int16_T *omy,
    int16_T *omz,
    int16_T *temp,
    const real_T *xD);
  extern void MCU6050_Update_wrapper(int16_T *ax,
    int16_T *ay,
    int16_T *az,
    int16_T *omx,
    int16_T *omy,
    int16_T *omz,
    int16_T *temp,
    real_T *xD);
  extern void MCU6050_Terminate_wrapper(real_T *xD);

#ifdef __cplusplus

}
#endif

extern int16_T rt_sqrt_Us32En14_Ys16E_tOJnWsQ0(int32_T u);
extern void mul_wide_s32(int32_T in0, int32_T in1, uint32_T *ptrOutBitsHi,
  uint32_T *ptrOutBitsLo);
extern int32_T mul_s32_loSR(int32_T a, int32_T b, uint32_T aShift);
extern int32_T div_repeat_s32_floor(int32_T numerator, int32_T denominator,
  uint32_T nRepeatSub);
extern uint32_T div_nzp_repeat_u32_ceiling(uint32_T numerator, uint32_T
  denominator, uint32_T nRepeatSub);
extern uint32_T div_nzp_repeat_u32(uint32_T numerator, uint32_T denominator,
  uint32_T nRepeatSub);
extern int32_T div_s32_floor(int32_T numerator, int32_T denominator);
extern void mul_wide_su32(int32_T in0, uint32_T in1, uint32_T *ptrOutBitsHi,
  uint32_T *ptrOutBitsLo);
extern int32_T mul_ssu32_loSR(int32_T a, uint32_T b, uint32_T aShift);

#endif                                 /* RTW_HEADER_Steuerung_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
