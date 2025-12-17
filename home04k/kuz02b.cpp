 #include <iostream>
#include <windows.h>
#include <string>
using namespace std;
int main(){
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int x,y,z,a,b;
    cout<<"Введите стороны кирпича"<<endl;
    cin>>x>>y>>z;
    cout<<"Введите стороны отверстия"<<endl;
    cin>>a>>b;
    if ((x*y>a*b)||(y*z>a*b)||(z*x>a*b)){
        cout<<"Влезет";
    } else{
        cout<<"не влезет";
    }
}

    






