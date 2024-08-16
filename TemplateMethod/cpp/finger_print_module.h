
#ifndef __FINGER_PRINT_MODULE_H__
#define __FINGER_PRINT_MODULE_H__

#include <iostream>

class FingerPrintModule {
public:
    FingerPrintModule() {}
    virtual ~FingerPrintModule() {}

    void getImage() { std::cout << "采集指纹图像" << std::endl; }
    void output() { std::cout << "采集图像处理完成" << std::endl; }

    virtual bool isSafeMode() = 0;
    virtual void processImage() = 0;
    virtual void encrypt() = 0;
    virtual void decrypt() = 0;

    void algorithm() {
        getImage();
        if (isSafeMode()) {
            encrypt();
            decrypt();
        }
        processImage();
        output();
    }
};

class FingerPrintModuleA : public FingerPrintModule {
public:
    FingerPrintModuleA() {}

    void processImage() { std::cout << "第一代版本算法处理指纹图像" << std::endl; }
    bool isSafeMode() {
        std::cout << "安全模式" << std::endl;
        return true;
    }
    void encrypt() { std::cout << "使用 RSA 密钥加密" << std::endl; }
    void decrypt() { std::cout << "使用 RSA 密钥解密" << std::endl; }
};

class FingerPrintModuleB : public FingerPrintModule {
public:
    FingerPrintModuleB() {}

    void processImage() { std::cout << "第二代版本算法处理指纹图像" << std::endl; }
    bool isSafeMode() {
        std::cout << "非安全模式" << std::endl;
        return false;
    }
    void encrypt() {}
    void decrypt() {}
};

class FingerPrintModuleC : public FingerPrintModule {
public:
    FingerPrintModuleC() {}

    void processImage() { std::cout << "第一代版本算法处理指纹图像" << std::endl; }
    bool isSafeMode() {
        std::cout << "安全模式" << std::endl;
        return true;
    }
    void encrypt() { std::cout << "使用 DH 密钥加密" << std::endl; }
    void decrypt() { std::cout << "使用 DH 密钥解密" << std::endl; }
};

#endif // __FINGER_PRINT_MODULE_H__