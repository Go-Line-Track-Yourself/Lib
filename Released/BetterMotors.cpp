#ifndef MotorSystem_CPP
#define MotorSystem_CPP
#include <vector>
class MotorSystem{
    public:
    //    enum class ControlTypes{NONE,BTNS,TOGl,JOY};
    std::vector<vex::motor> Motors;
    int NumMotors=0;
    bool IsSpining=false;
    int MovePct=100;//Defalt Pct for moving
    int SSPct=0;//Still Speed Pct
    int Tal=5;//get to talerance

    int MinPos, MaxPos;
    bool HasMinPos=false, HasMaxPos=false;
    int PctAtMinPos=0;//Min Pos Still Speed
    int PctAtMaxPos=0;//Max Pos Still Speee
    //SetUp
    MotorSystem(int Num,vex::motor * Mots){
        NumMotors=Num;
        for(int i=0;i<Num;i++){
            Motors.at(i)=Mots[i];
        }
        //Motors.reserve(Num);//reserves the memory for Num motors to be added
    }
    void AddMotor(vex::motor & m){
        Motors.at(NumMotors)=m;
        NumMotors++;
    }
    void MinPosLimit(int Pos,int MinPct=0){
        HasMinPos=true;
        MinPos=Pos;
        PctAtMinPos=MinPct;
    }
    void MaxPosLimit(int Pos,int MaxPct=0){
        HasMaxPos=true;
        MaxPos=Pos;
        PctAtMaxPos=MaxPct;
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
    //Motor Comands
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
    /* 
    void GetTo(int TargetPos,bool WaitFor,int Pct=MovePct){
       SMS(Pct)
        if(Wait){
            while(ABS(TargetPos-Position())>Tal){}
            IsSpining=false;
       }
       else{

       }
       */
};
#endif