#include <iostream>
using namespace std;

bool func(int &day,int &mouth,int &year){
    setlocale(LC_ALL, "");
    wcout<<L"Введите день "<<endl;
    cin>>day;
    wcout<<L"Введите номер месяца "<<endl;
    cin>>mouth;
    wcout<<L"Введите год"<<endl;
    cin>>year;
    cout<<endl;
    if (day>=1&&day<=31&&mouth>=1&&mouth<=12){
        return true;
    } else{
        return false;
    }
}
int main(){
    setlocale(LC_ALL, "");
    int day;
    int mouth;
    int year;
    
    int day2;
    int mouth2;
    int year2;
    cout<<func(day,mouth,year)<<endl;
    cout<<func(day2,mouth2,year2)<<endl;

    if (day==day2&&mouth==mouth2){
        wcout<<L"С днем рождения! "<<endl;
    }

    if (day==1&&mouth==1){
        wcout<<L"С новым "<<year<<" годом ";
    }
    return 0;
}








