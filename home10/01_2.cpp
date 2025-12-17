#include <iostream>
using namespace std;
#include <cmath>
int main(){
    float m[5]={1.5,M_PI,-1.5,3.0,-2.3};
    cout<<*m<<" "<<*(m+1)<<" "<<*(m+4)<<endl;
    cout<<m<<" "<<m+1<<" "<<m+4<<endl;
    cout<<&m[1]-&m[0];
    return 0;



}














