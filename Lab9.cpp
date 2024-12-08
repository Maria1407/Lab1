#include<iostream>
using namespace std; 
 
int main() { 
    long long p; 
    cin >> p;
    long long* ptr = &p; 
 
    unsigned char* x = reinterpret_cast<unsigned char*>(ptr); 
    
    cout << static_cast<long long>(*x) << endl;
    cout << static_cast<long long>(*(x+1)) << endl;
    return 0; 
}