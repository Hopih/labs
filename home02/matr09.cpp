#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

int min(double arr[],int size){
    double z=9999999999999999;
    int index;
    for (int i=0;i<5;i++){
        if (arr[i]<z){
            z=arr[i];
            index=i;
        }
    }
    return index+1;
}
double max(double arr[],int size){
    double max=0;
       for (int i=0;i<5;i++){
        if (arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}
double maxnumber(double arr[],int size){
    double max=0;
    int numbermax;
    for (int i=0;i<5;i++){
        if (arr[i]>max){
            max=arr[i];
            numbermax=i;
        }
    }
    return numbermax+1;
}
int elem(double arr[],int size,int num){
    int d=0;
    for (int k=0;k<5;k++){
        if (arr[k]>num){
            d=d+1;
        }
    }
    return d;
}
int sumer(double arr[],int size){
    int k=0;
    for (int i=0;i<5;i++){
        k=k+arr[i];
    }
    return k;
}


int main(){
    double a[5];
    for (int i=0;i<5;i++){
        cin>>a[i];
    }
    cout<<min(a,5)<<" "<<max(a,5)<<" "<<maxnumber(a,5)<<" "<<elem(a,5,7)<<" "<<sumer(a,5);
    return 0;

}









