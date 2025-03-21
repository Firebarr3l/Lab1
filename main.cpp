#include <vector>
#include "rwFunc.hpp"
#include "menu.hpp"

int main() {
    std::vector<GardenRecord> gardens;

    // Читаем данные из файла
    readFromFile("gardenassociat.db", &gardens);

    // Запускаем меню
    menu(&gardens);

    return 0;
}
