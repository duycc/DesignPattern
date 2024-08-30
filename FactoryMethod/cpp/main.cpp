
#include "factory_method.h"

int main() {
    std::shared_ptr<AbstractFactory> fac;

    fac = std::make_shared<BasketballFactory>();
    fac->GetSportProduct();

    fac = std::make_shared<FootballFactory>();
    fac->GetSportProduct();

    fac = std::make_shared<VolleyballFactory>();
    fac->GetSportProduct();

    return EXIT_SUCCESS;
}