/*
 * Academic Student License -- for use by students to meet course
 * requirements and perform academic research at degree granting
 * institutions only.  Not for government, commercial, or other
 * organizational use.
 *
 * File: Steuerung.c
 *
 * Code generated for Simulink model 'Steuerung'.
 *
 * Model version                  : 1.301
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Tue Nov  6 10:28:21 2018
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Steuerung.h"
#include "Steuerung_private.h"
#include "Steuerung_dt.h"

/* Block signals (default storage) */
B_Steuerung_T Steuerung_B;

/* Block states (default storage) */
DW_Steuerung_T Steuerung_DW;

/* Real-time model */
RT_MODEL_Steuerung_T Steuerung_M_;
RT_MODEL_Steuerung_T *const Steuerung_M = &Steuerung_M_;
void mul_wide_s32(int32_T in0, int32_T in1, uint32_T *ptrOutBitsHi, uint32_T
                  *ptrOutBitsLo)
{
  uint32_T absIn0;
  uint32_T absIn1;
  uint32_T in0Lo;
  uint32_T in0Hi;
  uint32_T in1Hi;
  uint32_T productHiLo;
  uint32_T productLoHi;
  absIn0 = in0 < 0 ? ~(uint32_T)in0 + 1U : (uint32_T)in0;
  absIn1 = in1 < 0 ? ~(uint32_T)in1 + 1U : (uint32_T)in1;
  in0Hi = absIn0 >> 16U;
  in0Lo = absIn0 & 65535U;
  in1Hi = absIn1 >> 16U;
  absIn0 = absIn1 & 65535U;
  productHiLo = in0Hi * absIn0;
  productLoHi = in0Lo * in1Hi;
  absIn0 *= in0Lo;
  absIn1 = 0U;
  in0Lo = (productLoHi << /*MW:OvBitwiseOk*/ 16U) + /*MW:OvCarryOk*/ absIn0;
  if (in0Lo < absIn0) {
    absIn1 = 1U;
  }

  absIn0 = in0Lo;
  in0Lo += /*MW:OvCarryOk*/ productHiLo << /*MW:OvBitwiseOk*/ 16U;
  if (in0Lo < absIn0) {
    absIn1++;
  }

  absIn0 = (((productLoHi >> 16U) + (productHiLo >> 16U)) + in0Hi * in1Hi) +
    absIn1;
  if (!((in0 == 0) || ((in1 == 0) || ((in0 > 0) == (in1 > 0))))) {
    absIn0 = ~absIn0;
    in0Lo = ~in0Lo;
    in0Lo++;
    if (in0Lo == 0U) {
      absIn0++;
    }
  }

  *ptrOutBitsHi = absIn0;
  *ptrOutBitsLo = in0Lo;
}

int32_T mul_s32_loSR(int32_T a, int32_T b, uint32_T aShift)
{
  uint32_T u32_chi;
  uint32_T u32_clo;
  mul_wide_s32(a, b, &u32_chi, &u32_clo);
  u32_clo = u32_chi << /*MW:OvBitwiseOk*/ (32U - aShift) | u32_clo >> aShift;
  return (int32_T)u32_clo;
}

int32_T div_repeat_s32_floor(int32_T numerator, int32_T denominator, uint32_T
  nRepeatSub)
{
  int32_T quotient;
  uint32_T absNumerator;
  uint32_T absDenominator;
  if (denominator == 0) {
    quotient = numerator >= 0 ? MAX_int32_T : MIN_int32_T;

    /* Divide by zero handler */
  } else {
    absNumerator = numerator < 0 ? ~(uint32_T)numerator + 1U : (uint32_T)
      numerator;
    absDenominator = denominator < 0 ? ~(uint32_T)denominator + 1U : (uint32_T)
      denominator;
    if ((numerator < 0) != (denominator < 0)) {
      quotient = -(int32_T)div_nzp_repeat_u32_ceiling(absNumerator,
        absDenominator, nRepeatSub);
    } else {
      quotient = (int32_T)div_nzp_repeat_u32(absNumerator, absDenominator,
        nRepeatSub);
    }
  }

  return quotient;
}

uint32_T div_nzp_repeat_u32_ceiling(uint32_T numerator, uint32_T denominator,
  uint32_T nRepeatSub)
{
  uint32_T quotient;
  uint32_T iRepeatSub;
  boolean_T numeratorExtraBit;
  quotient = numerator / denominator;
  numerator %= denominator;
  for (iRepeatSub = 0U; iRepeatSub < nRepeatSub; iRepeatSub++) {
    numeratorExtraBit = (numerator >= 2147483648U);
    numerator <<= 1U;
    quotient <<= 1U;
    if (numeratorExtraBit || (numerator >= denominator)) {
      quotient++;
      numerator -= denominator;
    }
  }

  if (numerator > 0U) {
    quotient++;
  }

  return quotient;
}

uint32_T div_nzp_repeat_u32(uint32_T numerator, uint32_T denominator, uint32_T
  nRepeatSub)
{
  uint32_T quotient;
  uint32_T iRepeatSub;
  boolean_T numeratorExtraBit;
  quotient = numerator / denominator;
  numerator %= denominator;
  for (iRepeatSub = 0U; iRepeatSub < nRepeatSub; iRepeatSub++) {
    numeratorExtraBit = (numerator >= 2147483648U);
    numerator <<= 1U;
    quotient <<= 1U;
    if (numeratorExtraBit || (numerator >= denominator)) {
      quotient++;
      numerator -= denominator;
    }
  }

  return quotient;
}

int32_T div_s32_floor(int32_T numerator, int32_T denominator)
{
  int32_T quotient;
  uint32_T absNumerator;
  uint32_T absDenominator;
  uint32_T tempAbsQuotient;
  boolean_T quotientNeedsNegation;
  if (denominator == 0) {
    quotient = numerator >= 0 ? MAX_int32_T : MIN_int32_T;

    /* Divide by zero handler */
  } else {
    absNumerator = numerator < 0 ? ~(uint32_T)numerator + 1U : (uint32_T)
      numerator;
    absDenominator = denominator < 0 ? ~(uint32_T)denominator + 1U : (uint32_T)
      denominator;
    quotientNeedsNegation = ((numerator < 0) != (denominator < 0));
    tempAbsQuotient = absNumerator / absDenominator;
    if (quotientNeedsNegation) {
      absNumerator %= absDenominator;
      if (absNumerator > 0U) {
        tempAbsQuotient++;
      }
    }

    quotient = quotientNeedsNegation ? -(int32_T)tempAbsQuotient : (int32_T)
      tempAbsQuotient;
  }

  return quotient;
}

void mul_wide_su32(int32_T in0, uint32_T in1, uint32_T *ptrOutBitsHi, uint32_T
                   *ptrOutBitsLo)
{
  uint32_T outBitsLo;
  uint32_T absIn0;
  uint32_T in0Hi;
  uint32_T in1Lo;
  uint32_T in1Hi;
  uint32_T productHiLo;
  uint32_T productLoHi;
  absIn0 = in0 < 0 ? ~(uint32_T)in0 + 1U : (uint32_T)in0;
  in0Hi = absIn0 >> 16U;
  absIn0 &= 65535U;
  in1Hi = in1 >> 16U;
  in1Lo = in1 & 65535U;
  productHiLo = in0Hi * in1Lo;
  productLoHi = absIn0 * in1Hi;
  absIn0 *= in1Lo;
  in1Lo = 0U;
  outBitsLo = (productLoHi << /*MW:OvBitwiseOk*/ 16U) + /*MW:OvCarryOk*/ absIn0;
  if (outBitsLo < absIn0) {
    in1Lo = 1U;
  }

  absIn0 = outBitsLo;
  outBitsLo += /*MW:OvCarryOk*/ productHiLo << /*MW:OvBitwiseOk*/ 16U;
  if (outBitsLo < absIn0) {
    in1Lo++;
  }

  absIn0 = (((productLoHi >> 16U) + (productHiLo >> 16U)) + in0Hi * in1Hi) +
    in1Lo;
  if (!((in1 == 0U) || (in0 >= 0))) {
    absIn0 = ~absIn0;
    outBitsLo = ~outBitsLo;
    outBitsLo++;
    if (outBitsLo == 0U) {
      absIn0++;
    }
  }

  *ptrOutBitsHi = absIn0;
  *ptrOutBitsLo = outBitsLo;
}

int32_T mul_ssu32_loSR(int32_T a, uint32_T b, uint32_T aShift)
{
  uint32_T u32_chi;
  uint32_T u32_clo;
  mul_wide_su32(a, b, &u32_chi, &u32_clo);
  u32_clo = u32_chi << /*MW:OvBitwiseOk*/ (32U - aShift) | u32_clo >> aShift;
  return (int32_T)u32_clo;
}

int16_T rt_sqrt_Us32En14_Ys16E_tOJnWsQ0(int32_T u)
{
  int16_T y;
  int16_T tmp01_y;
  int16_T shiftMask;
  int32_T iBit;

  /* Fixed-Point Sqrt Computation by the bisection method. */
  if (u > 0) {
    y = 0;
    shiftMask = 16384;
    for (iBit = 0; iBit < 15; iBit++) {
      tmp01_y = (int16_T)(y | shiftMask);
      if (tmp01_y * tmp01_y <= u) {
        y = tmp01_y;
      }

      shiftMask = (int16_T)((uint32_T)shiftMask >> 1U);
    }
  } else {
    y = 0;
  }

  return y;
}

/* Model step function */
void Steuerung_step(void)
{
  boolean_T isMore;
  boolean_T prevEdgeIsVertical;
  boolean_T countTwice;
  boolean_T done;
  int32_T yElIdx;
  int32_T line_idx_0;
  int32_T acc1_idx_4;
  int32_T acc1_idx_3;
  int32_T acc1_idx_2;
  int32_T acc4_idx_0;
  int32_T acc2_idx_2;
  int32_T acc2_idx_0;
  int32_T acc2_idx_1;
  int32_T edgeTmp_tmp;
  int32_T DrawShapes_DW_Polygon_tmp;
  int32_T numActiveEdge_tmp;
  int32_T numActiveEdge_tmp_0;

  /* S-Function (RPI_Init): '<Root>/Init' */
  RPI_Init_Outputs_wrapper();

  /* ManualSwitch: '<Root>/Manual Switch1' incorporates:
   *  Constant: '<Root>/Constant6'
   *  Constant: '<Root>/Constant7'
   */
  if (Steuerung_P.ManualSwitch1_CurrentSetting == 1) {
    Steuerung_B.Gain2 = Steuerung_P.Constant6_Value;
  } else {
    Steuerung_B.Gain2 = Steuerung_P.Constant7_Value;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch1' */

  /* ManualSwitch: '<Root>/Manual Switch' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant2'
   */
  if (Steuerung_P.ManualSwitch_CurrentSetting == 1) {
    Steuerung_B.Add1 = Steuerung_P.Constant_Value;
  } else {
    Steuerung_B.Add1 = Steuerung_P.Constant2_Value;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch' */

  /* Logic: '<S1>/Logical Operator2' */
  Steuerung_B.LogicalOperator2 = ((Steuerung_B.Gain2 != 0.0) &&
    (Steuerung_B.Add1 != 0.0));

  /* Logic: '<S1>/Logical Operator1' incorporates:
   *  Logic: '<S1>/Logical Operator'
   */
  Steuerung_B.LogicalOperator1 = ((Steuerung_B.Gain2 != 0.0) &&
    (!(Steuerung_B.Add1 != 0.0)));

  /* DataTypeConversion: '<S1>/Data Type Conversion1' incorporates:
   *  Constant: '<Root>/Constant8'
   *  Constant: '<S1>/Constant1'
   *  Gain: '<Root>/Normalization'
   *  Gain: '<S1>/Gain'
   *  Gain: '<S4>/Slider Gain'
   *  Product: '<S1>/Product'
   *  Sum: '<S1>/Add'
   */
  Steuerung_B.Gain2 = floor(Steuerung_P.SliderGain_gain *
    Steuerung_P.Constant8_Value * Steuerung_P.Normalization_Gain_l *
    Steuerung_P.Gain_Gain + Steuerung_B.Gain2 * Steuerung_P.Constant1_Value);
  if (rtIsNaN(Steuerung_B.Gain2) || rtIsInf(Steuerung_B.Gain2)) {
    Steuerung_B.Gain2 = 0.0;
  } else {
    Steuerung_B.Gain2 = fmod(Steuerung_B.Gain2, 65536.0);
  }

  Steuerung_B.DataTypeConversion1 = (uint16_T)(Steuerung_B.Gain2 < 0.0 ?
    (int32_T)(uint16_T)-(int16_T)(uint16_T)-Steuerung_B.Gain2 : (int32_T)
    (uint16_T)Steuerung_B.Gain2);

  /* End of DataTypeConversion: '<S1>/Data Type Conversion1' */

  /* Gain: '<S5>/Slider Gain' incorporates:
   *  Constant: '<Root>/Constant5'
   */
  Steuerung_B.Gain2 = Steuerung_P.SliderGain1_gain * Steuerung_P.Constant5_Value;

  /* S-Function (v4l2_video_capture_sfcn): '<S6>/V4L2 Video Capture' */
  MW_videoCaptureOutput(Steuerung_ConstP.V4L2VideoCapture_p1,
                        Steuerung_B.V4L2VideoCapture_o1,
                        Steuerung_B.V4L2VideoCapture_o2,
                        Steuerung_B.V4L2VideoCapture_o3);

  /* PermuteDimensions: '<S6>/Permute Dimensions3' */
  yElIdx = 0;
  Steuerung_B.uElOffset1 = 0;
  for (Steuerung_B.ntIdx1 = 0; Steuerung_B.ntIdx1 < 320; Steuerung_B.ntIdx1++) {
    Steuerung_B.m = Steuerung_B.uElOffset1;
    for (Steuerung_B.imgRow = 0; Steuerung_B.imgRow < 240; Steuerung_B.imgRow++)
    {
      Steuerung_B.PermuteDimensions3[yElIdx] =
        Steuerung_B.V4L2VideoCapture_o1[Steuerung_B.m];
      yElIdx++;
      Steuerung_B.m += 320;
    }

    Steuerung_B.uElOffset1++;
  }

  /* End of PermuteDimensions: '<S6>/Permute Dimensions3' */

  /* Selector: '<S6>/Select every second pixel2' incorporates:
   *  Selector: '<S6>/clip image  to 120x1'
   */
  for (Steuerung_B.numActiveEdge = 0; Steuerung_B.numActiveEdge < 80;
       Steuerung_B.numActiveEdge++) {
    for (Steuerung_B.imgRow = 0; Steuerung_B.imgRow < 61; Steuerung_B.imgRow++)
    {
      Steuerung_B.Selecteverysecondpixel2[Steuerung_B.imgRow + 61 *
        Steuerung_B.numActiveEdge] = Steuerung_B.PermuteDimensions3
        [((Steuerung_B.numActiveEdge << 2) * 240 + Steuerung_B.imgRow) + 149];
    }
  }

  /* End of Selector: '<S6>/Select every second pixel2' */

  /* S-Function (svipedge): '<S3>/Edge Detection' */
  for (Steuerung_B.ntIdx1 = 0; Steuerung_B.ntIdx1 < 78; Steuerung_B.ntIdx1++) {
    for (Steuerung_B.imgRow = 0; Steuerung_B.imgRow < 59; Steuerung_B.imgRow++)
    {
      yElIdx = 0;
      Steuerung_B.uElOffset1 = 0;
      Steuerung_B.q2 = ((Steuerung_B.ntIdx1 + 1) * 61 + Steuerung_B.imgRow) + 1;
      for (Steuerung_B.m = 0; Steuerung_B.m < 6; Steuerung_B.m++) {
        yElIdx += mul_ssu32_loSR
          (Steuerung_ConstP.EdgeDetection_VC_RTP[Steuerung_B.m],
           Steuerung_B.Selecteverysecondpixel2[Steuerung_B.q2 +
           Steuerung_DW.EdgeDetection_VO_DW[Steuerung_B.m]], 23U);
        Steuerung_B.uElOffset1 += mul_ssu32_loSR
          (Steuerung_ConstP.EdgeDetection_HC_RTP[Steuerung_B.m],
           Steuerung_B.Selecteverysecondpixel2[Steuerung_B.q2 +
           Steuerung_DW.EdgeDetection_HO_DW[Steuerung_B.m]], 23U);
      }

      Steuerung_DW.EdgeDetection_GRAD_SUM_DW[Steuerung_B.q2] = mul_s32_loSR
        (yElIdx, yElIdx, 8U) + mul_s32_loSR(Steuerung_B.uElOffset1,
        Steuerung_B.uElOffset1, 8U);
    }
  }

  for (Steuerung_B.ntIdx1 = 0; Steuerung_B.ntIdx1 < 78; Steuerung_B.ntIdx1++) {
    yElIdx = 0;
    Steuerung_B.uElOffset1 = 0;
    Steuerung_B.accumThree = 0;
    Steuerung_B.accumFour = 0;
    Steuerung_B.imgRow = (Steuerung_B.ntIdx1 + 1) * 61;
    Steuerung_B.q2 = (Steuerung_B.ntIdx1 + 1) * 61 + 60;
    for (Steuerung_B.m = 0; Steuerung_B.m < 6; Steuerung_B.m++) {
      yElIdx += mul_ssu32_loSR
        (Steuerung_ConstP.EdgeDetection_HC_RTP[Steuerung_B.m],
         Steuerung_B.Selecteverysecondpixel2[Steuerung_B.imgRow +
         Steuerung_DW.EdgeDetection_HOU_DW[Steuerung_B.m]], 23U);
      Steuerung_B.uElOffset1 += mul_ssu32_loSR
        (Steuerung_ConstP.EdgeDetection_HC_RTP[Steuerung_B.m],
         Steuerung_B.Selecteverysecondpixel2[Steuerung_B.q2 +
         Steuerung_DW.EdgeDetection_HOD_DW[Steuerung_B.m]], 23U);
      Steuerung_B.accumThree += mul_ssu32_loSR
        (Steuerung_ConstP.EdgeDetection_VC_RTP[Steuerung_B.m],
         Steuerung_B.Selecteverysecondpixel2[Steuerung_B.imgRow +
         Steuerung_DW.EdgeDetection_VOU_DW[Steuerung_B.m]], 23U);
      Steuerung_B.accumFour += mul_ssu32_loSR
        (Steuerung_ConstP.EdgeDetection_VC_RTP[Steuerung_B.m],
         Steuerung_B.Selecteverysecondpixel2[Steuerung_B.q2 +
         Steuerung_DW.EdgeDetection_VOD_DW[Steuerung_B.m]], 23U);
    }

    Steuerung_DW.EdgeDetection_GRAD_SUM_DW[Steuerung_B.imgRow] = mul_s32_loSR
      (Steuerung_B.accumThree, Steuerung_B.accumThree, 8U) + mul_s32_loSR(yElIdx,
      yElIdx, 8U);
    Steuerung_DW.EdgeDetection_GRAD_SUM_DW[Steuerung_B.q2] = mul_s32_loSR
      (Steuerung_B.accumFour, Steuerung_B.accumFour, 8U) + mul_s32_loSR
      (Steuerung_B.uElOffset1, Steuerung_B.uElOffset1, 8U);
  }

  for (Steuerung_B.imgRow = 0; Steuerung_B.imgRow < 59; Steuerung_B.imgRow++) {
    yElIdx = 0;
    Steuerung_B.uElOffset1 = 0;
    Steuerung_B.accumThree = 0;
    Steuerung_B.accumFour = 0;
    for (Steuerung_B.m = 0; Steuerung_B.m < 6; Steuerung_B.m++) {
      yElIdx += mul_ssu32_loSR
        (Steuerung_ConstP.EdgeDetection_VC_RTP[Steuerung_B.m],
         Steuerung_B.Selecteverysecondpixel2[(Steuerung_B.imgRow +
          Steuerung_DW.EdgeDetection_VOL_DW[Steuerung_B.m]) + 1], 23U);
      Steuerung_B.uElOffset1 += mul_ssu32_loSR
        (Steuerung_ConstP.EdgeDetection_VC_RTP[Steuerung_B.m],
         Steuerung_B.Selecteverysecondpixel2[(Steuerung_B.imgRow +
          Steuerung_DW.EdgeDetection_VOR_DW[Steuerung_B.m]) + 4820], 23U);
      Steuerung_B.accumThree += mul_ssu32_loSR
        (Steuerung_ConstP.EdgeDetection_HC_RTP[Steuerung_B.m],
         Steuerung_B.Selecteverysecondpixel2[(Steuerung_B.imgRow +
          Steuerung_DW.EdgeDetection_HOL_DW[Steuerung_B.m]) + 1], 23U);
      Steuerung_B.accumFour += mul_ssu32_loSR
        (Steuerung_ConstP.EdgeDetection_HC_RTP[Steuerung_B.m],
         Steuerung_B.Selecteverysecondpixel2[(Steuerung_B.imgRow +
          Steuerung_DW.EdgeDetection_HOR_DW[Steuerung_B.m]) + 4820], 23U);
    }

    Steuerung_DW.EdgeDetection_GRAD_SUM_DW[Steuerung_B.imgRow + 1] =
      mul_s32_loSR(Steuerung_B.accumThree, Steuerung_B.accumThree, 8U) +
      mul_s32_loSR(yElIdx, yElIdx, 8U);
    Steuerung_DW.EdgeDetection_GRAD_SUM_DW[4820 + Steuerung_B.imgRow] =
      mul_s32_loSR(Steuerung_B.accumFour, Steuerung_B.accumFour, 8U) +
      mul_s32_loSR(Steuerung_B.uElOffset1, Steuerung_B.uElOffset1, 8U);
  }

  yElIdx = 0;
  Steuerung_B.uElOffset1 = 0;
  Steuerung_B.accumThree = 0;
  Steuerung_B.accumFour = 0;
  for (Steuerung_B.m = 0; Steuerung_B.m < 6; Steuerung_B.m++) {
    yElIdx += mul_ssu32_loSR(Steuerung_ConstP.EdgeDetection_VC_RTP[Steuerung_B.m],
      Steuerung_B.Selecteverysecondpixel2[Steuerung_DW.EdgeDetection_VOUL_DW[Steuerung_B.m]],
      23U);
    Steuerung_B.uElOffset1 += mul_ssu32_loSR
      (Steuerung_ConstP.EdgeDetection_HC_RTP[Steuerung_B.m],
       Steuerung_B.Selecteverysecondpixel2[Steuerung_DW.EdgeDetection_HOUL_DW[Steuerung_B.m]],
       23U);
    Steuerung_B.accumThree += mul_ssu32_loSR
      (Steuerung_ConstP.EdgeDetection_VC_RTP[Steuerung_B.m],
       Steuerung_B.Selecteverysecondpixel2[60 +
       Steuerung_DW.EdgeDetection_VOLL_DW[Steuerung_B.m]], 23U);
    Steuerung_B.accumFour += mul_ssu32_loSR
      (Steuerung_ConstP.EdgeDetection_HC_RTP[Steuerung_B.m],
       Steuerung_B.Selecteverysecondpixel2[60 +
       Steuerung_DW.EdgeDetection_HOLL_DW[Steuerung_B.m]], 23U);
  }

  Steuerung_DW.EdgeDetection_GRAD_SUM_DW[0] = mul_s32_loSR(yElIdx, yElIdx, 8U) +
    mul_s32_loSR(Steuerung_B.uElOffset1, Steuerung_B.uElOffset1, 8U);
  Steuerung_DW.EdgeDetection_GRAD_SUM_DW[60] = mul_s32_loSR
    (Steuerung_B.accumThree, Steuerung_B.accumThree, 8U) + mul_s32_loSR
    (Steuerung_B.accumFour, Steuerung_B.accumFour, 8U);
  yElIdx = 0;
  Steuerung_B.uElOffset1 = 0;
  Steuerung_B.accumThree = 0;
  Steuerung_B.accumFour = 0;
  for (Steuerung_B.m = 0; Steuerung_B.m < 6; Steuerung_B.m++) {
    yElIdx += mul_ssu32_loSR(Steuerung_ConstP.EdgeDetection_VC_RTP[Steuerung_B.m],
      Steuerung_B.Selecteverysecondpixel2[4819 +
      Steuerung_DW.EdgeDetection_VOUR_DW[Steuerung_B.m]], 23U);
    Steuerung_B.uElOffset1 += mul_ssu32_loSR
      (Steuerung_ConstP.EdgeDetection_HC_RTP[Steuerung_B.m],
       Steuerung_B.Selecteverysecondpixel2[4819 +
       Steuerung_DW.EdgeDetection_HOUR_DW[Steuerung_B.m]], 23U);
    Steuerung_B.accumThree += mul_ssu32_loSR
      (Steuerung_ConstP.EdgeDetection_VC_RTP[Steuerung_B.m],
       Steuerung_B.Selecteverysecondpixel2[4879 +
       Steuerung_DW.EdgeDetection_VOLR_DW[Steuerung_B.m]], 23U);
    Steuerung_B.accumFour += mul_ssu32_loSR
      (Steuerung_ConstP.EdgeDetection_HC_RTP[Steuerung_B.m],
       Steuerung_B.Selecteverysecondpixel2[4879 +
       Steuerung_DW.EdgeDetection_HOLR_DW[Steuerung_B.m]], 23U);
  }

  Steuerung_DW.EdgeDetection_GRAD_SUM_DW[4819] = mul_s32_loSR(yElIdx, yElIdx, 8U)
    + mul_s32_loSR(Steuerung_B.uElOffset1, Steuerung_B.uElOffset1, 8U);
  Steuerung_DW.EdgeDetection_GRAD_SUM_DW[4879] = mul_s32_loSR
    (Steuerung_B.accumThree, Steuerung_B.accumThree, 8U) + mul_s32_loSR
    (Steuerung_B.accumFour, Steuerung_B.accumFour, 8U);
  yElIdx = 0;
  Steuerung_B.m = 0;
  while (Steuerung_B.m < 4880) {
    yElIdx += mul_s32_loSR(Steuerung_DW.EdgeDetection_GRAD_SUM_DW[Steuerung_B.m],
      Steuerung_DW.EdgeDetection_MEAN_FACTOR_DW, 31U);
    Steuerung_B.m++;
  }

  yElIdx = mul_s32_loSR(Steuerung_P.EdgeDetection_thresholdTuning, yElIdx, 8U);
  Steuerung_B.m = 0;
  while (Steuerung_B.m < 4880) {
    Steuerung_B.Imageedge[Steuerung_B.m] =
      (Steuerung_DW.EdgeDetection_GRAD_SUM_DW[Steuerung_B.m] > yElIdx);
    Steuerung_B.m++;
  }

  /* End of S-Function (svipedge): '<S3>/Edge Detection' */

  /* S-Function (sviphough): '<S3>/Hough Transform' */
  MWVIP_Hough_D(&Steuerung_B.Imageedge[0], &Steuerung_B.HoughTransform_o1[0],
                &Steuerung_ConstP.HoughTransform_SINE_TABLE_RTP[0],
                &Steuerung_ConstP.HoughTransform_FIRSTRHO_RTP, 61, 80, 201, 91);

  /* S-Function (svipfindlocalmax): '<S3>/Find Local Maxima' */
  yElIdx = 0;
  done = false;
  Steuerung_B.imgRow = 0;
  while (Steuerung_B.imgRow < 36180) {
    Steuerung_DW.FindLocalMaxima_TEMP_IN_DWORKS[Steuerung_B.imgRow] =
      Steuerung_B.HoughTransform_o1[Steuerung_B.imgRow];
    Steuerung_B.imgRow++;
  }

  Steuerung_B.FindLocalMaxima[0] = 0U;
  Steuerung_B.FindLocalMaxima[1] = 0U;
  Steuerung_B.FindLocalMaxima[2] = 0U;
  Steuerung_B.FindLocalMaxima[3] = 0U;
  while (!done) {
    Steuerung_B.ntIdx1 = 0;
    Steuerung_B.Add1 = Steuerung_DW.FindLocalMaxima_TEMP_IN_DWORKS[0];
    Steuerung_B.imgRow = 0;
    while (Steuerung_B.imgRow < 36180) {
      if (Steuerung_DW.FindLocalMaxima_TEMP_IN_DWORKS[Steuerung_B.imgRow] >
          Steuerung_B.Add1) {
        Steuerung_B.ntIdx1 = Steuerung_B.imgRow;
        Steuerung_B.Add1 =
          Steuerung_DW.FindLocalMaxima_TEMP_IN_DWORKS[Steuerung_B.imgRow];
      }

      Steuerung_B.imgRow++;
    }

    Steuerung_B.m = Steuerung_B.ntIdx1 % 201;
    Steuerung_B.imgRow = Steuerung_B.ntIdx1 / 201;
    if (Steuerung_DW.FindLocalMaxima_TEMP_IN_DWORKS[Steuerung_B.ntIdx1] >=
        Steuerung_P.FindLocalMaxima_threshold) {
      Steuerung_B.FindLocalMaxima[yElIdx] = (uint32_T)(1 + Steuerung_B.imgRow);
      Steuerung_B.FindLocalMaxima[2U + yElIdx] = (uint32_T)(1 + Steuerung_B.m);
      yElIdx++;
      if (yElIdx == 2) {
        done = true;
      }

      Steuerung_B.ntIdx1 = Steuerung_B.m - 2;
      if (!(Steuerung_B.ntIdx1 > 0)) {
        Steuerung_B.ntIdx1 = 0;
      }

      Steuerung_B.m += 2;
      if (!(Steuerung_B.m < 200)) {
        Steuerung_B.m = 200;
      }

      Steuerung_B.q2 = Steuerung_B.imgRow + 3;
      if (!(Steuerung_B.q2 < 179)) {
        Steuerung_B.q2 = 179;
      }

      acc4_idx_0 = Steuerung_B.imgRow - 3;
      if (!(acc4_idx_0 > 0)) {
        acc4_idx_0 = 0;
      }

      while (acc4_idx_0 <= Steuerung_B.q2) {
        Steuerung_B.jRowsIn = acc4_idx_0 * 201;
        Steuerung_B.imgRow = Steuerung_B.ntIdx1;
        while (Steuerung_B.imgRow <= Steuerung_B.m) {
          Steuerung_DW.FindLocalMaxima_TEMP_IN_DWORKS[Steuerung_B.imgRow +
            Steuerung_B.jRowsIn] = 0.0;
          Steuerung_B.imgRow++;
        }

        acc4_idx_0++;
      }
    } else {
      done = true;
    }
  }

  Steuerung_B.fromIdx = 2U;
  Steuerung_B.toIdx = (uint32_T)yElIdx;
  Steuerung_B.imgRow = 0;
  while (Steuerung_B.imgRow < yElIdx) {
    Steuerung_B.FindLocalMaxima[Steuerung_B.toIdx] =
      Steuerung_B.FindLocalMaxima[Steuerung_B.fromIdx];
    Steuerung_B.fromIdx++;
    Steuerung_B.toIdx++;
    Steuerung_B.imgRow++;
  }

  Steuerung_DW.FindLocalMaxima_DIMS1[0] = yElIdx;
  Steuerung_DW.FindLocalMaxima_DIMS1[1] = 2;

  /* End of S-Function (svipfindlocalmax): '<S3>/Find Local Maxima' */

  /* Selector: '<S3>/Selector2' */
  Steuerung_DW.Selector2_DIMS1[0] = Steuerung_DW.FindLocalMaxima_DIMS1[0];
  Steuerung_DW.Selector2_DIMS1[1] = 1;
  Steuerung_B.imgRow = Steuerung_DW.FindLocalMaxima_DIMS1[0];
  if (0 <= Steuerung_B.imgRow - 1) {
    memcpy(&Steuerung_B.rtb_FindLocalMaxima_data[0],
           &Steuerung_B.FindLocalMaxima[0], Steuerung_B.imgRow * sizeof(uint32_T));
  }

  Steuerung_B.imgRow = Steuerung_DW.FindLocalMaxima_DIMS1[0];
  if (0 <= Steuerung_B.imgRow - 1) {
    memcpy(&Steuerung_B.Selector1[0], &Steuerung_B.rtb_FindLocalMaxima_data[0],
           Steuerung_B.imgRow * sizeof(uint32_T));
  }

  /* End of Selector: '<S3>/Selector2' */

  /* Selector: '<S3>/Selector' */
  Steuerung_B.imgRow = Steuerung_DW.Selector2_DIMS1[0] *
    Steuerung_DW.Selector2_DIMS1[1];
  Steuerung_DW.Selector_DIMS1 = Steuerung_B.imgRow;
  for (Steuerung_B.numActiveEdge = 0; Steuerung_B.numActiveEdge <
       Steuerung_B.imgRow; Steuerung_B.numActiveEdge++) {
    Steuerung_B.Selector[Steuerung_B.numActiveEdge] =
      Steuerung_B.HoughTransform_o2[(int32_T)
      Steuerung_B.Selector1[Steuerung_B.numActiveEdge] - 1];
  }

  /* End of Selector: '<S3>/Selector' */

  /* Selector: '<S3>/Selector1' */
  Steuerung_DW.Selector1_DIMS1[0] = Steuerung_DW.FindLocalMaxima_DIMS1[0];
  Steuerung_DW.Selector1_DIMS1[1] = 1;
  Steuerung_B.imgRow = Steuerung_DW.FindLocalMaxima_DIMS1[0];
  for (Steuerung_B.numActiveEdge = 0; Steuerung_B.numActiveEdge <
       Steuerung_B.imgRow; Steuerung_B.numActiveEdge++) {
    Steuerung_B.rtb_FindLocalMaxima_data[Steuerung_B.numActiveEdge] =
      Steuerung_B.FindLocalMaxima[Steuerung_B.numActiveEdge +
      Steuerung_DW.FindLocalMaxima_DIMS1[0]];
  }

  Steuerung_B.imgRow = Steuerung_DW.FindLocalMaxima_DIMS1[0];
  if (0 <= Steuerung_B.imgRow - 1) {
    memcpy(&Steuerung_B.Selector1[0], &Steuerung_B.rtb_FindLocalMaxima_data[0],
           Steuerung_B.imgRow * sizeof(uint32_T));
  }

  /* End of Selector: '<S3>/Selector1' */

  /* Selector: '<S3>/Selector3' */
  Steuerung_B.imgRow = Steuerung_DW.Selector1_DIMS1[0] *
    Steuerung_DW.Selector1_DIMS1[1];
  Steuerung_DW.Selector3_DIMS1 = Steuerung_B.imgRow;
  for (Steuerung_B.numActiveEdge = 0; Steuerung_B.numActiveEdge <
       Steuerung_B.imgRow; Steuerung_B.numActiveEdge++) {
    Steuerung_B.Selector3[Steuerung_B.numActiveEdge] =
      Steuerung_B.HoughTransform_o3[(int32_T)
      Steuerung_B.Selector1[Steuerung_B.numActiveEdge] - 1];
  }

  /* End of Selector: '<S3>/Selector3' */

  /* S-Function (sviphoughlines): '<S3>/Hough Lines' */
  Steuerung_DW.HoughLines_DIMS1[1] = 4;
  Steuerung_DW.HoughLines_DIMS1[0] = Steuerung_DW.Selector_DIMS1;
  Steuerung_B.imgRow = 0;
  while (Steuerung_B.imgRow < Steuerung_DW.Selector_DIMS1) {
    yElIdx = 0;
    Steuerung_B.Add1 = (Steuerung_B.Selector3[Steuerung_B.imgRow] +
                        2.2204460492503131E-16) / (cos
      (Steuerung_B.Selector[Steuerung_B.imgRow]) + 2.2204460492503131E-16);

    /* part-1: top horizontal axis */
    Steuerung_B.x_center_idx_2 = floor(Steuerung_B.Add1 + 0.5);
    if ((Steuerung_B.x_center_idx_2 >= 0.0) && (Steuerung_B.x_center_idx_2 <=
         79.0)) {
      Steuerung_B.tmp_data[0U] = 0;
      if (Steuerung_B.x_center_idx_2 >= 0.5) {
        Steuerung_B.tmp_data[1U] = (int32_T)floor(Steuerung_B.x_center_idx_2 +
          0.5);
      } else {
        Steuerung_B.tmp_data[1U] = (int32_T)(Steuerung_B.x_center_idx_2 * 0.0);
      }

      yElIdx = 1;
    }

    Steuerung_B.y2 = (Steuerung_B.Selector3[Steuerung_B.imgRow] +
                      2.2204460492503131E-16) / (sin
      (Steuerung_B.Selector[Steuerung_B.imgRow]) + 2.2204460492503131E-16);

    /* part-2: left vertical axis */
    Steuerung_B.x_center_idx_2 = floor(Steuerung_B.y2 + 0.5);
    if ((Steuerung_B.x_center_idx_2 >= 0.0) && (Steuerung_B.x_center_idx_2 <=
         60.0)) {
      if (Steuerung_B.x_center_idx_2 >= 0.5) {
        Steuerung_B.tmp_data[yElIdx << 1] = (int32_T)floor
          (Steuerung_B.x_center_idx_2 + 0.5);
      } else {
        Steuerung_B.tmp_data[yElIdx << 1] = (int32_T)(Steuerung_B.x_center_idx_2
          * 0.0);
      }

      Steuerung_B.tmp_data[1 + (yElIdx << 1)] = 0;
      yElIdx++;
    }

    /* part-3: Right vertical axis */
    if (yElIdx < 2) {
      Steuerung_B.x_center_idx_2 = floor((Steuerung_B.Add1 - 79.0) *
        (Steuerung_B.y2 / Steuerung_B.Add1) + 0.5);
      if ((Steuerung_B.x_center_idx_2 >= 0.0) && (Steuerung_B.x_center_idx_2 <=
           60.0)) {
        if (Steuerung_B.x_center_idx_2 >= 0.5) {
          Steuerung_B.tmp_data[yElIdx << 1] = (int32_T)floor
            (Steuerung_B.x_center_idx_2 + 0.5);
        } else {
          Steuerung_B.tmp_data[yElIdx << 1] = (int32_T)
            (Steuerung_B.x_center_idx_2 * 0.0);
        }

        Steuerung_B.tmp_data[1 + (yElIdx << 1)] = 79;
        yElIdx++;
      }
    }

    /* part-4: bottom horizontal axis */
    if (yElIdx < 2) {
      Steuerung_B.x_center_idx_2 = floor((Steuerung_B.Add1 - Steuerung_B.Add1 /
        Steuerung_B.y2 * 60.0) + 0.5);
      if ((Steuerung_B.x_center_idx_2 >= 0.0) && (Steuerung_B.x_center_idx_2 <=
           79.0)) {
        Steuerung_B.tmp_data[yElIdx << 1] = 60;
        if (Steuerung_B.x_center_idx_2 >= 0.5) {
          Steuerung_B.tmp_data[1 + (yElIdx << 1)] = (int32_T)floor
            (Steuerung_B.x_center_idx_2 + 0.5);
        } else {
          Steuerung_B.tmp_data[1 + (yElIdx << 1)] = (int32_T)
            (Steuerung_B.x_center_idx_2 * 0.0);
        }

        yElIdx++;
      }
    }

    if (yElIdx < 2) {
      Steuerung_B.tmp_data[0U] = -1;
      Steuerung_B.tmp_data[1U] = -1;
      Steuerung_B.tmp_data[2U] = -1;
      Steuerung_B.tmp_data[3U] = -1;
    }

    Steuerung_B.HoughLines[Steuerung_B.imgRow] = Steuerung_B.tmp_data[1] + 1;
    Steuerung_B.HoughLines[Steuerung_B.imgRow + Steuerung_DW.Selector_DIMS1] =
      Steuerung_B.tmp_data[0] + 1;
    if (Steuerung_B.tmp_data[3] > 2147483646) {
      Steuerung_B.HoughLines[Steuerung_B.imgRow + (Steuerung_DW.Selector_DIMS1 <<
        1)] = MAX_int32_T;
    } else {
      Steuerung_B.HoughLines[Steuerung_B.imgRow + (Steuerung_DW.Selector_DIMS1 <<
        1)] = Steuerung_B.tmp_data[3] + 1;
    }

    if (Steuerung_B.tmp_data[2] > 2147483646) {
      Steuerung_B.HoughLines[Steuerung_B.imgRow + 3 *
        Steuerung_DW.Selector_DIMS1] = MAX_int32_T;
    } else {
      Steuerung_B.HoughLines[Steuerung_B.imgRow + 3 *
        Steuerung_DW.Selector_DIMS1] = Steuerung_B.tmp_data[2] + 1;
    }

    Steuerung_B.imgRow++;
  }

  /* End of S-Function (sviphoughlines): '<S3>/Hough Lines' */

  /* MATLAB Function: '<S3>/Calculate angle' */
  /* MATLAB Function 'Lane-finding/Calculate angle': '<S9>:1' */
  /* '<S9>:1:3' IMAGE_SIZE = size(Ref_I); */
  /* '<S9>:1:4' IMAGE_HEIGHT = IMAGE_SIZE(1); */
  /* '<S9>:1:5' IMAGE_WIDTH = IMAGE_SIZE(2); */
  /* '<S9>:1:6' points = zeros(2,4); */
  /*  Sorting the lines */
  /* '<S9>:1:9' if double(lines(1,1)) < double(lines(2,1)) */
  if (Steuerung_B.HoughLines[0] < Steuerung_B.HoughLines[1]) {
    /* '<S9>:1:10' points(1,:) = lines(1,:); */
    Steuerung_B.imgRow = Steuerung_DW.HoughLines_DIMS1[1];
    for (Steuerung_B.numActiveEdge = 0; Steuerung_B.numActiveEdge <
         Steuerung_B.imgRow; Steuerung_B.numActiveEdge++) {
      Steuerung_B.tmp_data[Steuerung_B.numActiveEdge] =
        Steuerung_B.HoughLines[Steuerung_DW.HoughLines_DIMS1[0] *
        Steuerung_B.numActiveEdge];
    }

    Steuerung_B.points[0] = Steuerung_B.tmp_data[0];
    Steuerung_B.points[4] = Steuerung_B.tmp_data[2];

    /* '<S9>:1:11' points(2,:) = lines(2,:); */
    Steuerung_B.imgRow = Steuerung_DW.HoughLines_DIMS1[1];
    for (Steuerung_B.numActiveEdge = 0; Steuerung_B.numActiveEdge <
         Steuerung_B.imgRow; Steuerung_B.numActiveEdge++) {
      Steuerung_B.tmp_data[Steuerung_B.numActiveEdge] =
        Steuerung_B.HoughLines[Steuerung_DW.HoughLines_DIMS1[0] *
        Steuerung_B.numActiveEdge + 1];
    }

    Steuerung_B.points[1] = Steuerung_B.tmp_data[0];
    Steuerung_B.points[5] = Steuerung_B.tmp_data[2];
  } else {
    /* '<S9>:1:12' else */
    /* '<S9>:1:13' points(1,:) = lines(2,:); */
    Steuerung_B.imgRow = Steuerung_DW.HoughLines_DIMS1[1];
    for (Steuerung_B.numActiveEdge = 0; Steuerung_B.numActiveEdge <
         Steuerung_B.imgRow; Steuerung_B.numActiveEdge++) {
      Steuerung_B.tmp_data[Steuerung_B.numActiveEdge] =
        Steuerung_B.HoughLines[Steuerung_DW.HoughLines_DIMS1[0] *
        Steuerung_B.numActiveEdge + 1];
    }

    Steuerung_B.points[0] = Steuerung_B.tmp_data[0];
    Steuerung_B.points[4] = Steuerung_B.tmp_data[2];

    /* '<S9>:1:14' points(2,:) = lines(1,:); */
    Steuerung_B.imgRow = Steuerung_DW.HoughLines_DIMS1[1];
    for (Steuerung_B.numActiveEdge = 0; Steuerung_B.numActiveEdge <
         Steuerung_B.imgRow; Steuerung_B.numActiveEdge++) {
      Steuerung_B.tmp_data[Steuerung_B.numActiveEdge] =
        Steuerung_B.HoughLines[Steuerung_DW.HoughLines_DIMS1[0] *
        Steuerung_B.numActiveEdge];
    }

    Steuerung_B.points[1] = Steuerung_B.tmp_data[0];
    Steuerung_B.points[5] = Steuerung_B.tmp_data[2];
  }

  /*  Calculate the lane center, top and bottom */
  /* '<S9>:1:18' x_center = double((points(1,:) + points(2,:))/2); */
  Steuerung_B.x_center_idx_2 = ((real_T)Steuerung_B.points[4] + (real_T)
    Steuerung_B.points[5]) / 2.0;

  /* MATLAB Function: '<S3>/Calculate center line' */
  /*  Calculate the angle of the centerline: 0 -> vertical */
  /* '<S9>:1:21' angle = atan((x_center(3) - x_center(1))/IMAGE_HEIGHT); */
  /*  Auxilliary lines */
  /* '<S9>:1:24' Pts = int32([x_center(1), 1, x_center(3), 75]); */
  /* '<S9>:1:25' Pts_d = int32([IMAGE_WIDTH/2, 1, IMAGE_WIDTH/2, 75]); */
  /*  angles = atan2d(double((lines(:,1) - lines(:,3))), -double(lines(:,2) - lines(:,4))); */
  /* MATLAB Function 'Lane-finding/Calculate center line': '<S10>:1' */
  /* '<S10>:1:3' IMAGE_SIZE = size(Ref_I); */
  /* '<S10>:1:4' IMAGE_HEIGHT = IMAGE_SIZE(1); */
  /* '<S10>:1:5' IMAGE_WIDTH = IMAGE_SIZE(2); */
  /* '<S10>:1:6' points = zeros(2,4); */
  /*  Sorting the lines */
  /* '<S10>:1:9' if double(lines(1,1)) < double(lines(2,1)) */
  if (Steuerung_B.HoughLines[0] < Steuerung_B.HoughLines[1]) {
    /* '<S10>:1:10' points(1,:) = lines(1,:); */
    Steuerung_B.imgRow = Steuerung_DW.HoughLines_DIMS1[1];
    for (Steuerung_B.numActiveEdge = 0; Steuerung_B.numActiveEdge <
         Steuerung_B.imgRow; Steuerung_B.numActiveEdge++) {
      Steuerung_B.tmp_data[Steuerung_B.numActiveEdge] =
        Steuerung_B.HoughLines[Steuerung_DW.HoughLines_DIMS1[0] *
        Steuerung_B.numActiveEdge];
    }

    Steuerung_B.points[4] = Steuerung_B.tmp_data[2];

    /* '<S10>:1:11' points(2,:) = lines(2,:); */
    Steuerung_B.imgRow = Steuerung_DW.HoughLines_DIMS1[1];
    for (Steuerung_B.numActiveEdge = 0; Steuerung_B.numActiveEdge <
         Steuerung_B.imgRow; Steuerung_B.numActiveEdge++) {
      Steuerung_B.tmp_data[Steuerung_B.numActiveEdge] =
        Steuerung_B.HoughLines[Steuerung_DW.HoughLines_DIMS1[0] *
        Steuerung_B.numActiveEdge + 1];
    }

    Steuerung_B.points[5] = Steuerung_B.tmp_data[2];
  } else {
    /* '<S10>:1:12' else */
    /* '<S10>:1:13' points(1,:) = lines(2,:); */
    Steuerung_B.imgRow = Steuerung_DW.HoughLines_DIMS1[1];
    for (Steuerung_B.numActiveEdge = 0; Steuerung_B.numActiveEdge <
         Steuerung_B.imgRow; Steuerung_B.numActiveEdge++) {
      Steuerung_B.tmp_data[Steuerung_B.numActiveEdge] =
        Steuerung_B.HoughLines[Steuerung_DW.HoughLines_DIMS1[0] *
        Steuerung_B.numActiveEdge + 1];
    }

    Steuerung_B.points[4] = Steuerung_B.tmp_data[2];

    /* '<S10>:1:14' points(2,:) = lines(1,:); */
    Steuerung_B.imgRow = Steuerung_DW.HoughLines_DIMS1[1];
    for (Steuerung_B.numActiveEdge = 0; Steuerung_B.numActiveEdge <
         Steuerung_B.imgRow; Steuerung_B.numActiveEdge++) {
      Steuerung_B.tmp_data[Steuerung_B.numActiveEdge] =
        Steuerung_B.HoughLines[Steuerung_DW.HoughLines_DIMS1[0] *
        Steuerung_B.numActiveEdge];
    }

    Steuerung_B.points[5] = Steuerung_B.tmp_data[2];
  }

  /* Sum: '<S2>/Add1' incorporates:
   *  Constant: '<Root>/y_d'
   *  Gain: '<Root>/Gain2'
   *  MATLAB Function: '<S3>/Calculate center line'
   */
  /*  Calculate the lane center, top and bottom */
  /* '<S10>:1:18' x_center = double((points(1,:) + points(2,:))/2); */
  /*  Output the lane center at the bottom of the picture */
  /* '<S10>:1:21' line_center = x_center(3); */
  Steuerung_B.Selector[1] = ((real_T)Steuerung_B.points[4] + (real_T)
    Steuerung_B.points[5]) / 2.0 * Steuerung_P.Gain2_Gain -
    Steuerung_P.y_d_Value;

  /* SampleTimeMath: '<S8>/TSamp' incorporates:
   *  Gain: '<S7>/Derivative Gain'
   *
   * About '<S8>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  Steuerung_B.Add1 = Steuerung_P.DiscretePIDController_D * Steuerung_B.Selector
    [1] * Steuerung_P.TSamp_WtEt;

  /* ManualSwitch: '<Root>/Manual // Automatic Steering' incorporates:
   *  Gain: '<Root>/Normalization1'
   */
  if (Steuerung_P.ManualAutomaticSteering_Current == 1) {
    Steuerung_B.steeringangle = Steuerung_P.Normalization1_Gain *
      Steuerung_B.Gain2;
  } else {
    /* Gain: '<S2>/Normalization' incorporates:
     *  Constant: '<Root>/theta_d'
     *  Delay: '<S8>/UD'
     *  Gain: '<Root>/Gain3'
     *  Gain: '<S2>/K1'
     *  Gain: '<S7>/Proportional Gain'
     *  MATLAB Function: '<S3>/Calculate angle'
     *  Sum: '<S2>/Add1'
     *  Sum: '<S2>/Add3'
     *  Sum: '<S7>/Sum'
     *  Sum: '<S8>/Diff'
     */
    Steuerung_B.Gain2 = ((atan((Steuerung_B.x_center_idx_2 - ((real_T)
      Steuerung_B.points[0] + (real_T)Steuerung_B.points[1]) / 2.0) / 61.0) *
                          Steuerung_P.Gain3_Gain - Steuerung_P.theta_d_Value) *
                         Steuerung_P.K1_Gain +
                         (Steuerung_P.DiscretePIDController_P *
                          Steuerung_B.Selector[1] + (Steuerung_B.Add1 -
      Steuerung_DW.UD_DSTATE))) * Steuerung_P.Normalization_Gain;

    /* Saturate: '<S2>/Saturation' */
    if (Steuerung_B.Gain2 > Steuerung_P.Saturation_UpperSat) {
      Steuerung_B.steeringangle = Steuerung_P.Saturation_UpperSat;
    } else if (Steuerung_B.Gain2 < Steuerung_P.Saturation_LowerSat) {
      Steuerung_B.steeringangle = Steuerung_P.Saturation_LowerSat;
    } else {
      Steuerung_B.steeringangle = Steuerung_B.Gain2;
    }

    /* End of Saturate: '<S2>/Saturation' */
  }

  /* End of ManualSwitch: '<Root>/Manual // Automatic Steering' */

  /* DataTypeConversion: '<S1>/Data Type Conversion3' incorporates:
   *  Constant: '<S1>/Constant3'
   *  Gain: '<S1>/Gain1'
   *  Sum: '<S1>/Add1'
   */
  Steuerung_B.Gain2 = floor(Steuerung_P.Gain1_Gain * Steuerung_B.steeringangle +
    Steuerung_P.Constant3_Value);
  if (rtIsNaN(Steuerung_B.Gain2) || rtIsInf(Steuerung_B.Gain2)) {
    Steuerung_B.Gain2 = 0.0;
  } else {
    Steuerung_B.Gain2 = fmod(Steuerung_B.Gain2, 65536.0);
  }

  Steuerung_B.DataTypeConversion3 = (uint16_T)(Steuerung_B.Gain2 < 0.0 ?
    (int32_T)(uint16_T)-(int16_T)(uint16_T)-Steuerung_B.Gain2 : (int32_T)
    (uint16_T)Steuerung_B.Gain2);

  /* End of DataTypeConversion: '<S1>/Data Type Conversion3' */

  /* S-Function (PCA6585): '<Root>/PCA6585' */
  PCA6585_Outputs_wrapper(&Steuerung_B.LogicalOperator2,
    &Steuerung_B.LogicalOperator1, &Steuerung_B.DataTypeConversion1,
    &Steuerung_B.DataTypeConversion3, &Steuerung_DW.PCA6585_DSTATE[0]);

  /* SignalConversion: '<S3>/ConcatBufferAtMatrix ConcatenateIn1' */
  for (Steuerung_B.imgRow = 0; Steuerung_B.imgRow < 4880; Steuerung_B.imgRow++)
  {
    Steuerung_B.MatrixConcatenate[Steuerung_B.imgRow] =
      Steuerung_B.Selecteverysecondpixel2[Steuerung_B.imgRow];
    Steuerung_B.MatrixConcatenate[Steuerung_B.imgRow + 4880] =
      Steuerung_B.Selecteverysecondpixel2[Steuerung_B.imgRow];
    Steuerung_B.MatrixConcatenate[Steuerung_B.imgRow + 9760] =
      Steuerung_B.Selecteverysecondpixel2[Steuerung_B.imgRow];
  }

  /* End of SignalConversion: '<S3>/ConcatBufferAtMatrix ConcatenateIn1' */

  /* S-Function (svipdrawshapes): '<S3>/Draw Shapes' */
  if (Steuerung_P.DrawShapes_lineWidth == 1) {
    /* Compute output for unity line width
     */
    yElIdx = 0;
    Steuerung_B.uElOffset1 = 0;
    if (Steuerung_DW.HoughLines_DIMS1[1] > 1) {
      Steuerung_B.uElOffset1 = Steuerung_DW.HoughLines_DIMS1[1] >> 1;
      done = (Steuerung_B.uElOffset1 << 1 == Steuerung_DW.HoughLines_DIMS1[1]);
      yElIdx = Steuerung_DW.HoughLines_DIMS1[0];
    } else {
      if (Steuerung_DW.HoughLines_DIMS1[1] == 1) {
        Steuerung_B.uElOffset1 = Steuerung_DW.HoughLines_DIMS1[0] >> 1;
        done = (Steuerung_B.uElOffset1 << 1 == Steuerung_DW.HoughLines_DIMS1[0]);
        yElIdx = 1;
      }
    }

    /* Copy the image from input to output. */
    memcpy(&Steuerung_B.Image_Lines_1[0], &Steuerung_B.MatrixConcatenate[0],
           14640U * sizeof(uint8_T));
    if (done && (yElIdx > 0)) {
      /* Update view port. */
      Steuerung_B.q2 = 0;
      while (Steuerung_B.q2 < yElIdx) {
        Steuerung_B.jRowsIn = 0;
        Steuerung_B.ntIdx1 = 0;
        while (Steuerung_B.ntIdx1 < Steuerung_B.uElOffset1 - 1) {
          Steuerung_B.activeCol = Steuerung_B.HoughLines[(((Steuerung_B.jRowsIn *
            yElIdx) << 1) + Steuerung_B.q2) + yElIdx] - 1;
          Steuerung_B.mNumPtPerPolygon_new = Steuerung_B.HoughLines
            [((Steuerung_B.jRowsIn * yElIdx) << 1) + Steuerung_B.q2] - 1;
          Steuerung_B.jRowsIn++;
          DrawShapes_DW_Polygon_tmp = Steuerung_B.HoughLines
            [(((Steuerung_B.jRowsIn * yElIdx) << 1) + Steuerung_B.q2) + yElIdx]
            - 1;
          acc1_idx_2 = Steuerung_B.HoughLines[((Steuerung_B.jRowsIn * yElIdx) <<
            1) + Steuerung_B.q2] - 1;
          if ((Steuerung_B.HoughLines[(((Steuerung_B.jRowsIn * yElIdx) << 1) +
                Steuerung_B.q2) + yElIdx] - 1 != Steuerung_B.activeCol) ||
              (Steuerung_B.HoughLines[((Steuerung_B.jRowsIn * yElIdx) << 1) +
               Steuerung_B.q2] - 1 != Steuerung_B.mNumPtPerPolygon_new)) {
            isMore = false;

            /* Find the visible portion of a line. */
            countTwice = false;
            prevEdgeIsVertical = false;
            done = false;
            line_idx_0 = Steuerung_B.activeCol;
            Steuerung_B.idxEdgeCur = Steuerung_B.mNumPtPerPolygon_new;
            Steuerung_B.m = DrawShapes_DW_Polygon_tmp;
            Steuerung_B.idxEdgePre = acc1_idx_2;
            while (!done) {
              Steuerung_B.fromIdx = 0U;
              Steuerung_B.toIdx = 0U;

              /* Determine viewport violations. */
              if (line_idx_0 < 0) {
                Steuerung_B.fromIdx = 4U;
              } else {
                if (line_idx_0 > 60) {
                  Steuerung_B.fromIdx = 8U;
                }
              }

              if (Steuerung_B.m < 0) {
                Steuerung_B.toIdx = 4U;
              } else {
                if (Steuerung_B.m > 60) {
                  Steuerung_B.toIdx = 8U;
                }
              }

              if (Steuerung_B.idxEdgeCur < 0) {
                Steuerung_B.fromIdx |= 1U;
              } else {
                if (Steuerung_B.idxEdgeCur > 79) {
                  Steuerung_B.fromIdx |= 2U;
                }
              }

              if (Steuerung_B.idxEdgePre < 0) {
                Steuerung_B.toIdx |= 1U;
              } else {
                if (Steuerung_B.idxEdgePre > 79) {
                  Steuerung_B.toIdx |= 2U;
                }
              }

              if (!((Steuerung_B.fromIdx | Steuerung_B.toIdx) != 0U)) {
                /* Line falls completely within bounds. */
                done = true;
                isMore = true;
              } else if ((Steuerung_B.fromIdx & Steuerung_B.toIdx) != 0U) {
                /* Line falls completely out of bounds. */
                done = true;
                isMore = false;
              } else if (Steuerung_B.fromIdx != 0U) {
                /* Clip 1st point; if it's in-bounds, clip 2nd point. */
                if (countTwice) {
                  line_idx_0 = Steuerung_B.activeCol;
                  Steuerung_B.idxEdgeCur = Steuerung_B.mNumPtPerPolygon_new;
                }

                Steuerung_B.imgRow = Steuerung_B.m - line_idx_0;
                Steuerung_B.accumThree = Steuerung_B.idxEdgePre -
                  Steuerung_B.idxEdgeCur;
                if ((Steuerung_B.imgRow > 1073741824) || (Steuerung_B.imgRow <
                     -1073741824) || ((Steuerung_B.accumThree > 1073741824) ||
                                      (Steuerung_B.accumThree < -1073741824))) {
                  /* Possible Inf or Nan. */
                  done = true;
                  isMore = false;
                  countTwice = true;
                } else if ((Steuerung_B.fromIdx & 4U) != 0U) {
                  /* Violated RMin. */
                  Steuerung_B.accumFour = -line_idx_0 * Steuerung_B.accumThree;
                  if ((Steuerung_B.accumFour > 1073741824) ||
                      (Steuerung_B.accumFour < -1073741824)) {
                    /* Check for Inf or Nan. */
                    done = true;
                    isMore = false;
                  } else if (((Steuerung_B.accumFour >= 0) &&
                              (Steuerung_B.imgRow >= 0)) ||
                             ((Steuerung_B.accumFour < 0) && (Steuerung_B.imgRow
                    < 0))) {
                    Steuerung_B.idxEdgeCur += (div_s32_floor
                      (Steuerung_B.accumFour << 1, Steuerung_B.imgRow) + 1) >> 1;
                  } else {
                    Steuerung_B.idxEdgeCur -= (div_s32_floor
                      (-Steuerung_B.accumFour << 1, Steuerung_B.imgRow) + 1) >>
                      1;
                  }

                  line_idx_0 = 0;
                  countTwice = true;
                } else if ((Steuerung_B.fromIdx & 8U) != 0U) {
                  /* Violated RMax. */
                  Steuerung_B.accumFour = (60 - line_idx_0) *
                    Steuerung_B.accumThree;
                  if ((Steuerung_B.accumFour > 1073741824) ||
                      (Steuerung_B.accumFour < -1073741824)) {
                    /* Check for Inf or Nan. */
                    done = true;
                    isMore = false;
                  } else if (((Steuerung_B.accumFour >= 0) &&
                              (Steuerung_B.imgRow >= 0)) ||
                             ((Steuerung_B.accumFour < 0) && (Steuerung_B.imgRow
                    < 0))) {
                    Steuerung_B.idxEdgeCur += (div_s32_floor
                      (Steuerung_B.accumFour << 1, Steuerung_B.imgRow) + 1) >> 1;
                  } else {
                    Steuerung_B.idxEdgeCur -= (div_s32_floor
                      (-Steuerung_B.accumFour << 1, Steuerung_B.imgRow) + 1) >>
                      1;
                  }

                  line_idx_0 = 60;
                  countTwice = true;
                } else if ((Steuerung_B.fromIdx & 1U) != 0U) {
                  /* Violated CMin. */
                  Steuerung_B.accumFour = -Steuerung_B.idxEdgeCur *
                    Steuerung_B.imgRow;
                  if ((Steuerung_B.accumFour > 1073741824) ||
                      (Steuerung_B.accumFour < -1073741824)) {
                    /* Check for Inf or Nan. */
                    done = true;
                    isMore = false;
                  } else if (((Steuerung_B.accumFour >= 0) &&
                              (Steuerung_B.accumThree >= 0)) ||
                             ((Steuerung_B.accumFour < 0) &&
                              (Steuerung_B.accumThree < 0))) {
                    line_idx_0 += (div_s32_floor(Steuerung_B.accumFour << 1,
                      Steuerung_B.accumThree) + 1) >> 1;
                  } else {
                    line_idx_0 -= (div_s32_floor(-Steuerung_B.accumFour << 1,
                      Steuerung_B.accumThree) + 1) >> 1;
                  }

                  Steuerung_B.idxEdgeCur = 0;
                  countTwice = true;
                } else {
                  /* Violated CMax. */
                  Steuerung_B.accumFour = (79 - Steuerung_B.idxEdgeCur) *
                    Steuerung_B.imgRow;
                  if ((Steuerung_B.accumFour > 1073741824) ||
                      (Steuerung_B.accumFour < -1073741824)) {
                    /* Check for Inf or Nan. */
                    done = true;
                    isMore = false;
                  } else if (((Steuerung_B.accumFour >= 0) &&
                              (Steuerung_B.accumThree >= 0)) ||
                             ((Steuerung_B.accumFour < 0) &&
                              (Steuerung_B.accumThree < 0))) {
                    line_idx_0 += (div_s32_floor(Steuerung_B.accumFour << 1,
                      Steuerung_B.accumThree) + 1) >> 1;
                  } else {
                    line_idx_0 -= (div_s32_floor(-Steuerung_B.accumFour << 1,
                      Steuerung_B.accumThree) + 1) >> 1;
                  }

                  Steuerung_B.idxEdgeCur = 79;
                  countTwice = true;
                }
              } else {
                /* Clip the 2nd point. */
                if (prevEdgeIsVertical) {
                  Steuerung_B.m = DrawShapes_DW_Polygon_tmp;
                  Steuerung_B.idxEdgePre = acc1_idx_2;
                }

                Steuerung_B.imgRow = Steuerung_B.m - line_idx_0;
                Steuerung_B.accumThree = Steuerung_B.idxEdgePre -
                  Steuerung_B.idxEdgeCur;
                if ((Steuerung_B.imgRow > 1073741824) || (Steuerung_B.imgRow <
                     -1073741824) || ((Steuerung_B.accumThree > 1073741824) ||
                                      (Steuerung_B.accumThree < -1073741824))) {
                  /* Possible Inf or Nan. */
                  done = true;
                  isMore = false;
                  prevEdgeIsVertical = true;
                } else if ((Steuerung_B.toIdx & 4U) != 0U) {
                  /* Violated RMin. */
                  Steuerung_B.accumFour = -Steuerung_B.m *
                    Steuerung_B.accumThree;
                  if ((Steuerung_B.accumFour > 1073741824) ||
                      (Steuerung_B.accumFour < -1073741824)) {
                    /* Check for Inf or Nan. */
                    done = true;
                    isMore = false;
                  } else if (((Steuerung_B.accumFour >= 0) &&
                              (Steuerung_B.imgRow >= 0)) ||
                             ((Steuerung_B.accumFour < 0) && (Steuerung_B.imgRow
                    < 0))) {
                    Steuerung_B.idxEdgePre += (div_s32_floor
                      (Steuerung_B.accumFour << 1, Steuerung_B.imgRow) + 1) >> 1;
                  } else {
                    Steuerung_B.idxEdgePre -= (div_s32_floor
                      (-Steuerung_B.accumFour << 1, Steuerung_B.imgRow) + 1) >>
                      1;
                  }

                  Steuerung_B.m = 0;
                  prevEdgeIsVertical = true;
                } else if ((Steuerung_B.toIdx & 8U) != 0U) {
                  /* Violated RMax. */
                  Steuerung_B.accumFour = (60 - Steuerung_B.m) *
                    Steuerung_B.accumThree;
                  if ((Steuerung_B.accumFour > 1073741824) ||
                      (Steuerung_B.accumFour < -1073741824)) {
                    /* Check for Inf or Nan. */
                    done = true;
                    isMore = false;
                  } else if (((Steuerung_B.accumFour >= 0) &&
                              (Steuerung_B.imgRow >= 0)) ||
                             ((Steuerung_B.accumFour < 0) && (Steuerung_B.imgRow
                    < 0))) {
                    Steuerung_B.idxEdgePre += (div_s32_floor
                      (Steuerung_B.accumFour << 1, Steuerung_B.imgRow) + 1) >> 1;
                  } else {
                    Steuerung_B.idxEdgePre -= (div_s32_floor
                      (-Steuerung_B.accumFour << 1, Steuerung_B.imgRow) + 1) >>
                      1;
                  }

                  Steuerung_B.m = 60;
                  prevEdgeIsVertical = true;
                } else if ((Steuerung_B.toIdx & 1U) != 0U) {
                  /* Violated CMin. */
                  Steuerung_B.accumFour = -Steuerung_B.idxEdgePre *
                    Steuerung_B.imgRow;
                  if ((Steuerung_B.accumFour > 1073741824) ||
                      (Steuerung_B.accumFour < -1073741824)) {
                    /* Check for Inf or Nan. */
                    done = true;
                    isMore = false;
                  } else if (((Steuerung_B.accumFour >= 0) &&
                              (Steuerung_B.accumThree >= 0)) ||
                             ((Steuerung_B.accumFour < 0) &&
                              (Steuerung_B.accumThree < 0))) {
                    Steuerung_B.m += (div_s32_floor(Steuerung_B.accumFour << 1,
                      Steuerung_B.accumThree) + 1) >> 1;
                  } else {
                    Steuerung_B.m -= (div_s32_floor(-Steuerung_B.accumFour << 1,
                      Steuerung_B.accumThree) + 1) >> 1;
                  }

                  Steuerung_B.idxEdgePre = 0;
                  prevEdgeIsVertical = true;
                } else {
                  /* Violated CMax. */
                  Steuerung_B.accumFour = (79 - Steuerung_B.idxEdgePre) *
                    Steuerung_B.imgRow;
                  if ((Steuerung_B.accumFour > 1073741824) ||
                      (Steuerung_B.accumFour < -1073741824)) {
                    /* Check for Inf or Nan. */
                    done = true;
                    isMore = false;
                  } else if (((Steuerung_B.accumFour >= 0) &&
                              (Steuerung_B.accumThree >= 0)) ||
                             ((Steuerung_B.accumFour < 0) &&
                              (Steuerung_B.accumThree < 0))) {
                    Steuerung_B.m += (div_s32_floor(Steuerung_B.accumFour << 1,
                      Steuerung_B.accumThree) + 1) >> 1;
                  } else {
                    Steuerung_B.m -= (div_s32_floor(-Steuerung_B.accumFour << 1,
                      Steuerung_B.accumThree) + 1) >> 1;
                  }

                  Steuerung_B.idxEdgePre = 79;
                  prevEdgeIsVertical = true;
                }
              }
            }

            if (isMore) {
              /* Draw a line using Bresenham algorithm. */
              /* Initialize the Bresenham algorithm. */
              if (Steuerung_B.m >= line_idx_0) {
                DrawShapes_DW_Polygon_tmp = Steuerung_B.m - line_idx_0;
              } else {
                DrawShapes_DW_Polygon_tmp = line_idx_0 - Steuerung_B.m;
              }

              if (Steuerung_B.idxEdgePre >= Steuerung_B.idxEdgeCur) {
                acc1_idx_2 = Steuerung_B.idxEdgePre - Steuerung_B.idxEdgeCur;
              } else {
                acc1_idx_2 = Steuerung_B.idxEdgeCur - Steuerung_B.idxEdgePre;
              }

              if (DrawShapes_DW_Polygon_tmp > acc1_idx_2) {
                Steuerung_B.imgRow = 1;
                Steuerung_B.accumFour = 61;
              } else {
                Steuerung_B.imgRow = 61;
                Steuerung_B.accumFour = 1;
                Steuerung_B.accumThree = line_idx_0;
                line_idx_0 = Steuerung_B.idxEdgeCur;
                Steuerung_B.idxEdgeCur = Steuerung_B.accumThree;
                Steuerung_B.accumThree = Steuerung_B.m;
                Steuerung_B.m = Steuerung_B.idxEdgePre;
                Steuerung_B.idxEdgePre = Steuerung_B.accumThree;
              }

              if (line_idx_0 > Steuerung_B.m) {
                Steuerung_B.accumThree = line_idx_0;
                line_idx_0 = Steuerung_B.m;
                Steuerung_B.m = Steuerung_B.accumThree;
                Steuerung_B.accumThree = Steuerung_B.idxEdgeCur;
                Steuerung_B.idxEdgeCur = Steuerung_B.idxEdgePre;
                Steuerung_B.idxEdgePre = Steuerung_B.accumThree;
              }

              Steuerung_B.accumThree = Steuerung_B.m - line_idx_0;
              if (Steuerung_B.idxEdgeCur <= Steuerung_B.idxEdgePre) {
                Steuerung_B.activeCol = 1;
                Steuerung_B.mNumPtPerPolygon_new = Steuerung_B.idxEdgePre -
                  Steuerung_B.idxEdgeCur;
              } else {
                Steuerung_B.activeCol = -1;
                Steuerung_B.mNumPtPerPolygon_new = Steuerung_B.idxEdgeCur -
                  Steuerung_B.idxEdgePre;
              }

              Steuerung_B.idxEdgePre = -((Steuerung_B.accumThree + 1) >> 1);
              Steuerung_B.idxEdgeCur = line_idx_0 * Steuerung_B.imgRow +
                Steuerung_B.idxEdgeCur * Steuerung_B.accumFour;
              Steuerung_B.activeCol = Steuerung_B.activeCol *
                Steuerung_B.accumFour + Steuerung_B.imgRow;
              done = (line_idx_0 <= Steuerung_B.m);
              while (done) {
                Steuerung_B.Image_Lines_1[Steuerung_B.idxEdgeCur] =
                  Steuerung_P.DrawShapes_RTP_FILLCOLOR[0];
                acc4_idx_0 = Steuerung_B.idxEdgeCur + 4880;
                Steuerung_B.Image_Lines_1[acc4_idx_0] =
                  Steuerung_P.DrawShapes_RTP_FILLCOLOR[1];
                acc4_idx_0 += 4880;
                Steuerung_B.Image_Lines_1[acc4_idx_0] =
                  Steuerung_P.DrawShapes_RTP_FILLCOLOR[2];

                /* Compute the next location using Bresenham algorithm. */
                /* Move to the next pixel location. */
                Steuerung_B.idxEdgePre += Steuerung_B.mNumPtPerPolygon_new;
                if (Steuerung_B.idxEdgePre >= 0) {
                  Steuerung_B.idxEdgePre -= Steuerung_B.accumThree;
                  Steuerung_B.idxEdgeCur += Steuerung_B.activeCol;
                } else {
                  Steuerung_B.idxEdgeCur += Steuerung_B.imgRow;
                }

                line_idx_0++;
                done = (line_idx_0 <= Steuerung_B.m);
              }
            }
          }

          Steuerung_B.ntIdx1++;
        }

        Steuerung_B.q2++;
      }
    }
  } else {
    /* Compute output for non-unity line width
     */
    yElIdx = 0;
    Steuerung_B.uElOffset1 = 0;
    if (Steuerung_DW.HoughLines_DIMS1[1] > 1) {
      Steuerung_B.uElOffset1 = Steuerung_DW.HoughLines_DIMS1[1] >> 1;
      done = (Steuerung_B.uElOffset1 << 1 == Steuerung_DW.HoughLines_DIMS1[1]);
      yElIdx = Steuerung_DW.HoughLines_DIMS1[0];
    } else {
      if (Steuerung_DW.HoughLines_DIMS1[1] == 1) {
        Steuerung_B.uElOffset1 = Steuerung_DW.HoughLines_DIMS1[0] >> 1;
        done = (Steuerung_B.uElOffset1 << 1 == Steuerung_DW.HoughLines_DIMS1[0]);
        yElIdx = 1;
      }
    }

    /* Copy the image from input to output. */
    memcpy(&Steuerung_B.Image_Lines_1[0], &Steuerung_B.MatrixConcatenate[0],
           14640U * sizeof(uint8_T));
    if (done && (yElIdx > 0)) {
      /* Update view port. */
      /* ProcessStep-start-1
       */
      if (Steuerung_P.DrawShapes_lineWidth > 1) {
        /* convertLinePts2PolygonPts
         */
        Steuerung_B.m = 0;
        Steuerung_B.imgRow = Steuerung_B.uElOffset1 << 1;
        Steuerung_B.jRowsIn = (Steuerung_B.uElOffset1 << 2) - 3;
        Steuerung_B.ntIdx1 = 0;
        while (Steuerung_B.ntIdx1 < yElIdx) {
          Steuerung_B.firstRow = Steuerung_B.HoughLines[Steuerung_B.ntIdx1] - 1;
          Steuerung_B.idxEdgePre = Steuerung_B.ntIdx1 + yElIdx;
          Steuerung_B.lastRow = Steuerung_B.HoughLines[Steuerung_B.idxEdgePre] -
            1;
          Steuerung_B.accumThree = Steuerung_B.HoughLines[(yElIdx << 1) +
            Steuerung_B.ntIdx1] - 1;
          Steuerung_B.accumFour = Steuerung_B.HoughLines[3 * yElIdx +
            Steuerung_B.ntIdx1] - 1;
          line_idx_0 = Steuerung_P.DrawShapes_lineWidth >> 1;

          /* getLineParams-1
           */
          /* getLineParams-main fcn
           */
          Steuerung_B.q2 = Steuerung_B.HoughLines[Steuerung_B.ntIdx1 + yElIdx] -
            Steuerung_B.HoughLines[3 * yElIdx + Steuerung_B.ntIdx1];
          acc4_idx_0 = Steuerung_B.HoughLines[Steuerung_B.ntIdx1] -
            Steuerung_B.HoughLines[(yElIdx << 1) + Steuerung_B.ntIdx1];
          if (acc4_idx_0 == 0) {
            DrawShapes_DW_Polygon_tmp = 0;
            Steuerung_B.activeCol = 1;
            acc1_idx_2 = ((Steuerung_B.HoughLines[Steuerung_B.ntIdx1] -
                           line_idx_0) - 1) << 14;
            acc1_idx_3 = ((Steuerung_B.HoughLines[Steuerung_B.ntIdx1] +
                           line_idx_0) - 1) << 14;
            acc1_idx_4 = (Steuerung_B.HoughLines[Steuerung_B.ntIdx1 + yElIdx] -
                          1) << 14;
          } else if (Steuerung_B.q2 == 0) {
            Steuerung_B.activeCol = 2;
            DrawShapes_DW_Polygon_tmp = 0;
            acc1_idx_2 = ((Steuerung_B.HoughLines[Steuerung_B.ntIdx1 + yElIdx] -
                           line_idx_0) - 1) << 14;
            acc1_idx_3 = ((Steuerung_B.HoughLines[Steuerung_B.ntIdx1 + yElIdx] +
                           line_idx_0) - 1) << 14;
            acc1_idx_4 = (Steuerung_B.HoughLines[Steuerung_B.ntIdx1] - 1) << 14;
          } else {
            Steuerung_B.activeCol = 0;
            DrawShapes_DW_Polygon_tmp = div_repeat_s32_floor(Steuerung_B.q2 <<
              14, acc4_idx_0 << 14, 14U);
            Steuerung_B.idxEdgeCur = ((Steuerung_B.HoughLines[Steuerung_B.ntIdx1
              + yElIdx] - 1) << 14) - mul_s32_loSR
              ((Steuerung_B.HoughLines[Steuerung_B.ntIdx1] - 1) << 14,
               DrawShapes_DW_Polygon_tmp, 14U);
            acc4_idx_0 = div_repeat_s32_floor(line_idx_0 << 14,
              div_repeat_s32_floor(acc4_idx_0 << 14,
              rt_sqrt_Us32En14_Ys16E_tOJnWsQ0((Steuerung_B.q2 * Steuerung_B.q2 +
              acc4_idx_0 * acc4_idx_0) << 14) << 7, 14U), 14U);
            acc1_idx_2 = Steuerung_B.idxEdgeCur + acc4_idx_0;
            acc1_idx_3 = Steuerung_B.idxEdgeCur - acc4_idx_0;
            acc1_idx_4 = ((Steuerung_B.HoughLines[Steuerung_B.ntIdx1 + yElIdx] -
                           1) << 14) + div_repeat_s32_floor
              ((Steuerung_B.HoughLines[Steuerung_B.ntIdx1] - 1) << 14,
               DrawShapes_DW_Polygon_tmp, 14U);
          }

          /* findPointOfIntersectionNormal-1
           */
          /* findPointOfIntersectionNormal- main fcn
           */
          if (Steuerung_B.activeCol == 1) {
            Steuerung_DW.DrawShapes_DW_Points[Steuerung_B.ntIdx1] = ((acc1_idx_2
              & 8192U) != 0U) + (acc1_idx_2 >> 14);
            Steuerung_B.col = ((acc1_idx_4 & 8192U) != 0U) + (acc1_idx_4 >> 14);
          } else if (Steuerung_B.activeCol == 2) {
            Steuerung_DW.DrawShapes_DW_Points[Steuerung_B.ntIdx1] = ((acc1_idx_4
              & 8192U) != 0U) + (acc1_idx_4 >> 14);
            Steuerung_B.col = ((acc1_idx_2 & 8192U) != 0U) + (acc1_idx_2 >> 14);
          } else {
            Steuerung_B.numActiveEdge = div_repeat_s32_floor(mul_s32_loSR
              (acc1_idx_4 - acc1_idx_2, DrawShapes_DW_Polygon_tmp, 14U),
              mul_s32_loSR(DrawShapes_DW_Polygon_tmp, DrawShapes_DW_Polygon_tmp,
                           14U) + 16384, 14U);
            Steuerung_DW.DrawShapes_DW_Points[Steuerung_B.ntIdx1] =
              ((Steuerung_B.numActiveEdge & 8192U) != 0U) +
              (Steuerung_B.numActiveEdge >> 14);
            Steuerung_B.numActiveEdge = mul_s32_loSR(DrawShapes_DW_Polygon_tmp,
              Steuerung_B.numActiveEdge, 14U) + acc1_idx_2;
            Steuerung_B.col = ((Steuerung_B.numActiveEdge & 8192U) != 0U) +
              (Steuerung_B.numActiveEdge >> 14);
          }

          Steuerung_DW.DrawShapes_DW_Points[Steuerung_B.idxEdgePre] =
            Steuerung_B.col;
          Steuerung_B.idxEdgePre = 2;

          /* findPointOfIntersectionNormal-2
           */
          /* findPointOfIntersectionNormal- main fcn
           */
          if (Steuerung_B.activeCol == 1) {
            acc4_idx_0 = ((acc1_idx_3 & 8192U) != 0U) + (acc1_idx_3 >> 14);
            Steuerung_DW.DrawShapes_DW_Points[Steuerung_B.ntIdx1 +
              (Steuerung_B.jRowsIn + 2) * yElIdx] = ((acc1_idx_4 & 8192U) != 0U)
              + (acc1_idx_4 >> 14);
          } else if (Steuerung_B.activeCol == 2) {
            acc4_idx_0 = ((acc1_idx_4 & 8192U) != 0U) + (acc1_idx_4 >> 14);
            Steuerung_DW.DrawShapes_DW_Points[Steuerung_B.ntIdx1 +
              (Steuerung_B.jRowsIn + 2) * yElIdx] = ((acc1_idx_3 & 8192U) != 0U)
              + (acc1_idx_3 >> 14);
          } else {
            Steuerung_B.numActiveEdge = div_repeat_s32_floor(mul_s32_loSR
              (acc1_idx_4 - acc1_idx_3, DrawShapes_DW_Polygon_tmp, 14U),
              mul_s32_loSR(DrawShapes_DW_Polygon_tmp, DrawShapes_DW_Polygon_tmp,
                           14U) + 16384, 14U);
            acc4_idx_0 = ((Steuerung_B.numActiveEdge & 8192U) != 0U) +
              (Steuerung_B.numActiveEdge >> 14);
            Steuerung_B.numActiveEdge = mul_s32_loSR(DrawShapes_DW_Polygon_tmp,
              Steuerung_B.numActiveEdge, 14U) + acc1_idx_3;
            Steuerung_DW.DrawShapes_DW_Points[Steuerung_B.ntIdx1 +
              (Steuerung_B.jRowsIn + 2) * yElIdx] = ((Steuerung_B.numActiveEdge
              & 8192U) != 0U) + (Steuerung_B.numActiveEdge >> 14);
          }

          Steuerung_DW.DrawShapes_DW_Points[Steuerung_B.ntIdx1 +
            (Steuerung_B.jRowsIn + 1) * yElIdx] = acc4_idx_0;
          Steuerung_B.idxEdgeCur = Steuerung_B.jRowsIn;
          if (Steuerung_B.imgRow == 4) {
            /* getLineParams-2
             */
            /* getLineParams-main fcn
             */
            acc4_idx_0 = Steuerung_B.HoughLines[Steuerung_B.ntIdx1] -
              Steuerung_B.HoughLines[(yElIdx << 1) + Steuerung_B.ntIdx1];
            if (acc4_idx_0 == 0) {
              DrawShapes_DW_Polygon_tmp = 0;
              Steuerung_B.activeCol = 1;
              acc1_idx_2 = ((Steuerung_B.HoughLines[Steuerung_B.ntIdx1] -
                             line_idx_0) - 1) << 14;
              acc1_idx_3 = ((Steuerung_B.HoughLines[Steuerung_B.ntIdx1] +
                             line_idx_0) - 1) << 14;
              acc1_idx_4 = (Steuerung_B.HoughLines[3 * yElIdx +
                            Steuerung_B.ntIdx1] - 1) << 14;
            } else if (Steuerung_B.q2 == 0) {
              Steuerung_B.activeCol = 2;
              DrawShapes_DW_Polygon_tmp = 0;
              acc1_idx_2 = ((Steuerung_B.HoughLines[Steuerung_B.ntIdx1 + yElIdx]
                             - line_idx_0) - 1) << 14;
              acc1_idx_3 = ((Steuerung_B.HoughLines[Steuerung_B.ntIdx1 + yElIdx]
                             + line_idx_0) - 1) << 14;
              acc1_idx_4 = (Steuerung_B.HoughLines[(yElIdx << 1) +
                            Steuerung_B.ntIdx1] - 1) << 14;
            } else {
              Steuerung_B.activeCol = 0;
              DrawShapes_DW_Polygon_tmp = div_repeat_s32_floor(Steuerung_B.q2 <<
                14, acc4_idx_0 << 14, 14U);
              Steuerung_B.idxEdgeCur =
                ((Steuerung_B.HoughLines[Steuerung_B.ntIdx1 + yElIdx] - 1) << 14)
                - mul_s32_loSR((Steuerung_B.HoughLines[Steuerung_B.ntIdx1] - 1) <<
                               14, DrawShapes_DW_Polygon_tmp, 14U);
              acc4_idx_0 = div_repeat_s32_floor(line_idx_0 << 14,
                div_repeat_s32_floor(acc4_idx_0 << 14,
                rt_sqrt_Us32En14_Ys16E_tOJnWsQ0((Steuerung_B.q2 * Steuerung_B.q2
                + acc4_idx_0 * acc4_idx_0) << 14) << 7, 14U), 14U);
              acc1_idx_2 = Steuerung_B.idxEdgeCur + acc4_idx_0;
              acc1_idx_3 = Steuerung_B.idxEdgeCur - acc4_idx_0;
              acc1_idx_4 = div_repeat_s32_floor((Steuerung_B.HoughLines[(yElIdx <<
                1) + Steuerung_B.ntIdx1] - 1) << 14, DrawShapes_DW_Polygon_tmp,
                14U) + ((Steuerung_B.HoughLines[3 * yElIdx + Steuerung_B.ntIdx1]
                         - 1) << 14);
            }

            /* findPointOfIntersectionNormal-3
             */
            /* findPointOfIntersectionNormal- main fcn
             */
            if (Steuerung_B.activeCol == 1) {
              Steuerung_DW.DrawShapes_DW_Points[Steuerung_B.ntIdx1 + (yElIdx <<
                1)] = ((acc1_idx_2 & 8192U) != 0U) + (acc1_idx_2 >> 14);
              Steuerung_B.col = ((acc1_idx_4 & 8192U) != 0U) + (acc1_idx_4 >> 14);
            } else if (Steuerung_B.activeCol == 2) {
              Steuerung_DW.DrawShapes_DW_Points[Steuerung_B.ntIdx1 + (yElIdx <<
                1)] = ((acc1_idx_4 & 8192U) != 0U) + (acc1_idx_4 >> 14);
              Steuerung_B.col = ((acc1_idx_2 & 8192U) != 0U) + (acc1_idx_2 >> 14);
            } else {
              Steuerung_B.numActiveEdge = div_repeat_s32_floor(mul_s32_loSR
                (acc1_idx_4 - acc1_idx_2, DrawShapes_DW_Polygon_tmp, 14U),
                mul_s32_loSR(DrawShapes_DW_Polygon_tmp,
                             DrawShapes_DW_Polygon_tmp, 14U) + 16384, 14U);
              Steuerung_DW.DrawShapes_DW_Points[Steuerung_B.ntIdx1 + (yElIdx <<
                1)] = ((Steuerung_B.numActiveEdge & 8192U) != 0U) +
                (Steuerung_B.numActiveEdge >> 14);
              Steuerung_B.numActiveEdge = mul_s32_loSR(DrawShapes_DW_Polygon_tmp,
                Steuerung_B.numActiveEdge, 14U) + acc1_idx_2;
              Steuerung_B.col = ((Steuerung_B.numActiveEdge & 8192U) != 0U) +
                (Steuerung_B.numActiveEdge >> 14);
            }

            Steuerung_DW.DrawShapes_DW_Points[Steuerung_B.ntIdx1 + 3 * yElIdx] =
              Steuerung_B.col;

            /* findPointOfIntersectionNormal-4
             */
            /* findPointOfIntersectionNormal- main fcn
             */
            if (Steuerung_B.activeCol == 1) {
              acc4_idx_0 = ((acc1_idx_3 & 8192U) != 0U) + (acc1_idx_3 >> 14);
              Steuerung_DW.DrawShapes_DW_Points[Steuerung_B.ntIdx1 +
                Steuerung_B.jRowsIn * yElIdx] = ((acc1_idx_4 & 8192U) != 0U) +
                (acc1_idx_4 >> 14);
            } else if (Steuerung_B.activeCol == 2) {
              acc4_idx_0 = ((acc1_idx_4 & 8192U) != 0U) + (acc1_idx_4 >> 14);
              Steuerung_DW.DrawShapes_DW_Points[Steuerung_B.ntIdx1 +
                Steuerung_B.jRowsIn * yElIdx] = ((acc1_idx_3 & 8192U) != 0U) +
                (acc1_idx_3 >> 14);
            } else {
              Steuerung_B.numActiveEdge = div_repeat_s32_floor(mul_s32_loSR
                (acc1_idx_4 - acc1_idx_3, DrawShapes_DW_Polygon_tmp, 14U),
                mul_s32_loSR(DrawShapes_DW_Polygon_tmp,
                             DrawShapes_DW_Polygon_tmp, 14U) + 16384, 14U);
              acc4_idx_0 = ((Steuerung_B.numActiveEdge & 8192U) != 0U) +
                (Steuerung_B.numActiveEdge >> 14);
              Steuerung_B.numActiveEdge = mul_s32_loSR(DrawShapes_DW_Polygon_tmp,
                Steuerung_B.numActiveEdge, 14U) + acc1_idx_3;
              Steuerung_DW.DrawShapes_DW_Points[Steuerung_B.ntIdx1 +
                Steuerung_B.jRowsIn * yElIdx] = ((Steuerung_B.numActiveEdge &
                8192U) != 0U) + (Steuerung_B.numActiveEdge >> 14);
            }

            Steuerung_DW.DrawShapes_DW_Points[Steuerung_B.ntIdx1 +
              (Steuerung_B.jRowsIn - 1) * yElIdx] = acc4_idx_0;
          } else {
            Steuerung_B.q2 = 4;
            while (Steuerung_B.q2 < Steuerung_B.imgRow) {
              if (Steuerung_B.q2 < Steuerung_B.imgRow) {
                Steuerung_B.mNumPtPerPolygon_new = Steuerung_B.q2;
              } else {
                Steuerung_B.mNumPtPerPolygon_new = Steuerung_B.q2 -
                  Steuerung_B.imgRow;
              }

              Steuerung_B.numActiveEdge = 0;
              if (Steuerung_B.imgRow - 2 == Steuerung_B.q2) {
                Steuerung_B.numActiveEdge = 1;
              }

              /* getLineParams-4
               */
              /* getLineParams-main fcn
               */
              Steuerung_B.col = (Steuerung_B.accumFour - Steuerung_B.HoughLines
                                 [(Steuerung_B.mNumPtPerPolygon_new + 1) *
                                 yElIdx + Steuerung_B.ntIdx1]) + 1;
              acc4_idx_0 = (Steuerung_B.accumThree -
                            Steuerung_B.HoughLines[Steuerung_B.mNumPtPerPolygon_new
                            * yElIdx + Steuerung_B.ntIdx1]) + 1;
              acc1_idx_4 = 0;
              if (acc4_idx_0 == 0) {
                acc2_idx_0 = 0;
                Steuerung_B.m = 1;
                acc2_idx_2 = (Steuerung_B.accumThree - line_idx_0) << 14;
                acc2_idx_1 = (Steuerung_B.accumThree + line_idx_0) << 14;
                if (Steuerung_B.numActiveEdge != 0) {
                  acc1_idx_4 = (Steuerung_B.HoughLines
                                [(Steuerung_B.mNumPtPerPolygon_new + 1) * yElIdx
                                + Steuerung_B.ntIdx1] - 1) << 14;
                }
              } else if (Steuerung_B.col == 0) {
                Steuerung_B.m = 2;
                acc2_idx_0 = 0;
                acc2_idx_2 = (Steuerung_B.accumFour - line_idx_0) << 14;
                acc2_idx_1 = (Steuerung_B.accumFour + line_idx_0) << 14;
                if (Steuerung_B.numActiveEdge != 0) {
                  acc1_idx_4 =
                    (Steuerung_B.HoughLines[Steuerung_B.mNumPtPerPolygon_new *
                     yElIdx + Steuerung_B.ntIdx1] - 1) << 14;
                }
              } else {
                Steuerung_B.m = 0;
                acc2_idx_0 = div_repeat_s32_floor(Steuerung_B.col << 14,
                  acc4_idx_0 << 14, 14U);
                acc2_idx_1 = (Steuerung_B.accumFour << 14) - mul_s32_loSR
                  (Steuerung_B.accumThree << 14, acc2_idx_0, 14U);
                acc4_idx_0 = div_repeat_s32_floor(line_idx_0 << 14,
                  div_repeat_s32_floor(acc4_idx_0 << 14,
                  rt_sqrt_Us32En14_Ys16E_tOJnWsQ0((Steuerung_B.col *
                  Steuerung_B.col + acc4_idx_0 * acc4_idx_0) << 14) << 7, 14U),
                  14U);
                acc2_idx_2 = acc2_idx_1 + acc4_idx_0;
                acc2_idx_1 -= acc4_idx_0;
                if (Steuerung_B.numActiveEdge != 0) {
                  acc1_idx_4 = ((Steuerung_B.HoughLines
                                 [(Steuerung_B.mNumPtPerPolygon_new + 1) *
                                 yElIdx + Steuerung_B.ntIdx1] - 1) << 14) +
                    div_repeat_s32_floor
                    ((Steuerung_B.HoughLines[Steuerung_B.mNumPtPerPolygon_new *
                      yElIdx + Steuerung_B.ntIdx1] - 1) << 14, acc2_idx_0, 14U);
                }
              }

              /* isValidPair- main fcn
               */
              if (Steuerung_B.activeCol == 1) {
                Steuerung_B.col = ((acc1_idx_2 & 8192U) != 0U) + (acc1_idx_2 >>
                  14);
                acc4_idx_0 = Steuerung_B.lastRow;
              } else if (Steuerung_B.activeCol == 2) {
                Steuerung_B.col = Steuerung_B.firstRow;
                acc4_idx_0 = ((acc1_idx_2 & 8192U) != 0U) + (acc1_idx_2 >> 14);
              } else {
                Steuerung_B.col = 0;
                acc4_idx_0 = ((acc1_idx_2 & 8192U) != 0U) + (acc1_idx_2 >> 14);
              }

              /* is_RightOfLine_CtrToRef- main fcn
               */
              numActiveEdge_tmp = Steuerung_B.accumThree - Steuerung_B.firstRow;
              numActiveEdge_tmp_0 = Steuerung_B.accumFour - Steuerung_B.lastRow;
              Steuerung_B.col -= Steuerung_B.firstRow;
              acc4_idx_0 -= Steuerung_B.lastRow;
              Steuerung_B.numActiveEdge = numActiveEdge_tmp * acc4_idx_0 -
                Steuerung_B.col * numActiveEdge_tmp_0;
              if (Steuerung_B.m == 1) {
                Steuerung_B.idxNew = ((acc2_idx_2 & 8192U) != 0U) + (acc2_idx_2 >>
                  14);
                Steuerung_B.idxOld = Steuerung_B.lastRow;
              } else if (Steuerung_B.m == 2) {
                Steuerung_B.idxNew = Steuerung_B.firstRow;
                Steuerung_B.idxOld = ((acc2_idx_2 & 8192U) != 0U) + (acc2_idx_2 >>
                  14);
              } else {
                Steuerung_B.idxNew = 0;
                Steuerung_B.idxOld = ((acc2_idx_2 & 8192U) != 0U) + (acc2_idx_2 >>
                  14);
              }

              /* is_RightOfLine_CtrToRef- main fcn
               */
              edgeTmp_tmp = (Steuerung_B.HoughLines
                             [(Steuerung_B.mNumPtPerPolygon_new + 1) * yElIdx +
                             Steuerung_B.ntIdx1] - Steuerung_B.accumFour) - 1;
              Steuerung_B.firstRow =
                (Steuerung_B.HoughLines[Steuerung_B.mNumPtPerPolygon_new *
                 yElIdx + Steuerung_B.ntIdx1] - Steuerung_B.accumThree) - 1;
              Steuerung_B.lastRow = Steuerung_B.idxNew - Steuerung_B.accumThree;
              Steuerung_B.idxOld -= Steuerung_B.accumFour;
              Steuerung_B.edgeTmp = Steuerung_B.firstRow * Steuerung_B.idxOld -
                edgeTmp_tmp * Steuerung_B.lastRow;
              if (((Steuerung_B.edgeTmp < 0) || ((!(Steuerung_B.edgeTmp > 0)) &&
                    (edgeTmp_tmp * edgeTmp_tmp + Steuerung_B.firstRow *
                     Steuerung_B.firstRow > Steuerung_B.lastRow *
                     Steuerung_B.lastRow + Steuerung_B.idxOld *
                     Steuerung_B.idxOld))) != ((Steuerung_B.numActiveEdge < 0) ||
                   ((!(Steuerung_B.numActiveEdge > 0)) && (numActiveEdge_tmp *
                     numActiveEdge_tmp + numActiveEdge_tmp_0 *
                     numActiveEdge_tmp_0 > Steuerung_B.col * Steuerung_B.col +
                     acc4_idx_0 * acc4_idx_0)))) {
                Steuerung_B.firstRow = acc2_idx_2;
                acc2_idx_2 = acc2_idx_1;
                acc2_idx_1 = Steuerung_B.firstRow;
              }

              /* findPointOfIntersection-1
               */
              /* findPointOfIntersection- main fcn
               */
              done = false;
              if (Steuerung_B.activeCol == 1) {
                done = true;
              }

              isMore = false;
              if (Steuerung_B.m == 1) {
                isMore = true;
              }

              if (done && isMore) {
                Steuerung_B.firstRow = ((acc1_idx_2 & 8192U) != 0U) +
                  (acc1_idx_2 >> 14);
                Steuerung_B.col = Steuerung_B.accumFour;
              } else if (done) {
                Steuerung_B.firstRow = ((acc1_idx_2 & 8192U) != 0U) +
                  (acc1_idx_2 >> 14);
                Steuerung_B.numActiveEdge = mul_s32_loSR(Steuerung_B.firstRow <<
                  14, acc2_idx_0, 14U) + acc2_idx_2;
                Steuerung_B.col = ((Steuerung_B.numActiveEdge & 8192U) != 0U) +
                  (Steuerung_B.numActiveEdge >> 14);
              } else if (isMore) {
                Steuerung_B.firstRow = ((acc2_idx_2 & 8192U) != 0U) +
                  (acc2_idx_2 >> 14);
                Steuerung_B.numActiveEdge = mul_s32_loSR(Steuerung_B.firstRow <<
                  14, DrawShapes_DW_Polygon_tmp, 14U) + acc1_idx_2;
                Steuerung_B.col = ((Steuerung_B.numActiveEdge & 8192U) != 0U) +
                  (Steuerung_B.numActiveEdge >> 14);
              } else {
                Steuerung_B.firstRow = DrawShapes_DW_Polygon_tmp - acc2_idx_0;
                if (Steuerung_B.firstRow == 0) {
                  Steuerung_B.firstRow = Steuerung_B.accumThree;
                  Steuerung_B.numActiveEdge = mul_s32_loSR
                    (Steuerung_B.accumThree << 14, DrawShapes_DW_Polygon_tmp,
                     14U) + acc1_idx_2;
                  Steuerung_B.col = ((Steuerung_B.numActiveEdge & 8192U) != 0U)
                    + (Steuerung_B.numActiveEdge >> 14);
                } else {
                  Steuerung_B.numActiveEdge = div_repeat_s32_floor(acc2_idx_2 -
                    acc1_idx_2, Steuerung_B.firstRow, 14U);
                  Steuerung_B.firstRow = ((Steuerung_B.numActiveEdge & 8192U) !=
                    0U) + (Steuerung_B.numActiveEdge >> 14);
                  Steuerung_B.numActiveEdge = mul_s32_loSR
                    (DrawShapes_DW_Polygon_tmp, Steuerung_B.numActiveEdge, 14U)
                    + acc1_idx_2;
                  Steuerung_B.col = ((Steuerung_B.numActiveEdge & 8192U) != 0U)
                    + (Steuerung_B.numActiveEdge >> 14);
                }
              }

              /* findPointOfIntersection-2
               */
              /* findPointOfIntersection- main fcn
               */
              done = false;
              if (Steuerung_B.activeCol == 1) {
                done = true;
              }

              isMore = false;
              if (Steuerung_B.m == 1) {
                isMore = true;
              }

              if (done && isMore) {
                acc4_idx_0 = ((acc1_idx_3 & 8192U) != 0U) + (acc1_idx_3 >> 14);
                Steuerung_B.activeCol = Steuerung_B.accumFour;
              } else if (done) {
                acc4_idx_0 = ((acc1_idx_3 & 8192U) != 0U) + (acc1_idx_3 >> 14);
                Steuerung_B.numActiveEdge = mul_s32_loSR(acc4_idx_0 << 14,
                  acc2_idx_0, 14U) + acc2_idx_1;
                Steuerung_B.activeCol = ((Steuerung_B.numActiveEdge & 8192U) !=
                  0U) + (Steuerung_B.numActiveEdge >> 14);
              } else if (isMore) {
                acc4_idx_0 = ((acc2_idx_1 & 8192U) != 0U) + (acc2_idx_1 >> 14);
                Steuerung_B.numActiveEdge = mul_s32_loSR(acc4_idx_0 << 14,
                  DrawShapes_DW_Polygon_tmp, 14U) + acc1_idx_3;
                Steuerung_B.activeCol = ((Steuerung_B.numActiveEdge & 8192U) !=
                  0U) + (Steuerung_B.numActiveEdge >> 14);
              } else {
                acc4_idx_0 = DrawShapes_DW_Polygon_tmp - acc2_idx_0;
                if (acc4_idx_0 == 0) {
                  acc4_idx_0 = Steuerung_B.accumThree;
                  Steuerung_B.numActiveEdge = mul_s32_loSR
                    (Steuerung_B.accumThree << 14, DrawShapes_DW_Polygon_tmp,
                     14U) + acc1_idx_3;
                  Steuerung_B.activeCol = ((Steuerung_B.numActiveEdge & 8192U)
                    != 0U) + (Steuerung_B.numActiveEdge >> 14);
                } else {
                  Steuerung_B.numActiveEdge = div_repeat_s32_floor(acc2_idx_1 -
                    acc1_idx_3, acc4_idx_0, 14U);
                  acc4_idx_0 = ((Steuerung_B.numActiveEdge & 8192U) != 0U) +
                    (Steuerung_B.numActiveEdge >> 14);
                  Steuerung_B.numActiveEdge = mul_s32_loSR
                    (DrawShapes_DW_Polygon_tmp, Steuerung_B.numActiveEdge, 14U)
                    + acc1_idx_3;
                  Steuerung_B.activeCol = ((Steuerung_B.numActiveEdge & 8192U)
                    != 0U) + (Steuerung_B.numActiveEdge >> 14);
                }
              }

              Steuerung_DW.DrawShapes_DW_Points[Steuerung_B.ntIdx1 +
                Steuerung_B.idxEdgePre * yElIdx] = Steuerung_B.firstRow;
              Steuerung_DW.DrawShapes_DW_Points[Steuerung_B.ntIdx1 +
                (Steuerung_B.idxEdgePre + 1) * yElIdx] = Steuerung_B.col;
              Steuerung_B.idxEdgePre += 2;
              Steuerung_DW.DrawShapes_DW_Points[Steuerung_B.ntIdx1 +
                Steuerung_B.idxEdgeCur * yElIdx] = Steuerung_B.activeCol;
              Steuerung_B.idxEdgeCur -= 2;
              Steuerung_DW.DrawShapes_DW_Points[Steuerung_B.ntIdx1 +
                (Steuerung_B.idxEdgeCur + 1) * yElIdx] = acc4_idx_0;
              Steuerung_B.firstRow = Steuerung_B.accumThree;
              Steuerung_B.lastRow = Steuerung_B.accumFour;
              Steuerung_B.accumThree =
                Steuerung_B.HoughLines[Steuerung_B.mNumPtPerPolygon_new * yElIdx
                + Steuerung_B.ntIdx1] - 1;
              Steuerung_B.accumFour = Steuerung_B.HoughLines
                [(Steuerung_B.mNumPtPerPolygon_new + 1) * yElIdx +
                Steuerung_B.ntIdx1] - 1;
              DrawShapes_DW_Polygon_tmp = acc2_idx_0;
              acc1_idx_2 = acc2_idx_2;
              acc1_idx_3 = acc2_idx_1;
              Steuerung_B.activeCol = Steuerung_B.m;
              Steuerung_B.q2 += 2;
            }

            /* findPointOfIntersectionNormal-5
             */
            /* findPointOfIntersectionNormal- main fcn
             */
            if (Steuerung_B.m == 1) {
              Steuerung_DW.DrawShapes_DW_Points[Steuerung_B.ntIdx1 +
                Steuerung_B.idxEdgePre * yElIdx] = ((acc1_idx_2 & 8192U) != 0U)
                + (acc1_idx_2 >> 14);
              Steuerung_B.col = ((acc1_idx_4 & 8192U) != 0U) + (acc1_idx_4 >> 14);
            } else if (Steuerung_B.m == 2) {
              Steuerung_DW.DrawShapes_DW_Points[Steuerung_B.ntIdx1 +
                Steuerung_B.idxEdgePre * yElIdx] = ((acc1_idx_4 & 8192U) != 0U)
                + (acc1_idx_4 >> 14);
              Steuerung_B.col = ((acc1_idx_2 & 8192U) != 0U) + (acc1_idx_2 >> 14);
            } else {
              Steuerung_B.numActiveEdge = div_repeat_s32_floor(mul_s32_loSR
                (acc1_idx_4 - acc1_idx_2, DrawShapes_DW_Polygon_tmp, 14U),
                mul_s32_loSR(DrawShapes_DW_Polygon_tmp,
                             DrawShapes_DW_Polygon_tmp, 14U) + 16384, 14U);
              Steuerung_DW.DrawShapes_DW_Points[Steuerung_B.ntIdx1 +
                Steuerung_B.idxEdgePre * yElIdx] = ((Steuerung_B.numActiveEdge &
                8192U) != 0U) + (Steuerung_B.numActiveEdge >> 14);
              Steuerung_B.numActiveEdge = mul_s32_loSR(DrawShapes_DW_Polygon_tmp,
                Steuerung_B.numActiveEdge, 14U) + acc1_idx_2;
              Steuerung_B.col = ((Steuerung_B.numActiveEdge & 8192U) != 0U) +
                (Steuerung_B.numActiveEdge >> 14);
            }

            Steuerung_DW.DrawShapes_DW_Points[Steuerung_B.ntIdx1 +
              (Steuerung_B.idxEdgePre + 1) * yElIdx] = Steuerung_B.col;

            /* findPointOfIntersectionNormal-6
             */
            /* findPointOfIntersectionNormal- main fcn
             */
            if (Steuerung_B.m == 1) {
              acc4_idx_0 = ((acc1_idx_3 & 8192U) != 0U) + (acc1_idx_3 >> 14);
              Steuerung_DW.DrawShapes_DW_Points[Steuerung_B.ntIdx1 +
                Steuerung_B.idxEdgeCur * yElIdx] = ((acc1_idx_4 & 8192U) != 0U)
                + (acc1_idx_4 >> 14);
            } else if (Steuerung_B.m == 2) {
              acc4_idx_0 = ((acc1_idx_4 & 8192U) != 0U) + (acc1_idx_4 >> 14);
              Steuerung_DW.DrawShapes_DW_Points[Steuerung_B.ntIdx1 +
                Steuerung_B.idxEdgeCur * yElIdx] = ((acc1_idx_3 & 8192U) != 0U)
                + (acc1_idx_3 >> 14);
            } else {
              Steuerung_B.numActiveEdge = div_repeat_s32_floor(mul_s32_loSR
                (acc1_idx_4 - acc1_idx_3, DrawShapes_DW_Polygon_tmp, 14U),
                mul_s32_loSR(DrawShapes_DW_Polygon_tmp,
                             DrawShapes_DW_Polygon_tmp, 14U) + 16384, 14U);
              acc4_idx_0 = ((Steuerung_B.numActiveEdge & 8192U) != 0U) +
                (Steuerung_B.numActiveEdge >> 14);
              Steuerung_B.numActiveEdge = mul_s32_loSR(DrawShapes_DW_Polygon_tmp,
                Steuerung_B.numActiveEdge, 14U) + acc1_idx_3;
              Steuerung_DW.DrawShapes_DW_Points[Steuerung_B.ntIdx1 +
                Steuerung_B.idxEdgeCur * yElIdx] = ((Steuerung_B.numActiveEdge &
                8192U) != 0U) + (Steuerung_B.numActiveEdge >> 14);
            }

            Steuerung_DW.DrawShapes_DW_Points[Steuerung_B.ntIdx1 +
              (Steuerung_B.idxEdgeCur - 1) * yElIdx] = acc4_idx_0;
          }

          Steuerung_B.ntIdx1++;
        }

        /* just before call for cgpolygon-2
         */
        Steuerung_B.uElOffset1 <<= 1;
      }

      /* ProcessStep-after poly points-1
       */
      /* just before call for cgpolygon
       */
      Steuerung_B.jRowsIn = yElIdx * Steuerung_B.uElOffset1;

      /* Reset scanline states. */
      Steuerung_B.ntIdx1 = 0;
      Steuerung_B.accumThree = 0;
      Steuerung_B.m = Steuerung_B.jRowsIn * 9;
      if (0 < Steuerung_B.m) {
        Steuerung_B.idxTmpArray[0U] = Steuerung_B.uElOffset1 - 1;
      }

      isMore = (0 < Steuerung_B.m);
      while (isMore) {
        /* Initialize the scanline. */
        /* Convert polygon vertices to boundaries. */
        Steuerung_B.accumFour = 0;
        Steuerung_B.idxEdgePre = Steuerung_B.ntIdx1;
        Steuerung_B.idxEdgeCur = Steuerung_B.ntIdx1;

        /* start for loop
         */
        Steuerung_B.activeCol = ((Steuerung_B.idxTmpArray[0] << 1) + 1) * yElIdx
          + Steuerung_B.accumThree;
        Steuerung_B.firstRow = (Steuerung_B.idxTmpArray[0] << 1) * yElIdx +
          Steuerung_B.accumThree;
        Steuerung_B.idxOld = Steuerung_B.idxTmpArray[0];
        Steuerung_B.lastRow = ((Steuerung_B.idxTmpArray[0] - 1) << 1) * yElIdx +
          Steuerung_B.accumThree;
        Steuerung_B.col = Steuerung_B.uElOffset1;
        if (Steuerung_P.DrawShapes_lineWidth > 1) {
          /* getLoc-1
           */
          acc4_idx_0 = Steuerung_DW.DrawShapes_DW_Points[Steuerung_B.firstRow];

          /* getLoc-1
           */
          Steuerung_B.imgRow =
            Steuerung_DW.DrawShapes_DW_Points[Steuerung_B.lastRow];
        } else {
          /* getLoc-2
           */
          acc4_idx_0 = Steuerung_B.HoughLines[Steuerung_B.firstRow];

          /* getLoc-2
           */
          Steuerung_B.imgRow = Steuerung_B.HoughLines[Steuerung_B.lastRow];
        }

        while ((Steuerung_B.lastRow >= 0) && (acc4_idx_0 - 1 ==
                Steuerung_B.imgRow - 1)) {
          Steuerung_B.idxOld--;
          Steuerung_B.lastRow = ((Steuerung_B.idxOld - 1) << 1) * yElIdx +
            Steuerung_B.accumThree;
          Steuerung_B.col--;
          if (Steuerung_P.DrawShapes_lineWidth > 1) {
            /* getLoc-1
             */
            Steuerung_B.imgRow =
              Steuerung_DW.DrawShapes_DW_Points[Steuerung_B.lastRow];
          } else {
            /* getLoc-2
             */
            Steuerung_B.imgRow = Steuerung_B.HoughLines[Steuerung_B.lastRow];
          }
        }

        if (Steuerung_B.lastRow < 0) {
          Steuerung_B.lastRow = 0;
        }

        if (Steuerung_P.DrawShapes_lineWidth > 1) {
          /* getLoc-1
           */
          acc4_idx_0 = Steuerung_DW.DrawShapes_DW_Points[Steuerung_B.firstRow];

          /* getLoc-1
           */
          Steuerung_B.numActiveEdge =
            Steuerung_DW.DrawShapes_DW_Points[Steuerung_B.lastRow];
        } else {
          /* getLoc-2
           */
          acc4_idx_0 = Steuerung_B.HoughLines[Steuerung_B.firstRow];

          /* getLoc-2
           */
          Steuerung_B.numActiveEdge = Steuerung_B.HoughLines[Steuerung_B.lastRow];
        }

        isMore = (Steuerung_B.numActiveEdge - 1 > acc4_idx_0 - 1);
        Steuerung_B.idxNew = yElIdx + Steuerung_B.accumThree;
        Steuerung_B.lastRow = Steuerung_B.accumThree;
        prevEdgeIsVertical = false;
        if (Steuerung_P.DrawShapes_lineWidth > 1) {
          /* getLoc-1
           */
          acc4_idx_0 = Steuerung_DW.DrawShapes_DW_Points[Steuerung_B.accumThree];

          /* getLoc-1
           */
          Steuerung_B.numActiveEdge =
            Steuerung_DW.DrawShapes_DW_Points[Steuerung_B.firstRow];
        } else {
          /* getLoc-2
           */
          acc4_idx_0 = Steuerung_B.HoughLines[Steuerung_B.accumThree];

          /* getLoc-2
           */
          Steuerung_B.numActiveEdge =
            Steuerung_B.HoughLines[Steuerung_B.firstRow];
        }

        done = (Steuerung_B.numActiveEdge - 1 == acc4_idx_0 - 1);
        Steuerung_B.imgRow = 0;
        while (Steuerung_B.imgRow < Steuerung_B.col) {
          if (Steuerung_P.DrawShapes_lineWidth > 1) {
            /* getLoc-1
             */
            acc4_idx_0 = Steuerung_DW.DrawShapes_DW_Points[Steuerung_B.lastRow];

            /* getLoc-1
             */
            Steuerung_B.numActiveEdge =
              Steuerung_DW.DrawShapes_DW_Points[Steuerung_B.firstRow];
          } else {
            /* getLoc-2
             */
            acc4_idx_0 = Steuerung_B.HoughLines[Steuerung_B.lastRow];

            /* getLoc-2
             */
            Steuerung_B.numActiveEdge =
              Steuerung_B.HoughLines[Steuerung_B.firstRow];
          }

          if (Steuerung_B.numActiveEdge - 1 != acc4_idx_0 - 1) {
            if (Steuerung_P.DrawShapes_lineWidth > 1) {
              /* getLoc-1
               */
              acc4_idx_0 = Steuerung_DW.DrawShapes_DW_Points[Steuerung_B.lastRow];

              /* getLoc-1
               */
              Steuerung_B.numActiveEdge =
                Steuerung_DW.DrawShapes_DW_Points[Steuerung_B.firstRow];
            } else {
              /* getLoc-2
               */
              acc4_idx_0 = Steuerung_B.HoughLines[Steuerung_B.lastRow];

              /* getLoc-2
               */
              Steuerung_B.numActiveEdge =
                Steuerung_B.HoughLines[Steuerung_B.firstRow];
            }

            if (Steuerung_B.numActiveEdge - 1 < acc4_idx_0 - 1) {
              countTwice = false;
            } else {
              countTwice = true;
              Steuerung_B.idxOld = Steuerung_B.activeCol;
              Steuerung_B.activeCol = Steuerung_B.idxNew;
              Steuerung_B.idxNew = Steuerung_B.idxOld;
              Steuerung_B.idxOld = Steuerung_B.firstRow;
              Steuerung_B.firstRow = Steuerung_B.lastRow;
              Steuerung_B.lastRow = Steuerung_B.idxOld;
            }

            if (Steuerung_P.DrawShapes_lineWidth > 1) {
              /* getLoc-1
               */
              acc4_idx_0 = Steuerung_DW.DrawShapes_DW_Points[Steuerung_B.lastRow];

              /* getLoc-1
               */
              Steuerung_B.numActiveEdge =
                Steuerung_DW.DrawShapes_DW_Points[Steuerung_B.idxNew];

              /* getLoc-1
               */
              Steuerung_B.idxOld =
                Steuerung_DW.DrawShapes_DW_Points[Steuerung_B.firstRow];

              /* getLoc-1
               */
              Steuerung_B.edgeTmp =
                Steuerung_DW.DrawShapes_DW_Points[Steuerung_B.activeCol];
            } else {
              /* getLoc-2
               */
              acc4_idx_0 = Steuerung_B.HoughLines[Steuerung_B.lastRow];

              /* getLoc-2
               */
              Steuerung_B.numActiveEdge =
                Steuerung_B.HoughLines[Steuerung_B.idxNew];

              /* getLoc-2
               */
              Steuerung_B.idxOld = Steuerung_B.HoughLines[Steuerung_B.firstRow];

              /* getLoc-2
               */
              Steuerung_B.edgeTmp = Steuerung_B.HoughLines[Steuerung_B.activeCol];
            }

            /* Initialize a Bresenham line. */
            DrawShapes_DW_Polygon_tmp = acc4_idx_0 - Steuerung_B.idxOld;
            Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxEdgeCur] = 0;
            Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxEdgeCur + 1] =
              Steuerung_B.edgeTmp - 1;
            Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxEdgeCur + 2] =
              Steuerung_B.idxOld - 1;
            Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxEdgeCur + 3] =
              acc4_idx_0 - 1;
            Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxEdgeCur + 6] = 0;
            if (Steuerung_B.numActiveEdge - 1 >= Steuerung_B.edgeTmp - 1) {
              Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxEdgeCur + 8] =
                Steuerung_B.numActiveEdge - Steuerung_B.edgeTmp;
            } else {
              Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxEdgeCur + 8] =
                Steuerung_B.edgeTmp - Steuerung_B.numActiveEdge;
            }

            while (Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxEdgeCur + 8]
                   >= 0) {
              Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxEdgeCur + 6]++;
              Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxEdgeCur + 8] -=
                DrawShapes_DW_Polygon_tmp;
            }

            Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxEdgeCur + 5] =
              Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxEdgeCur + 6] - 1;
            Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxEdgeCur + 7] =
              Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxEdgeCur + 8] +
              DrawShapes_DW_Polygon_tmp;
            Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxEdgeCur + 4] =
              DrawShapes_DW_Polygon_tmp -
              (Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxEdgeCur + 7] <<
               1);
            if (Steuerung_B.edgeTmp - 1 > Steuerung_B.numActiveEdge - 1) {
              Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxEdgeCur + 5] =
                -Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxEdgeCur + 5];
              Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxEdgeCur + 6] =
                -Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxEdgeCur + 6];
            }

            if ((!isMore) && (!countTwice)) {
              /* Use Bresenham algorithm to calculate the polygon boundaries at the next column */
              Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxEdgeCur + 2]++;
              if ((Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxEdgeCur] <<
                   1) >
                  Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxEdgeCur + 4])
              {
                Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxEdgeCur] +=
                  Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxEdgeCur + 8];
                Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxEdgeCur + 1] +=
                  Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxEdgeCur + 6];
              } else {
                Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxEdgeCur] +=
                  Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxEdgeCur + 7];
                Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxEdgeCur + 1] +=
                  Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxEdgeCur + 5];
              }
            } else {
              if (isMore && countTwice) {
                Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxEdgeCur + 3]--;
              }
            }

            isMore = countTwice;
            if (!prevEdgeIsVertical) {
              /* Merge two Bresenham lines. */
              if ((Steuerung_B.idxEdgePre != Steuerung_B.idxEdgeCur) &&
                  ((Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxEdgePre +
                    5] ==
                    Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxEdgeCur +
                    5]) &&
                   (Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxEdgePre +
                    6] ==
                    Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxEdgeCur +
                    6]) &&
                   (Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxEdgePre +
                    7] ==
                    Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxEdgeCur +
                    7]) &&
                   (Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxEdgePre +
                    8] ==
                    Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxEdgeCur +
                    8]))) {
                if (Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxEdgePre +
                    3] + 1 ==
                    Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxEdgeCur +
                    2]) {
                  Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxEdgePre + 3]
                    = Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxEdgeCur
                    + 3];
                  prevEdgeIsVertical = true;
                } else {
                  if (Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxEdgeCur
                      + 3] + 1 ==
                      Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxEdgePre
                      + 2]) {
                    Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxEdgePre +
                      1] =
                      Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxEdgeCur
                      + 1];
                    Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxEdgePre +
                      2] =
                      Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxEdgeCur
                      + 2];
                    prevEdgeIsVertical = true;
                  }
                }
              }

              if (!prevEdgeIsVertical) {
                Steuerung_B.idxEdgePre = Steuerung_B.idxEdgeCur;
                Steuerung_B.accumFour++;
              }
            } else {
              Steuerung_B.idxEdgePre = Steuerung_B.idxEdgeCur;
              Steuerung_B.accumFour++;
            }

            Steuerung_B.idxEdgeCur = Steuerung_B.idxEdgePre + 9;
            if (!countTwice) {
              Steuerung_B.activeCol = Steuerung_B.idxNew;
              Steuerung_B.firstRow = Steuerung_B.lastRow;
            }

            Steuerung_B.idxNew = (yElIdx << 1) + Steuerung_B.activeCol;
            Steuerung_B.lastRow = (yElIdx << 1) + Steuerung_B.firstRow;
            prevEdgeIsVertical = false;
          } else {
            prevEdgeIsVertical = true;
            Steuerung_B.activeCol = Steuerung_B.idxNew;
            Steuerung_B.firstRow = Steuerung_B.lastRow;
            Steuerung_B.idxNew += yElIdx << 1;
            Steuerung_B.lastRow += yElIdx << 1;
          }

          Steuerung_B.imgRow++;
        }

        if (!done) {
          /* Merge two Bresenham lines. */
          if ((Steuerung_B.ntIdx1 != Steuerung_B.idxEdgePre) &&
              ((Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.ntIdx1 + 5] ==
                Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxEdgePre + 5]) &&
               (Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.ntIdx1 + 6] ==
                Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxEdgePre + 6]) &&
               (Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.ntIdx1 + 7] ==
                Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxEdgePre + 7]) &&
               (Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.ntIdx1 + 8] ==
                Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxEdgePre + 8])))
          {
            if (Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.ntIdx1 + 3] + 1 ==
                Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxEdgePre + 2])
            {
              Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.ntIdx1 + 3] =
                Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxEdgePre + 3];
              done = true;
            } else {
              if (Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxEdgePre + 3]
                  + 1 == Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.ntIdx1 +
                  2]) {
                Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.ntIdx1 + 1] =
                  Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxEdgePre + 1];
                Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.ntIdx1 + 2] =
                  Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxEdgePre + 2];
                done = true;
              }
            }
          }

          if (done) {
            Steuerung_B.accumFour--;
            Steuerung_B.idxEdgeCur -= 9;
          }
        }

        /* Set all other edges to invalid. */
        Steuerung_B.imgRow = Steuerung_B.accumFour;
        while (Steuerung_B.imgRow < Steuerung_B.uElOffset1) {
          Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxEdgeCur + 2] = 1;
          Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxEdgeCur + 3] = 0;
          Steuerung_B.idxEdgeCur += 9;
          Steuerung_B.imgRow++;
        }

        /* Sort the boundaries of the polygon. */
        isMore = true;
        while (isMore) {
          Steuerung_B.idxNew = Steuerung_B.ntIdx1;
          Steuerung_B.idxOld = Steuerung_B.ntIdx1 + 9;
          isMore = false;
          Steuerung_B.imgRow = 1;
          while (Steuerung_B.imgRow < Steuerung_B.accumFour) {
            if (Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxNew + 2] >
                Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxOld + 2]) {
              isMore = true;
              for (acc4_idx_0 = 0; acc4_idx_0 < 9; acc4_idx_0++) {
                edgeTmp_tmp = Steuerung_B.idxNew + acc4_idx_0;
                Steuerung_B.edgeTmp =
                  Steuerung_DW.DrawShapes_DW_Polygon[edgeTmp_tmp];
                DrawShapes_DW_Polygon_tmp = Steuerung_B.idxOld + acc4_idx_0;
                Steuerung_DW.DrawShapes_DW_Polygon[edgeTmp_tmp] =
                  Steuerung_DW.DrawShapes_DW_Polygon[DrawShapes_DW_Polygon_tmp];
                Steuerung_DW.DrawShapes_DW_Polygon[DrawShapes_DW_Polygon_tmp] =
                  Steuerung_B.edgeTmp;
              }
            }

            Steuerung_B.idxNew = Steuerung_B.idxOld;
            Steuerung_B.idxOld += 9;
            Steuerung_B.imgRow++;
          }
        }

        /* Find out the last column of the polygon. */
        Steuerung_B.mNumPtPerPolygon_new = Steuerung_B.ntIdx1 + 3;
        Steuerung_B.q2 = Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.ntIdx1 +
          3];
        Steuerung_B.imgRow = 1;
        while (Steuerung_B.imgRow < Steuerung_B.accumFour) {
          Steuerung_B.mNumPtPerPolygon_new += 9;
          if (Steuerung_B.q2 <
              Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.mNumPtPerPolygon_new])
          {
            Steuerung_B.q2 =
              Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.mNumPtPerPolygon_new];
          }

          Steuerung_B.imgRow++;
        }

        line_idx_0 = Steuerung_B.q2;
        if (Steuerung_B.q2 > 79) {
          line_idx_0 = 79;
        }

        /* Find out the first column of the polygon. */
        Steuerung_B.mNumPtPerPolygon_new = Steuerung_B.ntIdx1 + 2;
        Steuerung_B.q2 = Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.ntIdx1 +
          2];
        Steuerung_B.imgRow = 1;
        while (Steuerung_B.imgRow < Steuerung_B.accumFour) {
          Steuerung_B.mNumPtPerPolygon_new += 9;
          if (Steuerung_B.q2 >
              Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.mNumPtPerPolygon_new])
          {
            Steuerung_B.q2 =
              Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.mNumPtPerPolygon_new];
          }

          Steuerung_B.imgRow++;
        }

        if (Steuerung_B.q2 < 0) {
          Steuerung_B.q2 = 0;
        }

        /* Move to the next column and find out boundaries of the polygon at this column. */
        Steuerung_B.idxNew = Steuerung_B.ntIdx1;
        Steuerung_B.idxOld = Steuerung_B.ntIdx1;
        Steuerung_B.mNumPtPerPolygon_new = Steuerung_B.ntIdx1;
        Steuerung_B.idxEdgePre = 0;
        Steuerung_B.numActiveEdge = 0;
        Steuerung_B.imgRow = 0;
        while (Steuerung_B.imgRow < Steuerung_B.accumFour) {
          /* Find out the valid boundaries and bring them to the latest column. */
          if (Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxOld + 3] >=
              Steuerung_B.q2) {
            if (Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxOld + 2] <=
                Steuerung_B.q2) {
              while (Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxOld + 2] <
                     Steuerung_B.q2) {
                /* Use Bresenham algorithm to calculate the polygon boundaries at the next column */
                Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxOld + 2]++;
                if ((Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxOld] << 1)
                    > Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxOld + 4])
                {
                  Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxOld] +=
                    Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxOld + 8];
                  Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxOld + 1] +=
                    Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxOld + 6];
                } else {
                  Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxOld] +=
                    Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxOld + 7];
                  Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxOld + 1] +=
                    Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxOld + 5];
                }
              }

              Steuerung_B.mNumPtPerPolygon_new += 9;
              Steuerung_B.numActiveEdge++;
            }

            if (Steuerung_B.idxOld != Steuerung_B.idxNew) {
              for (acc4_idx_0 = 0; acc4_idx_0 < 9; acc4_idx_0++) {
                Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxNew +
                  acc4_idx_0] =
                  Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxOld +
                  acc4_idx_0];
              }
            }

            Steuerung_B.idxNew += 9;
            Steuerung_B.idxEdgePre++;
          }

          Steuerung_B.idxOld += 9;
          Steuerung_B.imgRow++;
        }

        /* Sort the boundaries of the polygon according to row values. */
        /* Sort the boundaries of the polygon. */
        isMore = true;
        while (isMore) {
          Steuerung_B.idxNew = Steuerung_B.ntIdx1;
          Steuerung_B.idxOld = Steuerung_B.ntIdx1 + 9;
          isMore = false;
          Steuerung_B.imgRow = 1;
          while (Steuerung_B.imgRow < Steuerung_B.numActiveEdge) {
            if (Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxNew + 1] >
                Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxOld + 1]) {
              isMore = true;
              for (acc4_idx_0 = 0; acc4_idx_0 < 9; acc4_idx_0++) {
                edgeTmp_tmp = Steuerung_B.idxNew + acc4_idx_0;
                Steuerung_B.edgeTmp =
                  Steuerung_DW.DrawShapes_DW_Polygon[edgeTmp_tmp];
                DrawShapes_DW_Polygon_tmp = Steuerung_B.idxOld + acc4_idx_0;
                Steuerung_DW.DrawShapes_DW_Polygon[edgeTmp_tmp] =
                  Steuerung_DW.DrawShapes_DW_Polygon[DrawShapes_DW_Polygon_tmp];
                Steuerung_DW.DrawShapes_DW_Polygon[DrawShapes_DW_Polygon_tmp] =
                  Steuerung_B.edgeTmp;
              }
            }

            Steuerung_B.idxNew = Steuerung_B.idxOld;
            Steuerung_B.idxOld += 9;
            Steuerung_B.imgRow++;
          }
        }

        Steuerung_B.numActiveEdge = Steuerung_B.ntIdx1;
        Steuerung_B.idxEdgeCur = Steuerung_B.q2 + 1;
        Steuerung_B.activeCol = 0;
        Steuerung_B.idxNew = 0;
        Steuerung_B.idxOld = -1;
        isMore = (0 <= line_idx_0);
        while (isMore) {
          /* Get a string of pixels */
          countTwice = false;
          done = (Steuerung_B.idxNew != 0);
          Steuerung_B.col = Steuerung_B.activeCol;
          if ((Steuerung_B.activeCol >= Steuerung_B.q2) &&
              (Steuerung_B.activeCol <= line_idx_0)) {
            if (Steuerung_B.numActiveEdge < Steuerung_B.mNumPtPerPolygon_new) {
              Steuerung_B.imgRow =
                Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.numActiveEdge + 1];
              Steuerung_B.numActiveEdge += 9;
              if ((Steuerung_B.imgRow == Steuerung_B.idxOld) &&
                  (Steuerung_B.numActiveEdge < Steuerung_B.mNumPtPerPolygon_new))
              {
                Steuerung_B.accumFour =
                  Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.numActiveEdge +
                  1];
                isMore = (Steuerung_B.numActiveEdge <
                          Steuerung_B.mNumPtPerPolygon_new);
                while (isMore && (Steuerung_B.imgRow == Steuerung_B.accumFour))
                {
                  countTwice = true;
                  Steuerung_B.imgRow =
                    Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.numActiveEdge
                    + 1];
                  Steuerung_B.numActiveEdge += 9;
                  isMore = (Steuerung_B.numActiveEdge <
                            Steuerung_B.mNumPtPerPolygon_new);
                  if (isMore) {
                    Steuerung_B.accumFour =
                      Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.numActiveEdge
                      + 1];
                  }
                }

                if (!isMore) {
                  countTwice = false;
                }
              }

              if (Steuerung_B.idxNew != 0) {
                Steuerung_B.firstRow = Steuerung_B.idxOld;
                if (Steuerung_B.imgRow <= 60) {
                  Steuerung_B.lastRow = Steuerung_B.imgRow;
                  Steuerung_B.idxOld = Steuerung_B.imgRow;
                } else {
                  Steuerung_B.lastRow = 60;
                  Steuerung_B.idxOld = 60;
                }
              } else {
                Steuerung_B.firstRow = Steuerung_B.idxOld + 1;
                if ((Steuerung_B.imgRow > 0) && (Steuerung_B.imgRow <= 60)) {
                  Steuerung_B.lastRow = Steuerung_B.imgRow - 1;
                  Steuerung_B.idxOld = Steuerung_B.imgRow;
                } else if (Steuerung_B.imgRow <= 0) {
                  Steuerung_B.lastRow = -1;
                  Steuerung_B.idxOld = 0;
                } else {
                  Steuerung_B.lastRow = 60;
                  Steuerung_B.idxOld = 61;
                }
              }

              if (!countTwice) {
                Steuerung_B.idxNew = !(Steuerung_B.idxNew != 0);
              }
            } else {
              /* Reset states and move to the next column. */
              done = false;
              Steuerung_B.firstRow = Steuerung_B.idxOld + 1;
              Steuerung_B.lastRow = 60;

              /* Move to the next column and find out boundaries of the polygon at this column. */
              Steuerung_B.idxNew = Steuerung_B.ntIdx1;
              Steuerung_B.idxOld = Steuerung_B.ntIdx1;
              Steuerung_B.mNumPtPerPolygon_new = Steuerung_B.ntIdx1;
              Steuerung_B.accumFour = 0;
              Steuerung_B.numActiveEdge = 0;
              Steuerung_B.imgRow = 0;
              while (Steuerung_B.imgRow < Steuerung_B.idxEdgePre) {
                /* Find out the valid boundaries and bring them to the latest column. */
                if (Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxOld + 3] >=
                    Steuerung_B.idxEdgeCur) {
                  if (Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxOld + 2]
                      <= Steuerung_B.idxEdgeCur) {
                    while (Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxOld
                           + 2] < Steuerung_B.idxEdgeCur) {
                      /* Use Bresenham algorithm to calculate the polygon boundaries at the next column */
                      Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxOld + 2]
                        ++;
                      if ((Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxOld]
                           << 1) >
                          Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxOld
                          + 4]) {
                        Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxOld] +=
                          Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxOld
                          + 8];
                        Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxOld +
                          1] +=
                          Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxOld
                          + 6];
                      } else {
                        Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxOld] +=
                          Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxOld
                          + 7];
                        Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxOld +
                          1] +=
                          Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxOld
                          + 5];
                      }
                    }

                    Steuerung_B.mNumPtPerPolygon_new += 9;
                    Steuerung_B.numActiveEdge++;
                  }

                  if (Steuerung_B.idxOld != Steuerung_B.idxNew) {
                    for (acc4_idx_0 = 0; acc4_idx_0 < 9; acc4_idx_0++) {
                      Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxNew +
                        acc4_idx_0] =
                        Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxOld +
                        acc4_idx_0];
                    }
                  }

                  Steuerung_B.idxNew += 9;
                  Steuerung_B.accumFour++;
                }

                Steuerung_B.idxOld += 9;
                Steuerung_B.imgRow++;
              }

              Steuerung_B.idxEdgePre = Steuerung_B.accumFour;

              /* Sort the boundaries of the polygon according to row values. */
              /* Sort the boundaries of the polygon. */
              while (isMore) {
                Steuerung_B.idxNew = Steuerung_B.ntIdx1;
                Steuerung_B.idxOld = Steuerung_B.ntIdx1 + 9;
                isMore = false;
                Steuerung_B.imgRow = 1;
                while (Steuerung_B.imgRow < Steuerung_B.numActiveEdge) {
                  if (Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxNew + 1]
                      > Steuerung_DW.DrawShapes_DW_Polygon[Steuerung_B.idxOld +
                      1]) {
                    isMore = true;
                    for (acc4_idx_0 = 0; acc4_idx_0 < 9; acc4_idx_0++) {
                      edgeTmp_tmp = Steuerung_B.idxNew + acc4_idx_0;
                      Steuerung_B.edgeTmp =
                        Steuerung_DW.DrawShapes_DW_Polygon[edgeTmp_tmp];
                      DrawShapes_DW_Polygon_tmp = Steuerung_B.idxOld +
                        acc4_idx_0;
                      Steuerung_DW.DrawShapes_DW_Polygon[edgeTmp_tmp] =
                        Steuerung_DW.DrawShapes_DW_Polygon[DrawShapes_DW_Polygon_tmp];
                      Steuerung_DW.DrawShapes_DW_Polygon[DrawShapes_DW_Polygon_tmp]
                        = Steuerung_B.edgeTmp;
                    }
                  }

                  Steuerung_B.idxNew = Steuerung_B.idxOld;
                  Steuerung_B.idxOld += 9;
                  Steuerung_B.imgRow++;
                }
              }

              Steuerung_B.numActiveEdge = Steuerung_B.ntIdx1;
              Steuerung_B.idxEdgeCur++;
              Steuerung_B.idxNew = 0;
              Steuerung_B.idxOld = -1;
              Steuerung_B.activeCol++;
            }
          } else {
            Steuerung_B.firstRow = 0;
            Steuerung_B.lastRow = 60;
            Steuerung_B.activeCol++;
          }

          if (Steuerung_B.firstRow < 0) {
            Steuerung_B.firstRow = 0;
          }

          if (Steuerung_B.lastRow < Steuerung_B.firstRow) {
            Steuerung_B.lastRow = Steuerung_B.firstRow - 1;
          }

          if (done) {
            Steuerung_B.edgeTmp = Steuerung_B.col * 61 + Steuerung_B.firstRow;
            DrawShapes_DW_Polygon_tmp = 1;
            if (Steuerung_P.DrawShapes_lineWidth > 1) {
              DrawShapes_DW_Polygon_tmp = 0;
            }

            acc4_idx_0 = Steuerung_B.edgeTmp;
            Steuerung_B.imgRow = Steuerung_B.firstRow;
            while (Steuerung_B.imgRow <= Steuerung_B.lastRow) {
              if (DrawShapes_DW_Polygon_tmp != 0) {
                Steuerung_B.Image_Lines_1[acc4_idx_0] = (uint8_T)(((int32_T)
                  ((uint32_T)Steuerung_B.Image_Lines_1[acc4_idx_0] *
                   Steuerung_B.Image_Lines_1[0]) << 14) >> 14);
                Steuerung_B.Image_Lines_1[acc4_idx_0] = (uint8_T)((uint32_T)
                  Steuerung_B.Image_Lines_1[acc4_idx_0] +
                  Steuerung_P.DrawShapes_RTP_FILLCOLOR[0]);
              } else {
                Steuerung_B.Image_Lines_1[acc4_idx_0] =
                  Steuerung_P.DrawShapes_RTP_FILLCOLOR[0];
              }

              acc4_idx_0++;
              Steuerung_B.imgRow++;
            }

            Steuerung_B.edgeTmp += 4880;
            DrawShapes_DW_Polygon_tmp = 1;
            if (Steuerung_P.DrawShapes_lineWidth > 1) {
              DrawShapes_DW_Polygon_tmp = 0;
            }

            acc4_idx_0 = Steuerung_B.edgeTmp;
            Steuerung_B.imgRow = Steuerung_B.firstRow;
            while (Steuerung_B.imgRow <= Steuerung_B.lastRow) {
              if (DrawShapes_DW_Polygon_tmp != 0) {
                Steuerung_B.Image_Lines_1[acc4_idx_0] = (uint8_T)(((int32_T)
                  ((uint32_T)Steuerung_B.Image_Lines_1[acc4_idx_0] *
                   Steuerung_B.Image_Lines_1[0]) << 14) >> 14);
                Steuerung_B.Image_Lines_1[acc4_idx_0] = (uint8_T)((uint32_T)
                  Steuerung_B.Image_Lines_1[acc4_idx_0] +
                  Steuerung_P.DrawShapes_RTP_FILLCOLOR[1]);
              } else {
                Steuerung_B.Image_Lines_1[acc4_idx_0] =
                  Steuerung_P.DrawShapes_RTP_FILLCOLOR[1];
              }

              acc4_idx_0++;
              Steuerung_B.imgRow++;
            }

            acc4_idx_0 = Steuerung_B.edgeTmp + 4880;
            DrawShapes_DW_Polygon_tmp = 1;
            if (Steuerung_P.DrawShapes_lineWidth > 1) {
              DrawShapes_DW_Polygon_tmp = 0;
            }

            Steuerung_B.imgRow = Steuerung_B.firstRow;
            while (Steuerung_B.imgRow <= Steuerung_B.lastRow) {
              if (DrawShapes_DW_Polygon_tmp != 0) {
                Steuerung_B.Image_Lines_1[acc4_idx_0] = (uint8_T)(((int32_T)
                  ((uint32_T)Steuerung_B.Image_Lines_1[acc4_idx_0] *
                   Steuerung_B.Image_Lines_1[0]) << 14) >> 14);
                Steuerung_B.Image_Lines_1[acc4_idx_0] = (uint8_T)((uint32_T)
                  Steuerung_B.Image_Lines_1[acc4_idx_0] +
                  Steuerung_P.DrawShapes_RTP_FILLCOLOR[2]);
              } else {
                Steuerung_B.Image_Lines_1[acc4_idx_0] =
                  Steuerung_P.DrawShapes_RTP_FILLCOLOR[2];
              }

              acc4_idx_0++;
              Steuerung_B.imgRow++;
            }
          }

          isMore = (Steuerung_B.activeCol <= line_idx_0);
        }

        /* Move to the next polygon. */
        Steuerung_B.ntIdx1 += Steuerung_B.uElOffset1 * 9;
        if (Steuerung_B.accumThree >= div_s32_floor(Steuerung_B.jRowsIn,
             Steuerung_B.uElOffset1) - 1) {
          Steuerung_B.accumThree = 0;
        } else {
          Steuerung_B.accumThree++;
        }

        isMore = (Steuerung_B.ntIdx1 < Steuerung_B.m);
      }
    }
  }

  /* End of S-Function (svipdrawshapes): '<S3>/Draw Shapes' */
  /* S-Function (PCF8591): '<Root>/PCF8591' */
  PCF8591_Outputs_wrapper(&Steuerung_B.PCF8591[0], &Steuerung_DW.PCF8591_DSTATE);

  /* S-Function (MCU6050): '<Root>/MCU6050' */
  MCU6050_Outputs_wrapper(&Steuerung_B.MCU6050_o1, &Steuerung_B.MCU6050_o2,
    &Steuerung_B.MCU6050_o3, &Steuerung_B.MCU6050_o4, &Steuerung_B.MCU6050_o5,
    &Steuerung_B.MCU6050_o6, &Steuerung_B.MCU6050_o7,
    &Steuerung_DW.MCU6050_DSTATE[0]);

  /* Update for Delay: '<S8>/UD' */
  Steuerung_DW.UD_DSTATE = Steuerung_B.Add1;

  /* Update for S-Function (PCA6585): '<Root>/PCA6585' */

  /* S-Function "PCA6585_wrapper" Block: <Root>/PCA6585 */
  PCA6585_Update_wrapper(&Steuerung_B.LogicalOperator2,
    &Steuerung_B.LogicalOperator1, &Steuerung_B.DataTypeConversion1,
    &Steuerung_B.DataTypeConversion3, &Steuerung_DW.PCA6585_DSTATE[0]);

  /* Update for S-Function (PCF8591): '<Root>/PCF8591' */

  /* S-Function "PCF8591_wrapper" Block: <Root>/PCF8591 */
  PCF8591_Update_wrapper(&Steuerung_B.PCF8591[0], &Steuerung_DW.PCF8591_DSTATE);

  /* Update for S-Function (MCU6050): '<Root>/MCU6050' */

  /* S-Function "MCU6050_wrapper" Block: <Root>/MCU6050 */
  MCU6050_Update_wrapper(&Steuerung_B.MCU6050_o1, &Steuerung_B.MCU6050_o2,
    &Steuerung_B.MCU6050_o3, &Steuerung_B.MCU6050_o4, &Steuerung_B.MCU6050_o5,
    &Steuerung_B.MCU6050_o6, &Steuerung_B.MCU6050_o7,
    &Steuerung_DW.MCU6050_DSTATE[0]);

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.1s, 0.0s] */
    rtExtModeUpload(0, Steuerung_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.1s, 0.0s] */
    if ((rtmGetTFinal(Steuerung_M)!=-1) &&
        !((rtmGetTFinal(Steuerung_M)-Steuerung_M->Timing.taskTime0) >
          Steuerung_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(Steuerung_M, "Simulation finished");
    }

    if (rtmGetStopRequested(Steuerung_M)) {
      rtmSetErrorStatus(Steuerung_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Steuerung_M->Timing.taskTime0 =
    (++Steuerung_M->Timing.clockTick0) * Steuerung_M->Timing.stepSize0;
}

/* Model initialize function */
void Steuerung_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Steuerung_M, 0,
                sizeof(RT_MODEL_Steuerung_T));
  rtmSetTFinal(Steuerung_M, -1);
  Steuerung_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  Steuerung_M->Sizes.checksums[0] = (2511292437U);
  Steuerung_M->Sizes.checksums[1] = (563146016U);
  Steuerung_M->Sizes.checksums[2] = (595279931U);
  Steuerung_M->Sizes.checksums[3] = (3472454600U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[9];
    Steuerung_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Steuerung_M->extModeInfo,
      &Steuerung_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Steuerung_M->extModeInfo, Steuerung_M->Sizes.checksums);
    rteiSetTPtr(Steuerung_M->extModeInfo, rtmGetTPtr(Steuerung_M));
  }

  /* block I/O */
  (void) memset(((void *) &Steuerung_B), 0,
                sizeof(B_Steuerung_T));

  {
    Steuerung_B.HoughTransform_o2[0] = -1.5707963267948966;
    Steuerung_B.HoughTransform_o2[1] = -1.5533430342749532;
    Steuerung_B.HoughTransform_o2[2] = -1.53588974175501;
    Steuerung_B.HoughTransform_o2[3] = -1.5184364492350666;
    Steuerung_B.HoughTransform_o2[4] = -1.5009831567151235;
    Steuerung_B.HoughTransform_o2[5] = -1.4835298641951802;
    Steuerung_B.HoughTransform_o2[6] = -1.4660765716752369;
    Steuerung_B.HoughTransform_o2[7] = -1.4486232791552935;
    Steuerung_B.HoughTransform_o2[8] = -1.4311699866353502;
    Steuerung_B.HoughTransform_o2[9] = -1.4137166941154069;
    Steuerung_B.HoughTransform_o2[10] = -1.3962634015954636;
    Steuerung_B.HoughTransform_o2[11] = -1.3788101090755203;
    Steuerung_B.HoughTransform_o2[12] = -1.3613568165555769;
    Steuerung_B.HoughTransform_o2[13] = -1.3439035240356338;
    Steuerung_B.HoughTransform_o2[14] = -1.3264502315156905;
    Steuerung_B.HoughTransform_o2[15] = -1.3089969389957472;
    Steuerung_B.HoughTransform_o2[16] = -1.2915436464758039;
    Steuerung_B.HoughTransform_o2[17] = -1.2740903539558606;
    Steuerung_B.HoughTransform_o2[18] = -1.2566370614359172;
    Steuerung_B.HoughTransform_o2[19] = -1.2391837689159739;
    Steuerung_B.HoughTransform_o2[20] = -1.2217304763960306;
    Steuerung_B.HoughTransform_o2[21] = -1.2042771838760873;
    Steuerung_B.HoughTransform_o2[22] = -1.1868238913561442;
    Steuerung_B.HoughTransform_o2[23] = -1.1693705988362009;
    Steuerung_B.HoughTransform_o2[24] = -1.1519173063162575;
    Steuerung_B.HoughTransform_o2[25] = -1.1344640137963142;
    Steuerung_B.HoughTransform_o2[26] = -1.1170107212763709;
    Steuerung_B.HoughTransform_o2[27] = -1.0995574287564276;
    Steuerung_B.HoughTransform_o2[28] = -1.0821041362364843;
    Steuerung_B.HoughTransform_o2[29] = -1.064650843716541;
    Steuerung_B.HoughTransform_o2[30] = -1.0471975511965976;
    Steuerung_B.HoughTransform_o2[31] = -1.0297442586766545;
    Steuerung_B.HoughTransform_o2[32] = -1.0122909661567112;
    Steuerung_B.HoughTransform_o2[33] = -0.99483767363676789;
    Steuerung_B.HoughTransform_o2[34] = -0.97738438111682457;
    Steuerung_B.HoughTransform_o2[35] = -0.95993108859688125;
    Steuerung_B.HoughTransform_o2[36] = -0.94247779607693793;
    Steuerung_B.HoughTransform_o2[37] = -0.92502450355699462;
    Steuerung_B.HoughTransform_o2[38] = -0.90757121103705141;
    Steuerung_B.HoughTransform_o2[39] = -0.89011791851710809;
    Steuerung_B.HoughTransform_o2[40] = -0.87266462599716477;
    Steuerung_B.HoughTransform_o2[41] = -0.85521133347722145;
    Steuerung_B.HoughTransform_o2[42] = -0.83775804095727824;
    Steuerung_B.HoughTransform_o2[43] = -0.82030474843733492;
    Steuerung_B.HoughTransform_o2[44] = -0.8028514559173916;
    Steuerung_B.HoughTransform_o2[45] = -0.78539816339744828;
    Steuerung_B.HoughTransform_o2[46] = -0.767944870877505;
    Steuerung_B.HoughTransform_o2[47] = -0.75049157835756175;
    Steuerung_B.HoughTransform_o2[48] = -0.73303828583761843;
    Steuerung_B.HoughTransform_o2[49] = -0.71558499331767511;
    Steuerung_B.HoughTransform_o2[50] = -0.69813170079773179;
    Steuerung_B.HoughTransform_o2[51] = -0.68067840827778847;
    Steuerung_B.HoughTransform_o2[52] = -0.66322511575784526;
    Steuerung_B.HoughTransform_o2[53] = -0.64577182323790194;
    Steuerung_B.HoughTransform_o2[54] = -0.62831853071795862;
    Steuerung_B.HoughTransform_o2[55] = -0.6108652381980153;
    Steuerung_B.HoughTransform_o2[56] = -0.59341194567807209;
    Steuerung_B.HoughTransform_o2[57] = -0.57595865315812877;
    Steuerung_B.HoughTransform_o2[58] = -0.55850536063818546;
    Steuerung_B.HoughTransform_o2[59] = -0.54105206811824214;
    Steuerung_B.HoughTransform_o2[60] = -0.52359877559829882;
    Steuerung_B.HoughTransform_o2[61] = -0.50614548307835561;
    Steuerung_B.HoughTransform_o2[62] = -0.48869219055841229;
    Steuerung_B.HoughTransform_o2[63] = -0.47123889803846897;
    Steuerung_B.HoughTransform_o2[64] = -0.4537856055185257;
    Steuerung_B.HoughTransform_o2[65] = -0.43633231299858238;
    Steuerung_B.HoughTransform_o2[66] = -0.41887902047863912;
    Steuerung_B.HoughTransform_o2[67] = -0.4014257279586958;
    Steuerung_B.HoughTransform_o2[68] = -0.38397243543875248;
    Steuerung_B.HoughTransform_o2[69] = -0.36651914291880922;
    Steuerung_B.HoughTransform_o2[70] = -0.3490658503988659;
    Steuerung_B.HoughTransform_o2[71] = -0.33161255787892263;
    Steuerung_B.HoughTransform_o2[72] = -0.31415926535897931;
    Steuerung_B.HoughTransform_o2[73] = -0.29670597283903605;
    Steuerung_B.HoughTransform_o2[74] = -0.27925268031909273;
    Steuerung_B.HoughTransform_o2[75] = -0.26179938779914941;
    Steuerung_B.HoughTransform_o2[76] = -0.24434609527920614;
    Steuerung_B.HoughTransform_o2[77] = -0.22689280275926285;
    Steuerung_B.HoughTransform_o2[78] = -0.20943951023931956;
    Steuerung_B.HoughTransform_o2[79] = -0.19198621771937624;
    Steuerung_B.HoughTransform_o2[80] = -0.17453292519943295;
    Steuerung_B.HoughTransform_o2[81] = -0.15707963267948966;
    Steuerung_B.HoughTransform_o2[82] = -0.13962634015954636;
    Steuerung_B.HoughTransform_o2[83] = -0.12217304763960307;
    Steuerung_B.HoughTransform_o2[84] = -0.10471975511965978;
    Steuerung_B.HoughTransform_o2[85] = -0.087266462599716474;
    Steuerung_B.HoughTransform_o2[86] = -0.069813170079773182;
    Steuerung_B.HoughTransform_o2[87] = -0.05235987755982989;
    Steuerung_B.HoughTransform_o2[88] = -0.034906585039886591;
    Steuerung_B.HoughTransform_o2[89] = -0.017453292519943295;
    Steuerung_B.HoughTransform_o2[90] = 0.0;
    Steuerung_B.HoughTransform_o2[91] = 0.017453292519943295;
    Steuerung_B.HoughTransform_o2[92] = 0.034906585039886591;
    Steuerung_B.HoughTransform_o2[93] = 0.05235987755982989;
    Steuerung_B.HoughTransform_o2[94] = 0.069813170079773182;
    Steuerung_B.HoughTransform_o2[95] = 0.087266462599716474;
    Steuerung_B.HoughTransform_o2[96] = 0.10471975511965978;
    Steuerung_B.HoughTransform_o2[97] = 0.12217304763960307;
    Steuerung_B.HoughTransform_o2[98] = 0.13962634015954636;
    Steuerung_B.HoughTransform_o2[99] = 0.15707963267948966;
    Steuerung_B.HoughTransform_o2[100] = 0.17453292519943295;
    Steuerung_B.HoughTransform_o2[101] = 0.19198621771937624;
    Steuerung_B.HoughTransform_o2[102] = 0.20943951023931956;
    Steuerung_B.HoughTransform_o2[103] = 0.22689280275926285;
    Steuerung_B.HoughTransform_o2[104] = 0.24434609527920614;
    Steuerung_B.HoughTransform_o2[105] = 0.26179938779914941;
    Steuerung_B.HoughTransform_o2[106] = 0.27925268031909273;
    Steuerung_B.HoughTransform_o2[107] = 0.29670597283903605;
    Steuerung_B.HoughTransform_o2[108] = 0.31415926535897931;
    Steuerung_B.HoughTransform_o2[109] = 0.33161255787892263;
    Steuerung_B.HoughTransform_o2[110] = 0.3490658503988659;
    Steuerung_B.HoughTransform_o2[111] = 0.36651914291880922;
    Steuerung_B.HoughTransform_o2[112] = 0.38397243543875248;
    Steuerung_B.HoughTransform_o2[113] = 0.4014257279586958;
    Steuerung_B.HoughTransform_o2[114] = 0.41887902047863912;
    Steuerung_B.HoughTransform_o2[115] = 0.43633231299858238;
    Steuerung_B.HoughTransform_o2[116] = 0.4537856055185257;
    Steuerung_B.HoughTransform_o2[117] = 0.47123889803846897;
    Steuerung_B.HoughTransform_o2[118] = 0.48869219055841229;
    Steuerung_B.HoughTransform_o2[119] = 0.50614548307835561;
    Steuerung_B.HoughTransform_o2[120] = 0.52359877559829882;
    Steuerung_B.HoughTransform_o2[121] = 0.54105206811824214;
    Steuerung_B.HoughTransform_o2[122] = 0.55850536063818546;
    Steuerung_B.HoughTransform_o2[123] = 0.57595865315812877;
    Steuerung_B.HoughTransform_o2[124] = 0.59341194567807209;
    Steuerung_B.HoughTransform_o2[125] = 0.6108652381980153;
    Steuerung_B.HoughTransform_o2[126] = 0.62831853071795862;
    Steuerung_B.HoughTransform_o2[127] = 0.64577182323790194;
    Steuerung_B.HoughTransform_o2[128] = 0.66322511575784526;
    Steuerung_B.HoughTransform_o2[129] = 0.68067840827778847;
    Steuerung_B.HoughTransform_o2[130] = 0.69813170079773179;
    Steuerung_B.HoughTransform_o2[131] = 0.71558499331767511;
    Steuerung_B.HoughTransform_o2[132] = 0.73303828583761843;
    Steuerung_B.HoughTransform_o2[133] = 0.75049157835756175;
    Steuerung_B.HoughTransform_o2[134] = 0.767944870877505;
    Steuerung_B.HoughTransform_o2[135] = 0.78539816339744828;
    Steuerung_B.HoughTransform_o2[136] = 0.8028514559173916;
    Steuerung_B.HoughTransform_o2[137] = 0.82030474843733492;
    Steuerung_B.HoughTransform_o2[138] = 0.83775804095727824;
    Steuerung_B.HoughTransform_o2[139] = 0.85521133347722145;
    Steuerung_B.HoughTransform_o2[140] = 0.87266462599716477;
    Steuerung_B.HoughTransform_o2[141] = 0.89011791851710809;
    Steuerung_B.HoughTransform_o2[142] = 0.90757121103705141;
    Steuerung_B.HoughTransform_o2[143] = 0.92502450355699462;
    Steuerung_B.HoughTransform_o2[144] = 0.94247779607693793;
    Steuerung_B.HoughTransform_o2[145] = 0.95993108859688125;
    Steuerung_B.HoughTransform_o2[146] = 0.97738438111682457;
    Steuerung_B.HoughTransform_o2[147] = 0.99483767363676789;
    Steuerung_B.HoughTransform_o2[148] = 1.0122909661567112;
    Steuerung_B.HoughTransform_o2[149] = 1.0297442586766545;
    Steuerung_B.HoughTransform_o2[150] = 1.0471975511965976;
    Steuerung_B.HoughTransform_o2[151] = 1.064650843716541;
    Steuerung_B.HoughTransform_o2[152] = 1.0821041362364843;
    Steuerung_B.HoughTransform_o2[153] = 1.0995574287564276;
    Steuerung_B.HoughTransform_o2[154] = 1.1170107212763709;
    Steuerung_B.HoughTransform_o2[155] = 1.1344640137963142;
    Steuerung_B.HoughTransform_o2[156] = 1.1519173063162575;
    Steuerung_B.HoughTransform_o2[157] = 1.1693705988362009;
    Steuerung_B.HoughTransform_o2[158] = 1.1868238913561442;
    Steuerung_B.HoughTransform_o2[159] = 1.2042771838760873;
    Steuerung_B.HoughTransform_o2[160] = 1.2217304763960306;
    Steuerung_B.HoughTransform_o2[161] = 1.2391837689159739;
    Steuerung_B.HoughTransform_o2[162] = 1.2566370614359172;
    Steuerung_B.HoughTransform_o2[163] = 1.2740903539558606;
    Steuerung_B.HoughTransform_o2[164] = 1.2915436464758039;
    Steuerung_B.HoughTransform_o2[165] = 1.3089969389957472;
    Steuerung_B.HoughTransform_o2[166] = 1.3264502315156905;
    Steuerung_B.HoughTransform_o2[167] = 1.3439035240356338;
    Steuerung_B.HoughTransform_o2[168] = 1.3613568165555769;
    Steuerung_B.HoughTransform_o2[169] = 1.3788101090755203;
    Steuerung_B.HoughTransform_o2[170] = 1.3962634015954636;
    Steuerung_B.HoughTransform_o2[171] = 1.4137166941154069;
    Steuerung_B.HoughTransform_o2[172] = 1.4311699866353502;
    Steuerung_B.HoughTransform_o2[173] = 1.4486232791552935;
    Steuerung_B.HoughTransform_o2[174] = 1.4660765716752369;
    Steuerung_B.HoughTransform_o2[175] = 1.4835298641951802;
    Steuerung_B.HoughTransform_o2[176] = 1.5009831567151235;
    Steuerung_B.HoughTransform_o2[177] = 1.5184364492350666;
    Steuerung_B.HoughTransform_o2[178] = 1.53588974175501;
    Steuerung_B.HoughTransform_o2[179] = 1.5533430342749532;
    Steuerung_B.HoughTransform_o3[0] = -100.0;
    Steuerung_B.HoughTransform_o3[1] = -99.0;
    Steuerung_B.HoughTransform_o3[2] = -98.0;
    Steuerung_B.HoughTransform_o3[3] = -97.0;
    Steuerung_B.HoughTransform_o3[4] = -96.0;
    Steuerung_B.HoughTransform_o3[5] = -95.0;
    Steuerung_B.HoughTransform_o3[6] = -94.0;
    Steuerung_B.HoughTransform_o3[7] = -93.0;
    Steuerung_B.HoughTransform_o3[8] = -92.0;
    Steuerung_B.HoughTransform_o3[9] = -91.0;
    Steuerung_B.HoughTransform_o3[10] = -90.0;
    Steuerung_B.HoughTransform_o3[11] = -89.0;
    Steuerung_B.HoughTransform_o3[12] = -88.0;
    Steuerung_B.HoughTransform_o3[13] = -87.0;
    Steuerung_B.HoughTransform_o3[14] = -86.0;
    Steuerung_B.HoughTransform_o3[15] = -85.0;
    Steuerung_B.HoughTransform_o3[16] = -84.0;
    Steuerung_B.HoughTransform_o3[17] = -83.0;
    Steuerung_B.HoughTransform_o3[18] = -82.0;
    Steuerung_B.HoughTransform_o3[19] = -81.0;
    Steuerung_B.HoughTransform_o3[20] = -80.0;
    Steuerung_B.HoughTransform_o3[21] = -79.0;
    Steuerung_B.HoughTransform_o3[22] = -78.0;
    Steuerung_B.HoughTransform_o3[23] = -77.0;
    Steuerung_B.HoughTransform_o3[24] = -76.0;
    Steuerung_B.HoughTransform_o3[25] = -75.0;
    Steuerung_B.HoughTransform_o3[26] = -74.0;
    Steuerung_B.HoughTransform_o3[27] = -73.0;
    Steuerung_B.HoughTransform_o3[28] = -72.0;
    Steuerung_B.HoughTransform_o3[29] = -71.0;
    Steuerung_B.HoughTransform_o3[30] = -70.0;
    Steuerung_B.HoughTransform_o3[31] = -69.0;
    Steuerung_B.HoughTransform_o3[32] = -68.0;
    Steuerung_B.HoughTransform_o3[33] = -67.0;
    Steuerung_B.HoughTransform_o3[34] = -66.0;
    Steuerung_B.HoughTransform_o3[35] = -65.0;
    Steuerung_B.HoughTransform_o3[36] = -64.0;
    Steuerung_B.HoughTransform_o3[37] = -63.0;
    Steuerung_B.HoughTransform_o3[38] = -62.0;
    Steuerung_B.HoughTransform_o3[39] = -61.0;
    Steuerung_B.HoughTransform_o3[40] = -60.0;
    Steuerung_B.HoughTransform_o3[41] = -59.0;
    Steuerung_B.HoughTransform_o3[42] = -58.0;
    Steuerung_B.HoughTransform_o3[43] = -57.0;
    Steuerung_B.HoughTransform_o3[44] = -56.0;
    Steuerung_B.HoughTransform_o3[45] = -55.0;
    Steuerung_B.HoughTransform_o3[46] = -54.0;
    Steuerung_B.HoughTransform_o3[47] = -53.0;
    Steuerung_B.HoughTransform_o3[48] = -52.0;
    Steuerung_B.HoughTransform_o3[49] = -51.0;
    Steuerung_B.HoughTransform_o3[50] = -50.0;
    Steuerung_B.HoughTransform_o3[51] = -49.0;
    Steuerung_B.HoughTransform_o3[52] = -48.0;
    Steuerung_B.HoughTransform_o3[53] = -47.0;
    Steuerung_B.HoughTransform_o3[54] = -46.0;
    Steuerung_B.HoughTransform_o3[55] = -45.0;
    Steuerung_B.HoughTransform_o3[56] = -44.0;
    Steuerung_B.HoughTransform_o3[57] = -43.0;
    Steuerung_B.HoughTransform_o3[58] = -42.0;
    Steuerung_B.HoughTransform_o3[59] = -41.0;
    Steuerung_B.HoughTransform_o3[60] = -40.0;
    Steuerung_B.HoughTransform_o3[61] = -39.0;
    Steuerung_B.HoughTransform_o3[62] = -38.0;
    Steuerung_B.HoughTransform_o3[63] = -37.0;
    Steuerung_B.HoughTransform_o3[64] = -36.0;
    Steuerung_B.HoughTransform_o3[65] = -35.0;
    Steuerung_B.HoughTransform_o3[66] = -34.0;
    Steuerung_B.HoughTransform_o3[67] = -33.0;
    Steuerung_B.HoughTransform_o3[68] = -32.0;
    Steuerung_B.HoughTransform_o3[69] = -31.0;
    Steuerung_B.HoughTransform_o3[70] = -30.0;
    Steuerung_B.HoughTransform_o3[71] = -29.0;
    Steuerung_B.HoughTransform_o3[72] = -28.0;
    Steuerung_B.HoughTransform_o3[73] = -27.0;
    Steuerung_B.HoughTransform_o3[74] = -26.0;
    Steuerung_B.HoughTransform_o3[75] = -25.0;
    Steuerung_B.HoughTransform_o3[76] = -24.0;
    Steuerung_B.HoughTransform_o3[77] = -23.0;
    Steuerung_B.HoughTransform_o3[78] = -22.0;
    Steuerung_B.HoughTransform_o3[79] = -21.0;
    Steuerung_B.HoughTransform_o3[80] = -20.0;
    Steuerung_B.HoughTransform_o3[81] = -19.0;
    Steuerung_B.HoughTransform_o3[82] = -18.0;
    Steuerung_B.HoughTransform_o3[83] = -17.0;
    Steuerung_B.HoughTransform_o3[84] = -16.0;
    Steuerung_B.HoughTransform_o3[85] = -15.0;
    Steuerung_B.HoughTransform_o3[86] = -14.0;
    Steuerung_B.HoughTransform_o3[87] = -13.0;
    Steuerung_B.HoughTransform_o3[88] = -12.0;
    Steuerung_B.HoughTransform_o3[89] = -11.0;
    Steuerung_B.HoughTransform_o3[90] = -10.0;
    Steuerung_B.HoughTransform_o3[91] = -9.0;
    Steuerung_B.HoughTransform_o3[92] = -8.0;
    Steuerung_B.HoughTransform_o3[93] = -7.0;
    Steuerung_B.HoughTransform_o3[94] = -6.0;
    Steuerung_B.HoughTransform_o3[95] = -5.0;
    Steuerung_B.HoughTransform_o3[96] = -4.0;
    Steuerung_B.HoughTransform_o3[97] = -3.0;
    Steuerung_B.HoughTransform_o3[98] = -2.0;
    Steuerung_B.HoughTransform_o3[99] = -1.0;
    Steuerung_B.HoughTransform_o3[100] = 0.0;
    Steuerung_B.HoughTransform_o3[101] = 1.0;
    Steuerung_B.HoughTransform_o3[102] = 2.0;
    Steuerung_B.HoughTransform_o3[103] = 3.0;
    Steuerung_B.HoughTransform_o3[104] = 4.0;
    Steuerung_B.HoughTransform_o3[105] = 5.0;
    Steuerung_B.HoughTransform_o3[106] = 6.0;
    Steuerung_B.HoughTransform_o3[107] = 7.0;
    Steuerung_B.HoughTransform_o3[108] = 8.0;
    Steuerung_B.HoughTransform_o3[109] = 9.0;
    Steuerung_B.HoughTransform_o3[110] = 10.0;
    Steuerung_B.HoughTransform_o3[111] = 11.0;
    Steuerung_B.HoughTransform_o3[112] = 12.0;
    Steuerung_B.HoughTransform_o3[113] = 13.0;
    Steuerung_B.HoughTransform_o3[114] = 14.0;
    Steuerung_B.HoughTransform_o3[115] = 15.0;
    Steuerung_B.HoughTransform_o3[116] = 16.0;
    Steuerung_B.HoughTransform_o3[117] = 17.0;
    Steuerung_B.HoughTransform_o3[118] = 18.0;
    Steuerung_B.HoughTransform_o3[119] = 19.0;
    Steuerung_B.HoughTransform_o3[120] = 20.0;
    Steuerung_B.HoughTransform_o3[121] = 21.0;
    Steuerung_B.HoughTransform_o3[122] = 22.0;
    Steuerung_B.HoughTransform_o3[123] = 23.0;
    Steuerung_B.HoughTransform_o3[124] = 24.0;
    Steuerung_B.HoughTransform_o3[125] = 25.0;
    Steuerung_B.HoughTransform_o3[126] = 26.0;
    Steuerung_B.HoughTransform_o3[127] = 27.0;
    Steuerung_B.HoughTransform_o3[128] = 28.0;
    Steuerung_B.HoughTransform_o3[129] = 29.0;
    Steuerung_B.HoughTransform_o3[130] = 30.0;
    Steuerung_B.HoughTransform_o3[131] = 31.0;
    Steuerung_B.HoughTransform_o3[132] = 32.0;
    Steuerung_B.HoughTransform_o3[133] = 33.0;
    Steuerung_B.HoughTransform_o3[134] = 34.0;
    Steuerung_B.HoughTransform_o3[135] = 35.0;
    Steuerung_B.HoughTransform_o3[136] = 36.0;
    Steuerung_B.HoughTransform_o3[137] = 37.0;
    Steuerung_B.HoughTransform_o3[138] = 38.0;
    Steuerung_B.HoughTransform_o3[139] = 39.0;
    Steuerung_B.HoughTransform_o3[140] = 40.0;
    Steuerung_B.HoughTransform_o3[141] = 41.0;
    Steuerung_B.HoughTransform_o3[142] = 42.0;
    Steuerung_B.HoughTransform_o3[143] = 43.0;
    Steuerung_B.HoughTransform_o3[144] = 44.0;
    Steuerung_B.HoughTransform_o3[145] = 45.0;
    Steuerung_B.HoughTransform_o3[146] = 46.0;
    Steuerung_B.HoughTransform_o3[147] = 47.0;
    Steuerung_B.HoughTransform_o3[148] = 48.0;
    Steuerung_B.HoughTransform_o3[149] = 49.0;
    Steuerung_B.HoughTransform_o3[150] = 50.0;
    Steuerung_B.HoughTransform_o3[151] = 51.0;
    Steuerung_B.HoughTransform_o3[152] = 52.0;
    Steuerung_B.HoughTransform_o3[153] = 53.0;
    Steuerung_B.HoughTransform_o3[154] = 54.0;
    Steuerung_B.HoughTransform_o3[155] = 55.0;
    Steuerung_B.HoughTransform_o3[156] = 56.0;
    Steuerung_B.HoughTransform_o3[157] = 57.0;
    Steuerung_B.HoughTransform_o3[158] = 58.0;
    Steuerung_B.HoughTransform_o3[159] = 59.0;
    Steuerung_B.HoughTransform_o3[160] = 60.0;
    Steuerung_B.HoughTransform_o3[161] = 61.0;
    Steuerung_B.HoughTransform_o3[162] = 62.0;
    Steuerung_B.HoughTransform_o3[163] = 63.0;
    Steuerung_B.HoughTransform_o3[164] = 64.0;
    Steuerung_B.HoughTransform_o3[165] = 65.0;
    Steuerung_B.HoughTransform_o3[166] = 66.0;
    Steuerung_B.HoughTransform_o3[167] = 67.0;
    Steuerung_B.HoughTransform_o3[168] = 68.0;
    Steuerung_B.HoughTransform_o3[169] = 69.0;
    Steuerung_B.HoughTransform_o3[170] = 70.0;
    Steuerung_B.HoughTransform_o3[171] = 71.0;
    Steuerung_B.HoughTransform_o3[172] = 72.0;
    Steuerung_B.HoughTransform_o3[173] = 73.0;
    Steuerung_B.HoughTransform_o3[174] = 74.0;
    Steuerung_B.HoughTransform_o3[175] = 75.0;
    Steuerung_B.HoughTransform_o3[176] = 76.0;
    Steuerung_B.HoughTransform_o3[177] = 77.0;
    Steuerung_B.HoughTransform_o3[178] = 78.0;
    Steuerung_B.HoughTransform_o3[179] = 79.0;
    Steuerung_B.HoughTransform_o3[180] = 80.0;
    Steuerung_B.HoughTransform_o3[181] = 81.0;
    Steuerung_B.HoughTransform_o3[182] = 82.0;
    Steuerung_B.HoughTransform_o3[183] = 83.0;
    Steuerung_B.HoughTransform_o3[184] = 84.0;
    Steuerung_B.HoughTransform_o3[185] = 85.0;
    Steuerung_B.HoughTransform_o3[186] = 86.0;
    Steuerung_B.HoughTransform_o3[187] = 87.0;
    Steuerung_B.HoughTransform_o3[188] = 88.0;
    Steuerung_B.HoughTransform_o3[189] = 89.0;
    Steuerung_B.HoughTransform_o3[190] = 90.0;
    Steuerung_B.HoughTransform_o3[191] = 91.0;
    Steuerung_B.HoughTransform_o3[192] = 92.0;
    Steuerung_B.HoughTransform_o3[193] = 93.0;
    Steuerung_B.HoughTransform_o3[194] = 94.0;
    Steuerung_B.HoughTransform_o3[195] = 95.0;
    Steuerung_B.HoughTransform_o3[196] = 96.0;
    Steuerung_B.HoughTransform_o3[197] = 97.0;
    Steuerung_B.HoughTransform_o3[198] = 98.0;
    Steuerung_B.HoughTransform_o3[199] = 99.0;
    Steuerung_B.HoughTransform_o3[200] = 100.0;
  }

  /* states (dwork) */
  (void) memset((void *)&Steuerung_DW, 0,
                sizeof(DW_Steuerung_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Steuerung_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 19;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  {
    int32_T nonZeroIdx;
    int32_T EdgeDetection_VO_DW_tmp;

    /* Start for S-Function (v4l2_video_capture_sfcn): '<S6>/V4L2 Video Capture' */
    MW_videoCaptureInit(Steuerung_ConstP.V4L2VideoCapture_p1, 0, 0, 0, 0, 320U,
                        240U, 1U, 2U, 1U, 0.1);

    /* Start for S-Function (svipedge): '<S3>/Edge Detection' */
    Steuerung_DW.EdgeDetection_MEAN_FACTOR_DW = 440058;
    for (nonZeroIdx = 0; nonZeroIdx < 6; nonZeroIdx++) {
      EdgeDetection_VO_DW_tmp =
        Steuerung_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 61 +
        Steuerung_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
      Steuerung_DW.EdgeDetection_VO_DW[nonZeroIdx] = EdgeDetection_VO_DW_tmp;
      if (Steuerung_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx] > 0) {
        Steuerung_DW.EdgeDetection_VOU_DW[nonZeroIdx] = EdgeDetection_VO_DW_tmp;
        Steuerung_DW.EdgeDetection_VOD_DW[nonZeroIdx] =
          Steuerung_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 61;
      } else {
        Steuerung_DW.EdgeDetection_VOU_DW[nonZeroIdx] =
          Steuerung_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 61;
        Steuerung_DW.EdgeDetection_VOD_DW[nonZeroIdx] = EdgeDetection_VO_DW_tmp;
      }

      if (Steuerung_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] > 0) {
        Steuerung_DW.EdgeDetection_VOL_DW[nonZeroIdx] = EdgeDetection_VO_DW_tmp;
        Steuerung_DW.EdgeDetection_VOR_DW[nonZeroIdx] =
          Steuerung_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
      } else {
        Steuerung_DW.EdgeDetection_VOL_DW[nonZeroIdx] =
          Steuerung_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
        Steuerung_DW.EdgeDetection_VOR_DW[nonZeroIdx] = EdgeDetection_VO_DW_tmp;
      }

      if ((Steuerung_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx] < 0) &&
          (Steuerung_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] < 0)) {
        Steuerung_DW.EdgeDetection_VOUL_DW[nonZeroIdx] = 0;
        Steuerung_DW.EdgeDetection_VOLR_DW[nonZeroIdx] = EdgeDetection_VO_DW_tmp;
        Steuerung_DW.EdgeDetection_VOLL_DW[nonZeroIdx] =
          Steuerung_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
        Steuerung_DW.EdgeDetection_VOUR_DW[nonZeroIdx] =
          Steuerung_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 61;
      }

      if ((Steuerung_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx] >= 0) &&
          (Steuerung_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] < 0)) {
        Steuerung_DW.EdgeDetection_VOLL_DW[nonZeroIdx] = 0;
        Steuerung_DW.EdgeDetection_VOUR_DW[nonZeroIdx] = EdgeDetection_VO_DW_tmp;
        Steuerung_DW.EdgeDetection_VOUL_DW[nonZeroIdx] =
          Steuerung_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
        Steuerung_DW.EdgeDetection_VOLR_DW[nonZeroIdx] =
          Steuerung_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 61;
      }

      if ((Steuerung_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx] < 0) &&
          (Steuerung_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] >= 0)) {
        Steuerung_DW.EdgeDetection_VOUR_DW[nonZeroIdx] = 0;
        Steuerung_DW.EdgeDetection_VOLL_DW[nonZeroIdx] = EdgeDetection_VO_DW_tmp;
        Steuerung_DW.EdgeDetection_VOUL_DW[nonZeroIdx] =
          Steuerung_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 61;
        Steuerung_DW.EdgeDetection_VOLR_DW[nonZeroIdx] =
          Steuerung_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
      }

      if ((Steuerung_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx] >= 0) &&
          (Steuerung_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] >= 0)) {
        Steuerung_DW.EdgeDetection_VOLR_DW[nonZeroIdx] = 0;
        Steuerung_DW.EdgeDetection_VOUL_DW[nonZeroIdx] = EdgeDetection_VO_DW_tmp;
        Steuerung_DW.EdgeDetection_VOLL_DW[nonZeroIdx] =
          Steuerung_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 61;
        Steuerung_DW.EdgeDetection_VOUR_DW[nonZeroIdx] =
          Steuerung_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
      }

      EdgeDetection_VO_DW_tmp =
        Steuerung_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 61 +
        Steuerung_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
      Steuerung_DW.EdgeDetection_HO_DW[nonZeroIdx] = EdgeDetection_VO_DW_tmp;
      if (Steuerung_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx] > 0) {
        Steuerung_DW.EdgeDetection_HOU_DW[nonZeroIdx] = EdgeDetection_VO_DW_tmp;
        Steuerung_DW.EdgeDetection_HOD_DW[nonZeroIdx] =
          Steuerung_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 61;
      } else {
        Steuerung_DW.EdgeDetection_HOU_DW[nonZeroIdx] =
          Steuerung_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 61;
        Steuerung_DW.EdgeDetection_HOD_DW[nonZeroIdx] = EdgeDetection_VO_DW_tmp;
      }

      if (Steuerung_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] > 0) {
        Steuerung_DW.EdgeDetection_HOL_DW[nonZeroIdx] = EdgeDetection_VO_DW_tmp;
        Steuerung_DW.EdgeDetection_HOR_DW[nonZeroIdx] =
          Steuerung_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
      } else {
        Steuerung_DW.EdgeDetection_HOL_DW[nonZeroIdx] =
          Steuerung_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
        Steuerung_DW.EdgeDetection_HOR_DW[nonZeroIdx] = EdgeDetection_VO_DW_tmp;
      }

      if ((Steuerung_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx] < 0) &&
          (Steuerung_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] < 0)) {
        Steuerung_DW.EdgeDetection_HOUL_DW[nonZeroIdx] = 0;
        Steuerung_DW.EdgeDetection_HOLR_DW[nonZeroIdx] = EdgeDetection_VO_DW_tmp;
        Steuerung_DW.EdgeDetection_HOLL_DW[nonZeroIdx] =
          Steuerung_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
        Steuerung_DW.EdgeDetection_HOUR_DW[nonZeroIdx] =
          Steuerung_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 61;
      }

      if ((Steuerung_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx] >= 0) &&
          (Steuerung_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] < 0)) {
        Steuerung_DW.EdgeDetection_HOLL_DW[nonZeroIdx] = 0;
        Steuerung_DW.EdgeDetection_HOUR_DW[nonZeroIdx] = EdgeDetection_VO_DW_tmp;
        Steuerung_DW.EdgeDetection_HOUL_DW[nonZeroIdx] =
          Steuerung_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
        Steuerung_DW.EdgeDetection_HOLR_DW[nonZeroIdx] =
          Steuerung_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 61;
      }

      if ((Steuerung_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx] < 0) &&
          (Steuerung_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] >= 0)) {
        Steuerung_DW.EdgeDetection_HOUR_DW[nonZeroIdx] = 0;
        Steuerung_DW.EdgeDetection_HOLL_DW[nonZeroIdx] = EdgeDetection_VO_DW_tmp;
        Steuerung_DW.EdgeDetection_HOUL_DW[nonZeroIdx] =
          Steuerung_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 61;
        Steuerung_DW.EdgeDetection_HOLR_DW[nonZeroIdx] =
          Steuerung_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
      }

      if ((Steuerung_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx] >= 0) &&
          (Steuerung_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] >= 0)) {
        Steuerung_DW.EdgeDetection_HOLR_DW[nonZeroIdx] = 0;
        Steuerung_DW.EdgeDetection_HOUL_DW[nonZeroIdx] = EdgeDetection_VO_DW_tmp;
        Steuerung_DW.EdgeDetection_HOLL_DW[nonZeroIdx] =
          Steuerung_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 61;
        Steuerung_DW.EdgeDetection_HOUR_DW[nonZeroIdx] =
          Steuerung_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
      }
    }

    /* End of Start for S-Function (svipedge): '<S3>/Edge Detection' */

    /* InitializeConditions for Delay: '<S8>/UD' */
    Steuerung_DW.UD_DSTATE = Steuerung_P.UD_InitialCondition;

    /* InitializeConditions for S-Function (PCA6585): '<Root>/PCA6585' */

    /* S-Function Block: <Root>/PCA6585 */
    {
      real_T initVector[2] = { 0, -1 };

      {
        int_T i1;
        real_T *dw_DSTATE = &Steuerung_DW.PCA6585_DSTATE[0];
        for (i1=0; i1 < 2; i1++) {
          dw_DSTATE[i1] = initVector[i1];
        }
      }
    }

    /* InitializeConditions for S-Function (PCF8591): '<Root>/PCF8591' */

    /* S-Function Block: <Root>/PCF8591 */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          Steuerung_DW.PCF8591_DSTATE = initVector[0];
        }
      }
    }

    /* InitializeConditions for S-Function (MCU6050): '<Root>/MCU6050' */

    /* S-Function Block: <Root>/MCU6050 */
    {
      real_T initVector[2] = { 0, -1 };

      {
        int_T i1;
        real_T *dw_DSTATE = &Steuerung_DW.MCU6050_DSTATE[0];
        for (i1=0; i1 < 2; i1++) {
          dw_DSTATE[i1] = initVector[i1];
        }
      }
    }
  }
}

/* Model terminate function */
void Steuerung_terminate(void)
{
  /* user code (Terminate function Body) */

  /* Send ALL_LED_OFF Signal to all PWM driver chip address
     See PCA9685 user manual, section 7.3.4
     Set Chip in sleep mode, section 7.3.1
     Reset the PWM ON/OFF states for all LEDs */
  int fd;
  fd = wiringPiI2CSetup(0x70);
  wiringPiI2CWriteReg8(fd, 0x00, 0x11);// sleep mode
  wiringPiI2CWriteReg8(fd, 0xFD, 0x10);// all LED off
  wiringPiI2CWriteReg8(fd, 0xFC, 0x00);
  wiringPiI2CWriteReg8(fd, 0xFB, 0x00);
  wiringPiI2CWriteReg8(fd, 0xFA, 0x00);

  /* Terminate for S-Function (v4l2_video_capture_sfcn): '<S6>/V4L2 Video Capture' */
  MW_videoCaptureTerminate(Steuerung_ConstP.V4L2VideoCapture_p1);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
