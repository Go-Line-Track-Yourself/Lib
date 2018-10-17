bool YPressed=false;//in
bool BPressed=false;//stop
bool APressed=false;//out
bool IntakeManualControlEnabled=false;
bool IntakeToggleControlEnabled=false;
enum Intake{OUT=-50,STOP=0,IN=100};
int IntakeSetting=Intake(STOP);
//
bool DriveMotorInverted=false;
bool DriveInvertConBtnPressed=false;
//
bool FliperManualControlEnabled=false;
bool FliperPosControlEnabled=false;
bool L1Pressed=false;
bool L2Pressed=false;
enum Fliper{UP=-40,DOWN=-460,TAL=5};
int FliperRequested=Fliper(UP);
//
bool DriveManualControlEnabled=false;
int LJoy=0;
int RJoy=0;