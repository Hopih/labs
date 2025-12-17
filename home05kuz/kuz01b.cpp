 #include <iostream>
#include <windows.h>
#include <string>
#include <cmath>
#include <math.h>
using namespace std;
int main(){
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    double x=0;
    double z;
    do{
        z=(log(x+1))*sin(x);
        cout <<z<<endl;
        x=x+0.5;
    } while (x<=5);
    return 0;
}








