#ifndef RWFUNC_HPP
#define RWFUNC_HPP

#include <string>

// Структура для хранения данных о членах товарищества
struct GardenAssociation {
    int id;
    int area;
    std::string name;
    std::string phone;
    std::string address;
};

// Функция для записи данных в файл
void writeToFile(const std::string& filename, const int size);

// Функция для чтения данных из файла
void readFromFile(const std::string& filename, GardenAssociation *data, const int size);

#endif // RWFUNC_HPP
