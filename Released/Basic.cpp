double abs(double Var){
    if(Var<0)  Var=Var*(-1);
    return Var;
}
double sgn(double Var){
    if(Var>0)   Var=1;
    else        Var=-1;
    return Var;
}