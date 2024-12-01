#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <vector>
#include <algorithm>

// Функция для проверки, содержится ли буква в слове не менее трех раз
bool hasLetterAtLeastThreeTimes(const std::string& word) {
    std::vector<int> letterCount(26, 0); // Для подсчета букв a-z
    for (char ch : word) {
        // Приводим к нижнему регистру и проверяем только буквы
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

    // Переносим слова в вектор для сортировки
    std::vector<std::string> uniqueWords(foundWords.begin(), foundWords.end());

    // Сортируем слова по длине
    std::sort(uniqueWords.begin(), uniqueWords.end(), [](const std::string& a, const std::string& b) {
        return a.length() < b.length();
    });

    // Ограничиваем выборку до N
    int N = std::min(2000, static_cast<int>(uniqueWords.size()));

    // Записываем результат в выходной файл
    for (int i = 0; i < N; ++i) {
        outputFile << uniqueWords[i] << std::endl;
    }

    inputFile.close();
    outputFile.close();
    
    return 0;
}