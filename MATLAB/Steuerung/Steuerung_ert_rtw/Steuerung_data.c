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
 * Model version                  : 1.300
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Thu Oct 25 19:24:36 2018
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Steuerung.h"
#include "Steuerung_private.h"

/* Block parameters (default storage) */
P_Steuerung_T Steuerung_P = {
  /* Mask Parameter: DiscretePIDController_D
   * Referenced by: '<S7>/Derivative Gain'
   */
  2.0,

  /* Mask Parameter: DiscretePIDController_P
   * Referenced by: '<S7>/Proportional Gain'
   */
  18.0,

  /* Mask Parameter: SliderGain_gain
   * Referenced by: '<S4>/Slider Gain'
   */
  400.0,

  /* Mask Parameter: SliderGain1_gain
   * Referenced by: '<S5>/Slider Gain'
   */
  300.0,

  /* Mask Parameter: FindLocalMaxima_threshold
   * Referenced by: '<S3>/Find Local Maxima'
   */
  10.0,

  /* Mask Parameter: DrawShapes_lineWidth
   * Referenced by: '<S3>/Draw Shapes'
   */
  1,

  /* Mask Parameter: EdgeDetection_thresholdTuning
   * Referenced by: '<S3>/Edge Detection'
   */
  1024,

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

  /* Expression: 2
   * Referenced by: '<S2>/K1'
   */
  2.0,

  /* Expression: 1/300
   * Referenced by: '<S2>/Normalization'
   */
  0.0033333333333333335,

  /* Expression: 1
   * Referenced by: '<S2>/Saturation'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S2>/Saturation'
   */
  -1.0,

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

  /* Expression: 1
   * Referenced by: '<Root>/Gain3'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<Root>/Gain2'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/theta_d'
   */
  0.0,

  /* Expression: 40
   * Referenced by: '<Root>/y_d'
   */
  40.0,

  /* Computed Parameter: TSamp_WtEt
   * Referenced by: '<S8>/TSamp'
   */
  10.0,

  /* Expression: DifferentiatorICPrevScaledInput
   * Referenced by: '<S8>/UD'
   */
  0.0,

  /* Expression: 300
   * Referenced by: '<S1>/Gain1'
   */
  300.0,

  /* Expression: 1228
   * Referenced by: '<S1>/Constant3'
   */
  1228.0,

  /* Computed Parameter: UD_DelayLength
   * Referenced by: '<S8>/UD'
   */
  1U,

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
  1U,

  /* Computed Parameter: DrawShapes_RTP_FILLCOLOR
   * Referenced by: '<S3>/Draw Shapes'
   */
  { 0U, 0U, 255U }
};

/* Constant parameters (default storage) */
const ConstP_Steuerung_T Steuerung_ConstP = {
  /* Computed Parameter: HoughTransform_SINE_TABLE_RTP
   * Referenced by: '<S3>/Hough Transform'
   */
  { -1.0, -0.99984769515639127, -0.99939082701909565, -0.99862953475457383,
    -0.9975640502598242, -0.99619469809174555, -0.9945218953682734,
    -0.992546151641322, -0.99026806874157036, -0.98768834059513766,
    -0.98480775301220791, -0.98162718344766386, -0.97814760073380558,
    -0.97437006478523525, -0.97029572627599658, -0.96592582628906831,
    -0.96126169593831889, -0.95630475596303555, -0.95105651629515353,
    -0.94551857559931674, -0.93969262078590832, -0.93358042649720174,
    -0.92718385456678754, -0.92050485345244026, -0.913545457642601,
    -0.90630778703664994, -0.898794046299167, -0.89100652418836779,
    -0.88294759285892688, -0.87461970713939574, -0.8660254037844386,
    -0.85716730070211233, -0.848048096156426, -0.838670567945424,
    -0.82903757255504162, -0.8191520442889918, -0.80901699437494745,
    -0.79863551004729283, -0.788010753606722, -0.7771459614569709,
    -0.766044443118978, -0.7547095802227719, -0.74314482547739424,
    -0.73135370161917046, -0.71933980033865119, -0.70710678118654746,
    -0.69465837045899725, -0.68199836006249859, -0.66913060635885824,
    -0.65605902899050728, -0.64278760968653936, -0.62932039104983739,
    -0.61566147532565829, -0.60181502315204827, -0.587785252292473,
    -0.573576436351046, -0.55919290347074679, -0.54463903501502708,
    -0.529919264233205, -0.51503807491005416, -0.49999999999999994,
    -0.48480962024633706, -0.46947156278589081, -0.45399049973954675,
    -0.4383711467890774, -0.42261826174069939, -0.40673664307580026,
    -0.39073112848927377, -0.37460659341591196, -0.35836794954530027,
    -0.34202014332566871, -0.3255681544571567, -0.30901699437494745,
    -0.29237170472273677, -0.27563735581699916, -0.25881904510252074,
    -0.24192189559966773, -0.224951054343865, -0.20791169081775934,
    -0.1908089953765448, -0.17364817766693033, -0.15643446504023087,
    -0.13917310096006544, -0.12186934340514748, -0.10452846326765347,
    -0.087155742747658166, -0.0697564737441253, -0.052335956242943835,
    -0.034899496702500969, -0.017452406437283512, 0.0 },

  /* Computed Parameter: HoughTransform_FIRSTRHO_RTP
   * Referenced by: '<S3>/Hough Transform'
   */
  -100.0,

  /* Computed Parameter: EdgeDetection_VRO_RTP
   * Referenced by: '<S3>/Edge Detection'
   */
  { -1, -1, -1, 1, 1, 1 },

  /* Computed Parameter: EdgeDetection_VCO_RTP
   * Referenced by: '<S3>/Edge Detection'
   */
  { -1, 0, 1, -1, 0, 1 },

  /* Computed Parameter: EdgeDetection_HRO_RTP
   * Referenced by: '<S3>/Edge Detection'
   */
  { -1, -1, 0, 0, 1, 1 },

  /* Computed Parameter: EdgeDetection_HCO_RTP
   * Referenced by: '<S3>/Edge Detection'
   */
  { -1, 1, -1, 1, -1, 1 },

  /* Computed Parameter: EdgeDetection_VC_RTP
   * Referenced by: '<S3>/Edge Detection'
   */
  { 268435456, 536870912, 268435456, -268435456, -536870912, -268435456 },

  /* Computed Parameter: EdgeDetection_HC_RTP
   * Referenced by: '<S3>/Edge Detection'
   */
  { 268435456, -268435456, 536870912, -536870912, 268435456, -268435456 },

  /* Expression: devName
   * Referenced by: '<S6>/V4L2 Video Capture'
   */
  { 47U, 100U, 101U, 118U, 47U, 118U, 105U, 100U, 101U, 111U, 48U, 0U }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
