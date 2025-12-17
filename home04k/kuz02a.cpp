 #include <iostream>
#include <windows.h>
#include <string>
using namespace std;
int main(){
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int a,b,r,d;
    cin>>a>>b>>r;
    d=r*2;
    if ((d<a)&&(d<b)){
        cout<<"Влезет";
    } else{
        cout <<"не влезет";
    }
}







