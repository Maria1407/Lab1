#include <iostream>

using namespace std;

bool multiplicityDigitThirtyFive(int num)  
{ 
    int product = 1; 

    while (num > 0) { 
        int digit = num % 10; 
        product *= digit; 

        num /= 10; 
    }

    return (product % 5 == 0 && product % 7 == 0);
}

int sumOfDigits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() 
{  
    const int N_Max  = 20000; 
    int mas[N_Max]; 
    int n; 
    cin >> n; 

    if (n > N_Max) { 
        cerr << "Error: Number of elements exceeds maximum limit." << endl; 
        return 1; 
    }

    for(int i = 0; i < n; i++) 
        cin >> mas[i]; 
     
    for (int i = 0; i < n; i++) { 
        if (sumOfDigits(mas[i]) == 18) { 
            for (int j = i; j < n - 1; j++) 
                mas[j] = mas[j + 1]; 
            i--; 
            n--; 
        } 
    } 

    for (int i = 0; i < n; i++) { 
        if (multiplicityDigitThirtyFive(mas[i])) { 
            if (n >= N_Max) { 
                cerr << "Error: Array size exceeded maximum limit." << endl; 
                break; 
            }
            
            for (int j = n; j > i; j--) 
                mas[j] = mas[j - 1];   
            n++; 
            i++; 
        }  
    }  

    cout << "Result: "; 
    for (int i = 0; i < n; i++) { 
        cout << mas[i] << " "; 
    } 
    cout << endl; 

    return 0;  
}