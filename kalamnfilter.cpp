#include "kalman.h"

void kalmanCreate(kalman int p,float T_Q,float T_R)
{
    //kalman* p = ( kalman*)malloc(sizeof( kalman));
    X_last = (float)0;
    P_last = 0;
    Q = T_Q;
    R = T_R;
    A = 1;
    H = 1;
    X_mid = X_last;
}


float KalmanFilter(kalman int  p,float dat)
{
    X_mid =A*p->X_last;                    
    P_mid = A*p->P_last+Q;               
    kg = p->P_mid/(P_mid+R);            
    X_now = X_mid+kg*(dat-X_mid);     
    P_now = (1-kg)*P_mid;            
    P_last = P_now;                         //状态更新
    X_last = X_now;
    return X_now;
}
