#include "ally_center.h"
#include "observer.h"

AllyCenter::AllyCenter() { std::cout << "大吉大利, 今晚吃鸡!" << std::endl; }

void AllyCenter::Join(Observer* player) {
    if (this->playerList.size() == 4) {
        std::cout << "人数已满!" << std::endl;
        return;
    }

    std::cout << "玩家 " << player->GetName() << " 加入!" << std::endl;
    this->playerList.emplace_back(player);
    if (this->playerList.size() == 4) {
        std::cout << "组队成功, 不要怂, 一起上!" << std::endl;
    }
}

void AllyCenter::Remove(Observer* player) { std::cout << "玩家 " << player->GetName() << " 退出!" << std::endl; }

AllyCenterController::AllyCenterController() {}

void AllyCenterController::Notify(MESSAGE_TYPE msgType, std::string name) {
    switch (msgType) {
    case RESOURCE:
        for (auto obs : this->playerList) {
            if (obs->GetName() != name) {
                ((Player*)obs)->Come();
            }
        }
        break;
    case HELP:
        for (auto obs : this->playerList) {
            if (obs->GetName() != name) {
                ((Player*)obs)->Help();
            }
        }
    default:
        break;
    }
}