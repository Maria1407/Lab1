#include <iostream>
#include <set>
#include <string>
#include <cstring>
#include <algorithm>

// Функция для проверки, содержится ли буква в слове не менее трех раз
bool hasLetterAtLeastThreeTimes(const std::string& word) {
    int letterCount[26] = {0}; // Для подсчета букв a-z
    for (char ch : word) {
        if (isalpha(ch)) {
            letterCount[tolower(ch) - 'a']++;
            if (letterCount[tolower(ch) - 'a'] >= 3) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Ошибка открытия файла." << std::endl;
        return 1;
    }

    std::set<std::string> foundWords; // Используем set для хранения уникальных слов
    std::string word;

    // Чтение слов из файла
    while (inputFile >> word) {
        // Проверяем, удовлетворяет ли слово условиям
        if (hasLetterAtLeastThreeTimes(word)) {
            foundWords.insert(word); // Добавляем слово в множество
        }
    }

    // Создаем массив фиксированного размера
    const int MAX_WORDS = 2000;
    std::string uniqueWords[MAX_WORDS];
    int count = 0;

    // Заполняем массив уникальными словами из множества
    for (const auto& w : foundWords) {
        if (count < MAX_WORDS) {
            uniqueWords[count++] = w;
        } else {
            break; // Прерываем, если достигли максимума
        }
    }

    // Сортируем слова по длине
    std::sort(uniqueWords, uniqueWords + count, [](const std::string& a, const std::string& b) {
        return a.length() < b.length();
    });

    // Записываем результат в выходной файл
    for (int i = 0; i < count; ++i) {
        outputFile << uniqueWords[i] << std::endl;
    }

    inputFile.close();
    outputFile.close();
    
    return 0;
}