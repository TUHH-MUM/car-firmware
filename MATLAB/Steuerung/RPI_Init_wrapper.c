
/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif



/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#include <math.h>
#ifndef MATLAB_MEX_FILE
#include </home/pi/wiringPi/wiringPi/wiringPi.h>
//#include </home/pi/wiringPi/wiringPi/wiringPi.c>
//#include </home/pi/wiringPi/wiringPi/piHiPri.c>
//#include </home/pi/wiringPi/wiringPi/softTone.h>
//#include </home/pi/wiringPi/wiringPi/softTone.c>
//#include </home/pi/wiringPi/wiringPi/softPwm.h>
//#include </home/pi/wiringPi/wiringPi/wiringPiI2C.h>
#include </home/pi/wiringPi/wiringPi/wiringPiI2C.c>
#include </home/pi/wiringPi/wiringPi/pcf8591.c>
// for digital out:
#include </home/pi/wiringPi/wiringPi/wiringPi.c>
#include </home/pi/wiringPi/wiringPi/piHiPri.c>
// for pwm:
//#include </home/pi/wiringPi/wiringPi/softPwm.c>
#include </home/pi/wiringPi/wiringPi/piThread.c>
#endif
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output function
 *
 */
void RPI_Init_Outputs_wrapper(void)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
/* This sample sets the output equal to the input
      y0[0] = u0[0]; 
 For complex signals use: y0[0].re = u0[0].re; 
      y0[0].im = u0[0].im;
      y1[0].re = u1[0].re;
      y1[0].im = u1[0].im;
*/
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}


