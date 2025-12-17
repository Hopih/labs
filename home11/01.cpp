#include <iostream>
using namespace std;

double sum(double x,double y){
    return x+y;
}

double ruz(double x, double y){
    return x-y;
}

double proz(double x,double y){
    return x*y;
}

int main(){
    double a;
    double b;
    cin>>a>>b;
    cout<<sum(proz(5,ruz(sum(a,b),2)),proz(1000,a));
    return 0;
}

















