double ABS(double Var){
    if(Var<0)  Var=Var*(-1);
    return Var;
}
int SGN(double Var){
    if(Var>0)   Var=1;
    else        Var=-1;
    return Var;
}