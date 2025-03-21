#ifndef RWFUNC_HPP
#define RWFUNC_HPP

#include <string>
#include <vector>

// Прототип функции для чтения данных из файла
void readFromFile(const std::string& filename, std::vector<std::string>& data);

// Прототип функции для записи данных в файл
void writeToFile(const std::string& filename, const std::vector<std::string>& data);

#endif // RWFUNC_HPP
