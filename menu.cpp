#include "menu.hpp"
#include <iostream>
#include <string>

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
    std::string filename = "gardenassociat.db";  // Файл по умолчанию

    do {
        std::cout << "\nМеню:\n";
        std::cout << "1. Открыть файл\n";
        std::cout << "2. Сохранить файл\n";
        std::cout << "3. Вывести на экран список\n";
        std::cout << "4. Выйти\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {  // Открыть файл
            readFromFile(filename, data);
            std::cout << "Файл открыт и данные загружены.\n";
            break;
        }
        case 2: {  // Сохранить файл
            writeToFile(filename, data);
            break;
        }
        case 3:  // Вывести на экран список
            displayGardens(data);
            break;
        case 4:  // Выйти
            std::cout << "Выход из программы.\n";
            break;
        default:
            std::cout << "Некорректный выбор, попробуйте снова.\n";
        }
    } while (choice != 4);
}
