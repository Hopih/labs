#include <iostream>
#include <windows.h>
using namespace std;
int main(){
    SetConsoleOutputCP(1251); 
    SetConsoleCP(1251);      
    int a,d;
    cin >>a;
    if (a>0){
        cout <<">0";
    }
    if (a==0){
        cout <<"=0";
    }
    if (a<0){
        cout <<"<0";
    }
    d=a%2;
    if (d==0){
        cout <<" Odd";
    } else{
        cout <<" Even";
    }
    return 0;

}












