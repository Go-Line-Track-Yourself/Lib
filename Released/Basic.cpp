#ifndef Basic_cpp
#define Basic_cpp
double ABS(double Var){//use "#include <cmath>" and "std::abs()"instead
    if(Var<0)  Var=Var*(-1);
    return Var;
}
int SGN(double Var){
    if(Var>0)   Var=1;
    else        Var=-1;
    return Var;
}
#endif