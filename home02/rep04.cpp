#include <iostream>
using namespace std;

void input(double&x,double&y,double&z){
    cin>>x>>y>>z;
}


void money(double f,double  g,double  h,double &answ1,double &answ2,double &answ3){
    double sum,nalog,clearsum;
    
    sum=(f*g)+(((f*g)/100.0)*h);
    nalog=sum*0.13;
    clearsum=sum-nalog;
    answ1=sum;
    answ2=nalog;
    answ3=clearsum;
}

int main(){
    double a,b,c;
    double i,j,k;
    input(a,b,c);
    money(a,b,c,i,j,k);
    cout<<"sum "<<i<<" nalog "<<j<<" clearsum "<<k;
    return 0;
}


















