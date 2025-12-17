#include <iostream>

// Scalar product
double scalarProduct(double* a, double* b, int n) {
    double res = 0;
    for (int i = 0; i < n; i++) res += a[i] * b[i];
    return res;
}

// Vector addition
void addVectors(double* a, double* b, double* res, int n) {
    for (int i = 0; i < n; i++) res[i] = a[i] + b[i];
}

int main() {
    const int  n = 3;
    double* a = new double[n] {1.0, 2.0, 3.0};
    double* b = new double[n] {4.0, 5.0, 6.0};
    double* c = new double[n];

    double d;
    double z=INT_MAX;
    bool flag=false;
    bool flag2=false;
    std::cout << "Number search" << std::endl;
    std::cin >> d;
    
    std::cout << "Scalar product: " << scalarProduct(a, b, n) << std::endl;
    
    addVectors(a, b, c, n);
    std::cout << "Sum: ";
    for (int i = 0; i < n; i++) std::cout << c[i] << " ";
    std::cout<<std::endl;

    for (int k=0;k<n;k++){
        if (c[k]==d){
            std::cout<<k;
            flag=true;
            break;
        }
        if (c[k]>d&&c[k]<z){
            z=k;
        }
    }
        if (!flag&&flag2){
        std::cout<<z;
    } else{
        std::cout<<"Invalid value";
    }



    delete[] a;
    delete[] b;
    delete[] c;
    return 0;
}







