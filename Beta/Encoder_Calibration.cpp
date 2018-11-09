#ifndef Encoder_Calibration_cpp
#define Encoder_Calibration_cpp
//copy function and change motor object and change Rpm for direction
//run this in a task so it doesnt stop the main cood loop
#include <cmath>
int JawCal(){
    int Rpm=-200;       //Velocity to hit the end stop
    int TimeOut=1000;   //Max time to hit end stop
    int UpdateMsec=20;  //the time delay in the loop
    int CalTimer=0;     //resets a local timer
    JawMotor.spin(vex::directionType::fwd, Rpm, vex::velocityUnits::rpm);   //starts the spin to hit the end stop 
    double MinChange=Rpm/240000*UpdateMsec;                                 ///(1/4)*(Rpm/60/1000); MinChange = 1/4 of requested rpm changed into msec instead of min
    LastRotation=JawMotor.rotation(vex::rotationUnits::rev)+4*MinChange;    //makes sure that the while loop starts
    vex::task::sleep(100);                                                  //wait for the motor get some speed
    while(std::abs(JawMotor.rotation(vex::rotationUnits::rev)-LastRotation)>MinChange && CalTimer<TimeOut){//while the motors displacement is more then the MinChange and while the the timer is less then the timeout time
        LastRotation=JawMotor.rotation(vex::rotationUnits::rev);//update LastRotation
        CalTimer=CalTimer+UpdateMsec;   //add time to the timer
        vex::task::sleep(UpdateMsec);   //wait for the motor to spin
    }                                   //motor stoped spinning or time ran out
    if(CalTimer>=TimeOut) return 0;     //if timed out return error code 0 or false
    else{                               //hit the end stop
    JawMotor.resetRotation();           //reset the rotation
    JawMotor.stop();                    //dont burn out the motor
    return 1;                           //return 1 or true
    }
}
#endif