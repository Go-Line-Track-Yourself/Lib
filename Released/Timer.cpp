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
        return (Remaning<0);
    }
    void Start(double T){
        
        StartTime=T;
    }
};
#endif
Timer lift(10000);
