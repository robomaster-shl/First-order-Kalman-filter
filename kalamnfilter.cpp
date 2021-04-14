#include "kalman.h"

void kalmanCreate(kalman *p,float T_Q,float T_R)
{
    //kalman* p = ( kalman*)malloc(sizeof( kalman));
    p->X_last = (float)0;
    p->P_last = 0;
    p->Q = T_Q;
    p->R = T_R;
    p->A = 1;
    p->H = 1;
    p->X_mid = p->X_last;
    //return p;
}


float KalmanFilter(kalman* p,float dat)
{
    p->X_mid =p->A*p->X_last;                    
    p->P_mid = p->A*p->P_last+p->Q;               
    p->kg = p->P_mid/(p->P_mid+p->R);            
    p->X_now = p->X_mid+p->kg*(dat-p->X_mid);     
    p->P_now = (1-p->kg)*p->P_mid;            
    p->P_last = p->P_now;                         //状态更新
    p->X_last = p->X_now;
    return p->X_now;
}
