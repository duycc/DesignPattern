#ifndef __DECORATOR_H__
#define __DECORATOR_H__

#include <iostream>

class Component {
public:
    Component() {}
    virtual ~Component() {}

    virtual void Operation() = 0;
};

class Phone : public Component {
public:
    Phone() {}

    void Operation() { std::cout << "手机!" << std::endl; }
};

class Decorator : public Component {
public:
    Decorator() {}
    Decorator(Component* _component) : component(_component) {}

    void Operation() { this->component->Operation(); }

    Component* GetComponent() { return this->component; }
    void SetComponent(Component* _component) { this->component = _component; }

private:
    Component* component;
};

// 安装手机壳
class ShellDecorator : public Decorator {
public:
    ShellDecorator() {}
    ShellDecorator(Component* _component) { this->SetComponent(_component); }

    void Operation() {
        this->GetComponent()->Operation();
        installShell();
    }

    void installShell() { std::cout << "安装手机壳!" << std::endl; }
};

// 手机贴膜
class StickerDecorator : public Decorator {
public:
    StickerDecorator() {}
    StickerDecorator(Component* _component) { this->SetComponent(_component); }

    void Operation() {
        this->GetComponent()->Operation();
        installSticker();
    }

    void installSticker() { std::cout << "贴膜!" << std::endl; }
};

#endif // __DECORATOR_H__