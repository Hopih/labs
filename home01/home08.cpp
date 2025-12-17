#include <iostream>
using namespace std;
int main(){
    int n,h,m,s;
    cin>>n;
    h=n/3600;
    m=n/60;
    s=n-(m*60);
    cout<<"Часы "<<h<<" Минуты "<<m<<" Остаток секунд "<<s;
    return 0;

}













