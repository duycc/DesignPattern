#ifndef __BRIDGE_H__
#define __BRIDGE_H__

#include <iostream>

class Game {
public:
    Game() {}
    virtual ~Game() {}

    virtual void Play() = 0;
};

class GameX : public Game {
public:
    GameX() {}

    void Play() { std::cout << "玩游戏X!" << std::endl; }
};

class GameY : public Game {
public:
    GameY() {}

    void Play() { std::cout << "玩游戏Y!" << std::endl; }
};

class Phone {
public:
    Phone() {}
    virtual ~Phone() {}

    void SetupGame(Game* _game) { this->game = _game; }
    virtual void Play() = 0;

protected:
    Game* GetGame() { return this->game; }

private:
    Game* game;
};

class PhoneA : public Phone {
public:
    PhoneA() { std::cout << "手机A!" << std::endl; }

    void Play() { this->GetGame()->Play(); }
};

class PhoneB : public Phone {
public:
    PhoneB() { std::cout << "手机B!" << std::endl; }

    void Play() { this->GetGame()->Play(); }
};

#endif // __BRIDGE_H__