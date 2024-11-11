#include "func.hpp"
#include <cmath>
#include <iostream>

namespace mt
{
    bool isPrime(int num) {
        if (num < 2) return false;
        for (int i = 2; i <= sqrt(num); ++i) {
            if (num % i == 0) return false;
        }
        return true;
    }

    bool Read(int matrix[N][M], int& n, int& m)
    {
        //int n, m;
        int readMatrix;
        std::cin >> n >> m;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                std::cin >> matrix[i][j];
            }
        }
    }
}