#include <vector>
#ifndef BetterMotor_h
#define BetterMotor_h

class MotorSystem{
    public:
    //    enum class ControlTypes{NONE,BTNS,TOGl,JOY};
    std::vector<vex::motor> Motors;
    int NumMotors=0; 
    bool IsSpining=false;
    int MovePct=100;//Defalt Pct for moving
    int SSPct=0;//Still Speed Pct
    int Tal=5;//get within

    int MinPos, MaxPos;
    bool HasMinPos=false, HasMaxPos=false;
    int PctAtMinPos=0;//Min Pos Still Speed
    int PctAtMaxPos=0;//Max Pos Still Speee
    //SetUp
    MotorSystem(int Num);
    void AddMotor(vex::motor & m);
    void MinPosLimit(int Pos);
    void MaxPosLimit(int Pos);
    void PosLimit(int Min,int Max,int MinPct=0,int MaxPct=0);
    //End SetUp
    //Sensors
    int Position(vex::rotationUnits Units,int Index=1);
    //End Sensors
    //Motor
    void Stop();
    void SM(int Pct);
    void SMS(int Pct);
};
#endif