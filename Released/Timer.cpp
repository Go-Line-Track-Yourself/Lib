#include "Timer.h"
    Timer::Timer(int Tar){
        TargetTimer=Tar;
    }
    bool Timer::Hit(){
        if(Remaining<0)      return true;
        else                return false;
    }
    void Timer::Start(double T){
        Started=true;
        StartTime=T+1;
    }

};