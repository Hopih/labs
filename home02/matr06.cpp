#include <iostream>
#include <windows.h>
using namespace std;

double nalog(double n){
    return n*0.13;
}
double sum(double x,double y){
    return x-y;
}
int main(){
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    double a,b,c,d,e,r,nal1,money1;
    double hours,money,bonus,result,nal2,money2;
    string fam1,fam2;
    cout <<"Фамилия первого работника ";
    cin >>fam1;
    cout <<"Данные для первого работника"<<endl;
    cin >> a>>b>>c;

    d=a*b; //первый 
    e=(d/100)*c; //первый
    r=d+e; //первый
    nal1=nalog(r); //первый
    money1=sum(r,nalog(r)); //первый

    cout <<"Фамилия второго работника ";
    cin >> fam2;
 
    cout <<"Данные для второго работника"<<endl;

    cin >>hours>>money>>bonus;
    result=hours*money+(hours*money/100)*bonus;
    nal2=nalog(result);
    money2=sum(result,nal2);


    if (money1<1000){
        cout <<fam1<<endl;
    }
    if (money2<1000){
        cout <<fam2<<endl;
    }

    if (nal1>50){
        cout <<fam1.substr(0,1)<<"-"<<fam1.substr(fam1.length()-1,1)<<endl;
    }

    if (nal2>50){
        cout <<fam2.substr(0,1)<<"-"<<fam2.substr(fam2.length()-1,1)<<endl;
    }

    return 0;
}

















