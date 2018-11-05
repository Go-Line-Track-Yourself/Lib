#ifndef Timer_cpp
#define Timer_cpp
class Timer{
    public:
    int StartTime=0;
    int TargetTime=0;

    Timer(int Tar){
        TargetTime=Tar;
    }
    int RelTime=Brain.timer(vex::timeUnits::msec)-StartTime;//counts up
    int Remaning=TargetTime-RelTime;//counts down
    bool Hit(){
        return (Remaing<0);
    }
    void Start(double T){
        Started=true;
        StartTime=T+1;
    }
};
#endif
Timer lift(10000);
