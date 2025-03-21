#include "rwFunc.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

// Функция для чтения данных из файла
void readFromFile(const std::string& filename, std::vector<GardenRecord>& data) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка при открытии файла для чтения!" << std::endl;
        return;  // Выход из функции при ошибке открытия файла
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        GardenRecord garden;
        std::string temp;

        std::getline(ss, temp, ';');
        garden.id = std::stoi(temp);

        std::getline(ss, temp, ';');
        garden.number = std::stoi(temp);

        std::getline(ss, garden.name, ';');

        std::getline(ss, garden.phone, ';');

        std::getline(ss, garden.address, ';');

        data.push_back(garden);
    }


    file.close();
}

// Функция для записи данных в файл
void writeToFile(const std::string& filename, const std::vector<GardenRecord>& data) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка при открытии файла для записи!" << std::endl;
        return;  // Выход из функции при ошибке открытия файла
    }

    for (const auto& garden : data) {
        file << garden.id << ";"
             << garden.number << ";"
             << garden.name << ";"
             << garden.phone << ";"
             << garden.address << ";"
             << std::endl;  // Записываем данные в файл
    }

    file.close();
}
