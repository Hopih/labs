#include <iostream>
using namespace std;
int main(){
    int x,y;
    cin >>x>>y;
    if (x*x+y*y>16){
        cout<<"0";

    } else{
        if ((x*x+y*y>4)&&(x*x+y*y<16)){
            cout <<"5";


        } else{
            cout <<"10";
        }
    }

}














