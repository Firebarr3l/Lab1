#include "rwFunc.hpp"
#include <fstream>
#include <iostream>

// Функция для чтения данных из файла
void readFromFile(const std::string& filename, std::vector<std::string>& data) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка при открытии файла для чтения!" << std::endl;
        return;  // Выход из функции при ошибке открытия файла
    }

    std::string line;
    while (std::getline(file, line)) {
        data.push_back(line); // Добавляем строку в вектор
    }

    file.close();
}

// Функция для записи данных в файл
void writeToFile(const std::string& filename, const std::vector<std::string>& data) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка при открытии файла для записи!" << std::endl;
        return;  // Выход из функции при ошибке открытия файла
    }

    for (const auto& line : data) {
        file << line << std::endl; // Записываем каждую строку в файл
    }

    file.close();
}
