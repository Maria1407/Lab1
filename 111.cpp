#include <iostream>
#include <cmath> 

class Square {
private:
    double side;

public:
    Square(double sideLength) : side(sideLength) {}

    double area() {
        return side * side;
    }

    double perimeter() {
        return 4 * side;
    }

    double diagonalLength() {
        return sqrt(2) * side;
    }
};

int main() {
    double sideLength;

    std::cout << "Enter the length of the side of the square: ";
    std::cin >> sideLength;

    Square square(sideLength);

    std::cout << "Square area: " << square.area() << std::endl;
    std::cout << "The perimeter of the square: " << square.perimeter() << std::endl;
    std::cout << "The length of the diagonal of the square: " << square.diagonalLength() << std::endl;

    return 0;
}
