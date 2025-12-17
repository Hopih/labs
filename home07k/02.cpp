#include <iostream>
#include <string>
#include <windows.h>
using namespace std;
int main(){
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int a[7];
    int b[7];
    int c[21];
    for (int i=0;i<7;i++){
        int num;
        int num2;
        cout <<"Число для первого массива ";
        cin>>num;
        a[i]=num;
        cout <<"Число для второго массива ";
        cin>>num2;
        b[i]=num2;

        
    }
    cout <<"Элементы первого массива "<<endl;
    for (int k=0;k<7;k++){
        cout <<a[k]<<" ";
    }
    cout<<endl<<"Элементы второго массива"<<endl;
    for (int j=0;j<7;j++){
        cout <<b[j]<<" ";
    }
    for (int z=0;z<21;z+=3){
        c[z]=a[z/3];
        c[z+1]=b[z/3];
        c[z+2]=a[z/3]+b[z/3];
    }
    cout<<endl<<"Элементы третего массива"<<endl;
    for (int t=0;t<21;t++){
        cout<<c[t]<<" ";
    }
    


    

    
    
    
}









