#include <iostream>
using namespace std;

double nalog(double n){
    return n*0.13;
}
double sum(double x,double y){
    return x-y;
}

void input(double&x,double&y,double&z){
    cin>>x>>y>>z;
}

int main(){
    double a,b,c,d,e,r,p;
    input(a,b,c);
    d=a*b;
    e=(d/100)*c;
    r=d+e;

    cout <<nalog(r)<<endl;
    cout<<sum(r,nalog(r));
    return 0;
}
