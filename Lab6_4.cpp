#include <iostream>

using namespace std;

bool multiplicityDigitFourteen(int num) 
{
    int product = 1;
    bool hasEvenDigit = false;
    bool hasDigitSeven = false;

    while (num > 0) {
        int digit = num % 10;
        product *= digit;

        if (digit % 2 == 0) {
            hasEvenDigit = true;
        }
        if (digit == 7) {
            hasDigitSeven = true;
        }
        
        num /= 10;
    }

    return hasEvenDigit && hasDigitSeven;
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
    
    for (int i = 0; i < n; i++) 
    {
        bool uniqueDigits = true; 
        int x = mas[i];
        int digits[10] = {0};
        
        while (x > 0)
        {
            int digit = x % 10;
            digits[digit]++;
            
            if (digits[digit] > 1) {
                uniqueDigits = false;
                break; 
                }
                
            x /= 10;
        }
            
            
        if (uniqueDigits) 
        {
            for(int j = i; j < n - 1; j++)
                mas[j] = mas[j+1];
            i--;
            n--;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (multiplicityDigitFourteen(mas[i]))  
        { 
           
            for (int j = n; j > i; j--) 
                mas[j] = mas[j - 1]; 
            i++; 
            n++; 
            
            if (n >= N_Max)
            {
                cerr << "Error: Array size exceeded maximum limit." << endl;
                break; 
            }
        } 
    } 

    cout << "Result: ";
    for (int i = 0; i < n; i++) {
        cout << mas[i] << " ";
    }
    cout << endl;

    return 0; 
    
}
