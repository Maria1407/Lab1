#include <iostream>

using namespace std;


bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) return false;
    }
    return true;
}


int main()
{
    const int n=5;
    const int m=5;
    int matrix[n][m];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }

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
                if (isPrime(matrix[i][j]) && matrix[i][j] > maxPrime) {
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