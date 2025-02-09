#include <iostream>
#include <thread>
#include <algorithm>
#pragma comment(linker, "/STACK:16777216")



void QuickSort(int a, int b, int* arr) {
    if(a>=b)
        return;
    // Выбор опорного элемента
    int k = (rand()*rand()) % (b-a+1) + a; //ранддомное число
    int m = arr[k];
    // Пресорт
    int l = a - 1;
    int r = b + 1;
    while(true) {
        do l++; while(arr[l] < m);
        do r--; while(arr[r] > m);
        if(l >= r) 
            break;
        std::swap(arr[l], arr[r]);
    }
    l = r;
    r++;
    QuickSort(a, l, arr);
    QuickSort(r, b, arr);
}

int main() {


    srand(time(0));
    const int n = 1'000'000;
    int arr[n] = {2, 3, 1, 6, 4};

    
    std::sort(arr, arr + n);

    std::cout << "===" << std::endl;
    for(int i=n-10;i<n;i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
    return 0;
}