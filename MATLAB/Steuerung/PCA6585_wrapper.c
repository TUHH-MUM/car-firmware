
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
#define u_width 1

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
void PCA6585_Outputs_wrapper(const boolean_T *IN_1,
			const boolean_T *IN_2,
			const uint16_T *PWM,
			const uint16_T *SERVO,
			const real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
/*
*/
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
 * Updates function
 *
 */
void PCA6585_Update_wrapper(const boolean_T *IN_1,
			const boolean_T *IN_2,
			const uint16_T *PWM,
			const uint16_T *SERVO,
			real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
/* don't do anything for mex file generation */
# ifndef MATLAB_MEX_FILE

uint8_T fd;

if (xD[0]!=1) {
        
    fd = wiringPiI2CSetup(0x40);
    
    wiringPiI2CWriteReg8(fd, 0x00, 0x01); // wake chip from low power mode
    
    /* 
     * write the LOW registers for IN1/IN2, these will not change since
     * they are only logical signals (full on/full off)
     * write off states for motors to 0, control is only done by on states
     */
    // IN_1
    wiringPiI2CWriteReg8(fd, 0x32, 0x00);
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

    
    xD[1] = fd;
    
    /* initialization done */ 
    xD[0]=1;
}
else{
    
    fd = xD[1];
    
    /* The Motor Shield is driven by a PCA9685 16 channel PWM
     * driver chip.
     *      IN1 / IN2 control the direction of the motor
     *      PWM controls the voltage of the motor
     *      IN1 and IN2 have the following states:
     *          IN1 = high and IN2 = low: motor turns clockwise
     *          IN1 = low and IN2 = high: motor turns counterclockwise
     *          else: motor is stopped
     *
     * The Motor drivers are connected to the PWM driver as follows:
     *  IN1: LED11
     *  IN2: LED8
     *  PWM_1: LED10
     *  PWM_2: LED9
     *  SERVO: LED6
     */
    
     // SERVO
    wiringPiI2CWriteReg8(fd, 0x20, (uint8_T) SERVO[0]);
    wiringPiI2CWriteReg8(fd, 0x21, (uint8_T) ((SERVO[0] << 3) >> 11));
    
    if (IN_1[0]==1 && IN_2[0]==0){
        // write PWM_2
        wiringPiI2CWriteReg8(fd, 0x2C, 0x00);
        wiringPiI2CWriteReg8(fd, 0x2D, 0x10);
        // write IN1
        wiringPiI2CWriteReg8(fd, 0x33, 0x10);
        wiringPiI2CWriteReg8(fd, 0x35, 0x00);
        // write IN2
        wiringPiI2CWriteReg8(fd, 0x27, 0x10);
        wiringPiI2CWriteReg8(fd, 0x29, 0x00);
        // write PWM_1
        wiringPiI2CWriteReg8(fd, 0x30, (uint8_T) PWM[0]);
        wiringPiI2CWriteReg8(fd, 0x31, (uint8_T) ((PWM[0] << 3) >> 11));
       
    }
    else{
        if (IN_1[0]==0 && IN_2[0]==1){
             // write PWM_1
             wiringPiI2CWriteReg8(fd, 0x30, 0x00);
             wiringPiI2CWriteReg8(fd, 0x31, 0x10);
             // write IN1
             wiringPiI2CWriteReg8(fd, 0x33, 0x10);
             wiringPiI2CWriteReg8(fd, 0x35, 0x00);
             // write IN2
             wiringPiI2CWriteReg8(fd, 0x27, 0x10);
             wiringPiI2CWriteReg8(fd, 0x29, 0x00);
             // write PWM_2
             wiringPiI2CWriteReg8(fd, 0x2C, (uint8_T) PWM[0]);
             wiringPiI2CWriteReg8(fd, 0x2D, (uint8_T) ((PWM[0] << 3) >> 11));
        }
        else{
            // write IN1
              wiringPiI2CWriteReg8(fd, 0x33, 0x00);
              wiringPiI2CWriteReg8(fd, 0x35, 0x10);
             // write IN2
             wiringPiI2CWriteReg8(fd, 0x27, 0x00);
             wiringPiI2CWriteReg8(fd, 0x29, 0x10);
              // write PWM_1
             wiringPiI2CWriteReg8(fd, 0x30, 0x00);
             wiringPiI2CWriteReg8(fd, 0x31, 0x10);
               // write PWM_2
             wiringPiI2CWriteReg8(fd, 0x2C, 0x00);
             wiringPiI2CWriteReg8(fd, 0x2D, 0x10);
			}
    }
     
}
# endif
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}

