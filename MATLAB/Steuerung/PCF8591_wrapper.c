
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
void PCF8591_Outputs_wrapper(uint8_T *PCF8591_out,
			const real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
int_T k;
/* wait until after initialization is done */
if (xD[0]==1) {
    
    /* don't do anything for mex file generation */
    # ifndef MATLAB_MEX_FILE

        for(k = 0; k < 4; k++){
            // Write PCF8591 distance sensor output to outport
            PCF8591_out[k] = analogRead(64 + k);
    }
    # endif
    
}
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
 * Updates function
 *
 */
void PCF8591_Update_wrapper(uint8_T *PCF8591_out,
			real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
if (xD[0]!=1)
{
    /* don't do anything for MEX-file generation */
    # ifndef MATLAB_MEX_FILE
            // Initialize WiringPi
            wiringPiSetup ();
            // Setup for the PCF8591
            pcf8591Setup (64, 0x48);
    # endif
    
    /* initialization done */ 
    xD[0]=1;
}
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}

