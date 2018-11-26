#ifndef Ramping_cpp
#define Ramping_cpp
class Ramping{
    public:
    int ChangePct=1;      //the amout of Pct change per loop
    int ChangeMsec=1;     //the amount of time inbetween loops

    int RequestedPct=0;   //used to request Pct value change
    int Pct=0;            //Pct output
    int MinUpPct=2;         //Used as moveing up StillSpeed
    int MinDownPct=2;       //Used as moving down StillSpeed
    int MaxPct=100;         //the max pct value

    Ramping(int CP,int CM,int MaxP=100,int MinDP=0,int MinUP=0){
        //ChangePct,ChangeMsec,MaxPct
        ChangePct=CP;
        ChangeMsec=CM;
        MaxPct=MaxP;
        MinUpPct=MinUP;
        MinDownPct=MinDP;
    }

    void TaskRun(){
        if(RequestedPct>Pct){
            Pct=Pct+ChangePct;
        }
        else if(RequestedPct<Pct){
            Pct=Pct-ChangePct;
        }
        //limit Pct
        if(Pct>MaxPct)	Pct=MaxPct;
        if(Pct<-MaxPct)	Pct=-MaxPct;
        if(Pct>0 && Pct<MinUpPct)   Pct=MinUpPct;
        if(Pct<0 && Pct>MinDownPct) Pct=MinDownPct;
    }
};
#endif