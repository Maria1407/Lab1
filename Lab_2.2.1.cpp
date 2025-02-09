#include <iostream>

unsigned long long factorial(int n) {
    if (n == 1 || n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    int N;
    std::cout << "Enter the number N (1 <= N <= 19): ";
    std::cin >> N;

    if (N < 1 || N > 19) {
        std::cerr << "Mistake: N must be between 1 and 19." << std::endl;
        return 1;
    }

    unsigned long long result = factorial(N);
    std::cout << "The factorial of a number " << N << " equal to " << result << std::endl;

    return 0;
}