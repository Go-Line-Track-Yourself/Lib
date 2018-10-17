void PuncherControl(){
    if(Controller1.ButtonX.pressing()){
        IntakeSetting=Intake(STOP);
        PuncherSMS(100);
    }
    else    PuncherSMS(0);
}
//
void IntakeManualControl(){
    if(Controller1.ButtonR2.pressing()){
        IntakeManualControlEnabled=true;
        IntakeSMS(Intake(OUT));
    }
    else if(Controller1.ButtonR1.pressing()){
        IntakeManualControlEnabled=true;
        IntakeSMS(Intake(IN));
    }
    else if(IntakeManualControlEnabled){//first loop disabled
        IntakeSetting=Intake(STOP);
        IntakeManualControlEnabled=false;
    }
}
//
void IntakeToggleControl(){
    if(Controller1.ButtonB.pressing() && !BPressed){
        BPressed=true;
        IntakeSetting=Intake(STOP);
    }
    else if(Controller1.ButtonY.pressing() && !YPressed){
        YPressed=true;
        IntakeSetting=Intake(IN);
    }
    else if(Controller1.ButtonA.pressing() && !APressed){
        APressed=true;
        IntakeSetting=Intake(OUT);
    }
    if(!Controller1.ButtonB.pressing() && BPressed)     BPressed=false;
    if(!Controller1.ButtonY.pressing() && YPressed)     YPressed=false;
    if(!Controller1.ButtonA.pressing() && APressed)     APressed=false;

    IntakeSMS(IntakeSetting);
}
void IntakeControl(){
    IntakeManualControl();
    if(!IntakeManualControlEnabled) IntakeToggleControl();
}
//
void FliperManualControl(){
    if(Controller1.ButtonRight.pressing()){
        FliperManualControlEnabled=true;
        FliperSMS(100);  
    }
    else if(Controller1.ButtonLeft.pressing()){
        FliperManualControlEnabled=true;
        FliperSMS(-100);
    }
    else if(FliperManualControlEnabled){//first loop
        FliperSMS(0);
        FliperManualControlEnabled=false;
    }
}
void FliperFlip(){
    if(FliperRequested==Fliper(UP)) FliperRequested=Fliper(DOWN);
    else if(FliperRequested==Fliper(DOWN))  FliperRequested=Fliper(UP);
}
void FliperPosControl(){
    if(Controller1.ButtonL1.pressing() && !L1Pressed){
        L1Pressed=true;
        FliperFlip();
        FliperPosControlEnabled=true;
    }
    if(Controller1.ButtonL2.pressing() && !L2Pressed){
        L2Pressed=true;
        FliperFlip();
        FliperPosControlEnabled=true;
    }

    if(!Controller1.ButtonL1.pressing() && L1Pressed)   L1Pressed=false;
    if(!Controller1.ButtonR2.pressing() && L2Pressed)   L2Pressed=false;

    if(FliperPosControlEnabled){
        if(std::abs(FliperRequested-FlipMotor.rotation(vex::rotationUnits::deg))<Fliper(TAL)){//when gets near
            FliperPosControlEnabled=false;
            FliperSMS(0);   
        }
        else{
            FlipMotor.startRotateTo(FliperRequested,vex::rotationUnits::deg,100,vex::velocityUnits::pct);
        }
    }
}
void FliperControl(){
    FliperManualControl();
    FliperPosControl();
}
//
Ramping LDR(1,1);   //LeftDriveRamping
Ramping RDR(1,1);   //RightDriveRamping
void DR(int LPct,int RPct){
    LDR.RequestedPct=LPct;
    RDR.RequestedPct=RPct;
}
int DriveRamping(){
    while(1){
        LDR.TaskRun();
        RDR.TaskRun();
        DriveSMS(LDR.Pct,RDR.Pct);
        vex::task::sleep(LDR.ChangeMsec);
    }
}
void DriveManualControl(){
    if(Controller1.ButtonUp.pressing() && !DriveInvertConBtnPressed){
        DriveInvertConBtnPressed=true;
        DriveMotorInverted=!DriveMotorInverted;
    }
    else if(!Controller1.ButtonUp.pressing() && DriveInvertConBtnPressed){
        DriveInvertConBtnPressed=false;
    }
    LJoy=Controller1.Axis3.value();
    RJoy=Controller1.Axis2.value();

    if(LJoy!=0 || RJoy!=0){
        DriveManualControlEnabled=true;
        DR(DriveMotorInverted ? -RJoy : LJoy,DriveMotorInverted ? -LJoy : RJoy);
    }
    else{
        if(DriveManualControlEnabled)  DR(0,0);//Last loop before disableing; used to release drivemanualcontrol
        DriveManualControlEnabled=false;
    }
}
//