#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

// ====== ЛИНЕЙНАЯ РЕКУРСИЯ (один рекурсивный вызов) ======

// а) Проверка, есть ли положительные элементы
bool hasPositiveLinear(int arr[], int size, int index = 0) {
    if (index >= size) {
        return false; // Базовый случай: дошли до конца массива
    }
    if (arr[index] > 0) {
        return true; // Нашли положительный элемент
    }
    return hasPositiveLinear(arr, size, index + 1); // Рекурсивный вызов
}

// б) Проверка, нет ли отрицательных элементов
bool hasNoNegativeLinear(int arr[], int size, int index = 0) {
    if (index >= size) {
        return true; // Базовый случай: дошли до конца, не нашли отрицательных
    }
    if (arr[index] < 0) {
        return false; // Нашли отрицательный элемент
    }
    return hasNoNegativeLinear(arr, size, index + 1); // Рекурсивный вызов
}

// в) Проверка, есть ли элемент больший заданного значения
bool hasGreaterThanLinear(int arr[], int size, int value, int index = 0) {
    if (index >= size) {
        return false; // Базовый случай: дошли до конца массива
    }
    if (arr[index] > value) {
        return true; // Нашли элемент больше заданного значения
    }
    return hasGreaterThanLinear(arr, size, value, index + 1); // Рекурсивный вызов
}

// г) Поиск максимального элемента
int findMaxLinear(int arr[], int size, int index = 0) {
    if (index >= size) {
        return INT_MIN; // Базовый случай: пустой массив
    }
    if (index == size - 1) {
        return arr[index]; // Базовый случай: последний элемент
    }
    int currentMax = findMaxLinear(arr, size, index + 1); // Рекурсивный вызов
    return max(arr[index], currentMax);
}

// д) Количество положительных элементов
int countPositiveLinear(int arr[], int size, int index = 0) {
    if (index >= size) {
        return 0; // Базовый случай: дошли до конца массива
    }
    int count = countPositiveLinear(arr, size, index + 1); // Рекурсивный вызов
    return (arr[index] > 0) ? count + 1 : count;
}

// е) Сортировка методом поиска (Selection Sort рекурсивно)
void selectionSortRecursive(int arr[], int size, int startIndex = 0) {
    if (startIndex >= size - 1) {
        return; // Базовый случай: массив отсортирован
    }
    
    // Находим минимальный элемент в неотсортированной части
    int minIndex = startIndex;
    for (int i = startIndex + 1; i < size; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    
    // Меняем местами с первым элементом неотсортированной части
    if (minIndex != startIndex) {
        swap(arr[minIndex], arr[startIndex]);
    }
    
    // Рекурсивный вызов для оставшейся части
    selectionSortRecursive(arr, size, startIndex + 1);
}

// ====== КАСКАДНАЯ РЕКУРСИЯ (несколько рекурсивных вызовов) ======

// ж) Поиск максимального элемента (разделяй и властвуй)
int findMaxCascade(int arr[], int start, int end) {
    if (start == end) {
        return arr[start]; // Базовый случай: один элемент
    }
    
    int mid = start + (end - start) / 2;
    int leftMax = findMaxCascade(arr, start, mid);     // Рекурсивный вызов для левой части
    int rightMax = findMaxCascade(arr, mid + 1, end); // Рекурсивный вызов для правой части
    
    return max(leftMax, rightMax);
}

// з) Сумма всех отрицательных элементов (разделяй и властвуй)
int sumNegativeCascade(int arr[], int start, int end) {
    if (start == end) {
        return (arr[start] < 0) ? arr[start] : 0; // Базовый случай
    }
    
    int mid = start + (end - start) / 2;
    int leftSum = sumNegativeCascade(arr, start, mid);     // Рекурсивный вызов для левой части
    int rightSum = sumNegativeCascade(arr, mid + 1, end); // Рекурсивный вызов для правой части
    
    return leftSum + rightSum;
}

// и) Произведение элементов, квадрат которых меньше заданного числа W
double productSquareLessThanW(int arr[], int start, int end, double W) {
    if (start == end) {
        double square = arr[start] * arr[start];
        return (square < W) ? arr[start] : 1.0; // Базовый случай
    }
    
    int mid = start + (end - start) / 2;
    double leftProduct = productSquareLessThanW(arr, start, mid, W);     // Левая часть
    double rightProduct = productSquareLessThanW(arr, mid + 1, end, W); // Правая часть
    
    return leftProduct * rightProduct;
}

// ====== ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ ======

void printArray(int arr[], int size) {
    cout << "[";
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1) cout << ", ";
    }
    cout << "]";
}

void testArray(int arr[], int size, const string& name) {
    cout << "\n=== Testing array: " << name << " ===" << endl;
    cout << "Array: ";
    printArray(arr, size);
    cout << endl;
    
    // Линейная рекурсия
    cout << "\nLinear recursion:" << endl;
    cout << "a) Has positive elements: " << (hasPositiveLinear(arr, size) ? "YES" : "NO") << endl;
    cout << "b) Has no negative elements: " << (hasNoNegativeLinear(arr, size) ? "YES" : "NO") << endl;
    cout << "c) Has element > 10: " << (hasGreaterThanLinear(arr, size, 10) ? "YES" : "NO") << endl;
    cout << "d) Max element: " << findMaxLinear(arr, size) << endl;
    cout << "e) Count of positive elements: " << countPositiveLinear(arr, size) << endl;
    
    // Копия для сортировки
    int arrCopy[size];
    copy(arr, arr + size, arrCopy);
    selectionSortRecursive(arrCopy, size);
    cout << "f) Sorted array: ";
    printArray(arrCopy, size);
    cout << endl;
    
    // Каскадная рекурсия
    if (size > 0) {
        cout << "\nCascade recursion:" << endl;
        cout << "g) Max element (cascade): " << findMaxCascade(arr, 0, size - 1) << endl;
        cout << "h) Sum of negative elements: " << sumNegativeCascade(arr, 0, size - 1) << endl;
        cout << "i) Product of elements with square < 25: " 
             << productSquareLessThanW(arr, 0, size - 1, 25) << endl;
    }
}

int main() {
    cout << "=== Testing recursive array functions ===" << endl;
    
    // Тестовые массивы
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {-5, -3, -1, 0, 2};
    int arr3[] = {-10, -8, -3, 0};
    int arr4[] = {15, -2, 8, -7, 12, -4};
    int arr5[] = {2, -1, 4, -3, 6, -5, 8};
    
    // Тестируем каждый массив
    testArray(arr1, 5, "All positive");
    testArray(arr2, 5, "Mixed with negative");
    testArray(arr3, 4, "Mostly negative");
    testArray(arr4, 6, "Mixed with large values");
    testArray(arr5, 7, "Alternating positive/negative");
    
    // Демонстрация работы сортировки
    cout << "\n\n=== Demonstration of recursive selection sort ===" << endl;
    int sortArr[] = {64, 25, 12, 22, 11};
    int sortSize = 5;
    
    cout << "Original array: ";
    printArray(sortArr, sortSize);
    cout << endl;
    
    selectionSortRecursive(sortArr, sortSize);
    
    cout << "Sorted array: ";
    printArray(sortArr, sortSize);
    cout << endl;
    
    // Демонстрация каскадной рекурсии для поиска максимума
    cout << "\n=== Cascade recursion step-by-step ===" << endl;
    int cascadeArr[] = {3, 8, 1, 9, 4, 7, 2};
    int cascadeSize = 7;
    
    cout << "Array: ";
    printArray(cascadeArr, cascadeSize);
    cout << endl;
    
    cout << "Finding max using cascade recursion:" << endl;
    cout << "findMaxCascade(arr, 0, 6)" << endl;
    cout << "  left: findMaxCascade(arr, 0, 3)" << endl;
    cout << "    left: findMaxCascade(arr, 0, 1) -> max(3, 8) = 8" << endl;
    cout << "    right: findMaxCascade(arr, 2, 3) -> max(1, 9) = 9" << endl;
    cout << "    max(8, 9) = 9" << endl;
    cout << "  right: findMaxCascade(arr, 4, 6)" << endl;
    cout << "    left: findMaxCascade(arr, 4, 5) -> max(4, 7) = 7" << endl;
    cout << "    right: findMaxCascade(arr, 6, 6) -> 2" << endl;
    cout << "    max(7, 2) = 7" << endl;
    cout << "  Result: max(9, 7) = 9" << endl;
    
    int maxResult = findMaxCascade(cascadeArr, 0, cascadeSize - 1);
    cout << "Actual result: " << maxResult << endl;
    
    return 0;
}