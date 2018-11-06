/*
 * Academic Student License -- for use by students to meet course
 * requirements and perform academic research at degree granting
 * institutions only.  Not for government, commercial, or other
 * organizational use.
 *
 * File: Steuerung_data.c
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

#include "Steuerung.h"
#include "Steuerung_private.h"

/* Invariant block signals (default storage) */
const ConstB_Steuerung_T Steuerung_ConstB = {
  0.0                                  /* '<Root>/Constant Ramp' */
};

/* Block parameters (default storage) */
P_Steuerung_T Steuerung_P = {
  /* Mask Parameter: SliderGain_gain
   * Referenced by: '<S5>/Slider Gain'
   */
  161.85,

  /* Mask Parameter: SliderGain1_gain
   * Referenced by: '<S6>/Slider Gain'
   */
  300.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant7'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant6'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant'
   */
  1.0,

  /* Expression: 1/300
   * Referenced by: '<Root>/Normalization1'
   */
  0.0033333333333333335,

  /* Expression: 600
   * Referenced by: '<S1>/Constant1'
   */
  600.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant8'
   */
  1.0,

  /* Expression: 3000
   * Referenced by: '<Root>/Saturation'
   */
  3000.0,

  /* Expression: -0.5
   * Referenced by: '<Root>/Saturation'
   */
  -0.5,

  /* Expression: 1
   * Referenced by: '<Root>/Quantizer'
   */
  1.0,

  /* Expression: 1/3395
   * Referenced by: '<Root>/Normalization'
   */
  0.00029455081001472752,

  /* Expression: 3395
   * Referenced by: '<S1>/Gain'
   */
  3395.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant5'
   */
  1.0,

  /* Expression: 300
   * Referenced by: '<S1>/Gain1'
   */
  300.0,

  /* Expression: 1180
   * Referenced by: '<S1>/Constant3'
   */
  1180.0,

  /* Computed Parameter: ManualSwitch1_CurrentSetting
   * Referenced by: '<Root>/Manual Switch1'
   */
  0U,

  /* Computed Parameter: ManualSwitch_CurrentSetting
   * Referenced by: '<Root>/Manual Switch'
   */
  0U,

  /* Computed Parameter: ManualAutomaticSteering_Current
   * Referenced by: '<Root>/Manual // Automatic Steering'
   */
  1U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
