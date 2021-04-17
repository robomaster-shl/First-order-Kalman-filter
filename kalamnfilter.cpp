#include "kalman.h"

void kalmanCreate(float T_Q,float T_R)
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


ffloat KalmanFilter(float dat)
{
    X_mid =A*X_last;                     //x(k|k-1) = AX(k-1|k-1)+BU(k)
    P_mid = A*P_last+Q;               //p(k|k-1) = Ap(k-1|k-1)A'+Q
    kg = P_mid/(P_mid+R);             //kg(k) = p(k|k-1)H'/(Hp(k|k-1)'+R)
    X_now = X_mid+kg*(dat-X_mid);     //x(k|k) = X(k|k-1)+kg(k)(Z(k)-HX(k|k-1))
    P_now = (1-kg)*P_mid;                //p(k|k) = (I-kg(k)H)P(k|k-1)
    P_last = P_now;                         //状态更新
    X_last = X_now;
    return X_now;
}
