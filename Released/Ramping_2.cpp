#ifndef Ramping_2_cpp
#define Ramping_2_cpp
class Ramping{
    protected:
        int ChangeVal=1;    //the amout of Val change per loop

        int ValRequested=0; //used to request value
        int ValOutput=0;    //val output
        int MaxVal=100;     //the max val output
        int MinVal=0;       //the min val output
    public:
        //need to move to protected
            bool Enabled=false;
            int ChangeMsec=1;   //the amount of time inbetween loops

        Ramping(int CV,int CM,int maxV=100,int minV=0){
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
        int Output(){
            return ValOutput;
        }
};
#endif