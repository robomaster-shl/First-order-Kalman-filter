#ifndef _KALMAN_H
#define _KALMAN_H

#include "stdlib.h"

typedef struct {
    float X_last; 
    float X_mid;  
    float X_now;  
    float P_mid;  
    float P_now;  
    float P_last; 
    float kg;     //kalman增益
    float A;  
    float Q;
    float R;
    float H;
}
kalman;

void kalmanCreate(float T_Q,float T_R);
float KalmanFilter(float dat);

#endif
