TMotors::TMotors(vex::motor motor[], int num){
    Motors=motor;
    NumberOfMotors=num;
}
void TMotors::Stop(){
    for(int i=0; i < NumberOfMotors; ++i){
            Motors[i].stop(SUnits);
    }
}
void TMotors::SMS(int v,bool limit){
    VSet=v*Ratio;
    if(v==0)    Stop();
    else if(MinPosEnabled && v<0 && Rotation()<MinPos) Stop();//requested left/down and over min left/donw pos
    else if(MaxPosEnabled && v>0 && Rotation()>MaxPos) Stop();//requested right/up and over max right/up pos
    else{
        for(int i=0; i < NumberOfMotors; ++i){
            Motors[i].spin(vex::directionType::fwd,VSet,VUnits);
        }
    }
}
void TMotors::SST(double tar,int v){
    // if(tar==0.001)  tar=TargetSetting;//defaults
    // if(v==0)        v=VSetting;//defaults
    Target=tar;//update target
    VSet=v;//update velocity

    TargetSum+=tar;
    for(int i=0; i < NumberOfMotors; ++i){
            Motors[i].startRotateTo(Target,RUnits,VSet,VUnits);
        }
}
bool TMotors::Spinning(){
    double Sum=0;
    for(int i=0; i < NumberOfMotors; ++i){
        Sum+=Motors[i].velocity(VUnits);
    }
    if(std::abs(Motors[0].velocity(VUnits))>VMinChange) return true;
    else                                                return false;
}
bool TMotors::SSTTH(){//StartSpinToTargetHit
    bool SSTTH=false;
    for(int i=0; i < NumberOfMotors && !SSTTH; ++i){
        SSTTH=Motors[i].isSpinning();//is spining to target
    }

    return SSTTH;
}
double TMotors::Rotation(){
    double Sum=0;
    for(int i=0; i < NumberOfMotors; ++i){
        Sum+=Motors[i].rotation(RUnits);
    }
    return Sum/NumberOfMotors;
}
void TMotors::ResetRotation(){
    for(int i=0; i < NumberOfMotors; ++i){
            Motors[0].resetRotation();
    }
}
void TMotors::SetStop(vex::brakeType sunits){
    SUnits=sunits;
}
vex::brakeType TMotors::GetStop(){
    return SUnits;
}
void TMotors::SetVUnits(vex::velocityUnits vunits){
    VUnits=vunits;
}
vex::velocityUnits TMotors::GetVUnits(){
    return VUnits;
}
void TMotors::SetRUnits(vex::rotationUnits runits){
    RUnits=runits;
}
vex::rotationUnits TMotors::GetRUnits(){
    return RUnits;
}
void TMotors::SetVSetting(int v){
    VSetting=v;
}
int TMotors::GetVSetting(){
    return VSetting;
}
void TMotors::SetTargetSetting(double tar){
    TargetSetting=tar;
}
void TMotors::AddTargetSetting(double tar){
    TargetSetting+=tar;
}
double TMotors::GetTargetSetting(){
    return TargetSetting;
}
void TMotors::SetTarget(double tar){
    Target=tar;
}
double TMotors::GetTarget(){
    return Target;
}
void TMotors::SetMinPos(int pos){
    MinPosEnabled=true;
    MinPos=pos;
}
void TMotors::SetMaxPos(int pos){
    MaxPosEnabled=true;
    MaxPos=pos;
}
void TMotors::SetPosLimits(int minpos,int maxpos){
    SetMinPos(minpos);
    SetMaxPos(maxpos);
}
void TMotors::Calibrate(int rpm,float minv,int timeout,int updatemsec,int acelmsec){
    // int Rpm=200;       //Velocity to hit the end stop
    // int TimeOut=1000;   //Max time to hit end stop
    // int UpdateMsec=10;  //the time delay in the loop
    vex::velocityUnits StartVUnits = VUnits;
    VUnits=vex::velocityUnits::rpm;
    vex::rotationUnits StartRUnits = RUnits;
    RUnits = vex::rotationUnits::rev;

    int CalTimer=0;     //resets a local timer
    SMS(rpm,false);     //starts the spin to hit the end stop 
     double MinChange=(std::abs(rpm)*updatemsec*minv/60000);                                 ///(1/4)*(Rpm/60/1000); MinChange = 1/4 of requested rpm changed into msec
     int LastRotation=Rotation()+4*MinChange;  //makes sure that the while loop starts
    vex::task::sleep(acelmsec);                                                  //wait for the motor get some speed
    while(std::abs(Rotation()-LastRotation)>MinChange && CalTimer<timeout){//while the motors displacement is more then the MinChange and while the the timer is less then the timeout time
        LastRotation=Rotation();//update LastRotation
        CalTimer=CalTimer+updatemsec;   //add time to the timer
        vex::task::sleep(updatemsec);   //wait for the motor to spin
    }                                   //motor stoped spinning or time ran out
    ResetRotation();             //reset the rotation
    SMS(0);                      //dont burn out the motor
    SetVUnits(StartVUnits);
    RUnits = StartRUnits;
    Calibrated=true;
}
bool TMotors::GetCalibrated(){
    return Calibrated;
}
void TMotors::SetVRatio(double r){
    Ratio=r;
}
double TMotors::GetVRatio(){
    return Ratio;
}
double TMotors::GetTargetSettingDelta(){
    return TargetSetting-Rotation();
}