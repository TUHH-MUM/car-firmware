#include <HCSR04.h>
#include <stdio.h>
#include <stdlib.h>

double read_value(){
    char command[50];
    char c[5];
    double dist;
    FILE *fp;
    
    strcpy(command, "sudo python HCSR04.py");
    system(command);
    
    if ((fp = fopen("sensordata.txt","r")) == NULL){
        dist = -1;
        exit(1);
    }
    
    fscanf(fp,"%[^\n]",c);
    double dc = strtod(c,NULL);
    dist = dc;
    fclose(fp);
    
    return dist;
}