#include <iostream>
using namespace std;

/// @brief 
// 1231
/// @return 

// aaaaaaqaaaa
int main() {
    cout << "Data Type: int; Size: 4 bytes; min range:: -2*10^9 ; max range:: 2*10^9\n" << endl;
    int a = 10;
    int b = -1;

    cout << "A = 10, B = 1, A + B =" << a+b << "\n" << endl;


cout    << "Data Type: unsigned int; Size: 4 bytes; min range:: 0; max range:: 4*10^9\n"<< endl;
    unsigned int x = 3;
    unsigned int y = 5;

    cout << "X = 3, Y = 5, X * Y =" << x*y << "\n" << endl;

     cout    << "Data Type: long long; Size: 8 bytes; min range: -9*10^18; max range: 9*10^18\n" << endl;
    
    long long c = 10000000000000000;
    long long d = -1000000000000;

    cout << "C = 10000000000000000, D =-1000000000000, C / D =" << c/d << "\n" << endl;


    cout    << "Data Type: unsigned long long; Size: 8 bytes; min range: 0; max range: 18*10^18\n"<< endl;

    unsigned long long s = 1000000000000000000;
    unsigned long long t = 1000000000000000;

    cout << "S = 1000000000000000000, T = 1000000000000000, S - T =" << s-t << "\n" << endl;

    cout    << "Data Type: char; Size: 1 byte; min range: 0; max range:255\n"<< endl;


    char f = 'A';
    char l = 'B';

    cout << "F = A, L = B, F + L =" << f+l << "\n" <<endl;



    cout    << "Data Type:  bool; Size: 1 byte; Range: true / false\n"<< endl;

    bool D = (a > b);
    cout << "Boolean result of (a > b): " << D << "\n" << endl;
    
    
    
    cout    << "Data Type: double; Size: 8 byte; min range: +/- 1.7E-308; max range: 1.7E+308\n"<< endl;

    double q = 11.111;
    double r = 12.222;

    cout << "Q = 11.111,  R = 12.222, Q + R =" << q+r << endl;

    cout    << "Data Type: long; Size: 4 or 8 byte; 4: min range:−2 147 483 648 ; max range:2 147 483 647; 8: min range:−9 223 372 036 854 775 808; max range:+9 223 372 036 854 775 807 \n"<< endl;

    long z = 20000000;
    long w = -19999999;

    cout << "Z = 20000000, W =-19999999, Z - W =" << z-w << "\n" << endl;


    return 0;

}