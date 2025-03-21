#include "rwFunc.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

void writeToFile(const std::string& filename, const GardenAssociation *data, const int size) {
    std::ofstream dbFile(filename);
    if (!dbFile) {
        std::cerr << "Ошибка открытия файла для записи: " << filename << std::endl;
        return;
    }

    // Записываем данные в файл
    for (int i = 0; i < size; ++i) {
        dbFile << data[i].id << ";" << data[i].area << ";" << data[i].name << ";"
               << data[i].phone << ";" << data[i].address << ";" << std::endl;
    }

    dbFile.close();
    std::cout << "Данные успешно записаны в файл: " << filename << std::endl;
}

void readFromFile(const std::string& filename, GardenAssociation *data, const int size) {
    std::ifstream dbFile(filename);
    if (!dbFile) {
        std::cerr << "Ошибка открытия файла для чтения: " << filename << std::endl;
        return;
    }

    std::string line;
    int index = 0;
    while (std::getline(dbFile, line) && index < size) {
        std::stringstream ss(line);
        std::string token;
        GardenAssociation record;

        // Чтение данных из строки
        std::getline(ss, token, ';');
        record.id = std::stoi(token);

        std::getline(ss, token, ';');
        record.area = std::stoi(token);

        std::getline(ss, record.name, ';');
        std::getline(ss, record.phone, ';');
        std::getline(ss, record.address, ';');

        data[index++] = record;
    }

    dbFile.close();
}
