#include <iostream>
#include <algorithm>

using namespace std;
const int ROWS = 3; // ʳ������ �����
const int COLS = 3; // ʳ������ ��������

// ������� ��� ����������� ������������� �������� � �������
int findMaxInColumn(int arr[][COLS], int col) {
    int maxElement = arr[0][col];
    for (int i = 1; i < ROWS; ++i) {
        if (arr[i][col] > maxElement) {
            maxElement = arr[i][col];
        }
    }
    return maxElement;
}

// ������� ��� ����������� ���������� �������� � �������
int findMinInColumn(int arr[][COLS], int col) {
    int minElement = arr[0][col];
    for (int i = 1; i < ROWS; ++i) {
        if (arr[i][col] < minElement) {
            minElement = arr[i][col];
        }
    }
    return minElement;
}

// ������� ��� ����� ������������� �� ���������� �������� � �������
void swapMaxAndMinInColumn(int arr[][COLS], int col) {
    int maxElement = findMaxInColumn(arr, col);
    int minElement = findMinInColumn(arr, col);

    // ��������� ������� ������������� �� ���������� ��������
    int maxIndex = -1, minIndex = -1;
    for (int i = 0; i < ROWS; ++i) {
        if (arr[i][col] == maxElement) {
            maxIndex = i;
        }
        if (arr[i][col] == minElement) {
            minIndex = i;
        }
    }

    // ���� ������
    swap(arr[maxIndex][col], arr[minIndex][col]);
}

int main() {
    // ������������ ����������
    setlocale(LC_ALL, "");

    int array[ROWS][COLS];

    // �������� �������� ����������� ������
    cout << "������ �������� ������ " << ROWS << "x" << COLS << ":\n";
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << "������� [" << i << "][" << j << "]: ";
            cin >> array[i][j];
        }
    }

    // ��������� ����������� ������
    cout << "\n���������� �����:\n";
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << array[i][j] << "\t";
        }
        cout << '\n';
    }

    // ����������� ������������� �� ���������� �������� � ������� ������� �� ���� �� ������
    for (int j = 0; j < COLS; ++j) {
        swapMaxAndMinInColumn(array, j);
    }

    // ��������� ����������
    cout << "\n����� ���� ����� ������������ � ��������� ��������:\n";
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << array[i][j] << "\t";
        }
        cout << '\n';
    }

    return 0;
}