#include "menu.hpp"
#include <iostream>

void displayGardens(const std::vector<GardenRecord>* data) {
    if (data->empty()) {
        std::cout << "Нет данных для отображения." << std::endl;
        return;
    }

    for (const auto& garden : *data) {
        std::cout << "ID: " << garden.id
                  << ", Участок: " << garden.number
                  << ", Имя: " << garden.name
                  << ", Телефон: " << garden.phone
                  << ", Адрес: " << garden.address << std::endl;
    }
}
