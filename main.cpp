#include <iostream>
#include <vector>
#include "rwFunc.hpp"


int main() {
    std::vector<GardenRecord> gardens;

    // Читаем данные из файла
    readFromFile("gardenassociat.db", gardens);

    // Выводим данные для проверки
    for (const auto& garden : gardens) {
        std::cout << "ID: " << garden.id
                  << ", Участок: " << garden.number
                  << ", Имя: " << garden.name
                  << ", Телефон: " << garden.phone
                  << ", Адрес: " << garden.address << std::endl;
    }

    return 0;
}
