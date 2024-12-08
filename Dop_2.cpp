#include <iostream>
using namespace std;

int sumOfDigits(int n) {
    int S = 0;
    while (n > 0) {
        S += n % 10;
        n /= 10;
    }
    return S;
}

int main() {
    int S = 0;
    int count[28] = {0}; 

    for (int i = 0; i < 1000; ++i) {
        int digitSum = sumOfDigits(i);
        count[digitSum]++; 
    }

    for (int i = 0; i < 28; ++i) {
        S += count[i] * count[i]; 
    }

    cout << S; 
    return 0;
}