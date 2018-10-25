#include "Timer.h"

    bool Timer::Hit(){
        if(Remaning<0)      return true;
        else                return false;
    }
    void Timer::Start(double T){
        Started=true;
        StartTime=T+1;
    }

};