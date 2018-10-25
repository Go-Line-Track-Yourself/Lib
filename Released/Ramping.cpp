#include "Ramping.h"
void Ramping::TaskRun(){
    if(RequestedPct>Pct){
        Pct=Pct+ChangePct;
    }
    else if(RequestedPct<Pct){
        Pct=Pct-ChangePct;
    }
    //limit Pct
    if(Pct>MaxPct)	Pct=MaxPct;
    if(Pct<-MaxPct)	Pct=-MaxPct;
    if(Pct>0 && Pct<MinUpPct) Pct=MinUpPct;
    if(Pct<0 && Pct>MinDownPct)    Pct=MinDownPct;
}