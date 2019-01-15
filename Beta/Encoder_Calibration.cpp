void LiftCal(){
        LiftCaled=false;
        int Rpm=-100;
        int TimeOut=1000;
        int UpdateMsec=50;
        int CalTimer=0;
        DI(Rpm);
        double MinChange=Rpm/120000*UpdateMsec;///(1/4)*(Rpm/60/1000); MinChange = 1/4 of requested rpm but in msec`s
        vex::task::sleep(250);//wait for acel
        double LastRotation=LiftMotor.rotation(vex::rotationUnits::rev)/1000;//make sure it goes first loop
        while(std::abs(LiftMotor.rotation(vex::rotationUnits::rev)-LastRotation)>MinChange && CalTimer<TimeOut){//if displacement is more then 1/4 of what it is set to be and it is not out of time
            LastRotation=LiftMotor.rotation(vex::rotationUnits::rev);
            CalTimer=CalTimer+UpdateMsec;
            vex::task::sleep(UpdateMsec);
        }
        LiftMotor.resetRotation();
        LiftMotor.stop();
        LiftCaled=true;
        LiftSpinToControlRunEnabled=true;
        LiftSpinToControlEnabled=true;
        while(LiftSpinToControlEnabled){
            LiftSpinTo(LiftFlagPos[1]);
            DR(LiftPctSetting);
            EndTimeSlice();
        }
    }
    int LiftCalTaskFun(){
        LiftCal();
        return 1;
    }