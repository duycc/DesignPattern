/**
 * @file     Singleton.h
 * @brief
 * @author   YongDu
 * @date     2021-10-07
 */

class Singleton {
  private:
    Singleton();
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static Singleton* m_instance;

    struct GC {
        ~GC() {
            if (Singleton::m_instance) {
                delete Singleton::m_instance;
                Singleton::m_instance = nullptr;
            }
        }
    };

  public:
    static Singleton* getInstance();
};

Singleton* Singleton::m_instance = nullptr;

//===------------------------- [单线程版] ----------------------------------===//
// 1. 线程不安全
// 2. 且 m_instance 得不到释放
//===----------------------------------------------------------------------===//
Singleton* Singleton::getInstance() {
    if (m_instance == nullptr) {
        m_instance = new Singleton();
    }
    return m_instance;
}

//===------------------------- [双检查锁] ----------------------------------===//
// 1. 多线程安全
// 2. 可释放资源
// 3. 无法解决内存 reorder 问题
//===----------------------------------------------------------------------===//
Singleton* Singleton::getInstance() {
    if (m_instance == nullptr) {
        // lock
        if (m_instance == nullptr) {
            m_instance = new Singleton();
            static GC gc;
        }
        // unlock
    }
    return m_instance;
}

//===------------------------- [饿汉模式] ----------------------------------===//
// 1. 对象在程序运行之前已经初始化好，多线程安全，资源可释放
//===----------------------------------------------------------------------===//
class CSingleton {
  private:
    CSingleton();

  public:
    CSingleton& getInstance() { // 需用引用类型接受
        static CSingleton m_instance;
        return m_instance;
    }
};
