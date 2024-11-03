#include <iostream>  
  
using namespace std;  
  
int getFirstDigit(int n); 
int productOfDigits(int n);  
void swap(int &a, int &b); 
  
  
int main()  
{ 
    int summ = 0, min_sum = 1000000, column = -1; 
    const int n=3; 
    const int m=3; 
    int arr[n][m]; 
    for (int i = 0; i < n; i++) { 
          for (int j = 0; j < m; j++) { 
        // cout << "Enter a number: ";  
        cin >> arr[i][j];  
        } 
    }   
    cout << endl; 
 
    for (int j = 0; j < m; j++) 
    { 
        summ = 0; 
        for (int i = 0; i < n; i++) 
        { 
            summ += arr[i][j]; 
        } 
        if (summ < min_sum) { 
            min_sum = summ; 
            column = j; 
        } 
 
    } 
 
    for (int i = 0; i < n; i++) { 
        arr[i][column] += 3; 
    } 
 
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < m; j++) { 
            cout << arr[i][j] << " "; 
        } 
        cout << endl; 
    } 
 
}