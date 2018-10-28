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
 * Model version                  : 1.300
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Thu Oct 25 19:24:36 2018
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Steuerung_h_
#define RTW_HEADER_Steuerung_h_
#include <math.h>
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef Steuerung_COMMON_INCLUDES_
# define Steuerung_COMMON_INCLUDES_
#include <math.h>
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "dt_info.h"
#include "ext_work.h"
#include "v4l2_capture.h"
#include "viphough_rt.h"
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
  real_T HoughTransform_o1[36180];     /* '<S3>/Hough Transform' */
  real_T HoughTransform_o2[180];       /* '<S3>/Hough Transform' */
  real_T HoughTransform_o3[201];       /* '<S3>/Hough Transform' */
  int32_T HoughLines[8];               /* '<S3>/Hough Lines' */
  uint8_T V4L2VideoCapture_o1[76800];  /* '<S6>/V4L2 Video Capture' */
  uint8_T PermuteDimensions3[76800];   /* '<S6>/Permute Dimensions3' */
  uint8_T V4L2VideoCapture_o2[38400];  /* '<S6>/V4L2 Video Capture' */
  uint8_T V4L2VideoCapture_o3[38400];  /* '<S6>/V4L2 Video Capture' */
  uint8_T Image_Lines_1[14640];        /* '<S3>/Draw Shapes' */
  uint8_T MatrixConcatenate[14640];    /* '<S3>/Matrix Concatenate' */
  uint8_T Selecteverysecondpixel2[4880];/* '<S6>/Select every second pixel2' */
  int32_T points[8];
  real_T Selector[2];                  /* '<S3>/Selector' */
  real_T Selector3[2];                 /* '<S3>/Selector3' */
  uint32_T FindLocalMaxima[4];         /* '<S3>/Find Local Maxima' */
  int32_T tmp_data[4];
  real_T steeringangle;                /* '<Root>/Manual // Automatic Steering' */
  real_T y2;
  real_T Gain2;                        /* '<Root>/Gain2' */
  real_T Add1;                         /* '<S1>/Add1' */
  real_T x_center_idx_2;
  int32_T idxTmpArray[2];
  uint32_T Selector1[2];               /* '<S3>/Selector1' */
  uint32_T rtb_FindLocalMaxima_data[2];
  int32_T col;
  int32_T firstRow;
  int32_T lastRow;
  int32_T activeCol;
  int32_T idxEdgeCur;
  int32_T idxEdgePre;
  int32_T mNumPtPerPolygon_new;
  int32_T idxOld;
  int32_T idxNew;
  int32_T numActiveEdge;
  int32_T edgeTmp;
  int32_T jRowsIn;
  int32_T q2;
  int32_T m;
  int32_T accumFour;
  int32_T accumThree;
  int32_T imgRow;
  int32_T ntIdx1;
  int32_T uElOffset1;
  uint32_T toIdx;
  uint32_T fromIdx;
  uint16_T DataTypeConversion1;        /* '<S1>/Data Type Conversion1' */
  uint16_T DataTypeConversion3;        /* '<S1>/Data Type Conversion3' */
  int16_T MCU6050_o1;                  /* '<Root>/MCU6050' */
  int16_T MCU6050_o2;                  /* '<Root>/MCU6050' */
  int16_T MCU6050_o3;                  /* '<Root>/MCU6050' */
  int16_T MCU6050_o4;                  /* '<Root>/MCU6050' */
  int16_T MCU6050_o5;                  /* '<Root>/MCU6050' */
  int16_T MCU6050_o6;                  /* '<Root>/MCU6050' */
  int16_T MCU6050_o7;                  /* '<Root>/MCU6050' */
  uint8_T PCF8591[4];                  /* '<Root>/PCF8591' */
  boolean_T LogicalOperator2;          /* '<S1>/Logical Operator2' */
  boolean_T LogicalOperator1;          /* '<S1>/Logical Operator1' */
  boolean_T Imageedge[4880];           /* '<S3>/Edge Detection' */
} B_Steuerung_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  int32_T EdgeDetection_GRAD_SUM_DW[4880];/* '<S3>/Edge Detection' */
  int32_T DrawShapes_DW_Polygon[72];   /* '<S3>/Draw Shapes' */
  int32_T DrawShapes_DW_Points[16];    /* '<S3>/Draw Shapes' */
  real_T UD_DSTATE;                    /* '<S8>/UD' */
  real_T PCA6585_DSTATE[2];            /* '<Root>/PCA6585' */
  real_T PCF8591_DSTATE;               /* '<Root>/PCF8591' */
  real_T MCU6050_DSTATE[2];            /* '<Root>/MCU6050' */
  real_T FindLocalMaxima_TEMP_IN_DWORKS[36180];/* '<S3>/Find Local Maxima' */
  struct {
    void *LoggedData;
  } Scope3_PWORK;                      /* '<Root>/Scope3' */

  struct {
    void *LoggedData[4];
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData[6];
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  int32_T EdgeDetection_VO_DW[6];      /* '<S3>/Edge Detection' */
  int32_T EdgeDetection_HO_DW[6];      /* '<S3>/Edge Detection' */
  int32_T EdgeDetection_VOU_DW[6];     /* '<S3>/Edge Detection' */
  int32_T EdgeDetection_VOD_DW[6];     /* '<S3>/Edge Detection' */
  int32_T EdgeDetection_VOL_DW[6];     /* '<S3>/Edge Detection' */
  int32_T EdgeDetection_VOR_DW[6];     /* '<S3>/Edge Detection' */
  int32_T EdgeDetection_HOU_DW[6];     /* '<S3>/Edge Detection' */
  int32_T EdgeDetection_HOD_DW[6];     /* '<S3>/Edge Detection' */
  int32_T EdgeDetection_HOL_DW[6];     /* '<S3>/Edge Detection' */
  int32_T EdgeDetection_HOR_DW[6];     /* '<S3>/Edge Detection' */
  int32_T EdgeDetection_VOUL_DW[6];    /* '<S3>/Edge Detection' */
  int32_T EdgeDetection_VOLL_DW[6];    /* '<S3>/Edge Detection' */
  int32_T EdgeDetection_VOUR_DW[6];    /* '<S3>/Edge Detection' */
  int32_T EdgeDetection_VOLR_DW[6];    /* '<S3>/Edge Detection' */
  int32_T EdgeDetection_HOUL_DW[6];    /* '<S3>/Edge Detection' */
  int32_T EdgeDetection_HOLL_DW[6];    /* '<S3>/Edge Detection' */
  int32_T EdgeDetection_HOUR_DW[6];    /* '<S3>/Edge Detection' */
  int32_T EdgeDetection_HOLR_DW[6];    /* '<S3>/Edge Detection' */
  int32_T FindLocalMaxima_DIMS1[2];    /* '<S3>/Find Local Maxima' */
  int32_T Selector2_DIMS1[2];          /* '<S3>/Selector2' */
  int32_T Selector_DIMS1;              /* '<S3>/Selector' */
  int32_T Selector1_DIMS1[2];          /* '<S3>/Selector1' */
  int32_T Selector3_DIMS1;             /* '<S3>/Selector3' */
  int32_T HoughLines_DIMS1[2];         /* '<S3>/Hough Lines' */
  int32_T EdgeDetection_MEAN_FACTOR_DW;/* '<S3>/Edge Detection' */
} DW_Steuerung_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: HoughTransform_SINE_TABLE_RTP
   * Referenced by: '<S3>/Hough Transform'
   */
  real_T HoughTransform_SINE_TABLE_RTP[91];

  /* Computed Parameter: HoughTransform_FIRSTRHO_RTP
   * Referenced by: '<S3>/Hough Transform'
   */
  real_T HoughTransform_FIRSTRHO_RTP;

  /* Computed Parameter: EdgeDetection_VRO_RTP
   * Referenced by: '<S3>/Edge Detection'
   */
  int32_T EdgeDetection_VRO_RTP[6];

  /* Computed Parameter: EdgeDetection_VCO_RTP
   * Referenced by: '<S3>/Edge Detection'
   */
  int32_T EdgeDetection_VCO_RTP[6];

  /* Computed Parameter: EdgeDetection_HRO_RTP
   * Referenced by: '<S3>/Edge Detection'
   */
  int32_T EdgeDetection_HRO_RTP[6];

  /* Computed Parameter: EdgeDetection_HCO_RTP
   * Referenced by: '<S3>/Edge Detection'
   */
  int32_T EdgeDetection_HCO_RTP[6];

  /* Computed Parameter: EdgeDetection_VC_RTP
   * Referenced by: '<S3>/Edge Detection'
   */
  int32_T EdgeDetection_VC_RTP[6];

  /* Computed Parameter: EdgeDetection_HC_RTP
   * Referenced by: '<S3>/Edge Detection'
   */
  int32_T EdgeDetection_HC_RTP[6];

  /* Expression: devName
   * Referenced by: '<S6>/V4L2 Video Capture'
   */
  uint8_T V4L2VideoCapture_p1[12];
} ConstP_Steuerung_T;

/* Parameters (default storage) */
struct P_Steuerung_T_ {
  real_T DiscretePIDController_D;      /* Mask Parameter: DiscretePIDController_D
                                        * Referenced by: '<S7>/Derivative Gain'
                                        */
  real_T DiscretePIDController_P;      /* Mask Parameter: DiscretePIDController_P
                                        * Referenced by: '<S7>/Proportional Gain'
                                        */
  real_T SliderGain_gain;              /* Mask Parameter: SliderGain_gain
                                        * Referenced by: '<S4>/Slider Gain'
                                        */
  real_T SliderGain1_gain;             /* Mask Parameter: SliderGain1_gain
                                        * Referenced by: '<S5>/Slider Gain'
                                        */
  real_T FindLocalMaxima_threshold;    /* Mask Parameter: FindLocalMaxima_threshold
                                        * Referenced by: '<S3>/Find Local Maxima'
                                        */
  int32_T DrawShapes_lineWidth;        /* Mask Parameter: DrawShapes_lineWidth
                                        * Referenced by: '<S3>/Draw Shapes'
                                        */
  int32_T EdgeDetection_thresholdTuning;/* Mask Parameter: EdgeDetection_thresholdTuning
                                         * Referenced by: '<S3>/Edge Detection'
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
  real_T K1_Gain;                      /* Expression: 2
                                        * Referenced by: '<S2>/K1'
                                        */
  real_T Normalization_Gain;           /* Expression: 1/300
                                        * Referenced by: '<S2>/Normalization'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 1
                                        * Referenced by: '<S2>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -1
                                        * Referenced by: '<S2>/Saturation'
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
  real_T Normalization_Gain_l;         /* Expression: 1/3395
                                        * Referenced by: '<Root>/Normalization'
                                        */
  real_T Gain_Gain;                    /* Expression: 3395
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T Constant5_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant5'
                                        */
  real_T Gain3_Gain;                   /* Expression: 1
                                        * Referenced by: '<Root>/Gain3'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1
                                        * Referenced by: '<Root>/Gain2'
                                        */
  real_T theta_d_Value;                /* Expression: 0
                                        * Referenced by: '<Root>/theta_d'
                                        */
  real_T y_d_Value;                    /* Expression: 40
                                        * Referenced by: '<Root>/y_d'
                                        */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S8>/TSamp'
                                        */
  real_T UD_InitialCondition;          /* Expression: DifferentiatorICPrevScaledInput
                                        * Referenced by: '<S8>/UD'
                                        */
  real_T Gain1_Gain;                   /* Expression: 300
                                        * Referenced by: '<S1>/Gain1'
                                        */
  real_T Constant3_Value;              /* Expression: 1228
                                        * Referenced by: '<S1>/Constant3'
                                        */
  uint32_T UD_DelayLength;             /* Computed Parameter: UD_DelayLength
                                        * Referenced by: '<S8>/UD'
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
  uint8_T DrawShapes_RTP_FILLCOLOR[3]; /* Computed Parameter: DrawShapes_RTP_FILLCOLOR
                                        * Referenced by: '<S3>/Draw Shapes'
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

/* Constant parameters (default storage) */
extern const ConstP_Steuerung_T Steuerung_ConstP;

/* Model entry point functions */
extern void Steuerung_initialize(void);
extern void Steuerung_step(void);
extern void Steuerung_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Steuerung_T *const Steuerung_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S8>/DTDup' : Unused code path elimination
 * Block '<S1>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S1>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S3>/Reshape' : Reshape block reduction
 * Block '<S3>/Reshape1' : Reshape block reduction
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
 * '<S4>'   : 'Steuerung/Slider Gain'
 * '<S5>'   : 'Steuerung/Slider Gain1'
 * '<S6>'   : 'Steuerung/Video Input'
 * '<S7>'   : 'Steuerung/Lane following/Discrete PID Controller'
 * '<S8>'   : 'Steuerung/Lane following/Discrete PID Controller/Differentiator'
 * '<S9>'   : 'Steuerung/Lane-finding/Calculate angle'
 * '<S10>'  : 'Steuerung/Lane-finding/Calculate center line'
 */
#endif                                 /* RTW_HEADER_Steuerung_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
