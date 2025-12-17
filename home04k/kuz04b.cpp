 #include <iostream>
#include <windows.h>
#include <string>
using namespace std;
int main(){
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    cout<<"Введите дату день рождения"<<endl;
    int day,mouth,year;
    cin>>day>>mouth>>year;
    cout<<"Введите сегодняшнюю дату"<<endl;
    int day2,mouth2,year2;
    cin >>day2>>mouth2>>year2;
    int result;
    result=year2-year-1;
    if (mouth2>mouth){
        result=result+1;
    }
    if (mouth2=mouth){
        if (day2>=day){
            result=result+1;
        }
    }

    if (result==1){
        cout <<"Вам " <<result<<" год";
    } 
    if (result==2||result==3||result==4){
        cout<<"Вам "<<result<<" года";
    }
    if (result>9&&result<21){
        cout<<"Вам "<<result<<" лет";
        
    }
    if (result>20){
        if (result%10==0||result%10==8||result%10==9){
            cout<<"Вам "<<result<<" лет";
        }
        if (result%10==1){
            cout<<"Вам "<< result<<" год";
        }
        if (result%10==2||result%10==3||result%10==4){
            cout<<"Вам "<<result<<" года";
        }
        if (result%10==5||result%10==6||result%10==7){
            cout<<"Вам "<<result<<" лет";
        }
    }
    return 0;
}
    









