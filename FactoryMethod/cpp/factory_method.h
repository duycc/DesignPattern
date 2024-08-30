#ifndef __FACTORY_METHOD_H__
#define __FACTORY_METHOD_H__

#include <iostream>
#include <string>

class AbstractSportProduct {
public:
    AbstractSportProduct() {}
    virtual ~AbstractSportProduct() {}

    virtual void Play() {}
};

class Basketball : public AbstractSportProduct {
public:
    Basketball() { Play(); }

    void Play() { std::cout << "play basketball" << std::endl; }
};

class Football : public AbstractSportProduct {
public:
    Football() { Play(); }

    void Play() { std::cout << "play football" << std::endl; }
};

class Volleyball : public AbstractSportProduct {
public:
    Volleyball() { Play(); }

    void Play() { std::cout << "play volleyball" << std::endl; }
};

class AbstractFactory {
public:
    AbstractFactory() {}
    virtual ~AbstractFactory() {}

    virtual AbstractSportProduct* GetSportProduct() = 0;
};

class BasketballFactory : public AbstractFactory {
public:
    BasketballFactory() {}

    AbstractSportProduct* GetSportProduct() { return new Basketball(); }
};

class FootballFactory : public AbstractFactory {
public:
    FootballFactory() {}

    AbstractSportProduct* GetSportProduct() { return new Football(); }
};

class VolleyballFactory : public AbstractFactory {
public:
    VolleyballFactory() {}

    AbstractSportProduct* GetSportProduct() { return new Volleyball(); }
};

#endif // __FACTORY_METHOD_H__