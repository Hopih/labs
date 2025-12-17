#include <iostream>
#include <string>
#include <windows.h>
using namespace std;
int main(){
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int w;
    cin>>w;
    int a[10];
    for (int i=0;i<10;i++){
        int num;
        cin>>num;
        a[i]=num;
    }
    for (int j=0;j<10;j++){
        for (int k=0;k<10;k++){
            if (a[j]+a[k]==w){
                cout <<"elem "<<a[k]<<" "<<a[j]<<endl;
                cout<< "ind "<<k<<" "<<j<<endl;
            }
        }
    }







}











