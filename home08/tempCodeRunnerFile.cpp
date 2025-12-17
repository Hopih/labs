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
    cout <<endl;
    int zam;
    for (int i=1;i<100;i++){
        for (int j=i;j>=0;j--){
            if ((a[j]<a[j-1])&&(j%13==0)&&((j-1)%13==0)){
                zam=a[j-1];
                a[j-1]=a[j];
                a[j]=zam;
            }
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

