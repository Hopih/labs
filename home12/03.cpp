#include <iostream>
using namespace std;

double add(double x,double y){
    return (x+y)/2.0;
}

double add(double x,double y,double z){
    return (x+y+z)/3.0;
}

double add(double x,double y,double z,double d){
    return (x+y+z+d)/4.0;
}

int main(){
    cout<<add(1,2)<<endl;
    cout<<add(1,2,3)<<endl;
    cout<<add(1,2,3,4)<<endl;
    return 0;
}


















