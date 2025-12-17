#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

int min(double q[],int size){
    double x=9999999999999999;
    int indx;
    for (int i=0;i<size;i++){
        if (q[i]<x){
            x=q[i];
            indx=i;
        }
    }
    return indx+1;
}

double max(double q[],int size){
    double max=0;
       for (int i=0;i<size;i++){
        if (q[i]>max){
            max=q[i];
        }
    }
    return max;
}

double maxnumber(double q[],int size){
    double max=0;
    int NumMax;
    for (int i=0;i<size;i++){
        if (q[i]>max){
            max=q[i];
            NumMax=i;
        }
    }
    return NumMax+1;
}


int main(){
    int l;
    int m;
    cin>>l;
    cin>>m;
    double n[l];
    for (int i=0; i<l; i++){
        cin>> n[i];
    }
    cout<< min(n,l)<<" "<<max(n,l)<<" "<<maxnumber(n,l);
    return 0;
}