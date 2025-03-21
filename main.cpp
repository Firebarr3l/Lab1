#include <vector>
#include "rwFunc.hpp"
#include "menu.hpp"

int main() {
    std::vector<GardenRecord> gardens;  // Массив структур

    // Запускаем меню
    menu(&gardens);

    return 0;
}
