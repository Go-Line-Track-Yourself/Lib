#include "AutoStraight.h"
AutoStraight DriveStr()
#ifndef Drive
#define Drive

class Drive{
    public:
    int Input=0;
    float WheelCer=12.56;
    int RequestDeg=0;

    int Pct1=0;
    int Pct2=0;

    Drive(float WC){
    WheelCer=WC;
    }

    void Forward(int Dis,int Power);

    void Input(int IV);
};
#endif