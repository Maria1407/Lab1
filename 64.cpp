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
    cin >>n; 
    if (n > N_Max) {
        cerr << "Error: Number of elements exceeds maximum limit." << endl;
        return 1; // Проверка на превышение размера
    }

    for(int i = 0; i < n; i++) 
        cin >> mas[i]; 

    // Удаляем числа с уникальными цифрами
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
            // Сдвигаем массив влево
            for (int j = i; j < n - 1; j++) 
                mas[j] = mas[j + 1]; 
            i--; 
            n--; // Уменьшаем размер массива
        } 
    } 

    // Дублируем числа, произведение цифр которых кратно 14
    for (int i = 0; i < n; i++) 
    { 
        if (multiplicityDigitFourteen(mas[i]))  
        { 
            // Сдвигаем элементы вправо
            for (int j = n; j > i; j--) 
                mas[j] = mas[j - 1]; 
            mas[i + 1] = mas[i]; // Дублируем текущее число
            i++; // Пропускаем добавленный элемент
            n++; // Увеличиваем размер массива
            
            if (n >= N_Max) // Проверяем, не превышает ли n максимальный размер
            {
                cerr << "Error: Array size exceeded maximum limit." << endl;
                break; // Выход из цикла, если превышен размер массива
            }
        } 
    } 

    // Вывод результата
    cout << "Result: ";
    for (int i = 0; i < n; i++) {
        cout << mas[i] << " ";
    }
    cout << endl;

    return 0; // Возвращаем 0 для успешного завершения
}