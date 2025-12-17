#include <iostream>
using namespace std;
#include <cmath>

int main(){
    int n;
    cin>>n;
    float *m={new float[n]};
    float *s={new float[n]};
    float d=0;
    float mxn=INT_MIN;
    int z;

    for (int i=0;i<n;i++){
        cin>>m[i];
        s[i]=m[i];
    }

    for (int k=0;k<n;k++){
        if (m[k]>0){
            d=d+m[k];
            s[k]=s[k]*10;
            cout<<m[k]<<" "<<s[k]<<endl;
        } else{
            s[k]=s[k]-100;
            cout<<m[k]<<" "<<s[k]<<endl;
        }

        if (m[k]>mxn){
            mxn=m[k];
            z=k;
        }
    }
    delete []m;
    delete []s;
    m=nullptr;
    s=nullptr;
    cout<<d<<endl;
    cout<<z<<endl;
    return 0;
}



















