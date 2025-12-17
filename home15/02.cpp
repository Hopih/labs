#include <iostream>
using namespace std;

// Рекурсивная функция для ввода и вывода в обратном порядке
void reverseInputAndPrint() {
    int num;
    cin >> num;
    
    // Базовый случай: если введен 0, прекращаем рекурсию
    if (num == 0) {
        return;
    }
    
    // Рекурсивный вызов для следующего числа
    reverseInputAndPrint();
    
    // После возврата из рекурсии выводим текущее число
    cout << num << " ";
}

int main() {
    cout << "Enter a sequence of numbers (0 to end):" << endl;
    reverseInputAndPrint();
    cout << endl;
    
    return 0;
}