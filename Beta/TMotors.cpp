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