#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
int main() {
    srand(time(NULL));
    int a[100];
    int b[100];
    for (int n=0;n<100;n++){
        int x=rand()%10000 +1;
        a[n]=x;
        b[n]=x;
    }
    int zam;
    int d;
    for (int i=0;i<100;i++){
        if (i%13==0){
        d=i;
        int minnum=a[i];
        for (int k=i+1;k<100;k++){
          if ((a[k]<minnum)&&(k%13==0)&&(i%13==0)){
                minnum=a[k];
                d=k;
            }
          }
          zam=a[i];
          a[i]=minnum;
          a[d]=zam;
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








