#include <iostream>

int *createArray(int &size) {
    std::cout << "Enter the size of the array: ";
    std::cin >> size;
    int *array = new int[size];
    return array;
}

void fillArray(int *array, int size) {
    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        std::cin >> array[i];
    }
}

void printArray(int *array, int size) {
    std::cout << "[";
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "]" << std::endl;
}

void clearArray(int *array) {
    delete[] array;
    array = nullptr;
}

int findMin(int *array, int size) {
    int min = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}

int findMax(int *array, int size) {
    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

float findAverage(int *array, int size) {
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum / size;
}

int *getNegatives(int *array, int size, int &newSize) {
    newSize = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] < 0) {
            newSize++;
        }
    }
    int *negatives = new int[newSize];
    int j = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] < 0) {
            negatives[j++] = array[i];
        }
    }
    return negatives;
}

void sortArray(int *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}
enum Choice {
    CREATE_ARRAY = 1,
    FILL_ARRAY,
    PRINT_ARRAY,
    CLEAR_ARRAY,
    FIND_MIN,
    FIND_MAX,
    FIND_AVERAGE,
    GET_NEGATIVES,
    SORT_ARRAY,
    EXIT
};
void showPosibilities() {
    std::cout << "1. Create Array" << std::endl;
    std::cout << "2. Fill Array" << std::endl;
    std::cout << "3. Print Array " << std::endl;
    std::cout << "4. Clear Array" << std::endl;
    std::cout << "5. Find Minimum Value" << std::endl;
    std::cout << "6. Find Maximum Value" << std::endl;
    std::cout << "7. Find Average Value" << std::endl;
    std::cout << "8. Get Negative Elements" << std::endl;
    std::cout << "9. Sort Array" << std::endl;
    std::cout << "10. Exit" << std::endl;
}
Choice getChoice() {
    int choice;
    showPosibilities();
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    return static_cast<Choice>(choice);
}
int main() {
    int size;
    int *array = nullptr;
    Choice choice;
    int newSize;
    do {
        choice = getChoice();
        switch (choice) {
        case CREATE_ARRAY: {
            array = createArray(size);
            break;
        }
        case FILL_ARRAY:
            if (array == nullptr) {
                std::cout << "Create array first" << std::endl;
            } else {
                fillArray(array, size);
            }
            break;
        case PRINT_ARRAY:
            if (array == nullptr) {
                std::cout << "Create array first" << std::endl;
            } else {
                printArray(array, size);
            }
            break;
        case CLEAR_ARRAY:
            if (array == nullptr) {
                std::cout << "Create array first" << std::endl;
            } else {
                clearArray(array);
                array = nullptr;
                std::cout << "Array cleared" << std::endl;
            }
            break;
        case FIND_MIN:
            if (array == nullptr) {
                std::cout << "Create array first" << std::endl;
            } else {
                std::cout << "The minimum value is: " << findMin(array, size) << std::endl;
            }
            break;
        case FIND_MAX:
            if (array == nullptr) {
                std::cout << "Create array first" << std::endl;
            } else {
                std::cout << "The maximum value is: " << findMax(array, size) << std::endl;
            }
            break;
        case FIND_AVERAGE:
            if (array == nullptr) {
                std::cout << "Create array first" << std::endl;
            } else {
                std::cout << "The average value is: " << findAverage(array, size) << std::endl;
            }
            break;
        case GET_NEGATIVES:
            if (array == nullptr) {
                std::cout << "Create array first" << std::endl;
            } else {
                int *negatives = getNegatives(array, size, newSize);
                if(newSize) {
                    std::cout << "The negative elements are: ";
                    printArray(negatives, newSize);
                    std::cout << std::endl;
                    clearArray(negatives);
                } else {
                    std::cout << "There are no negative numbers\n";
                }
            }
            break;
        case SORT_ARRAY:
            if (array == nullptr) {
                std::cout << "Create array first" << std::endl;
            } else {
                sortArray(array, size);
                std::cout << "Array sorted in ascending order" << std::endl;
            }
            break;
        case EXIT:
            std::cout << "Exiting..." << std::endl;
            break;
        default:
            std::cout << "Invalid choice" << std::endl;
            break;
        }
    } while (choice != EXIT);
    return 0;
}