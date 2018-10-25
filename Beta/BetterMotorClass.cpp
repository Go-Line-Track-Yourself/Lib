int PuncLastRotation=0;
bool PuncherMotorIsSpinningUpDaterEnabled=true;
bool PMIS=false;//PuncherMotorIsSpinning renamed becuse vex v4 api made me
bool PuncherMotorIsSpinning(){
    if(abs(PuncherMotor.rotation(vex::rotationUnits::deg)-10)>PuncLastRotation)   return false;
    else                                        return true;
    // PuncLastRotation=PuncherMotor.rotation(vex::rotationUnits::raw);
}

int PuncherMotorIsSpinningUpDater(){
    PuncherMotorIsSpinningUpDaterEnabled=true;
    while(PuncherMotorIsSpinningUpDaterEnabled){
        PuncLastRotation=PuncherMotor.rotation(vex::rotationUnits::deg);
        PMIS=PuncherMotorIsSpinning();
        vex::task::sleep(1);
    }
    return 1;
}