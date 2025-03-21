#ifndef MENU_HPP
#define MENU_HPP

#include "rwFunc.hpp"

// Прототипы функций
void displayGardens(const std::vector<GardenRecord>* data);
void menu(std::vector<GardenRecord>* data);
void aboutProgram();  // Новый прототип для пункта "О программе"

#endif  // MENU_HPP
