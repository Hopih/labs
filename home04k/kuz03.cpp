 #include <iostream>
#include <windows.h>
#include <string>
using namespace std;
int main(){
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int x,y;
    cin>>x>>y;
    if (x<0&&x>-2){
        if (y>0&&y<1){
            cout<<"a) входит ";
        } else{
            cout<<"a) не входит ";
        }
    } else{
        cout<<"a) не входит ";
    }
    if (x>0){
        if (x*x+y*y>3&&x*x+y*y<6){
            cout<<"b) входит ";
        } else{
            cout<<"b) не входит ";
        }
    } else{
        cout<<"b) не входит ";
    }
    if (x>0&&y>0){
        if (-2*x+2>=y){
            cout <<"c) входит ";
        } else{
            cout <<"c) не входит ";
        }
    } else{
        cout<<"c) не входит ";
    }
}






