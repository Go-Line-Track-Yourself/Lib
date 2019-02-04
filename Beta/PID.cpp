PID::PID(double kp,double ki,double kd,int time){
    Kp=kp;
    Ki=ki;
    Kd=kd;
    Time=time;
}
double PID::Output(double tar,double cur){
    double output=0;
    P=Kp*(tar-cur);
    I=Ki*(I+(tar-cur))/Time;
    D=Kd*((tar-cur)-LastError)/Time;
    output=P+I+D;
    if(HasMaxValue && output>MaxValue)  output=MaxValue;
    if(HasMinValue && output<MinValue)  output=MinValue;
    if(HasMidValue && output>MidValue && output<MidMax) output=MidValue;
    if(HasMidValue && output<MidValue && output>MidMin) output=MidValue;
    return output;
}
void PID::SetMinValue(int minv){
    HasMinValue=true;
    MinValue=minv;
}
void PID::SetMaxValue(int maxv){
    HasMaxValue=true;
    MaxValue=maxv;
}
void PID::SetLimits(int minv,int maxv){
    SetMinValue(minv);
    SetMaxValue(maxv);
}
void PID::SetMidLimits(int minv,int maxv,int midv){
    HasMidValue=true;
    MidMin=minv;
    MidMax=maxv;
    MidValue=midv;
}
// mgError=mgRequestedValue - SensorValue[goalpot];
// mgP=mg_Kp * mgError;
// mgD=mgError - mgLastError;
// mgDF=mg_Kd * mgD;
// mgPower=mgP + mgDF;
// if(mgPower>127)		mgPower=127;
// if(mgPower<-127) 	mgPower=-127;
// if(mgEnabled)			setMgPower(-mgPower,-mgPower);
// mgLastError=mgError;
