#include <iostream>
#include <climits>
#include <cmath>

const int N = 100; // максимальный размер матрицы

bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    std::cout << "Введите размер матрицы n (n <= 100): ";
    std::cin >> n;

    int matrix[N][N];

    std::cout << "Введите элементы матрицы:" << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    // Проверяем, есть ли одинаковые строки
    bool hasIdenticalRows = false;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            bool identical = true;
            for (int k = 0; k < n; ++k) {
                if (matrix[i][k] != matrix[j][k]) {
                    identical = false;
                    break;
                }
            }
            if (identical) {
                hasIdenticalRows = true;
                break;
            }
        }
        if (hasIdenticalRows) break;
    }

    if (hasIdenticalRows) {
        int maxPrime = INT_MIN;

        // Находим наибольший простой элемент
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isPrime(matrix[i][j]) && matrix[i][j] > maxPrime) {
                    maxPrime = matrix[i][j];
                }
            }
        }

        // Заменяем минимальные элементы столбцов на найденный максимальный простой элемент
        for (int j = 0; j < n; ++j) {
            int minElement = INT_MAX;
            // Находим минимальный элемент в столбце
            for (int i = 0; i < n; ++i) {
                if (matrix[i][j] < minElement) {
                    minElement = matrix[i][j];
                }
            }
            // Заменяем минимальный элемент на максимальный простой элемент
            for (int i = 0; i < n; ++i) {
                if (matrix[i][j] == minElement) {
                    matrix[i][j] = maxPrime;
                }
            }
        }
    }

    // Выводим измененную матрицу
    std::cout << "Измененная матрица:" << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}