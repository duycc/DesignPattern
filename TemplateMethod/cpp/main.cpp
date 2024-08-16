
#include "finger_print_module.h"

int main() {
    FingerPrintModule* fp = new FingerPrintModuleA();
    fp->algorithm();
    delete fp;
    fp = nullptr;

    std::cout << std::endl;

    fp = new FingerPrintModuleB();
    fp->algorithm();
    delete fp;
    fp = nullptr;

    std::cout << std::endl;

    fp = new FingerPrintModuleC();
    fp->algorithm();
    delete fp;
    fp = nullptr;

    return EXIT_SUCCESS;
}