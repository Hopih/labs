#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        string z="";
        for (int j=0;j<n;j++){
            if (i%2==0){
                if (j%2==0){
                z=z+"o";
            } else{
                z=z+"*";
            }
            } else{
                if (j%2==0){
                    z=z+"*";
            } else{
                z=z+"o";
            }
            }

        }
        cout<<z<<endl; 
    } 
}








