#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>

// Option 3

const int N_MAX1 = 2000;
const int N_MAX23 = 10240;
const int SixteenUnpopularLet = 16;
using namespace std;

// функция, которая определяет знак ли это или буква
bool SignOrLetter(char sumbol){
    string str = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (str.find(sumbol) != string::npos){
        return true;
    } else {
        return false;
    }
} 

// Функция, которая определяет количество гласных в слове
int DefinitionVowels(string word){
    string str = "aeiouy";
    int summ = 0;
    for (int i = 0; i < word.length(); i++){
        if (str.find(word[i]) != string::npos){
            summ++;
        }
    }
    return summ;
}

// Функция, которая определяет является ли, поступившее значение словом или пустой строкой
int DefineWord(string& word){
    string str = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int summ = 0;
    for (int i = 0; i < word.length(); i++){
        if (str.find(word[i]) != string::npos){
            summ++;
        }
    }
    return summ;
}

// Функция, которая считает, сколько букв s в строке 
int CountingLetters(string& text, char s){
    int summ = 0;
    for (int i = 0; i < text.length(); i++){
        if (text[i] == s){
            summ++;
        }
    }
    return summ;
}

int main(){
// Задание 1
//---------------------------------------------------------------------------------------
    string n, n1 = "", str = "abcdefghijklmnopqrstuvwxyz";
    int counter1 = 0, counter2 = 0;
    cin >> n;
    vector<string> mas(N_MAX1);
    ifstream textt ("test.txt");
// Записываем слова из файл в массив
    while(!textt.eof()){
        textt >> mas[counter1];
        counter1++;
    }
    mas.resize(counter1);
    mas.shrink_to_fit();
// Разбиваем слово и удаляем повторяющиеся буквы
    for (int i = 0; i < n.length(); i++){
        n1 += tolower(n[i]);
    }
    sort(begin(n1), end(n1));
    auto it = unique(begin(n1), begin(n1) + n1.length()); 
    n1 = string(n1.begin(), it);
// Очищаем слова от лишних знаков
    for (int i = 0; i < counter1; i++){
        for (int j = 0; j < mas[i].length(); j++){
            if(SignOrLetter(mas[i][j]) == 0){
                mas[i].erase(j, 1);
                j--;
                continue;
            }  
            mas[i][j] = tolower(mas[i][j]);
        }
    }   
// Находим слова в которых есть буквы из заданного слова 
    for (int i = 0; i < counter1; i++){
        int count = 0;
        for (int j = 0; j < n1.length(); j++){
            if (mas[i].find(n1[j]) != string::npos){
                count++;
            }
        }
        if (count != n1.length()){
            mas[i] = "";
        }
    } 
// Находим кол-во других букв в найденных словах 
    for (int i = 0; i < counter1; i++){
        int countt = 0;
        for (int j = 0; j < str.length(); j++){
            if (mas[i].find(str[j]) != string::npos){
                countt++;
            }
        }
        if (countt != n1.length()+1){
             mas[i] = "";
        } else {
            counter2++;
        } 
    } 
// Проверка, есть ли вообще непустые строки
    if (counter2 == 0){
        return -1;
    }
// Убираем все лишние пустые строки
    sort(begin(mas), end(mas));
    mas.erase(mas.begin(), mas.end() - counter2);
// Убираем одинаковые слова
    auto itt = unique(begin(mas), begin(mas) + counter2);
    int pos = distance(mas.begin(), itt);
    mas.resize(pos);
// Создаём вспомогательный двумерный массив lst
    vector<vector<int>> lst(pos, vector<int>(2));
    for (int i = 0; i < pos; i++){
        lst[i][0] = mas[i].length(); // длинна слова
        lst[i][1] = i; // индекс слова
    }
// Сортируем массив lst по убыванию
    sort(begin(lst), end(lst));
    reverse(begin(lst), end(lst));
// Выводим результат
    for (int i = 0; i < pos; i++){
        cout << mas[lst[i][1]] << endl;
    } 
    textt.close();
// Задание 2
//---------------------------------------------------------------------------------------

    string str = "abcdefghijklmnopqrstuvwxyz", vowels = "aeiouy";
    int counter1 = 0, counter2 = 0;
    vector<string> mass(N_MAX23);
    ifstream textt ("test.txt");
// Записываем слова из файл в массив
    while(!textt.eof()){
        textt >> mass[counter1];
        counter1++;
    }
    mass.resize(counter1);
    mass.shrink_to_fit();
// Очищаем слова от лишних знаков
    for (int i = 0; i < counter1; i++){
        for (int j = 0; j < mass[i].length(); j++){
            if(SignOrLetter(mass[i][j]) == 0){
                mass[i].erase(j, 1);
                j--;
                continue;
            }  
            mass[i][j] = tolower(mass[i][j]);
        }
    } 
// В словах, у которых меньше 3 гласных, удаляем гласные и дублируем согласные
    for (int i = 0; i < counter1; i++){
        if (DefinitionVowels(mass[i]) < 3){
            for (int j = 0; j < mass[i].length(); j++){
                if (vowels.find(mass[i][j]) != string::npos){
                    mass[i].erase(j, 1);
                    j--;
                } else {
                    mass[i].insert(mass[i].begin()+j, mass[i][j]);
                    j++;
                }
            }
        } 
        if (DefineWord(mass[i]) >= 1){
            counter2++; 
        }
    } 
// Сортирум слова в порядке обратному алфавитному, заодно удаляем пустые строки
    sort(begin(mass), end(mass));
    reverse(begin(mass), end(mass));
// Выводим результат
    for (int i = 0; i < counter2; i++){
        cout << mass[i] << endl;
    } 
    textt.close();
// Задание 3
//---------------------------------------------------------------------------------------
    string str = "abcdefghijklmnopqrstuvwxyz", wordstext = "";
    int counter1 = 0, p = 0;
    vector<string> mas(N_MAX23);
    vector<vector<int>> lst(26, vector<int>(2));
    ifstream textt ("input1.txt");
// Записываем слова из файл в массив
    while(!textt.eof()){
        textt >> mas[counter1];
        counter1++;
    }
    mas.resize(counter1);
    mas.shrink_to_fit();
// Очищаем слова от лишних знаков
    for (int i = 0; i < counter1; i++){
        for (int j = 0; j < mas[i].length(); j++){
            if(SignOrLetter(mas[i][j]) == 0){
                mas[i].erase(j, 1);
                j--;
                continue;
            }  
            mas[i][j] = tolower(mas[i][j]);
        }
    } 
// Записываем слова из текста в строку
    for (int i = 0; i < counter1; i++){
        wordstext += mas[i];
    }
// находим самые частоиспользуемые буквы и заносим их в массив
    for (int i = 0; i < 26; i++){
        lst[i][0] = CountingLetters(wordstext, str[i]); // количество букв в тексте
        lst[i][1] = str[i]; // сама буква (ввиде числа)
    }  
// Сортируем массив, и удаляем из этих 26 букв 16 самых не популярных
    sort(begin(lst), end(lst));
    lst.erase(begin(lst), begin(lst)+SixteenUnpopularLet);
    reverse(begin(lst), end(lst));
// Находим слова содержащие ровно одну букву из тех, что чаще всего встречаются 
    for (int i = 0; i < counter1; i++){
        int count = 0;
        for (int j = 0; j < 10; j++){
            char vsp = lst[j][1];
            if (mas[i].find(vsp) != string::npos){ 
                count++;
            }
        }
        if (count != 1){
            mas[i] = "";
        } 
    }
// Записываем строки из массива mas в массив mass (без пустых строк)
    vector<string> mass(counter1);
     for (int i = 0; i < counter1; i++){
        if(mas[i] != ""){
            mass[p] = mas[i];
            p++;
        }
    } 
    mass.resize(p);
// Возводим буквы в верхний регистр
    for (int i = 0; i < p; i++){
        for (int j = 0; j < mass[i].length(); j++){
            mass[i][j] = toupper(mass[i][j]);
        }
    } 
// Добавляем вспомогательный массив в котором хранятся самые "популярные" буквы в найденных словах
    vector<string> vcpom(p);
    for (int i = 0; i < p; i++){
        for (int j = 0; j < 10; j++){
            char vsp = toupper(lst[j][1]);
            if (mass[i].find(vsp) != string::npos){
                vcpom[i] = lst[j][1];
            }
        } 
    }
    
// Записать найденные слова в output.txt
    ofstream out ("output.txt");
    for (int i = 0; i < p; i++){
        out << mass[i] << " (" << vcpom[i] << ")" << endl;
    }  
    textt.close();
    return 0;
}