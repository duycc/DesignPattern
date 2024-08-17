
#include <iostream>

#include "decorator.h"

int main() {
    Component* phone = new Phone();
    phone = new ShellDecorator(phone);
    phone->Operation();

    std::cout << std::endl;

    phone = new StickerDecorator(phone);
    phone->Operation();

    delete phone;
    phone = nullptr;

    return EXIT_SUCCESS;
}