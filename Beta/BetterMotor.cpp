#ifndef MotorSystem_CPP
#define MotorSystem_CPP

#include "BetterMotor.h"
using namespace MotorSystem;
    MotorSystem(int Num){
        NumMotors=Num;
        //Motors.reserve(Num);//reserves the memory for Num motors to be added
    }
    void AddMotor(vex::motor & m){
        Motors.at(NumMotors)=m;
        NumMotors++;
    }
    void MinPosLimit(int Pos){
        HasMinPos=true;
        MinPos=Pos;
    }
    void MaxPosLimit(int Pos){
        HasMaxPos=true;
        MaxPos=Pos;
    }
    void PosLimit(int Min,int Max,int MinPct=0,int MaxPct=0){
        MinPosLimit(Min);
        MaxPosLimit(Max);
        PctAtMinPos=MinPct;
        PctAtMaxPos=MaxPct;
    }
    //End SetUp
    //Sensors
    int Position(vex::rotationUnits Units,int Index=1){
        return int(Motors[Index].rotation(Units));
    }
    //End Sensors
    //Motor
    void Stop(){
        for( int i = 0; i < NumMotors; i++){
            Motors[i].stop();
        }
        IsSpining=false;
    }
    void SM(int Pct){
        if(Pct==0)  Stop();
        else{
            IsSpining=true;
            for( int i = 0; i < NumMotors; i++){
                Motors[i].spin(vex::directionType::fwd,Pct,vex::velocityUnits::pct);
            }
        }
    }
    void SMS(int Pct){
        if(HasMinPos && Position(vex::rotationUnits::deg) <= MinPos && Pct<PctAtMinPos){
            SM(PctAtMinPos);
        }
        if(HasMaxPos && Position(vex::rotationUnits::deg)>=MaxPos && Pct>PctAtMaxPos){
            SM(PctAtMaxPos);
        }
        else{
            SM(Pct);
        }
    }
    //End Motor Comands
    /*    void 
    void GetTo(int TargetPos,bool WaitFor,int Pct=MovePct){
        IsSpining=true;
        for(int i=0;i<NumMotors; i++){
            Motors[i].startRotateTo(TargetPos,vex::rotationUnits::deg,Pct,vex::velocityUnits::pct);
        }
        if(Wait){
            while(ABS(TargetPos-Position())>Tal){}
            IsSpining=false;
       }
       else{

       }
       */
#endif