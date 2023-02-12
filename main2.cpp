#include <ctime>
#include <iostream>

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
    int **array = new int *[rows];
    for (int i = 0; i < rows; i++) {
        array[i] = new int[columns];
    }
    return array;
}

void fillArray(int **array, int rows, int columns) {
    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            array[i][j] = rand() % 21 - 10;
            // std::cin >> array[i][j];
        }
    }
}

void printArray(int **array, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cout  << " " << array[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void clearArray(int **array, int rows){
    for (int i = 0; i < rows; i++) {
        delete[] array[i];
    }
    delete[] array;
}

int minArray(int **array, int rows, int columns) {
    int min = array[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (array[i][j] < min) {
                min = array[i][j];
            }
        }
    }
    return min;
}

int maxArray(int **array, int rows, int columns) {
    int max = array[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (array[i][j] > max) {
                max = array[i][j];
            }
        }
    }
    return max;
}

double avgArray(int **array, int rows, int columns) {
    int sum = 0;
    int numberOfElements = rows * columns;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            sum += array[i][j];
        }
    }
    return static_cast<double>(sum) / numberOfElements;
}

int **negArray(int **array, int rows, int columns, int &negRows) {
    int countOfNegativeNumbers = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (array[i][j] < 0) {
                countOfNegativeNumbers++;
            }
        }
    }
    int **negativeArray = createArray(rows, countOfNegativeNumbers);
    int index = 0;
    for(int i = 0; i < rows; i++) {
        countOfNegativeNumbers = 0;
        for (int j = 0; j < columns; j++) {
            if (array[i][j] < 0) {
                negativeArray[i][countOfNegativeNumbers++] = array[i][j];
            } else {
                negativeArray[i][countOfNegativeNumbers++] = 0;
            }
        }
        if (countOfNegativeNumbers > 0) {
            index++;
        }
    }
    negRows = index;
    return negativeArray;
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
Option getOption() {
    int option{};
    showPosibilities();
    std::cout << "Enter option:";
    std::cin >> option;
    return static_cast<Option>(option);
}
int getRows() {
    int rows;
    std::cout << "Enter the number of rows: ";
    std::cin >> rows;
    return rows;
}
int getColumns() {
    int columns;
    std::cout << "Enter the number of columns: ";
    std::cin >> columns;
    return columns;
}
int main() {
    int rows, columns;
    int **array;
    Option option;
    do {
        option = getOption();
        switch (option) {
            case CREATE: {
                rows = getRows();
                columns = getColumns();
                array = createArray(rows, columns);
                break;
            }
            case FILL: {
                fillArray(array, rows, columns);
                break;
            }
            case PRINT: {
                printArray(array, rows, columns);
                break;
            }
            case CLEAR: {
                clearArray(array,rows);
                break;
            }
            case MIN: {
                std::cout << "The minimum value of the array is: " << minArray(array, rows, columns) << std::endl;
            break;
            }
            case MAX: {
                std::cout << "The maximum value of the array is: " << maxArray(array, rows, columns) << std::endl;
                break;
            }
            case AVG: {
                std::cout << "The average arithmetic value of the array is: " << avgArray(array, rows, columns) << std::endl;
                break;
            }
            case NEG: {
                int negRows;
                int **negativeArray = negArray(array, rows, columns, negRows);
                std::cout << "The new array that contains all its negative elements: " << std::endl;
                printArray(negativeArray, negRows, columns);
                break;
            }
            case SUM_NEG: {
                int sumRows;
                int **sumArr = sumNegArray(array, rows, columns, sumRows);
                std::cout << "The new array from the sum of all negative elements of each row: " << std::endl;
                printArray(sumArr, sumRows, 2);
                break;
            }
            default: {
                std::cout << "Invalid option" << std::endl;
            }
        }
    } while(option != EXIT);
    return 0;
}