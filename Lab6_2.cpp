#include <iostream> 
 
using namespace std; 
 
int getFirstDigit(int n);
int productOfDigits(int n); 
void swap(int &a, int &b);
 
 
int main() 
{    
    cout << "TASK 2" << endl; 
 
    const int n = 5;  
    int arr[n];
  
    for (int i = 0; i < n; i++) {  
        cout << "Enter a number: "; 
        cin >> arr[i]; 
    }  
 
    for (int i = 0; i < n - 1; ++i)  
    {  
        for (int j = i + 1; j < n; ++j)  
        {  
            int number1 = arr[i]; 
            int number2 = arr[j]; 
 
            int first_digit1 = getFirstDigit(arr[i]); 
            int first_digit2 = getFirstDigit(arr[j]); 
 
            int productOfDigits1 = productOfDigits(arr[i]); 
            int productOfDigits2 = productOfDigits(arr[j]); 
             
            if (first_digit1 > first_digit2)  
            { 
                swap(arr[i], arr[j]); 
            
            } else if (first_digit1 == first_digit2) { 
                if (productOfDigits1 > productOfDigits2)  
                { 
                swap(arr[i], arr[j]);
                
                } else if (productOfDigits1 == productOfDigits2) { 
                    if (number1 > number2) { 
                        swap(arr[i], arr[j]); 
                    } 
                } 
            } 
        } 
    }  
     
    for (int i = 0; i < n; i++)  
            cout << arr[i] << " "; 
 
    return 0; 
} 
 
 
int productOfDigits(int n)  
{    
    int product = 1; 
    while (n)  
    { 
        product *= n % 10;
        n /= 10;
    } 
    return product;
} 
 
 
int getFirstDigit(int n)  
{ 
    while (n >= 10)  
        n /= 10; 
     
    return n;   
} 
 
void swap(int &a, int &b) { 
    int temp = a; 
    a = b; 
    b = temp; 
    return; 
}