#include <vector>
#include "rwFunc.hpp"
#include "menu.hpp"

int main() {
    std::vector<GardenRecord> gardens;

    // Читаем данные из файла через указатель
    readFromFile("gardenassociat.db", &gardens);

    displayGardens(&gardens);

    return 0;
}
