#include "rwFunc.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

void writeToFile(const std::string& filename, const int size) {
    // Создаем отдельную базу данных для записи
    GardenAssociation newData[] = {
        {1, 10, "Тест переписывания", "7468942", "ул. Строителей д. 5"},
        {2, 15, "Фантазия неработает", "7894561", "ул. Ленина д. 12"},
        {3, 25, "делаю это", "1234567", "ул. Гагарина д. 8"},
        {4, 30, "уже пять", "9876543", "ул. Центральная д. 3"},
        {5, 5, "часов Виктор", "7418529", "ул. Дачная д. 10"},
        {6, 12, "я непонял", "3692581", "ул. Садовая д. 7"},
        {7, 7, "Задания с", "9517536", "ул. Зеленая д. 15"},
        {8, 18, "переписыванием так", "8521479", "ул. Полевая д. 2"},
        {9, 22, "что я", "7539514", "ул. Лесная д. 4"},
        {10, 3, "не зная надоли", "1839233", "ул. Южная д. 6"}
    };


    std::ofstream dbFile(filename);
    if (!dbFile) {
        std::cerr << "Ошибка открытия файла для записи: " << filename << std::endl;
        return;
    }

    // Записываем данные из новой базы данных в файл
    for (int i = 0; i < size; ++i) {
        dbFile << newData[i].id << ";" << newData[i].area << ";" << newData[i].name << ";"
               << newData[i].phone << ";" << newData[i].address << ";" << std::endl;
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
