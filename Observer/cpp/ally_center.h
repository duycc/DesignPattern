#ifndef __ALLY_CENTER_H__
#define __ALLY_CENTER_H__

#include <string>
#include <vector>

#include "common.h"

class Observer;

class AllyCenter {
public:
    AllyCenter();
    virtual ~AllyCenter() {}

    virtual void Notify(MESSAGE_TYPE msgTtype, std::string name) = 0;
    void Join(Observer* player);
    void Remove(Observer* player);

protected:
    std::vector<Observer*> playerList;
};

class AllyCenterController : public AllyCenter {
public:
    AllyCenterController();
    void Notify(MESSAGE_TYPE msgType, std::string name);
};

#endif // __ALLY_CENTER_H__