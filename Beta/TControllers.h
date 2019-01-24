#ifndef TControllers_h
#define TControllers_h

class TControllers{
    private:
        TMotors *Motor;
        Ramping *Ramp;
        
    public:
       bool SpinToControlEnabled=false;// currently spining to target
        bool SpinToRunEnabled=false;// stops when it gets to target; gets rid of bounces
        int SpinToVSetting=0;// requested dir; output
        int Dir=1;// direction need to spin to get to target
        bool MonoDir=false;// motor only spins one way to get to target
        int LastTar=0;// last target->spinto
    TControllers(TMotors &motor);
    void RampingInit(Ramping &ramp);
    void OutPut(int v);
    void SpinTo(int tar,bool sms,bool stop,bool rel,int v,int tal);
};
#include "TControllers.cpp"
#endif