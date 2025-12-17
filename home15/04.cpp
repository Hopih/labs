#include <iostream>
using namespace std;

// а) Рекурсивное сложение с использованием только прибавления единицы
int recursiveAdd(int a, int b) {
    // Базовый случай: если b = 0, возвращаем a
    if (b == 0) {
        return a;
    }
    
    // Для положительного b
    if (b > 0) {
        // Рекурсивно прибавляем единицу: a + b = (a + 1) + (b - 1)
        return recursiveAdd(a + 1, b - 1);
    } 
    // Для отрицательного b
    else {
        // Рекурсивно вычитаем единицу: a + b = (a - 1) + (b + 1)
        return recursiveAdd(a - 1, b + 1);
    }
}

// б) Рекурсивное умножение с использованием только операции сложения
int recursiveMultiply(int a, int b) {
    // Базовые случаи
    if (a == 0 || b == 0) {
        return 0;
    }
    
    // Обработка отрицательных чисел
    if (a < 0 && b < 0) {
        return recursiveMultiply(-a, -b);
    }
    if (a < 0) {
        return -recursiveMultiply(-a, b);
    }
    if (b < 0) {
        return -recursiveMultiply(a, -b);
    }
    
    // Основной рекурсивный случай: a * b = a + (a * (b - 1))
    if (b == 1) {
        return a;
    }
    
    return a + recursiveMultiply(a, b - 1);
}

int main() {
    cout << "=== Testing recursive methods ===" << endl << endl;
    
    // Тест сложения
    cout << "a) Testing recursive addition:" << endl;
    cout << "================================" << endl;
    
    int addTestCases[][3] = {
        {5, 3, 8},
        {10, -4, 6},
        {-7, 2, -5},
        {-3, -2, -5},
        {0, 5, 5},
        {7, 0, 7}
    };
    
    for (int i = 0; i < sizeof(addTestCases)/sizeof(addTestCases[0]); i++) {
        int a = addTestCases[i][0];
        int b = addTestCases[i][1];
        int expected = addTestCases[i][2];
        int result = recursiveAdd(a, b);
        
        cout << a << " + " << b << " = " << result;
        cout << " [" << (result == expected ? "PASS" : "FAIL") << "]" << endl;
    }
    
    // Тест умножения
    cout << "\nb) Testing recursive multiplication:" << endl;
    cout << "====================================" << endl;
    
    int multiplyTestCases[][3] = {
        {4, 3, 12},
        {5, -2, -10},
        {-3, 4, -12},
        {-2, -3, 6},
        {0, 7, 0},
        {8, 0, 0},
        {1, 9, 9},
        {7, 1, 7}
    };
    
    for (int i = 0; i < sizeof(multiplyTestCases)/sizeof(multiplyTestCases[0]); i++) {
        int a = multiplyTestCases[i][0];
        int b = multiplyTestCases[i][1];
        int expected = multiplyTestCases[i][2];
        int result = recursiveMultiply(a, b);
        
        cout << a << " * " << b << " = " << result;
        cout << " [" << (result == expected ? "PASS" : "FAIL") << "]" << endl;
    }
    
    // Интерактивное тестирование
    cout << "\n=== Interactive testing ===" << endl;
    
    int x, y;
    
    cout << "\nEnter two numbers for addition test: ";
    cin >> x >> y;
    cout << "recursiveAdd(" << x << ", " << y << ") = " << recursiveAdd(x, y) << endl;
    cout << "Standard addition: " << x + y << endl;
    
    cout << "\nEnter two numbers for multiplication test: ";
    cin >> x >> y;
    cout << "recursiveMultiply(" << x << ", " << y << ") = " << recursiveMultiply(x, y) << endl;
    cout << "Standard multiplication: " << x * y << endl;
    
    // Демонстрация как работает рекурсивное сложение
    cout << "\n=== Step-by-step demonstration ===" << endl;
    cout << "recursiveAdd(3, 4):" << endl;
    cout << "recursiveAdd(4, 3)" << endl;
    cout << "recursiveAdd(5, 2)" << endl;
    cout << "recursiveAdd(6, 1)" << endl;
    cout << "recursiveAdd(7, 0) = 7" << endl;
    
    cout << "\nrecursiveMultiply(3, 4):" << endl;
    cout << "3 + recursiveMultiply(3, 3)" << endl;
    cout << "3 + (3 + recursiveMultiply(3, 2))" << endl;
    cout << "3 + (3 + (3 + recursiveMultiply(3, 1)))" << endl;
    cout << "3 + (3 + (3 + 3)) = 12" << endl;
    
    return 0;
}