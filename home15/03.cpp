#include <iostream>
#include <cmath>
using namespace std;

// а) Рекурсивная функция для вычисления количества цифр
int countDigits(int number) {
    // Обрабатываем отрицательные числа
    if (number < 0) {
        number = -number;
    }
    
    // Базовый случай: если число меньше 10, оно имеет 1 цифру
    if (number < 10) {
        // Особый случай для 0 - у него 1 цифра
        return 1;
    }
    
    // Убираем одну цифру (делим на 10) и рекурсивно считаем остальные
    return 1 + countDigits(number / 10);
}

// б) Рекурсивная функция для вычисления суммы цифр
int sumOfDigits(int number) {
    // Обрабатываем отрицательные числа
    if (number < 0) {
        number = -number;
    }
    
    // Базовый случай: если число меньше 10, возвращаем само число
    if (number < 10) {
        return number;
    }
    
    // Берем последнюю цифру и рекурсивно суммируем остальные
    int lastDigit = number % 10;
    return lastDigit + sumOfDigits(number / 10);
}

int main() {
    cout << "=== Testing recursive functions ===" << endl << endl;
    
    // Тестирование с вводом пользователя
    int number;
    cout << "Enter an integer to test: ";
    cin >> number;
    
    cout << "\nFor number " << number << ":" << endl;
    cout << "a) Number of digits: " << countDigits(number) << endl;
    cout << "b) Sum of digits: " << sumOfDigits(number) << endl;
    
    cout << "\n=== Automated test cases ===" << endl;
    
    // Автоматизированные тесты
    struct TestCase {
        int number;
        int expectedDigits;
        int expectedSum;
    };
    
    TestCase tests[] = {
        {0, 1, 0},
        {5, 1, 5},
        {10, 2, 1},
        {123, 3, 6},
        {-456, 3, 15},  // 4+5+6 = 15
        {98765, 5, 35}, // 9+8+7+6+5 = 35
        {-12345, 5, 15} // 1+2+3+4+5 = 15
    };
    
    for (int i = 0; i < sizeof(tests)/sizeof(tests[0]); i++) {
        TestCase test = tests[i];
        int actualDigits = countDigits(test.number);
        int actualSum = sumOfDigits(test.number);
        
        cout << "\nTest #" << i+1 << ": Number = " << test.number << endl;
        cout << "Digits: expected " << test.expectedDigits 
             << ", got " << actualDigits 
             << " [" << (actualDigits == test.expectedDigits ? "PASS" : "FAIL") << "]" << endl;
        cout << "Sum: expected " << test.expectedSum 
             << ", got " << actualSum 
             << " [" << (actualSum == test.expectedSum ? "PASS" : "FAIL") << "]" << endl;
    }
    
    return 0;
}