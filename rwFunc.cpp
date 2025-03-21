#include "rwFunc.hpp"
#include <iostream>
#include <fstream>
#include <string>

// Функция для чтения данных из файла
void readFromFile(const std::string& filename, std::vector<GardenAssociation>& data) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка открытия файла!" << std::endl;
        return;
    }

    for (auto& item : data) {
        char delimiter; // Для чтения символа ';'
        file >> item.id >> delimiter;
        file >> item.area >> delimiter;
        std::getline(file, item.name, ';');
        std::getline(file, item.phone, ';');
        std::getline(file, item.address, ';');
    }
    file.close();
}

// Функция для записи данных в файл
void writeToFile(const std::string& filename, const std::vector<GardenAssociation>& data) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка открытия файла для записи!" << std::endl;
        return;
    }

    for (const auto& item : data) {
        file << item.id << ";"
             << item.area << ";"
             << item.name << ";"
             << item.phone << ";"
             << item.address << ";\n";
    }
    file.close();
}
