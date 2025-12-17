#include <iostream>
using namespace std;
int main(){
    int a,b,c,d,z;
    d=0;
    z=0;
    cin >>a>>b>>c;
    if (a>10){
        z=z+a;

    }
    if (b>10){
        z=z+b;
    }
    if (c>10){
        c=z+c;
    }

    if (a%2==0){
        d=d+1;
    }
    if (b%2==0){
        d=d+1;
    }
      if (c%2==0){
        d=d+1;
    }
    cout <<z<<endl;
    cout <<d<<endl;
    if ((a>b&&a<c)||(a<b&&a>c)){
        cout<<a<<endl;
    } else{
        if((b>a&&b<c)||(b<a&&b>c)){
            cout <<b<<endl;
        } else{
            cout <<c<<endl;
        }
    }
    if (a<b&&a<c){
        cout <<1;
    } else{
        if (b<a&&b<c){
            cout <<2;
        } else{
            cout <<3;
        }
    }
}








