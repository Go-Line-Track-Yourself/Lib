TMotors::TMotors(vex::motor motor[], int num){
    Motors=motor;
    NumberOfMotors=num;
}
void TMotors::Stop(){
    for(int i=0; i < NumberOfMotors; ++i){
            Motors[i].stop(SUnits);
    }
}
void TMotors::SMS(int v){
    VSetting=v;
    if(v==0)    Stop();
    else{
        for(int i=0; i < NumberOfMotors; ++i){
            Motors[i].spin(vex::directionType::fwd,v,VUnits);
        }
    }
}
double TMotors::Rotation(){
    if(NumberOfMotors!=1){
        double Sum=0;
        for(int i=0; i < NumberOfMotors; ++i){
            Sum+=Motors[i].rotation(RUnits);
        }
        return Sum/NumberOfMotors;
    }
    else return Motors[0].rotation(RUnits);
}
void TMotors::SetStop(vex::brakeType sunits){
    SUnits=sunits;
}

TMotors::Controllers::Controllers(){

}
void TMotors::Controllers::SpinTo(int tar,bool sms=true,bool stop=true,bool rel=false,int v=100,int tal=0){
    if(rel) tar+=LastTar;
    if(!MonoDir) Dir=SGN(tar-TMotors.Rotation());//calculates dir needed to get to target
    if(std::abs(Rotation()-tar)>=tal && SpinToRunEnabled){//outside of tal
        SpinToControlEnabled=true;
        if(!MonoDir) Dir=SGN(tar-Rotation());//calculates dir needed to get to target
        SpinToVSetting=v*Dir;//set the motor to spin in the correct direction
    }
    else if(SpinToControlEnabled){//if in tar zone and was enabled; fist not enabled
        SpinToVSetting=0;
        SpinToControlEnabled=false;//deInit
        if(stop)    SpinToRunEnabled=false;//stop after it has been hit
    }
    if(sms) SMS(SpinToVSetting);
}