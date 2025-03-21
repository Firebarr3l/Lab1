#ifndef RWFUNC_HPP
#define RWFUNC_HPP

#include <string>
#include <vector>

// Структура для хранения данных
struct GardenAssociation {
    int id;
    int area;
    std::string name;
    std::string phone;
    std::string address;
};

// Прототипы функций
void readFromFile(const std::string& filename, std::vector<GardenAssociation>& data);
void writeToFile(const std::string& filename, const std::vector<GardenAssociation>& data);

#endif // RWFUNC_HPP
