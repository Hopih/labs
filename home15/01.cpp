#include <iostream>
using namespace std;

// Recursive function to print numbers and their squares
void printNumbersAndSquares(int n, int current = 1) {
    if (current > n) {
        return;  // Base case for recursion
    }
    
    cout << "Number: " << current << ", square: " << current * current << endl;
    printNumbersAndSquares(n, current + 1);  // Recursive call
}

int main() {
    int n;
    
    cout << "Enter an integer n: ";
    cin >> n;
    
    if (n < 1) {
        cout << "Number must be at least 1" << endl;
        return 1;
    }
    
    printNumbersAndSquares(n);
    
    return 0;
}





