#include "menu.hpp"
#include <iostream>


// Реализация displayGardens
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


void menu(std::vector<GardenRecord>* data) {
    int choice;

    do {
        std::cout << "\nМеню:\n";
        std::cout << "1. Показать все записи\n";
        std::cout << "2. Добавить запись\n";
        std::cout << "3. Сохранить изменения\n";
        std::cout << "4. Выйти\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            displayGardens(data);
            break;
        case 2: {
            GardenRecord newGarden;
            std::cout << "Введите ID: ";
            std::cin >> newGarden.id;
            std::cout << "Введите номер участка: ";
            std::cin >> newGarden.number;
            std::cin.ignore();
            std::cout << "Введите ФИО: ";
            std::getline(std::cin, newGarden.name);
            std::cout << "Введите телефон: ";
            std::getline(std::cin, newGarden.phone);
            std::cout << "Введите адрес: ";
            std::getline(std::cin, newGarden.address);

            data->push_back(newGarden);
            std::cout << "Запись добавлена.\n";
            break;
        }
        case 3:
            writeToFile("gardenassociat.db", data);
            break;
        case 4:
            std::cout << "Выход из программы.\n";
            break;
        default:
            std::cout << "Некорректный выбор, попробуйте снова.\n";
        }
    } while (choice != 4);
}
