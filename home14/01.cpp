#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <clocale>  // Добавим для поддержки локали

using namespace std;

// a) Function to print rectangular matrix
void printMatrix(const vector<vector<int>>& matrix) {
    if (matrix.empty()) {
        cout << "Matrix is empty!\n";
        return;
    }
    
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    cout << "Matrix " << rows << "x" << cols << ":\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

// b) Function to input matrix from keyboard
vector<vector<int>> inputMatrix() {
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;
    
    vector<vector<int>> matrix(rows, vector<int>(cols));
    
    cout << "Enter matrix elements:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
    return matrix;
}

// c) Function to fill existing matrix with random numbers
void fillMatrixRandom(vector<vector<int>>& matrix, int minVal = 0, int maxVal = 100) {
    srand(time(nullptr));
    for (auto& row : matrix) {
        for (auto& element : row) {
            element = minVal + rand() % (maxVal - minVal + 1);
        }
    }
}

// d) Function that returns new matrix of given size filled with random numbers
vector<vector<int>> createRandomMatrix(int rows, int cols, int minVal = 0, int maxVal = 100) {
    srand(time(nullptr));
    vector<vector<int>> matrix(rows, vector<int>(cols));
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = minVal + rand() % (maxVal - minVal + 1);
        }
    }
    return matrix;
}

// e) Function to get average of all matrix elements
double getMatrixAverage(const vector<vector<int>>& matrix) {
    if (matrix.empty()) return 0.0;
    
    long long sum = 0;
    int count = 0;
    
    for (const auto& row : matrix) {
        for (int element : row) {
            sum += element;
            count++;
        }
    }
    
    return (count == 0) ? 0.0 : static_cast<double>(sum) / count;
}

// f) Function to get array with minimal elements of matrix columns
vector<int> getColumnMinimals(const vector<vector<int>>& matrix) {
    if (matrix.empty()) return {};
    
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<int> minElements(cols);
    
    for (int j = 0; j < cols; j++) {
        int minVal = matrix[0][j];
        for (int i = 1; i < rows; i++) {
            if (matrix[i][j] < minVal) {
                minVal = matrix[i][j];
            }
        }
        minElements[j] = minVal;
    }
    return minElements;
}

// g) Function to sort first column using insertion sort
void sortFirstColumnInsertion(vector<vector<int>>& matrix) {
    if (matrix.empty()) return;
    
    int rows = matrix.size();
    
    // Insertion sort for first column
    for (int i = 1; i < rows; i++) {
        int key = matrix[i][0];
        int j = i - 1;
        
        // Move elements greater than key one position ahead
        while (j >= 0 && matrix[j][0] > key) {
            matrix[j + 1][0] = matrix[j][0];
            j--;
        }
        matrix[j + 1][0] = key;
    }
}

// h) Function to sort last row using selection sort, descending order
void sortLastRowSelection(vector<vector<int>>& matrix) {
    if (matrix.empty()) return;
    
    int lastRow = matrix.size() - 1;
    int cols = matrix[0].size();
    
    for (int i = 0; i < cols - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < cols; j++) {
            if (matrix[lastRow][j] > matrix[lastRow][maxIdx]) {
                maxIdx = j;
            }
        }
        swap(matrix[lastRow][i], matrix[lastRow][maxIdx]);
    }
}

// i) Function to sort main diagonal using bubble sort, descending order
void sortMainDiagonalBubble(vector<vector<int>>& matrix) {
    if (matrix.empty()) return;
    
    int size = min(matrix.size(), matrix[0].size());
    bool swapped;
    
    do {
        swapped = false;
        for (int i = 0; i < size - 1; i++) {
            if (matrix[i][i] < matrix[i + 1][i + 1]) {
                swap(matrix[i][i], matrix[i + 1][i + 1]);
                swapped = true;
            }
        }
        size--;
    } while (swapped);
}

// j) Function for binary search on main diagonal for given element
int binarySearchMainDiagonal(const vector<vector<int>>& matrix, int target) {
    if (matrix.empty()) return -1;
    
    int size = min(matrix.size(), matrix[0].size());
    
    // Create copy of main diagonal for binary search
    vector<int> diagonal(size);
    for (int i = 0; i < size; i++) {
        diagonal[i] = matrix[i][i];
    }
    
    // Check if diagonal is sorted (binary search requires sorted array)
    // We'll sort it if needed
    vector<int> sortedDiagonal = diagonal;
    sort(sortedDiagonal.begin(), sortedDiagonal.end());
    
    // Binary search
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (sortedDiagonal[mid] == target) {
            // Find original position in unsorted diagonal
            for (int i = 0; i < size; i++) {
                if (diagonal[i] == target) return i;
            }
            return -1;
        }
        
        if (sortedDiagonal[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1;  // Element not found
}

// Alternative version of binary search that assumes diagonal is sorted
int binarySearchSortedMainDiagonal(const vector<vector<int>>& matrix, int target) {
    if (matrix.empty()) return -1;
    
    int size = min(matrix.size(), matrix[0].size());
    
    // Binary search on main diagonal (assumes it's sorted)
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (matrix[mid][mid] == target) {
            return mid;
        }
        
        if (matrix[mid][mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1;  // Element not found
}

// Helper function to print array
void printArray(const vector<int>& arr) {
    cout << "Array: ";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;
}

// Function for testing
void testFunctions() {
    cout << "=== FUNCTION TESTING ===\n\n";
    
    // Test creating and printing random matrix
    cout << "1. Creating random matrix:\n";
    vector<vector<int>> matrix = createRandomMatrix(4, 5, 1, 50);
    printMatrix(matrix);
    
    // Test average calculation
    cout << "2. Average of all elements: ";
    cout << getMatrixAverage(matrix) << "\n\n";
    
    // Test minimal elements of columns
    cout << "3. Minimal elements of columns:\n";
    vector<int> minElements = getColumnMinimals(matrix);
    printArray(minElements);
    cout << endl;
    
    // Test sorting first column
    cout << "4. Sorting first column (insertion sort):\n";
    vector<vector<int>> matrix1 = matrix; // Copy for test
    sortFirstColumnInsertion(matrix1);
    printMatrix(matrix1);
    
    // Test sorting last row
    cout << "5. Sorting last row in descending order (selection sort):\n";
    vector<vector<int>> matrix2 = matrix; // Copy for test
    sortLastRowSelection(matrix2);
    printMatrix(matrix2);
    
    // Test sorting main diagonal
    cout << "6. Sorting main diagonal in descending order (bubble sort):\n";
    vector<vector<int>> matrix3 = matrix; // Copy for test
    cout << "Before sorting: ";
    int size = min(matrix3.size(), matrix3[0].size());
    for (int i = 0; i < size; i++) {
        cout << matrix3[i][i] << " ";
    }
    cout << endl;
    
    sortMainDiagonalBubble(matrix3);
    cout << "After sorting: ";
    for (int i = 0; i < size; i++) {
        cout << matrix3[i][i] << " ";
    }
    cout << "\n\n";
    
    // Test binary search on main diagonal
    cout << "7. Binary search on main diagonal:\n";
    // Create square matrix with sorted diagonal for binary search test
    vector<vector<int>> squareMatrix = {
        {1, 12, 13, 14},
        {15, 5, 17, 18},
        {19, 20, 9, 22},
        {23, 24, 25, 16}
    };
    
    cout << "Test matrix:\n";
    printMatrix(squareMatrix);
    
    // First sort the diagonal
    vector<vector<int>> sortedSquare = squareMatrix;
    sortMainDiagonalBubble(sortedSquare);
    
    cout << "Matrix with sorted diagonal:\n";
    printMatrix(sortedSquare);
    
    int target = 9;
    int result = binarySearchSortedMainDiagonal(sortedSquare, target);
    if (result != -1) {
        cout << "Element " << target << " found on main diagonal at position " << result << endl;
    } else {
        cout << "Element " << target << " not found on main diagonal\n";
    }
    
    target = 100;
    result = binarySearchSortedMainDiagonal(sortedSquare, target);
    if (result != -1) {
        cout << "Element " << target << " found on main diagonal at position " << result << endl;
    } else {
        cout << "Element " << target << " not found on main diagonal\n";
    }
}

// Simplified version with English text
int main() {
    // Try different methods for locale setting
    #ifdef _WIN32
        // For Windows
        system("chcp 65001 > nul");  // UTF-8
    #endif
    
    // Try to set locale (might work on some systems)
    setlocale(LC_ALL, "en_US.UTF-8");
    
    // Testing all functions
    testFunctions();
    
    // Additional example: working with keyboard input
    cout << "\n=== WORKING WITH KEYBOARD INPUT ===\n";
    cout << "Do you want to enter matrix from keyboard? (1 - yes, 0 - no): ";
    int choice;
    cin >> choice;
    
    if (choice == 1) {
        vector<vector<int>> userMatrix = inputMatrix();
        cout << "\nEntered matrix:\n";
        printMatrix(userMatrix);
        
        cout << "Average: " << getMatrixAverage(userMatrix) << endl;
        
        // Sort first column and show result
        vector<vector<int>> sortedMatrix = userMatrix;
        sortFirstColumnInsertion(sortedMatrix);
        cout << "\nMatrix with sorted first column:\n";
        printMatrix(sortedMatrix);
    }
    
    return 0;
}









