#include "menu.hpp"
#include "rwFunc.hpp"
#include <iostream>
#include <string>

// Функция для вывода данных на экран
void displayData(const GardenAssociation *data, const int size) {
    std::cout << "Список членов товарищества:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << "ID: " << data[i].id << ", Участок: " << data[i].area
                  << ", Имя: " << data[i].name << ", Телефон: " << data[i].phone
                  << ", Адрес: " << data[i].address << std::endl;
    }
}

// Функция для отображения меню
void menu(const std::string& filename, GardenAssociation *data, const int size) {
    int choice;
    do {
        std::cout << "\nМеню:\n";
        std::cout << "1. Открыть файл\n";
        std::cout << "2. Поменять файл\n";
        std::cout << "3. Вывести на экран список\n";
        std::cout << "4. О программе\n";
        std::cout << "5. Выход\n";
        std::cout << "Выберите пункт: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            readFromFile(filename, data, size);
            break;
        case 2:
            writeToFile(filename, size);
            break;
        case 3:
            displayData(data, size);
            break;
        case 4:
            std::cout << "\nО программе:\n";
            std::cout << "Фамилия: Клишин\n";
            std::cout << "Имя: Даниил\n";
            std::cout << "Отчество: Дмитриевич\n";
            std::cout << "Курс: 2\n";
            std::cout << "Группа: ИЦТМС 2-1\n";
            std::cout << "Дата компиляции: 21.03.2025\n";
            std::cout << "Номер варианта: 19\n";
            break;
        case 5:
            std::cout << "Выход из программы...\n";
            break;
        default:
            std::cout << "Неверный выбор, попробуйте снова.\n";
        }
    } while (choice != 5);
}
