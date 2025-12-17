#include <iostream>
#include <windows.h>
#include <string>
#include <cmath>
#include <math.h>
using namespace std;
int main(){
    int n;
    float t=0.0;
    float result;
    cin>>n;
    for(int i=2;i<=2*n;i=i+2){
        result=double(1)/double(i);
        t=t+result;
    }
    cout<<t;
    return 0;
}




