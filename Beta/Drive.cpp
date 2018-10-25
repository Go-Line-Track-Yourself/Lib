#include "Drive.h"
void Drive::Forward(int Dis,int Power){
    RequestDeg=(Dis/WheelCer)*360;
    while(Input)<RequestDeg){
        DriveStr.Straight()
        Pct1=DriveStr.Pct1;
        Pct2=DriveStr.Pct2;
    }
    Pct1=0;
    Pct2=0;    
}

void Drive::Input(int IV){
    Input=IV;
}