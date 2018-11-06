/*
 * Academic Student License -- for use by students to meet course
 * requirements and perform academic research at degree granting
 * institutions only.  Not for government, commercial, or other
 * organizational use.
 *
 * File: Steuerung.h
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

#ifndef RTW_HEADER_Steuerung_h_
#define RTW_HEADER_Steuerung_h_
#include <math.h>
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef Steuerung_COMMON_INCLUDES_
# define Steuerung_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "dt_info.h"
#include "ext_work.h"
#endif                                 /* Steuerung_COMMON_INCLUDES_ */

#include "Steuerung_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T steeringangle;                /* '<Root>/Manual // Automatic Steering' */
  uint16_T DataTypeConversion1;        /* '<S1>/Data Type Conversion1' */
  uint16_T DataTypeConversion3;        /* '<S1>/Data Type Conversion3' */
  boolean_T LogicalOperator2;          /* '<S1>/Logical Operator2' */
  boolean_T LogicalOperator1;          /* '<S1>/Logical Operator1' */
} B_Steuerung_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T PCA6585_DSTATE[2];            /* '<Root>/PCA6585' */
  struct {
    void *LoggedData;
  } Scope3_PWORK;                      /* '<Root>/Scope3' */
} DW_Steuerung_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T ConstantRamp;           /* '<Root>/Constant Ramp' */
} ConstB_Steuerung_T;

/* Parameters (default storage) */
struct P_Steuerung_T_ {
  real_T SliderGain_gain;              /* Mask Parameter: SliderGain_gain
                                        * Referenced by: '<S5>/Slider Gain'
                                        */
  real_T SliderGain1_gain;             /* Mask Parameter: SliderGain1_gain
                                        * Referenced by: '<S6>/Slider Gain'
                                        */
  real_T Constant7_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant7'
                                        */
  real_T Constant6_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant6'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Normalization1_Gain;          /* Expression: 1/300
                                        * Referenced by: '<Root>/Normalization1'
                                        */
  real_T Constant1_Value;              /* Expression: 600
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T Constant8_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant8'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 3000
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -0.5
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Quantizer_Interval;           /* Expression: 1
                                        * Referenced by: '<Root>/Quantizer'
                                        */
  real_T Normalization_Gain;           /* Expression: 1/3395
                                        * Referenced by: '<Root>/Normalization'
                                        */
  real_T Gain_Gain;                    /* Expression: 3395
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T Constant5_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant5'
                                        */
  real_T Gain1_Gain;                   /* Expression: 300
                                        * Referenced by: '<S1>/Gain1'
                                        */
  real_T Constant3_Value;              /* Expression: 1180
                                        * Referenced by: '<S1>/Constant3'
                                        */
  uint8_T ManualSwitch1_CurrentSetting;/* Computed Parameter: ManualSwitch1_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch1'
                                        */
  uint8_T ManualSwitch_CurrentSetting; /* Computed Parameter: ManualSwitch_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch'
                                        */
  uint8_T ManualAutomaticSteering_Current;/* Computed Parameter: ManualAutomaticSteering_Current
                                           * Referenced by: '<Root>/Manual // Automatic Steering'
                                           */
};

/* Real-time Model Data Structure */
struct tag_RTM_Steuerung_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_Steuerung_T Steuerung_P;

/* Block signals (default storage) */
extern B_Steuerung_T Steuerung_B;

/* Block states (default storage) */
extern DW_Steuerung_T Steuerung_DW;
extern const ConstB_Steuerung_T Steuerung_ConstB;/* constant block i/o */

/* Model entry point functions */
extern void Steuerung_initialize(void);
extern void Steuerung_step(void);
extern void Steuerung_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Steuerung_T *const Steuerung_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S1>/Data Type Conversion2' : Eliminate redundant data type conversion
 */

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
 * '<Root>' : 'Steuerung'
 * '<S1>'   : 'Steuerung/Data Conversion'
 * '<S2>'   : 'Steuerung/Lane following'
 * '<S3>'   : 'Steuerung/Lane-finding'
 * '<S4>'   : 'Steuerung/Ramp'
 * '<S5>'   : 'Steuerung/Slider Gain'
 * '<S6>'   : 'Steuerung/Slider Gain1'
 * '<S7>'   : 'Steuerung/Video Input'
 * '<S8>'   : 'Steuerung/Lane following/Discrete PID Controller'
 * '<S9>'   : 'Steuerung/Lane following/Discrete PID Controller/Differentiator'
 * '<S10>'  : 'Steuerung/Lane-finding/Calculate angle'
 * '<S11>'  : 'Steuerung/Lane-finding/Calculate center line'
 */
#endif                                 /* RTW_HEADER_Steuerung_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
