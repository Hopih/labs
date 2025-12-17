#include <iostream>
#include <string>
#include <windows.h>
using namespace std;
int main(){
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int a[10];
    int b[5];
    int secondmas[10]{-2,4,3,-7,0,12,9,-2,4,2};
    int ind=0;
    int d=0;
    for (int i=0;i<10;i++){
        int num;
        cin>>num;
        a[i]=num;
        d=d+a[i];
        if (i%2!=0){
            b[ind]=a[i];
            ind=ind+1;
        }
    }
    cout<<"второй элемент "<<a[1]<<endl;
    cout<<"предпоследний элемент "<<a[8]<<endl;
    cout<<"нечет числа ";
    for (int j=0;j<5;j++){
        cout <<b[j]<<" ";
    }
    double res=d/10.0;
    cout <<endl<<"средн арифм "<<res<<endl;
    for (int k=0;k<10;k++){
        cout <<secondmas[k]<<"+"<<a[k]<<"="<<secondmas[k]+a[k]<<endl;

    }
}







