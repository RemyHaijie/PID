#include "PID.h"
#include "stdio.h"
void PID_init(PID_ctrl * controler,PID_param * param,double getpoint){
    controler->param = param;
    controler->PID_feetback = 0;
    controler->PID_input = getpoint;
    controler->PID_inval = getpoint;
    controler->PID_D = 0;
    controler->PID_I = 0;
    controler->lastinval = 0;
}
double PID_updata(PID_ctrl * controler,double nowout){
    double result = 0;
    controler->PID_feetback = nowout;
    controler->PID_inval = controler->PID_input - controler->PID_feetback;
    controler->PID_I += controler->PID_inval;
    controler->PID_D = controler->PID_inval - controler->lastinval;
    //printf("inval: %lf\n",controler->PID_inval);
    result += controler->param->Kp * controler->PID_inval;
    result += controler->param->Ki * controler->PID_I;
    result += controler->param->Kd * controler->PID_D;
    //printf("result: %lf\n",result);
    return result;
}

