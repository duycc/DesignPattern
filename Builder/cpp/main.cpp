
#include "house.h"

int main() {
    House* house = nullptr;
    house = HouseDirector(new StoneHouseBuilder()).Construct();
    std::cout << std::endl;
    house = HouseDirector(new WoodenHouseBuilder()).Construct();

    return EXIT_SUCCESS;
}