#include <iostream>
using namespace std;

int nalog(double n){
    return n*0,13;
}
int sum(double x,double y){
    return x-y;
}

double input(){
    double f;
    cin>>f;
    return f;
}

int main(){
    double a,b,c,d,e,r,p;
    a=input();
    b=input();
    c=input();
    d=a*b;
    e=(d/100)*c;
    r=d+e;

    cout <<nalog(r);
    cout<<sum(r,nalog(r));
    return 0;
}



