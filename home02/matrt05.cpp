#include <iostream>
#include <windows.h>
using namespace std;


int main(){
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    double hours1,money1,hours2,money2,res1,res2;
    cout << "Для 1 работника"<<endl;
    cin >>hours1>>money1;
    cout << "Для 2 работника"<<endl;
    cin >>hours2>>money2;
    res1=hours1*money1;
    res2=hours2*money2;
    if (res1>res2){
        cout <<"Первый работник заработал больше"<<endl;
    } else {
        cout <<"Второй работник заработал больше"<<endl;

    }
    cout <<"Сумма обоих "<<res1+res2;
    return 0;
}


















