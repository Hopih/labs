#include <iostream>
using namespace std;
#include <cmath>
#include <climits>


int main(){
    int *s={new int [7]};
    float z=__FLT_MIN__;
    int t;
    int sum=0;
    float **m={new float*[7]{}};
    float num=__FLT_MAX__;
    string rt[7]={"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    for (int i=0;i<7;i++){
        int n;
        cout<<"Enter number of measurements for day "<<i+1<<endl;
        cin>>n;
        s[i]=n;
        m[i]=new float[n]{};
    }
    for (int k=0;k<7;k++){
        bool flag=true;
        for (int j=0;j<s[k];j++){
            cin>>m[k][j];
            if (k==0){
                num=m[k][j];
            }
            if (((k==5)||(k==6))&&(m[k][j]<0)&&(flag==true)){
                sum=sum+1;
                flag=false;
            }

            if (m[k][j]>z){
                z=m[k][j];
                t=k;
            }
    }
    }
    for (int i=0;i<7;i++){
        delete[] m[i]; 
    }
    delete[]m;
    delete[]s;
    cout<<"Min temp in monday "<<num<<endl;
    cout<<"days off with temp<0 "<<sum<<endl;
    cout<<"Max temp in week "<<rt[t]<<" "<<z;    
    return 0;
}













