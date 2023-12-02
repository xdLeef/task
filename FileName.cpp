#include <iostream>
#include <algorithm>

using namespace std;
const int ROWS = 3; // Кількість рядків
const int COLS = 3; // Кількість стовпців

// Функція для знаходження максимального елемента в стовпці
int findMaxInColumn(int arr[][COLS], int col) {
    int maxElement = arr[0][col];
    for (int i = 1; i < ROWS; ++i) {
        if (arr[i][col] > maxElement) {
            maxElement = arr[i][col];
        }
    }
    return maxElement;
}

// Функція для знаходження мінімального елемента в стовпці
int findMinInColumn(int arr[][COLS], int col) {
    int minElement = arr[0][col];
    for (int i = 1; i < ROWS; ++i) {
        if (arr[i][col] < minElement) {
            minElement = arr[i][col];
        }
    }
    return minElement;
}

// Функція для обміну максимального та мінімального елементів в стовпці
void swapMaxAndMinInColumn(int arr[][COLS], int col) {
    int maxElement = findMaxInColumn(arr, col);
    int minElement = findMinInColumn(arr, col);

    // Знаходимо індекси максимального та мінімального елементів
    int maxIndex = -1, minIndex = -1;
    for (int i = 0; i < ROWS; ++i) {
        if (arr[i][col] == maxElement) {
            maxIndex = i;
        }
        if (arr[i][col] == minElement) {
            minIndex = i;
        }
    }

    // Обмін місцями
    swap(arr[maxIndex][col], arr[minIndex][col]);
}

int main() {
    // Встановлення локалізації
    setlocale(LC_ALL, "");

    int array[ROWS][COLS];

    // Введення елементів двовимірного масиву
    cout << "Введіть елементи масиву " << ROWS << "x" << COLS << ":\n";
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << "Елемент [" << i << "][" << j << "]: ";
            cin >> array[i][j];
        }
    }

    // Виведення початкового масиву
    cout << "\nПочатковий масив:\n";
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << array[i][j] << "\t";
        }
        cout << '\n';
    }

    // Знаходження максимального та мінімального елементів в кожному стовпці та обмін їх місцями
    for (int j = 0; j < COLS; ++j) {
        swapMaxAndMinInColumn(array, j);
    }

    // Виведення результату
    cout << "\nМасив після обміну максимальних і мінімальних елементів:\n";
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << array[i][j] << "\t";
        }
        cout << '\n';
    }

    return 0;
}