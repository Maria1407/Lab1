#include <iostream>


 
using namespace std;
 
int main()
{
   
    int temp = 0, num1 = 0, num2 = 0;
    bool flag = false;

    const int n = 6;
    // cin >> n;
    int arr[n] {};

    for (int i = 0; i < n; i++) {
        int number;
        cin >> number;

        arr[i] = number;
    }

    // Сортируем 

    // for (int i = 0; i < n - 1; ++i)
    // {
    //     for (int j = 0; j < n - i - 1; ++j)
    //     {
    //         if (arr[j] > arr[j+1])
    //         {
    //             temp = arr[j+1];
    //             arr[j+1] = arr[j];
    //             arr[j] = temp;
    //         }
    //     }
    // }

    // for (int i = 0; i < n; ++i)
    //     cout << arr[i] << " ";
    
    // Выясняем есть ли одинаковые
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - 1; ++j)
        {
            if (arr[j] == arr[j+1])
            {
                flag = true;
                break;
            }
        }
    }
    cout << "\n";
    if (flag) {
        for (int i = 0; i < n - 1; ++i)
        {
            for (int j = 0; j < n - 1; ++j)
            {
                num1 = arr[j] % 10;
                num2 = arr[j+1] % 10;
                if (num1 < num2)
                {
                    temp = arr[j+1];
                    arr[j+1] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
        
    else
    {
        cout << "We does not have the same numbers" << endl;    
    }
    for (int i = 0; i < n; ++i)
            cout << arr[i] << " ";  
    //return 0; 
}