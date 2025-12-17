#include <iostream>
using namespace std;

double money(double f,double g,double h){
    double sum,nalog,clearsum;
    sum=f*g;
    nalog=sum*0.13;
    clearsum=sum-nalog;
    cout<<sum<<" "<<nalog<<" "<<clearsum;
    return 0;
}

int main(){
    double a,b,c;
    cin>>a>>b>>c;
    cout<< money(a,b,c);
    return 0;
}














