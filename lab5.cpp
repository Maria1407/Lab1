#include <iostream>
using namespace std;
 
int main()
{
    int j;
    float num;
    cout << "Enter the quantity\n";
    cin >> j;
    int size = j;
    float sum = 0;
    int num_max = 0;
    float size_max = INT_MIN;
 
    for (j = 1; j <= size; j++)
    {
        cout << "Enter a number \n";
        cin >> num;
 
        if ((num >= -7) && (num <= 19))
        {
            sum = sum + num;
 
            if (num > size_max)
            {
                size_max = num;
                num_max = j;
            }
        }
    }
    cout << sum << " " << size_max << " " << num_max << endl;
    
    
    
    
    int N;
    int SUM = 0;
 
    cout << "Enter n = ";
    cin >> N;
 
    while (N!=0)
    {
        SUM += N%10;
        N /= 10;
    }
    cout << "sum = " << SUM << endl;
    
    return 0;
}