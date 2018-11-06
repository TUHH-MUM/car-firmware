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
 * C/C++ source code generated on : Tue Nov  6 15:07:26 2018
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
real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function */
void Steuerung_step(void)
{
  real_T rtb_mainswitch;
  real_T rtb_Add1;

  /* S-Function (RPI_Init): '<Root>/Init' */
  RPI_Init_Outputs_wrapper();

  /* ManualSwitch: '<Root>/Manual Switch1' incorporates:
   *  Constant: '<Root>/Constant6'
   *  Constant: '<Root>/Constant7'
   */
  if (Steuerung_P.ManualSwitch1_CurrentSetting == 1) {
    rtb_mainswitch = Steuerung_P.Constant6_Value;
  } else {
    rtb_mainswitch = Steuerung_P.Constant7_Value;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch1' */

  /* ManualSwitch: '<Root>/Manual Switch' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant2'
   */
  if (Steuerung_P.ManualSwitch_CurrentSetting == 1) {
    rtb_Add1 = Steuerung_P.Constant_Value;
  } else {
    rtb_Add1 = Steuerung_P.Constant2_Value;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch' */

  /* Logic: '<S1>/Logical Operator2' */
  Steuerung_B.LogicalOperator2 = ((rtb_mainswitch != 0.0) && (rtb_Add1 != 0.0));

  /* Logic: '<S1>/Logical Operator1' incorporates:
   *  Logic: '<S1>/Logical Operator'
   */
  Steuerung_B.LogicalOperator1 = ((rtb_mainswitch != 0.0) && (!(rtb_Add1 != 0.0)));

  /* Saturate: '<Root>/Saturation' */
  if (Steuerung_ConstB.ConstantRamp > Steuerung_P.Saturation_UpperSat) {
    rtb_Add1 = Steuerung_P.Saturation_UpperSat;
  } else if (Steuerung_ConstB.ConstantRamp < Steuerung_P.Saturation_LowerSat) {
    rtb_Add1 = Steuerung_P.Saturation_LowerSat;
  } else {
    rtb_Add1 = Steuerung_ConstB.ConstantRamp;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* DataTypeConversion: '<S1>/Data Type Conversion1' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Gain: '<Root>/Normalization'
   *  Gain: '<S1>/Gain'
   *  Product: '<S1>/Product'
   *  Quantizer: '<Root>/Quantizer'
   *  Sum: '<S1>/Add'
   */
  rtb_Add1 = floor(rt_roundd_snf(rtb_Add1 / Steuerung_P.Quantizer_Interval) *
                   Steuerung_P.Quantizer_Interval *
                   Steuerung_P.Normalization_Gain * Steuerung_P.Gain_Gain +
                   rtb_mainswitch * Steuerung_P.Constant1_Value);
  if (rtIsNaN(rtb_Add1) || rtIsInf(rtb_Add1)) {
    rtb_Add1 = 0.0;
  } else {
    rtb_Add1 = fmod(rtb_Add1, 65536.0);
  }

  Steuerung_B.DataTypeConversion1 = (uint16_T)(rtb_Add1 < 0.0 ? (int32_T)
    (uint16_T)-(int16_T)(uint16_T)-rtb_Add1 : (int32_T)(uint16_T)rtb_Add1);

  /* End of DataTypeConversion: '<S1>/Data Type Conversion1' */

  /* ManualSwitch: '<Root>/Manual // Automatic Steering' incorporates:
   *  Constant: '<Root>/Constant5'
   *  Gain: '<Root>/Normalization1'
   *  Gain: '<S6>/Slider Gain'
   */
  if (Steuerung_P.ManualAutomaticSteering_Current == 1) {
    Steuerung_B.steeringangle = Steuerung_P.SliderGain1_gain *
      Steuerung_P.Constant5_Value * Steuerung_P.Normalization1_Gain;
  } else {
    Steuerung_B.steeringangle = 0.0;
  }

  /* End of ManualSwitch: '<Root>/Manual // Automatic Steering' */

  /* DataTypeConversion: '<S1>/Data Type Conversion3' incorporates:
   *  Constant: '<S1>/Constant3'
   *  Gain: '<S1>/Gain1'
   *  Sum: '<S1>/Add1'
   */
  rtb_Add1 = floor(Steuerung_P.Gain1_Gain * Steuerung_B.steeringangle +
                   Steuerung_P.Constant3_Value);
  if (rtIsNaN(rtb_Add1) || rtIsInf(rtb_Add1)) {
    rtb_Add1 = 0.0;
  } else {
    rtb_Add1 = fmod(rtb_Add1, 65536.0);
  }

  Steuerung_B.DataTypeConversion3 = (uint16_T)(rtb_Add1 < 0.0 ? (int32_T)
    (uint16_T)-(int16_T)(uint16_T)-rtb_Add1 : (int32_T)(uint16_T)rtb_Add1);

  /* End of DataTypeConversion: '<S1>/Data Type Conversion3' */

  /* S-Function (PCA6585): '<Root>/PCA6585' */
  PCA6585_Outputs_wrapper(&Steuerung_B.LogicalOperator2,
    &Steuerung_B.LogicalOperator1, &Steuerung_B.DataTypeConversion1,
    &Steuerung_B.DataTypeConversion3, &Steuerung_DW.PCA6585_DSTATE[0]);

  /* Update for S-Function (PCA6585): '<Root>/PCA6585' */

  /* S-Function "PCA6585_wrapper" Block: <Root>/PCA6585 */
  PCA6585_Update_wrapper(&Steuerung_B.LogicalOperator2,
    &Steuerung_B.LogicalOperator1, &Steuerung_B.DataTypeConversion1,
    &Steuerung_B.DataTypeConversion3, &Steuerung_DW.PCA6585_DSTATE[0]);

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
  Steuerung_M->Sizes.checksums[0] = (450265674U);
  Steuerung_M->Sizes.checksums[1] = (972400264U);
  Steuerung_M->Sizes.checksums[2] = (4062570481U);
  Steuerung_M->Sizes.checksums[3] = (3186828189U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[6];
    Steuerung_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Steuerung_M->extModeInfo,
      &Steuerung_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Steuerung_M->extModeInfo, Steuerung_M->Sizes.checksums);
    rteiSetTPtr(Steuerung_M->extModeInfo, rtmGetTPtr(Steuerung_M));
  }

  /* block I/O */
  (void) memset(((void *) &Steuerung_B), 0,
                sizeof(B_Steuerung_T));

  /* states (dwork) */
  (void) memset((void *)&Steuerung_DW, 0,
                sizeof(DW_Steuerung_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Steuerung_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

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
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
