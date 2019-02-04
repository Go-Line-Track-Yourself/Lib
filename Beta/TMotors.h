#ifndef TMotors_h
#define TMotors_h
/*How to use
    make an array of motors that are physicaly one
*/
/*Need to add
    Execute();// Execute
*/
    enum class SendControl{NONE,SST,SMS};

class TMotors{
    protected:
        vex::motor *Motors;//array of motors
        vex::velocityUnits VUnits = vex::velocityUnits::pct;//velocity units
        vex::rotationUnits RUnits = vex::rotationUnits::deg;//rotation units
        vex::brakeType SUnits = vex::brakeType::coast;//stop units

        int NumberOfMotors=0;// number of motors->Stop,SMS
        int VSetting=0;// velocity setting; used for when there are layered controllers
        int VSet=0;//what the last SMS request was
        int VMinChange;//used to calculate if it is spining or not
        //Motor Limits
            bool MinPosEnabled=false;
            bool MaxPosEnabled=false;
            int MinPos;
            int MaxPos;
        //SST
            double TargetSetting=0;
            double Target=TargetSetting;

        //calib
            bool Calibrated=false;
        //SMS
            double Ratio=1;

        // int VDefault=100;// velocity default setting ->spinto
    public:
                SendControl SendControl=SendControl::SMS;
                double TargetSum=0;

 
        //spin to; needs nested class

        TMotors(vex::motor motor[],int num);
        // void SetSendControl(SendControl sc,int vs)
        void Stop();
        void SMS(int v,bool limit=true);//setMotorSpin
        void SST(double tar,int v);//StartSpinTo
        bool Spinning();
        bool SSTTH();//StartSpinToTargetHit
        double Rotation();
        void ResetRotation();
        void SetStop(vex::brakeType sunits);
        vex::brakeType GetStop();
        void SetVUnits(vex::velocityUnits vunits);
        vex::velocityUnits GetVUnits();
        void SetRUnits(vex::rotationUnits runits);
        vex::rotationUnits GetRUnits();
        void SetVSetting(int v);
        int GetVSetting();
        void SetTargetSetting(double tar);
        void AddTargetSetting(double tar);
        double GetTargetSetting();
        void SetTarget(double tar);
        double GetTarget();
        void SetMinPos(int pos);
        void SetMaxPos(int pos);
        void SetPosLimits(int minpos,int maxpos);
        void Calibrate(int rpm=200,float minv=1/4,int timeout=1000,int updatemsec=10,int acelmsec=100);
        bool GetCalibrated();
        void SetVRatio(double r);
        double GetVRatio();
        double GetTargetSettingDelta();
        // void SpinToInit(int Tar=0,bool SMS,bool Stop,int Rel);
        // void SpinTo(int Tar,int V,int Tal);
};
#include "TMotors.cpp"
#endif