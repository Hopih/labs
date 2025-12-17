 #include <iostream>
#include <windows.h>
#include <string>
#include <cmath>
#include <math.h>
using namespace std;
int main(){
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    for (double i;i<=2*M_PI;i+=(M_PI/6)){
        cout<<cos(i)<<endl;

    }


}