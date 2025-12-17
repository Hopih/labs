#include <iostream>
using namespace std;

int main(){

    struct adress{
        string street;
        int home;
        double s;
        double price;
    };

    adress n1;
    adress n2;

    cin>>n1.street>>n1.home>>n1.s>>n1.price;
    n2.street="Kremvlevskaya";
    n2.home=18;
    n2.s=200;
    n2.price=10000;

    if (n1.s*n1.price>n2.s*n2.price){
        cout<<n1.street<<" "<<n1.home;
    } else{
        cout<<n2.street<<" "<<n2.home;
    }
    return 0;
}







