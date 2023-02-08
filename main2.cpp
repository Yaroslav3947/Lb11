#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

enum Option {
    CREATE = 1,
    FILL,
    PRINT,
    CLEAR,
    MIN,
    MAX,
    AVG,
    NEG,
    SUM_NEG,
    EXIT
};

int **createArray(int rows, int columns) {
    int **arr = new int *[rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[columns];
    }
    return arr;
}

void fillArray(int **array, int rows, int columns) {
    srand(time(0));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            // arr[i][j] = rand() % 21 - 10;
            std::cin >> array[i][j];
        }
    }
}

void printArray(int **arr, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << endl;
    }
}

void clearArray(int **arr, int rows){
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}

int minArray(int **arr, int rows, int columns) {
    int min = arr[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (arr[i][j] < min) {
                min = arr[i][j];
            }
        }
    }
    return min;
}

int maxArray(int **arr, int rows, int columns) {
    int max = arr[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (arr[i][j] > max) {
                max = arr[i][j];
            }
        }
    }
    return max;
}

double avgArray(int **arr, int rows, int columns) {
    int sum = 0;
    int elements = rows * columns;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            sum += arr[i][j];
        }
    }
    return (double)sum / elements;
}

int **negArray(int **arr, int rows, int columns, int &negRows) {
    int negCount = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (arr[i][j] < 0) {
                negCount++;
            }
        }
    }
int** negArr = createArray(rows, negCount);
    int index = 0;
    for(int i = 0; i < rows; i++) {
        negCount = 0;
        for (int j = 0; j < columns; j++) {
            if (arr[i][j] < 0) {
                negArr[i][negCount++] = arr[i][j];
            }
        }
        if (negCount > 0) {
            index++;
        }
    }
    negRows = index;
    return negArr;
}

int **sumNegArray(int **array, int rows, int columns, int &sumRows) {
    int negCount = 0;
    int *rowSums = new int[rows];
    int *negCounts = new int[rows];
    for (int i = 0; i < rows; i++) {
        int rowSum = 0;
        for (int j = 0; j < columns; j++) {
            if (array[i][j] < 0) {
                rowSum += array[i][j];
                negCount++;
            }
        }
        if (rowSum < 0) {
            rowSums[i] = rowSum;
            negCounts[i] = negCount;
            negCount = 0;
        } else {
            rowSums[i] = 0;
            negCounts[i] = 0;
            negCount = 0;
        }
    }
    int **sumArr = createArray(rows, 2);
    int index = 0;
    for (int i = 0; i < rows; i++) {
        if (rowSums[i] <= 0) {
            sumArr[index][0] = rowSums[i];
            sumArr[index][1] = negCounts[i];
            index++;
            }
        }
    sumRows = index;
    delete[] rowSums;
    delete[] negCounts;
    return sumArr;
}
void showPosibilities() {
    std::cout << "1. Create a dynamic array\n";
    std::cout << "2. Fill the dynamic array\n";
    std::cout << "3. Print the dynamic array\n";
    std::cout << "4. Clear the dynamic array\n";
    std::cout << "5. Determine the minimum value of the array\n";
    std::cout << "6. Determine the maximum value of the array\n";
    std::cout << "7. Determine the average arithmetic value of the array\n";
    std::cout << "8. Create a new array that contains all its negative elements\n";
    std::cout << "9. Create a new array from the sum of all negative elements of each row\n";
    std::cout << "10. Exit\n";
}
Option getChoice() {
    int option{};
    showPosibilities();
    std::cout << "Enter option:";
    std::cin >> option;
    return static_cast<Option>(option);
}
int main() {
    int rows, columns;
    int** arr;
  
    Option option;
    
    do {
        option = getChoice();
        switch (option) {
            case CREATE: {
                std::cout << "Enter the number of rows: ";
                std::cin >> rows;
                std::cout << "Enter the number of columns: ";
                std::cin >> columns;
                arr = createArray(rows, columns);
                break;
            }
            case FILL: {
                fillArray(arr, rows, columns);
                break;
            }
            case PRINT: {
                printArray(arr, rows, columns);
                break;
            }
            case CLEAR: {
                clearArray(arr,rows);
                break;
            }
            case MIN: {
                std::cout << "The minimum value of the array is: " << minArray(arr, rows, columns) << endl;
            break;
            }
            case MAX: {
                std::cout << "The maximum value of the array is: " << maxArray(arr, rows, columns) << endl;
                break;
            }
            case AVG: {
                std::cout << "The average arithmetic value of the array is: " << avgArray(arr, rows, columns) << endl;
                break;
            }
            case NEG: {
                int negRows;
                int **negArr = negArray(arr, rows, columns, negRows);
                std::cout << "The new array that contains all its negative elements: " << endl;
                printArray(negArr, negRows, columns);
                break;
            }
            case SUM_NEG: {
                int sumRows;
                int **sumArr = sumNegArray(arr, rows, columns, sumRows);
                std::cout << "The new array from the sum of all negative elements of each row: " << endl;
                printArray(sumArr, sumRows, 2);
                break;
            }
            default: {
                std::cout << "Invalid option" << endl;
            }
        }
    } while(option != EXIT);
    return 0;
}