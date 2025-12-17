#include <iostream>
#include <windows.h>
#include <string>
#include <cmath>
#include <math.h>
using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int z = 0;
    int c = 0;    
    int v = 99999999999;
    double delt;
    for (int i = 1; i <= 7; i++) {
        int number;
        cout << "Введите число: ";
        cin >> number;
        
        if (number < 0) {
            z++; 
        }
        
        if (number >= 10) {
            c += number; 
        }

        if (number < v) {
            v=number;
        }
    }
    cout << "Количество отрицательных чисел: " << z << endl;
    cout << "Сумма чисел >= 10: " << c << endl;
    cout <<"Мин число " <<v;
    
    return 0;
}
