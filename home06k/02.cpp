#include <iostream>
using namespace std;
bool flag=true;
int d=0;//чет
int main(){
for (int i=1;flag==true;i++){
    int num;
    string answ;
    cin>>num;
    if ((num&1)==0){
        d=d+1;
    } 
    cout <<"stop? yes/no"<<endl;
    cin>>answ;
    if (answ=="yes"){
        flag=false;
        cout<<i<<endl;
        cout<<d;
    
    }}

    return 0;
}




