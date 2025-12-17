#include <iostream>
using namespace std;
int main(){
    int x;
    cin >>x;
    if (x<=-2){
        cout <<0;
    } else{
        if (x<=10){
            double y;
            y=x*x+4*x+5;
            cout <<y;

        } else {
            double z;
            z=1/(x*x+4*x-5);
            cout <<z;
        }
    }
}








