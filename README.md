# First-order-Kalman-filter
                                                                                              
  *   使用时先定义一个kalman指针，然后调用kalmanCreate()创建一个滤波器
  *   每次读取到传感器数据后即可调用KalmanFilter()来对数据进行滤波。               

  *                          使用示例                                                    
  *          kalman p;                                                                   
  *          float SersorData;                                                            
  *          kalmanCreate(&p,20,200);                                                  
  *          while(1)                                                                     
  *          {                                                                            
  *             SersorData = sersor();                                                    
  *             SersorData = KalmanFilter(&p,SersorData);                                  
  *             printf("%2.2f",SersorData);                                               
  *          }            
