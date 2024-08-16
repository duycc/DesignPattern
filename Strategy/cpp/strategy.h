#ifndef __STRATEGY_H__
#define __STRATEGY_H__

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Strategy {
public:
    Strategy() {}
    virtual ~Strategy() {}
    virtual void sort(std::vector<int>& vec) = 0;
};

class BubbleSort : public Strategy {
public:
    BubbleSort() { std::cout << "bubble sort..." << std::endl; }

    void sort(std::vector<int>& vec) {
        int len = vec.size();
        bool sorted = false; // 在某一趟没有发生元素交换，则可判定序列已经有序

        for (int i = 0; i < len - 1 && !sorted; ++i) {
            sorted = true;
            for (int j = 0; j < len - 1 - i; ++j) {
                if (vec[j] > vec[j + 1]) {
                    sorted = false;
                    std::swap(vec[j], vec[j + 1]);
                }
            }
        }
        return;
    }
};

// 具体策略：选择排序
class SelectionSort : public Strategy {
public:
    SelectionSort() { std::cout << "select sort..." << std::endl; }

    void sort(std::vector<int>& vec) {
        int len = vec.size();
        for (int i = 0; i < len - 1; ++i) {
            int minIdx = i;
            for (int j = i + 1; j < len; ++j) {
                if (vec[j] < vec[minIdx]) {
                    minIdx = j;
                }
            }
            if (minIdx != i) {
                std::swap(vec[i], vec[minIdx]);
            }
        }
        return;
    }
};

// 具体策略：插入排序
class InsertSort : public Strategy {
public:
    InsertSort() { std::cout << "insert sort..." << std::endl; }

    void sort(std::vector<int>& vec) {
        int len = vec.size();
        for (int i = 1; i < len; ++i) {
            for (int j = i; j > 0; --j) {
                if (vec[j - 1] > vec[j]) {
                    std::swap(vec[j - 1], vec[j]);
                } else {
                    break;
                }
            }
        }
        return;
    }
};

#endif // __STRATEGY_H__