#include "rwFunc.hpp"
#include <fstream>
#include <iostream>

// Функция для чтения данных из файла
void readFromFile(const std::string& filename, std::vector<GardenRecord>* data) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка при открытии файла для чтения!" << std::endl;
        return;  // Выход из функции при ошибке открытия файла
    }

    std::string line;
    while (std::getline(file, line)) {
        GardenRecord garden;
        size_t pos = 0;

        garden.id = std::stoi(line, &pos);
        line = line.substr(pos + 1);
        garden.number = std::stoi(line, &pos);
        line = line.substr(pos + 1);
        garden.name = line.substr(0, line.find(';'));
        line = line.substr(line.find(';') + 1);
        garden.phone = line.substr(0, line.find(';'));
        line = line.substr(line.find(';') + 1);
        garden.address = line;

        data->push_back(garden);  // Используем указатель
    }

    file.close();
}

// Функция для записи данных в файл
void writeToFile(const std::string& filename, const std::vector<GardenRecord>* data) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка при открытии файла для записи!" << std::endl;
        return;  // Выход из функции при ошибке открытия файла
    }

    for (const auto& garden : *data) {
        file << garden.id << ";"
             << garden.number << ";"
             << garden.name << ";"
             << garden.phone << ";"
             << garden.address << ";"
             << std::endl;
    }

    file.close();
}
