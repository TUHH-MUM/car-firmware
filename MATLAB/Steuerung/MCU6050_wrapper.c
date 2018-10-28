
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
 
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define y_width 1

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
void MCU6050_Outputs_wrapper(int16_T *ax,
			int16_T *ay,
			int16_T *az,
			int16_T *omx,
			int16_T *omy,
			int16_T *omz,
			int16_T *temp,
			const real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
/* don't do anything for mex file generation */
# ifndef MATLAB_MEX_FILE    

uint8_T fd;
int16_T h, l;
if (xD[0]==1) {

    fd = xD[1];
    
    h = wiringPiI2CReadReg16 (fd, 0x3b);
    l = wiringPiI2CReadReg16 (fd, 0x3c);
    ax[0] = h<<8|l;
    
    h = wiringPiI2CReadReg16 (fd, 0x3d);
    l = wiringPiI2CReadReg16 (fd, 0x3e);
    ay[0] = h<<8|l;
    
    h = wiringPiI2CReadReg16 (fd, 0x3f);
    l = wiringPiI2CReadReg16 (fd, 0x40);
    az[0] = h<<8|l;
    
    h = wiringPiI2CReadReg16 (fd, 0x41);
    l = wiringPiI2CReadReg16 (fd, 0x42);
    temp[0] = h<<8|l;
    
    h = wiringPiI2CReadReg16 (fd, 0x43);
    l = wiringPiI2CReadReg16 (fd, 0x44);
    omx[0] = h<<8|l;
    
    h = wiringPiI2CReadReg16 (fd, 0x45);
    l = wiringPiI2CReadReg16 (fd, 0x46);
    omy[0] = h<<8|l;
    
    h = wiringPiI2CReadReg16 (fd, 0x47);
    l = wiringPiI2CReadReg16 (fd, 0x48);
    omz[0] = h<<8|l;
    
}
# endif
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
 * Updates function
 *
 */
void MCU6050_Update_wrapper(int16_T *ax,
			int16_T *ay,
			int16_T *az,
			int16_T *omx,
			int16_T *omy,
			int16_T *omz,
			int16_T *temp,
			real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
/* don't do anything for mex file generation */
# ifndef MATLAB_MEX_FILE

uint8_T fd;

if (xD[0]!=1) {
        
    fd = wiringPiI2CSetup(0x68);
    
    wiringPiI2CWriteReg8(fd, 0x6b, 0); // wake chip from low power mode
    
    /* 
     * write the LOW registers for IN1/IN2, these will not change since
     * they are only logical signals (full on/full off)
     * write off states for motors to 0, control is only done by on states
     */
    // IN_1
 /*   wiringPiI2CWriteReg8(fd, 0x32, 0x00);
    wiringPiI2CWriteReg8(fd, 0x34, 0x00);
    // IN_2
    wiringPiI2CWriteReg8(fd, 0x26, 0x00);
    wiringPiI2CWriteReg8(fd, 0x28, 0x00);
    // PWM_1
    wiringPiI2CWriteReg8(fd, 0x2E, 0x00);
    wiringPiI2CWriteReg8(fd, 0x2F, 0x00);
    // PWM_2
    wiringPiI2CWriteReg8(fd, 0x2A, 0x00);
    wiringPiI2CWriteReg8(fd, 0x2B, 0x00);
    // SERVO
    wiringPiI2CWriteReg8(fd, 0x1E, 0x00);
    wiringPiI2CWriteReg8(fd, 0x1F, 0x00);
    wiringPiI2CWriteReg8(fd, 0x20, 0xCC);
    wiringPiI2CWriteReg8(fd, 0x21, 0x04);
*/
    
    xD[1] = fd;
    
    /* initialization done */ 
    xD[0]=1;
}
# endif
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}

