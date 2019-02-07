#ifndef Ramping_2_cpp
#define Ramping_2_cpp
class Ramping{
    protected:
        double ChangeVal=1;    //the amout of Val change per loop

        double ValRequested=0; //used to request value
        double ValOutput=0;    //val output
        double MaxVal=100;     //the max val output
        double MinVal=0;       //the min val output
    public:
        //need to move to protected
            bool Enabled=false;
            int ChangeMsec=1;   //the amount of time inbetween loops

        Ramping(double CV,double CM,double maxV=100,double minV=0){
            ChangeVal=CV;
            ChangeMsec=CM;
            MaxVal=maxV;
            MinVal=minV;
        }

        void Run(){
            if(ValRequested>ValOutput){
                ValOutput+=ChangeVal;
            }
            else if(ValRequested<ValOutput){
                ValOutput-=ChangeVal;
            }
            //limit Val
            if(ValOutput>MaxVal)	ValOutput=MaxVal;
            if(ValOutput<-MaxVal)	ValOutput=-MaxVal;
            if(ValOutput>0 && ValOutput<MinVal) ValOutput=MinVal;
            if(ValOutput<0 && ValOutput>MinVal) ValOutput=-MinVal;
        }
        void Request(int val){
            ValRequested=val;
        }
        void Instant(int val){
            Request(val);
            ValOutput=val;
        }
        double Output(){
            return ValOutput;
        }
};
#endif