#include <iostream>
#include "func.hpp"

using namespace std;


int main()
{
    int matrix[mt::N][mt::M];
    int n, m;

    // Read
    mt::Read(matrix, n, m);

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



        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mt::isPrime(matrix[i][j]) && matrix[i][j] > maxPrime) {
                    maxPrime = matrix[i][j];
                }
            }
        }

        
        for (int j = 0; j < n; ++j) {
            int minElement = INT_MAX;
            
            
            for (int i = 0; i < n; ++i) {
                if (matrix[i][j] < minElement) {
                    minElement = matrix[i][j];
                }
            }
            

            for (int i = 0; i < n; ++i) {
                if (matrix[i][j] == minElement) {
                    matrix[i][j] = maxPrime;
                }
            }
        }
    }


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}