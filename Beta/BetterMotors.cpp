#ifndef MotorSystem_CPP
#define MotorSystem_CPP
#include <vector>
enum class MoveType{STOPED,GETTO,PID,TIME};
class MotorSystem{
    public:
    //    enum class ControlTypes{NONE,BTNS,TOGl,JOY};
    MoveType System
    std::vector<vex::motor> Motors;
    int NumMotors=0;
    bool IsSpining=false;
    int MovePct=100;//Defalt Pct for moving
    int SSPct=0;//Still Speed Pct
    int Tal=5;//get to talerance

    int MinPos, MaxPos;
    bool HasMinPos=false, HasMaxPos=false;
    int PctAtMinPos=0;//Min Pos Still Speed
    int PctAtMaxPos=0;//Max Pos Still Speed

    int TargetPos;
    //SetUp
    MotorSystem(int Num,vex::motor * Mots){
        NumMotors=Num;
        for(int i=0;i<Num;i++){
            Motors.at(i)=Mots[i];
        }
        System=MoveType::STOPED;
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
    void Execute(){

    }
    /*
    void GetTO(int Pos, bool runConcurrently=true, int movePower=127, int endPower=128, int timeout=10) {	//TODO: auto-determine endPower as in moveForDuration
	TargetPos = Pos;
	group->forward = group->targetPos > getPosition(group);
	group->movePower = abs(movePower) * (group->forward ? 1 : -1);
	group->endPower = (endPower>127 ? calcStillSpeed(group, group->forward) : endPower);
	group->maneuverTimeout = timeout;
	group->maneuverTimer = resetTimer();
	group->moving = MANEUVER;

	setPower(group, group->movePower);

	if (!runConcurrently) {
		while (group->moving == MANEUVER) {
			executeAutomovement(group);
			EndTimeSlice();
		}
	}
}
    */




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