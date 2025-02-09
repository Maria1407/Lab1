#include <iostream>
#include <cmath>

using namespace std;

class Square {
private:
    int side;
public:
    Square(int s) {
        side = s;
    }

    int area() {
        return pow(side, 2);
    }

    int perimeter() {
        return 4 * side;
    }

    double diagonal() {
        return side * sqrt(2);
    }
};

int main() {
    Square squareA(10); 
    Square squareB(5); 
    
    cout << "Square A: Area = " << squareA.area()
         << ", Perimeter = " << squareA.perimeter()
         << ", Diagonal = " << squareA.diagonal() << endl;

    cout << "Square B: Area = " << squareB.area()
         << ", Perimeter = " << squareB.perimeter()
         << ", Diagonal = " << squareB.diagonal() << endl;

    return 0;
}