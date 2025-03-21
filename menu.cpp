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

// Функция, которая выводит информацию о программе
void aboutProgram() {
    std::cout << "\nО программе:\n";
    std::cout << "Фамилия: Клишин\n";
    std::cout << "Имя: Даниил\n";
    std::cout << "Отчество: Дмитриевич\n";
    std::cout << "Курс: 2\n";
    std::cout << "Группа: ИЦТМС 2-1\n";
    std::cout << "Дата компиляции: ИЗМЕНИТЬ!!!5\n";
    std::cout << "Номер варианта: 19\n";
}

void menu(std::vector<GardenRecord>* data) {
    int choice;
    std::string filename = "gardenassociat.db";  // Файл по умолчанию

    do {
        std::cout << "\nМеню:\n";
        std::cout << "1. Открыть файл\n";
        std::cout << "2. Сохранить файл\n";
        std::cout << "3. Вывести на экран список\n";
        std::cout << "4. О программе\n";  // Новый пункт
        std::cout << "5. Выход\n";  // Новый пункт
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
        case 4:  // О программе
            aboutProgram();
            break;
        case 5:  // Выход
            std::cout << "Выход из программы.\n";
            break;
        default:
            std::cout << "Некорректный выбор, попробуйте снова.\n";
        }
    } while (choice != 5);  // Меню будет продолжаться до выхода
}
