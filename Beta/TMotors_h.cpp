#ifndef TMotors_h_cpp
#define TMotors_h_cpp
/*
make an array of motors that are physicaly one
*/
    enum class SendControl{Ramping,SetMotorSpin};

class TMotors{
    protected:
        vex::motor *Motors;//array of motors
        vex::velocityUnits VUnits = vex::velocityUnits::pct;//velocity units
        vex::rotationUnits RUnits = vex::rotationUnits::deg;//rotation units
        vex::brakeType SUnits = vex::brakeType::coast;//stop units

        SendControl SendControl=SendControl::SetMotorSpin;
        int NumberOfMotors=0;// number of motors->Stop,SMS
        int VSetting=0;// velocity setting
        // int VDefault=100;// velocity default setting ->spinto
    public:
        
        //spin to; needs nested class

        TMotors(vex::motor motor[],int num);
        void Stop();
        void SMS(int v);
        double Rotation();
        void SetStop(vex::brakeType sunits);

        class Controllers{
            public:
                bool SpinToControlEnabled=false;// currently spining to target
                bool SpinToRunEnabled=false;// stops when it gets to target; gets rid of bounces
                int SpinToVSetting=0;// requested dir; output
                int Dir=1;// direction need to spin to get to target
                bool MonoDir=false;// motor only spins one way to get to target
                int LastTar=0;// last target->spinto

                Controllers();
                void SpinTo(int tar,bool sms,bool stop,bool rel,int v,int tal);
        };
        // void SpinToInit(int Tar=0,bool SMS,bool Stop,int Rel);
        // void SpinTo(int Tar,int V,int Tal);
};
#include "TMotors.cpp"
#endif