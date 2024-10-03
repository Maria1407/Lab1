#include <iostream>
#include <vector>
#include <algorithm>

// Функция для получения первой цифры числа
int getFirstDigit(int num) {
    while (num >= 10) {
        num /= 10;
    }
    return num;
}

// Функция для получения суммы цифр числа
int getDigitSum(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

// Функция для сравнения двух чисел по заданным условиям
bool compareNumbers(int a, int b) {
    int firstDigitA = getFirstDigit(a);
    int firstDigitB = getFirstDigit(b);
    if (firstDigitA == firstDigitB) {
        int sumA = getDigitSum(a);
        int sumB = getDigitSum(b);
        if (sumA == sumB) {
            return a <= b;
        } else {
            return sumA <= sumB;
        }
    } else {
        return firstDigitA <= firstDigitB;
    }
}

int main() {
    int n;
    std::cout << "Введите количество чисел (n <= 1000): ";
    std::cin >> n;

    std::vector<int> numbers(n);
    std::cout << "Введите " << n << " натуральных чисел: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::sort(numbers.begin(), numbers.end(), compareNumbers);

    std::cout << "Отсортированная последовательность:" << std::endl;
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
