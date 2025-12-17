#include <iostream>
#include <cmath>
using namespace std;


double f(double x){
    if (x<0){
        return 7.0/3.0;
    }
    if (x>=0&&x<2*M_PI){
        return (x*x-3);
    } else{
        return (1+x*x*x)/(2*x);
    }
}

int main(){
    double a;
    double b;
    double mas[7];
    cout<<"a,b= "<<endl;
    cin>>a>>b;
    cout<<"mas x= "<<endl;
    for(int i=0;i<7;i++){
        double x;
        cin>>x;
        mas[i]=x;
    }
    cout<<"a) "<<12.5+f(2)-f(4)*f(10)+f(a)-f(b)+f(a*b)<<endl;
    cout<<"b)";
    for (int k=0;k<7;k++){
        cout<<f(mas[k])<<" ";
    }
    return 0;
}





