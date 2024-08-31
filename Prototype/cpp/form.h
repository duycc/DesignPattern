#ifndef __FORM_H__
#define __FORM_H__

#include <iostream>

#include "splitter.h"

class Form {
public:
    Form() {}
    Form(ISplitter* _splitter) { this->splitter = _splitter; }

    void Click() {
        ISplitter* tmpSplitter = this->splitter->Clone();
        tmpSplitter->Split();

        // TODO: 为什么必须有 Clone 方法？
        // this->splitter->Split();
    }

private:
    ISplitter* splitter;
};

#endif // __FORM_H__