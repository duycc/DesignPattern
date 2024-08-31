#ifndef __HOUSE_H__
#define __HOUSE_H__

#include <iostream>

class House {};

class HouseBuilder {
public:
    virtual ~HouseBuilder() {}

    House* GetResult() { return pHouse; }

    virtual void BuildPart1() = 0;
    virtual bool BuildPart2() = 0;
    virtual void BuildPart3() = 0;

private:
    House* pHouse;
};

class HouseDirector {
public:
    HouseDirector(HouseBuilder* houseBuilder) { this->pHouseBuilder = houseBuilder; }

    House* Construct() {
        pHouseBuilder->BuildPart1();

        bool flag = pHouseBuilder->BuildPart2();
        if (flag) {
            pHouseBuilder->BuildPart3();
        }

        return pHouseBuilder->GetResult();
    }

private:
    HouseBuilder* pHouseBuilder;
};

class WoodenHouse : public House {};

class WoodenHouseBuilder : public HouseBuilder {
public:
    void BuildPart1() { std::cout << "[Wooden House] Build Part1..." << std::endl; }
    bool BuildPart2() {
        std::cout << "[Wooden House] Build Part2..." << std::endl;
        return true;
    }
    void BuildPart3() { std::cout << "[Wooden House] Build Part3..." << std::endl; }
};

class StoneHouse : public House {};

class StoneHouseBuilder : public HouseBuilder {
public:
    void BuildPart1() { std::cout << "[Stone House] Build Part1..." << std::endl; }
    bool BuildPart2() {
        std::cout << "[Stone House] Build Part2..." << std::endl;
        return false;
    }
    void BuildPart3() { std::cout << "[Stone House] Build Part3..." << std::endl; }
};

#endif // __HOUSE_H__