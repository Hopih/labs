#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

double nalfunc(double arr[],int size){
    double z=0;
    for (int i=0;i<size;i++){
        z=z+(arr[i])*0.13;
    }
    return z;
}

int min(double arr[],int size){
    double z=9999999999999999;
    int index;
    for (int i=0;i<size;i++){
        if (arr[i]<z){
            z=arr[i];
            index=i;
        }
    }
    return index+1;
}

double max(double arr[],int size){
    double max=0;
       for (int i=0;i<size;i++){
        if (arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}

double maxnumber(double arr[],int size){
    double max=0;
    int numbermax;
    for (int i=0;i<size;i++){
        if (arr[i]>max){
            max=arr[i];
            numbermax=i;
        }
    }
    return numbermax+1;
}

int main(){
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int NUMWORKERS;
    cout <<"Введите количество работников"<<endl;
    cin>>NUMWORKERS;
    int a[NUMWORKERS];
    int b[NUMWORKERS];
    double zp[NUMWORKERS];
    string workers;
    int goodworkers=0;
    for (int j=0;j<NUMWORKERS;j++){
        int hours,money;
        cout <<"Введите данные для "<<j+1<<" работника"<<endl;
        cin >>hours>>money;
        a[j]=hours;
        b[j]=money;
    }
    for (int k=0;k<NUMWORKERS;k++){
        zp[k]=a[k]*b[k]-(a[k]*b[k])*0.13;
    }
    for (int i=0;i<NUMWORKERS;i++){
        if (zp[i]>50000){
            goodworkers=goodworkers+1;
            workers+=to_string(i+1)+" ";
        }
    }
    cout <<"Работник номер "<<min(zp,NUMWORKERS)<<" получил меньше всего"<<endl;
    cout <<"Работник номер "<<maxnumber(zp,NUMWORKERS)<<" получил самую большую зп "<<max(zp,NUMWORKERS)<<endl;
    cout <<goodworkers<<" работников получило больше 50000"<<endl;
    cout <<workers<<" номера работников получивших больше 50000"<<endl;
    cout <<nalfunc(zp,NUMWORKERS)<<" общая сумма налогов бригады"<<endl;
    
    return 0;   
}


























