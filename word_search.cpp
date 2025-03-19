#include <iostream>
#include <fstream>
#include <string>
#include <algorithm> // Для преобразования в нижний регистр
#include <cctype>    // Для std::tolower

// Функция для преобразования строки в нижний регистр
std::string toLowerCase(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), [](unsigned char c) { return std::tolower(c); });
    return result;
}

int main() {
    // Имя файла для поиска
    const std::string fileName = "words.txt";

    // Открываем файл
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file '" << fileName << "'." << std::endl;
        return 1; // Выход с кодом ошибки
    }

    // Запрашиваем слово для поиска
    std::cout << "Enter a word to search: ";
    std::string targetWord;
    std::cin >> targetWord;

    // Преобразуем слово в нижний регистр для нечувствительного поиска
    targetWord = toLowerCase(targetWord);

    // Счётчик вхождений слова
    int count = 0;
    std::string word;

    // Читаем слова из файла
    while (file >> word) {
        // Преобразуем каждое слово в нижний регистр
        word = toLowerCase(word);
        if (word == targetWord) {
            ++count; // Увеличиваем счётчик при совпадении
        }
    }

    // Выводим результат
    std::cout << "The word '" << targetWord << "' appears " << count << " times in the file." << std::endl;

    // Закрываем файл
    file.close();
    return 0; // Выход с кодом успеха
}
