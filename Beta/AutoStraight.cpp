#include "AutoStraight.h"

void AutoStraight::Straight(int P,int C){
    Pct=P;
    Correction=C;
    if(abs(Input1)>abs(Input2)){
        Pct1=Pct-Correction;
        Pct2=Pct;
    }
    else if(abs(Input1)<abs(Input2)){
        Pct1=Pct;
        Pct2=Pct-Correction;
    }
    else if(abs(Input1)==abs(Input2)){
        Pct1=Pct;
        Pct2=Pct;
    }
}

void AutoStraight::Input(int IV1, int IV2){
    Input1=IV1;
    Input2=IV2;
}