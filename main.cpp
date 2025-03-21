#include <vector>
#include "rwFunc.hpp"
#include "menu.hpp"

int main() {
    const int SIZE = 10; // Размер массива структур
    std::vector<GardenAssociation> data(SIZE); // Массив структур

    // Вызов меню
    menu(data);
    return 0;
}
