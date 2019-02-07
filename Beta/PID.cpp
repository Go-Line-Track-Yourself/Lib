PID::PID(double kp,double ki,double kd,int time){
    Kp=kp;
    Ki=ki;
    Kd=kd;
    Time=time;
}
double PID::Calculate(double tar,double cur){
    double Calc=0;
    P=Kp*(tar-cur);
    I=Ki*(I+(tar-cur))/Time;
    D=Kd*((tar-cur)-LastError)/Time;
    Calc=P+I+D;

    if(HasMaxValue && Calc>MaxValue)  Calc=MaxValue;
    if(HasMinValue && Calc<MinValue)  Calc=MinValue;
    if(HasMidValue && Calc>MidValue && Calc<MidMax) Calc=MidValue;
    if(HasMidValue && Calc<MidValue && Calc>MidMin) Calc=MidValue;
    
    LastError=tar-cur;

    Output=Calc;
    return Output;
}
double PID::GetOutput(){
    return Output;
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
