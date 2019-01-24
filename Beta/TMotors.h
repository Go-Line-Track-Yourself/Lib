#ifndef TMotors_h
#define TMotors_h
/*
make an array of motors that are physicaly one
*/
    enum class SendControl{Ramping,SMS};

class TMotors{
    protected:
        vex::motor *Motors;//array of motors
        vex::velocityUnits VUnits = vex::velocityUnits::pct;//velocity units
        vex::rotationUnits RUnits = vex::rotationUnits::deg;//rotation units
        vex::brakeType SUnits = vex::brakeType::coast;//stop units

        int NumberOfMotors=0;// number of motors->Stop,SMS
        int VSetting=0;// velocity setting; used for when there are layered controllers
        int VSet=0;//what the last SMS request was
        // int VDefault=100;// velocity default setting ->spinto
    public:
               SendControl SendControl=SendControl::SMS;
 
        //spin to; needs nested class

        TMotors(vex::motor motor[],int num);
        void Stop();
        void SMS(int v);
        double Rotation();
        void SetStop(vex::brakeType sunits);
        vex::brakeType GetStop();
        int SetVSetting(int v);
        int GetVSetting();
        // void SpinToInit(int Tar=0,bool SMS,bool Stop,int Rel);
        // void SpinTo(int Tar,int V,int Tal);
};
#include "TMotors.cpp"
#endif