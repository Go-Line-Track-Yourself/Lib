#ifndef Timer
#define Timer

class Timer{
    public:
    int StartTime=0;
    int TargetTime=3000;

    bool Started=false;

    Timer(int Tar){
        TargetTime=Tar;
    }

    int RelTime=Brain.timer(vex::timeUnits::msec)-StartTime;//counts up
    int Remaning=TargetTime-RelTime;//counts down
    bool Hit();
    void Start(double T);

};
#endif