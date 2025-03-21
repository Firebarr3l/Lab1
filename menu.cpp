#include "menu.hpp"
#include <iostream>

// Функция для вывода данных на экран
void printData(const std::vector<GardenAssociation>& data) {
    std::cout << "Список участников садоводства:\n";
    for (const auto& item : data) {
        std::cout << "ID: " << item.id << ", Площадь: " << item.area << ", Имя: " << item.name
                  << ", Телефон: " << item.phone << ", Адрес: " << item.address << std::endl;
    }
}

// Функция для вывода информации о программе
void aboutProgram() {
    std::cout << "Информация о программе:\n";
    std::cout << "Фамилия: Иванов\n";
    std::cout << "Имя: Иван\n";
    std::cout << "Отчество: Иванович\n";
    std::cout << "Курс: 3\n";
    std::cout << "Группа: ПИ-21\n";
    std::cout << "Дата компиляции: " << __DATE__ << " " << __TIME__ << "\n";
    std::cout << "Вариант: 1\n";
}

// Функция для отображения меню
void menu(std::vector<GardenAssociation>& data) {
    int choice;
    do {
        std::cout << "\nМеню:\n";
        std::cout << "1. Открыть файл\n";
        std::cout << "2. Сохранить файл\n";
        std::cout << "3. Вывести на экран список\n";
        std::cout << "4. О программе\n";
        std::cout << "5. Выход\n";
        std::cout << "Выберите пункт: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            readFromFile("gardenassociat.db", data);
            std::cout << "Файл успешно открыт!\n";
            break;
        case 2:
            writeToFile("/Users/f1rebarrel/Code/QtProjects/pr/Lab1/gardenassociat.db", data);
            std::cout << "Файл успешно сохранен!\n";
            break;
        case 3:
            printData(data);
            break;
        case 4:
            aboutProgram();
            break;
        case 5:
            std::cout << "Выход из программы.\n";
            break;
        default:
            std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 5);
}
