#include <iostream>

using namespace std;

bool containsDigitFive(int num);

int main()
{ 
    cout << "TASK 4" << endl;

    const int N_Max  = 20000;
    int mas[N_Max];

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> mas[i];
    
    for (int i = 0; i < n; i++) 
    {
        bool f = false;
        int x = mas[i];
        int digits[10] = {0};
        int y;

        while (x > 0) 
        {
            int digit = x % 10;
            if (digits[digit] > 0) {
                f = true;
                break; 
            }

            digits[digit]++;
            x /= 10;
        }

        if (f)
        {
            for(int j = i; j < n - 1; j++)
                mas[j] = mas[j+1];
            i--;
            n--;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (containsDigitFive(mas[i])) 
        {
            for (int j = n; j > i; j--)
                mas[j] = mas[j - 1];
            i++;
            n++;
        }
    }

    cout << "\nResult: ";
    for (int i = 0; i < n; ++i) {
        std::cout << mas[i] << " ";
    }
    cout << endl;

}


bool containsDigitFive(int num) 
{
    while (num) {
        if (num % 10 == 5) {
            return true; 
        }
        num /= 10;
    }
    return false;
}