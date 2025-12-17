#include <iostream>
using namespace std;
int main(){
    bool flag=true;
    int d=0;
    int z=0;
    for (int i=0;flag==true;i++){
        int num;
        cin>>num;
        if (num==0){
            flag=false;
        } else{
            if (num>z){
                z=num;
                d=0;
            }
            if (num==z){
                d=d+1;
            }
        }
    }
    cout<<d;
    return 0;
}








