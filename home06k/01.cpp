#include <iostream>
#include <cmath>
using namespace std;
double epsilon=0.001;
double d=1;
int z=1;
bool flag=true;
int main(){
    for (int i=3;flag==true;i+=2){
        if (z%2==0){
            d=d+(1.0/i);
        } else {
            d=d-(1.0/i);
        }
        if (abs(1.0/(i+2))<abs(epsilon)){
            flag=false;
        }
        z=z+1;
    }
    cout<<d;
    return 0;
}














