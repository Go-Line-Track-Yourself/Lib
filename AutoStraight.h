#ifndef AutoStraight
#define AutoStraight
class AutoStraight{
public:
int Input1=0;
int Input2=0;
int Pct=100;
int Correction=2;
int Pct1=0;
int Pct2=0;

AutoStraight(int P,int Cor){
    Pct=P;
    Correction=Cor;
}
void Straight(int P,int C);

void Input(int IV1, int IV2);
};
#endif