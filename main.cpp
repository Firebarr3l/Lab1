#include <string>
#include "menu.hpp"

#define SIZE 10  // Размер массива данных

int main() {
    std::string filename = "/Users/f1rebarrel/Code/QtProjects/pr/Lab1/gardenassociat.db";
    GardenAssociation data[SIZE];  // Массив структур для хранения записей

    // Запуск меню
    menu(filename, data, SIZE);

    return 0;
}
