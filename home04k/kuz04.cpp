 #include <iostream>
#include <windows.h>
#include <string>
using namespace std;
int main(){
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int number;
    cin>>number;
    if (number==1){
        cout <<"Джон собрал " <<number<<" гриб";
    } 
    if (number==2||number==3||number==4){
        cout<<"Джон собрал "<<number<<" гриба";
    }
    if (number>9&&number<21){
        cout<<"Джон собрал "<<number<<" грибов";
        
    }
    if (number>20){
        if (number%10==0||number%10==8||number%10==9){
            cout<<"Джон собрал "<<number<<" грибов";
        }
        if (number%10==1){
            cout<<"Джон собрал "<< number<<" гриб";
        }
        if (number%10==2||number%10==3||number%10==4){
            cout<<"Джон собрал "<<number<<" гриба";
        }
        if (number%10==5||number%10==6||number%10==7){
            cout<<"Джон собрал "<<number<<" грибов";
        }
    }
    return 0;
}













