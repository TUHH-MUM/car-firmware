/*
 * Steuerung_dt.h
 *
 * Academic Student License -- for use by students to meet course
 * requirements and perform academic research at degree granting
 * institutions only.  Not for government, commercial, or other
 * organizational use.
 *
 * Code generation for model "Steuerung".
 *
 * Model version              : 1.300
 * Simulink Coder version : 8.14 (R2018a) 06-Feb-2018
 * C source code generated on : Thu Oct 25 19:24:36 2018
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(int32_T),
  sizeof(int32_T),
  sizeof(int32_T),
  sizeof(int16_T),
  sizeof(int16_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "int32_T",
  "int32_T",
  "int32_T",
  "int16_T",
  "int16_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&Steuerung_B.HoughTransform_o1[0]), 0, 0, 36561 },

  { (char_T *)(&Steuerung_B.HoughLines[0]), 6, 0, 8 },

  { (char_T *)(&Steuerung_B.V4L2VideoCapture_o1[0]), 3, 0, 76800 },

  { (char_T *)(&Steuerung_B.V4L2VideoCapture_o2[0]), 3, 0, 91440 },

  { (char_T *)(&Steuerung_B.steeringangle), 0, 0, 1 },

  { (char_T *)(&Steuerung_B.DataTypeConversion1), 5, 0, 2 },

  { (char_T *)(&Steuerung_B.MCU6050_o1), 4, 0, 7 },

  { (char_T *)(&Steuerung_B.PCF8591[0]), 3, 0, 4 },

  { (char_T *)(&Steuerung_B.LogicalOperator2), 8, 0, 4882 }
  ,

  { (char_T *)(&Steuerung_DW.UD_DSTATE), 0, 0, 36186 },

  { (char_T *)(&Steuerung_DW.Scope3_PWORK.LoggedData), 11, 0, 12 },

  { (char_T *)(&Steuerung_DW.EdgeDetection_VO_DW[0]), 6, 0, 119 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  12U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&Steuerung_P.DiscretePIDController_D), 0, 0, 5 },

  { (char_T *)(&Steuerung_P.DrawShapes_lineWidth), 6, 0, 2 },

  { (char_T *)(&Steuerung_P.Constant7_Value), 0, 0, 22 },

  { (char_T *)(&Steuerung_P.UD_DelayLength), 7, 0, 1 },

  { (char_T *)(&Steuerung_P.ManualSwitch1_CurrentSetting), 3, 0, 6 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  5U,
  rtPTransitions
};

/* [EOF] Steuerung_dt.h */
