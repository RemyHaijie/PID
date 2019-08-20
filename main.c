#include "stdio.h"
#include "PID.h"
double objout(double inputval);
void printnext(void);
int main(int argc, char const *argv[])
{
    double inval = 0;
    double setval = 0;
    double updataval = 1;
    int i = 0;
    PID_ctrl PID_ctrlstruct;
    PID_param PID_paramstruc;
    PID_paramstruc.Kp = 0.02;
    PID_paramstruc.Ki = 0.08;
    PID_paramstruc.Kd = 0.01;
    /*set point is 20*/
    PID_init(&PID_ctrlstruct,&PID_paramstruc,100);
    printf("text begin");
    printnext();
    //printf("objtext val: %lf objout: %lf",inval,objout(inval));
    //printnext();
    printf("set point is %lf \n",50);
    for (i = 0;i<100;i++)
    {
        setval = objout(updataval);
        updataval = PID_updata(&PID_ctrlstruct,setval);
        //printnext();
        printf("%lf",setval);
        printnext();
    }
    return 0;
}
double objout(double inputval){
    return inputval*8 + 10;
}
void printnext(void){
    printf("\n");
}