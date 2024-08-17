#ifndef __OBSERVER_H__
#define __OBSERVER_H__

#include <iostream>
#include <string>

#include "ally_center.h"
#include "common.h"

class Observer {
public:
    Observer() {}
    virtual ~Observer() {}

    virtual void Call(MESSAGE_TYPE msgype, AllyCenter* center) = 0;

    std::string GetName() { return name; }
    void SetName(std::string name) { this->name = name; }

private:
    std::string name;
};

class Player : public Observer {
public:
    Player() { SetName("unknow player"); }
    Player(std::string name) { SetName(name); }

    void Call(MESSAGE_TYPE msgType, AllyCenter* center) {
        switch (msgType) {
        case RESOURCE:
            std::cout << GetName() << ": 我这里有物资!" << std::endl;
            break;
        case HELP:
            std::cout << GetName() << ": 救救我!" << std::endl;
            break;
        default:
            break;
        }

        center->Notify(msgType, GetName());
    }

    void Help() { std::cout << GetName() << ": 坚持住, 我来救你!" << std::endl; }

    void Come() { std::cout << GetName() << ": 好的, 我来取物资!" << std::endl; }

private:
};

#endif // __OBSERVER_H__