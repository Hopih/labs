#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 20;

// Глобальная таблица для мемоизации
vector<vector<int>> memo(MAX_N + 1, vector<int>(MAX_N + 1, -1));

int binomialCoefficientMemo(int n, int k) {
    // Базовые случаи
    if (k == 0 || k == n) {
        return 1;
    }
    
    // Проверка на некорректные входные данные
    if (k < 0 || k > n) {
        return 0;
    }
    
    // Если значение уже вычислено, возвращаем его
    if (memo[n][k] != -1) {
        return memo[n][k];
    }
    
    // Вычисляем и сохраняем в таблицу
    memo[n][k] = binomialCoefficientMemo(n - 1, k - 1) + binomialCoefficientMemo(n - 1, k);
    return memo[n][k];
}

int main() {
    cout << "=== Testing binomial coefficient with memoization ===" << endl;
    
    // Тестирование
    cout << "C(10, 3) = " << binomialCoefficientMemo(10, 3) << endl; // 120
    cout << "C(10, 5) = " << binomialCoefficientMemo(10, 5) << endl; // 252
    cout << "C(12, 4) = " << binomialCoefficientMemo(12, 4) << endl; // 495
    cout << "C(15, 7) = " << binomialCoefficientMemo(15, 7) << endl; // 6435
    
    return 0;
}