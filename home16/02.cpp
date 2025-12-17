#include <iostream>
using namespace std;

int main(){

    struct adress{
        string street;
        string home;
        string kv;

    };

    struct date{
        int day;
        int mouth;
        int year;

    };
    
    struct character{
        string secondname;
        string name;
        adress adress;
        date date ;
    };


    character mas[5];

    date data;

    cin>>data.day>>data.mouth>>data.year;

    for (int n=0;n<5;n++){
        cin>>mas[n].secondname>>mas[n].name;
        cin>>mas[n].adress.street>>mas[n].adress.home>>mas[n].adress.kv;
        cin >> mas[n].date.day >> mas[n].date.mouth >> mas[n].date.year;
    }

    for (int k=0;k<5;k++){
        if (data.day==mas[k].date.day&&data.mouth==mas[k].date.mouth){
            cout<<mas[k].secondname<<" "<<mas[k].name<<endl;
        }
        cout<<"Age "<<data.year-mas[k].date.year;
    }

}










