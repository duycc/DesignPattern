
#include <iostream>

#include "ally_center.h"
#include "observer.h"

int main() {
    AllyCenterController* controller = new AllyCenterController();

    Player* Jungle = new Player("Jungle");
    Player* Single = new Player("Single");
    Player* Jianmen = new Player("Jianmen");
    Player* Jacky = new Player("Jacky");
    controller->Join(Jungle);
    controller->Join(Single);
    controller->Join(Jianmen);
    controller->Join(Jacky);
    std::cout << std::endl;

    Jungle->Call(RESOURCE, controller);
    std::cout << std::endl;

    Jacky->Call(HELP, controller);
    std::cout << std::endl;

    delete controller;
    controller = nullptr;

    delete Jungle;
    Jungle = nullptr;

    delete Single;
    Single = nullptr;

    delete Jianmen;
    Jianmen = nullptr;

    delete Jacky;
    Jacky = nullptr;

    return EXIT_SUCCESS;
}