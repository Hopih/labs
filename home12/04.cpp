#include <iostream>
using namespace std;

bool func(int x,int y){
    if (x==y){
        return true;
    } else{
        return false;
    }
}

bool func(int x1,int x2,int x3,int x4,int x5,int x6,int y){
    string rez;
    int val;
    string z1,z2,z3,z4,z5,z6;
    z1=to_string(x1);
    z2=to_string(x2);
    z3=to_string(x3);
    z4=to_string(x4);
    z5=to_string(x5);
    z6=to_string(x6);
    rez=z1+z2+z3+z4+z5+z6;
    val=stoi(rez);
    if (val==y){
        return true;
    } else{
        return false;
    }
}

bool func(int x1,int x2,int y){
    string rez;
    int val;
    string z1,z2;
    z1=to_string(x1);
    z2=to_string(x2);
    rez=z1+z2;
    if (stoi(rez)==y){
        return true;
    } else{
        return false;
    }
}

int main(){
    cout<<func(123456,123456)<<endl;
    cout<<func(1,2,3,4,5,6,123456)<<endl;
    cout<<func(123,456,123456)<<endl;
    return 0;
}






