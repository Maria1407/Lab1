#include <iostream>
#include <algorithm>
using namespace std;

int firstDigit(int num) {
    while (num >= 10) {
        num /= 10;
    }
    return num;
}

int productOfDigits(int num) {
    int product = 1;
    while (num != 0) {
        int digit = num % 10;
        product *= digit;
        num /= 10;
    }
    return product;
}

bool compareNumbers(int a, int b) {
    if (firstDigit(a) != firstDigit(b)) {
        return firstDigit(a) < firstDigit(b);
    } else if (productOfDigits(a) != productOfDigits(b)) {
        return productOfDigits(a) < productOfDigits(b);
    } else {
        return a < b;
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    int arr[1000];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    sort(arr, arr + n, compareNumbers);
    
    cout << "Sorted sequence: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    return 0;
}