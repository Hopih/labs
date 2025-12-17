#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main(){
    srand(time(NULL));
    int a[100];
    int b[100];
    for (int n=0;n<100;n++){
        int x=rand()%10000 +1;
        a[n]=x;
        b[n]=x; 
    }
    int zam;
    bool flag;
    for (int i=0;i<7;i++){
        flag=false;
        for (int j=0;j<91;j+=13){
            if (a[j+13]<a[j]){
                flag=true;
                zam=a[j];
                a[j]=a[j+13];
                a[j+13]=zam;
            }
        }
        if (flag==false){
            break;
        }
    }
    for (int k=0;k<100;k++){
        if (a[k]!=b[k]){
            cout<<"\033[31m"<<a[k]<<" \033[0m"<<" ";
        } else{
            cout<<a[k]<<" ";
        }
    }
    return 0;
}















