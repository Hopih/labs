#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES
using namespace std;

int main(){
    double h,r,v,s;
    cout << "Введите высоту";
    cin >> h;
    cout << "Введите радиус";
    cin >> r;
    v=M_PI*pow(r,2)*h;
    s=(2*M_PI*r*h)+2*M_PI*pow(r,2);
    cout <<"Обьем "<<v<<" Площадь поверхности "<<s;
    return 0;

}












