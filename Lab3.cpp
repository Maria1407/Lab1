#include <iostream>

using namespace std;


int main() {
    int number, index; 
    cin >> number; 
    cin >> index;
    number = (number & ~(1 << index));
    cout << number << endl;
}