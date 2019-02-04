#ifndef PID_h
#define PID_h

class PID{
    protected:
        double Kp=0;
        double Ki=0;
        double Kd=0;

        double P=0;
        double I=0;
        double D=0;

        double LastError=0;
        int Time=0;

        bool HasMinValue=false;
        bool HasMaxValue=false;
        int MinValue=0;
        int MaxValue=0;
        bool HasMidValue=false;
        int MidMin=0;
        int MidMax=0;
        int MidValue=0;
    public:
        PID(double kp,double ki,double kd,int time);
        double Output(double tar,double cur);
        void SetMinValue(int minv);
        void SetMaxValue(int maxv);
        void SetLimits(int minv,int maxv);
        void SetMidLimits(int minv,int maxv,int midv);
};

#include "Lib/Beta/PID.cpp"
#endif