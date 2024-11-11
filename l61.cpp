#include <iostream>

using namespace std;

int main() 
{
    int temp = 0;
    bool flag = false; 

    const int n = 6; 
    int arr[n] {}; 

    for (int i = 0; i < n; i++) { 
        cin >> arr[i]; 
    } 

    // Проверяем на одинаковые элементы
    for (int i = 0; i < n - 1; ++i) { 
        for (int j = i + 1; j < n; ++j) { 
            if (arr[i] == arr[j]) { 
                flag = true; 
                break; 
            } 
        }
        if (flag) break; // Выходим из первого цикла при нахождении одинакового элемента
    } 

    if (flag) { 
        // Если есть одинаковые элементы, сортируем по последней цифре
        for (int i = 0; i < n - 1; ++i) { 
            for (int j = 0; j < n - i - 1; ++j) { 
                if (arr[j] % 10 < arr[j + 1] % 10) { 
                    temp = arr[j + 1]; 
                    arr[j + 1] = arr[j]; 
                    arr[j] = temp; 
                } 
            } 
        }
    } else { 
        cout << "We do not have the same numbers" << endl;     
    } 

    // Выводим массив
    for (int i = 0; i < n; ++i) 
        cout << arr[i] << " ";   

    return 0;  
}
