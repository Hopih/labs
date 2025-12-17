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
        cout<<x<<" ";
    }

    cout <<endl;
    int zam;
    for (int i=13;i<100;i+=13){
        int j=i-13;
        int current =a[i];
        while (j>=0&&a[j]>current){
            a[j+13]=a[j];
            j=j-13;
        }
        a[j+13]=current;
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






















