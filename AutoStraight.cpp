class Straight{
public:
int Pct1=0;
int Pct2=0;
int InputVal=0;
int RequestVal;
int StraightRun(){
	while(abs(InputVal)<RequestVal){
            if(abs(SensorValue[rightEnc])>abs(SensorValue[leftEnc])){
                driveLPower=power;
                driveRPower=power-driveCorrection;
                }
            if(abs(SensorValue[rightEnc])<abs(SensorValue[leftEnc])){
                driveLPower=power-driveCorrection;
                driveRPower=power;
            }
            if(abs(SensorValue[rightEnc])==abs(SensorValue[leftEnc])){
                driveLPower=power;
                driveRPower=power;
            }
        }
    }
}