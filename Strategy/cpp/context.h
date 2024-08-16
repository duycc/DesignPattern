#ifndef __CONTEXT_H__
#define __CONTEXT_H__

#include <iostream>

#include "strategy.h"

class Context {
public:
    Context() {
        vec.clear();
        sortStrategy = nullptr;
    }

    Context(std::vector<int>& vec) {
        this->vec = vec;
        sortStrategy = nullptr;
    }
    Context(const Context&) = delete;
    Context& operator=(const Context&) = delete;
    ~Context() {
        if (sortStrategy) {
            delete sortStrategy;
            sortStrategy = nullptr;
        }
    }

    void SetSortStrategy(Strategy* iStrategy) {
        if (sortStrategy) {
            delete sortStrategy;
            sortStrategy = nullptr;
        }
        sortStrategy = iStrategy;
    }

    void sort() {
        this->sortStrategy->sort(this->vec);
        this->Print();
    }

    void SetInput(std::vector<int>& vec) { this->vec = vec; }

    void Print() {
        for (auto elem : this->vec) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

private:
    Strategy* sortStrategy;
    std::vector<int> vec;
};

#endif // __CONTEXT_H__