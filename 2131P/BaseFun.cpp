void PuncherStop(){
    PuncherMotor.stop();
}
void PuncherSMS(int Pct){
    if(Pct==0)  PuncherStop();
    else{
        PuncherMotor.spin(vex::directionType::fwd,Pct,vex::velocityUnits::pct);
    }
}
void IntakeStop(){
    IntakeMotor.stop();
}
void IntakeSMS(int Pct){
    if(Pct==0)  IntakeStop();
    else{
        IntakeMotor.spin(vex::directionType::fwd,Pct,vex::velocityUnits::pct);
    }
}
void FliperStop(){
    FlipMotor.stop();
}
void FliperSMS(int Pct){
    if(FlipMotor.rotation(vex::rotationUnits::deg)>Fliper(UP) && Pct>0)     Pct=0;//upper limit
    if(FlipMotor.rotation(vex::rotationUnits::deg)<Fliper(DOWN) && Pct<0)   Pct=0;//lower limit
    if(Pct==0)  FliperStop();
    else{
        FlipMotor.spin(vex::directionType::fwd,Pct,vex::velocityUnits::pct);
    }
}
//
void LeftDriveStop(){
    FLDriveMotor.stop();
    BLDriveMotor.stop();
}
void RightDriveStop(){
    FRDriveMotor.stop();
    BRDriveMotor.stop();
}
void LeftDriveSMS(int pct){
    if(pct==0)   LeftDriveStop();
    else{
        FLDriveMotor.spin(vex::directionType::fwd,pct,vex::velocityUnits::pct);
        BLDriveMotor.spin(vex::directionType::fwd,pct,vex::velocityUnits::pct);
    }
}
void RightDriveSMS(int pct){
    if(pct==0)  RightDriveStop();
    else{
        FRDriveMotor.spin(vex::directionType::fwd,pct,vex::velocityUnits::pct);
        BRDriveMotor.spin(vex::directionType::fwd,pct,vex::velocityUnits::pct);
    }
}
void DriveSMS(int left, int right){
    LeftDriveSMS(left);
    RightDriveSMS(right);
}