#include <iostream>
#include <cmath>
using namespace std;

void f(int &a,int &b,int &c){
    int dis;
    dis=b*b-4*a*c;
    if (dis>0){
        cout<<(-b+sqrt(dis))/(2*a)<<endl;
        cout<<(-b-sqrt(dis))/(2*a)<<endl;
    }
    if (dis==0){
        cout<<-b/(2*a)<<endl;
    }
    if (dis<0){
        cout<<"0 solves"<<endl;
    }
}
int main(){
    int a1=4;
    int b1=5;
    int c1=1;

    int a2=13;
    int b2=2;
    int c2=5;

    int a3=1;
    int b3=8;
    int c3=4;

    f(a1,b1,c1);
    cout<<endl;
    f(a2,b2,c2);
    cout<<endl;
    f(a3,b3,c3);
    return 0;
}




















