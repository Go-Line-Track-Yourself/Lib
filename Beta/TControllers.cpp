TControllers::TControllers(TMotors &motor,bool spinto){
    Motor=&motor;
    SpinToControlEnabled=true;
}
void TControllers::RampingInit(Ramping &ramp){
    // Ramp=&ramp;
    // Motor->SendControl=SendControl::Ramping;
}
void TControllers::OutPut(int v){
    // switch(Motor->SendControl){
    //     case SendControl::SMS :
    //         Motor->SMS(v);
    //         break;
    //     case SendControl::Ramping :
    //         Ramp->Request(v);
    //         break;
    // }
}
void TControllers::SpinTo(int tar,bool sms=true,bool stop=true,bool rel=false,int v=100,int tal=0){
    if(rel) tar+=LastTar;
    if(!MonoDir){
        Dir=SGN(tar-Motor->Rotation());//calculates dir needed to get to target
            if(std::abs(Motor->Rotation()-tar)>=tal && SpinToRunEnabled){//outside of tal
                SpinToControlEnabled=true;
                if(!MonoDir) Dir=SGN(tar-Motor->Rotation());//calculates dir needed to get to target
                SpinToVSetting=v*Dir;//set the motor to spin in the correct direction
            }
            else if(SpinToControlEnabled){//if in tar zone and was enabled; fist not enabled
                SpinToVSetting=0;
                SpinToControlEnabled=false;//deInit
                if(stop)    SpinToRunEnabled=false;//stop after it has been hit
            }
            if(sms) Motor->SMS(SpinToVSetting);
    }
    else{
        if((Motor->Rotation())<(tar) && SpinToRunEnabled){//outside of tal
            SpinToControlEnabled=true;
            // Dir=SGN(Tar-PuncherMotor.rotation(vex::rotationUnits::deg));
            SpinToVSetting=v*Dir;//set the motor to spin in the correct direction
        }
        else if(SpinToControlEnabled){//if in tar zone and was enabled; fist not enabled
            SpinToVSetting=0;
            SpinToControlEnabled=false;//toggle
            if(stop)    SpinToRunEnabled=false;//stop after it has been hit
        }
        if(sms) Motor->SMS(SpinToVSetting);
    }
}