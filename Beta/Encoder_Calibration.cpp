#ifndef Encoder_Calibration_cpp
#define Encoder_Calibration_cpp
void EncoderCalibration(vex::motor M,int Timeout,int Pct,int MinChange=0){
    M.spin(vex::directionType::fwd,Pct,vex::velocityUnits::pct);
    while(std::abs(M.rotation(vex::rotationUnits::deg)-LastRotation) > MinChange)){
        vex::task::sleep(20);
    }
}
#endif
/*
    FlipMotor.setTimeout(1,vex::timeUnits::msec);
    FlipMotor.spin(vex::directionType::fwd,100,vex::velocityUnits::pct);
    while(FlipMotor.isSpinning()){}
    FlipMotor.setTimeout(250,vex::timeUnits::msec);
    FlipMotor.resetRotation();
    return 1;
    */