#ifndef __pid_h
#define __pid_h
typedef struct 
{
    double Kp;
    double Ki;
    double Kd;
}PID_param;
typedef struct
{
    PID_param * param;
    double PID_feetback;
    double PID_inval;
    double PID_input;

    double PID_I;
    double PID_D;

    double lastinval;

}PID_ctrl;
void PID_init(PID_ctrl * controler,PID_param * param,double getpoint);
double PID_updata(PID_ctrl * controler,double nowout);
#endif // !__pid_h

