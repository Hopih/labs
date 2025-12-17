 #include <iostream>
#include <windows.h>
#include <string>
using namespace std;
int main(){
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int a,b;
    cin>>a>>b;
    if (13 == a){
        if (5 == b || 2 == b){
            cout << "неудачный день ";
        }
    }
    if ((17==a)&&(5==b)){
        cout <<"неудачный день";
    }
}
    









