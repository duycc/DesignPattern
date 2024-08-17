
#include <iostream>

#include "bridge.h"

int main() {
    Phone* phone = new PhoneA();
    phone->SetupGame(new GameX());
    phone->Play();

    std::cout << std::endl;
    phone = new PhoneB();
    phone->SetupGame(new GameY());
    phone->Play();

    return EXIT_SUCCESS;
}