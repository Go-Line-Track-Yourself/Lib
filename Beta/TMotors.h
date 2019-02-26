#ifndef TMotors_h
#define TMotors_h
/*How to use
    make an array of motors that are physicaly one
*/
/*Need to add
    Execute();// Execute
    SetTargets(Pos,V);
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
            double TargetSetting=0;//Rel;what the target is set to
            double Target=TargetSetting;//abs;not used need to implement in controller
            double TargetSum=0;//why
            double Tolerance=1;
        //calib
            bool Calibrated=false;
        //SMS
            double Ratio=1;

        // int VDefault=100;// velocity default setting ->spinto

    public:
        //spin to; needs nested class
        SendControl SendControl=SendControl::SMS;//move to protected

        TMotors(vex::motor motor[],int num);
        // void SetSendControl(SendControl sc,int vs)
        //basic motor control
            void Stop();
            void SMS(int v,bool limit=true);//setMotorSpin
            void SST(double tar,int v);//StartSpinTo
            bool Spinning();
            bool SSTTH();//StartSpinToTargetHit
            double Rotation();
            void ResetRotation();
        //var handlers
            //Units
                //Brake
                    void SetStop(vex::brakeType sunits);
                    vex::brakeType GetStop();
                //Velocity
                    void SetVUnits(vex::velocityUnits vunits);
                    vex::velocityUnits GetVUnits();
                //Rotation
                    void SetRUnits(vex::rotationUnits runits);
                    vex::rotationUnits GetRUnits();
            //SendControl
                void SetSendControl(enum SendControl,int v);
                void SetSendControl(enum SendControl sc);
                enum SendControl GetSendControl();
            //Velocity
                void SetVSetting(int v);
                int GetVSetting();
            //Target
                void SetTargetSetting(double tar);
                void SetTargetSetting(double tar,int v);
                void AddTargetSetting(double tar);
                double GetTargetSetting();
                // void SetTarget(double tar);
                double GetTarget();
                void SetTolerance(double tal);
                double GetTolerance();
            //PosLimit
                void SetMinPos(int pos);
                void SetMaxPos(int pos);
                void SetPosLimits(int minpos,int maxpos);
            //SendRatio
                void SetVRatio(double r);
                double GetVRatio();
        //Functions
            double GetTargetSettingDelta();
            void Calibrate(int rpm=200,float minv=1/4,int timeout=1000,int updatemsec=10,int acelmsec=100);
            bool GetCalibrated();//isCalibrated
            //Wait
                // wait for the motor to get to target
                void SSTWait(int endwait);
                void Wait(double target,double tal,int endwait);
                void Wait(double target,double tal);
                void Wait(int endwait);
};
#include "TMotors.cpp"
#endif