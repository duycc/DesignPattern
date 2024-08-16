#ifndef __TEMPLATE_METHOD_H__
#define __TEMPLATE_METHOD_H__

class AbstractClass {
public:
    virtual ~AbstractClass() {}

    void templateMethod() {}

    void method1() {}
    virtual void mehtod2() = 0;
    void method3() {}
};

class ConcreteClass : public AbstractClass {
public:
    void method2() {}

    void method3() {}
};

#endif // __TEMPLATE_METHOD_H__