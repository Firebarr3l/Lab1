#ifndef RWFUNC_HPP
#define RWFUNC_HPP

#include <string>
#include <vector>


struct GardenRecord {
    int id;             // порядковый номер записи
    int number;            // номер участка
    std::string name;   // имя и фамилия
    std::string phone;  // телефон
    std::string address; // адрес
};

// Прототип функции для чтения данных из файла
void readFromFile(const std::string& filename, std::vector<GardenRecord>& data);

// Прототип функции для записи данных в файл
void writeToFile(const std::string& filename, const std::vector<GardenRecord>& data);

#endif // RWFUNC_HPP
