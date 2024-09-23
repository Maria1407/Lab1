#include <iostream>

using namespace std;

void setBitToZero(int& x, int position) {
    // Находим маску для установки нужного бита в ноль
    unsigned int mask = ~(1U << position);
    
    // Применяем маску к числу x
    x &= mask;
}

int main() {
    int x = 0b101001010111;
    int position;

    cout << "Enter position: ";
    cin >> position;

    cout << "\nx = " << x << endl;

    setBitToZero(x, position);

    cout << "\nX after setting bit to zero = " << x << endl;

    return 0;
}