//#ifndef Timer
//#define Timer

class Timer{
    public:
    int StartTime=0;
    bool Started=false;
    int TargetTime=0;

    Timer(int Tar);

    int RelTime=Brain.timer(vex::timeUnits::msec)-StartTime;//counts up
    int Remaining=TargetTime-RelTime;//counts down
    bool Hit();
    void Start(double T);

};
//#endif