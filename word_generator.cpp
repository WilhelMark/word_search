#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib> // Для rand() и srand()
#include <ctime>   // Для генерации случайного seed

// Функция для генерации случайного слова
std::string generateRandomWord(int length) {
    const std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    std::string word;
    for (int i = 0; i < length; ++i) {
        word += alphabet[rand() % alphabet.size()];
    }
    return word;
}

int main() {
    // Устанавливаем seed для генератора случайных чисел
    srand(static_cast<unsigned int>(time(0)));

    // Имя файла для записи
    const std::string fileName = "words.txt";

    // Открываем файл для записи
    std::ofstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Error: Could not create the file '" << fileName << "'." << std::endl;
        return 1; // Выход с кодом ошибки
    }

    // Параметры генерации
    const int totalWords = 50;       // Общее количество слов
    const int minWordLength = 3;     // Минимальная длина слова
    const int maxWordLength = 8;     // Максимальная длина слова

    for (int i = 0; i < totalWords; ++i) {
        // Генерируем случайную длину слова в заданных пределах
        int wordLength = minWordLength + rand() % (maxWordLength - minWordLength + 1);

        // Генерируем случайное слово
        std::string word = generateRandomWord(wordLength);

        // Записываем слово в файл
        file << word;

        // Добавляем пробел или перенос строки
        if ((i + 1) % 10 == 0) { // Каждое 10-е слово — перенос строки
            file << "\n";
        } else {
            file << " ";
        }
    }

    // Закрываем файл
    file.close();
    std::cout << "File '" << fileName << "' has been created and filled with random words." << std::endl;

    return 0; // Успешный выход
}
