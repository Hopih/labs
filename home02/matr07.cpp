#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

int main(){
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int d=0;
    for (int i=1;i<6;i++){
        int hours,money,bonus,result;
        cout <<"Введите данные для "<<i<<" работника"<<endl;
        cin >>hours>>money>>bonus;
        result = hours*money+(hours*money/100)*bonus;
        cout <<"Работник номер "<<i<<" заработал "<<result<<endl;
        d=d+result;
    }
    cout <<"Средняя зп "<<d/5<<endl;
    return 0;
}











