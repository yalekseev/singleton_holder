#include "singleton_holder.h"

#include <iostream>

class MyClass {
public:
    void print() const {
        std::cout << "Hi there!" << std::endl;
    }
};

typedef SingletonHolder<MyClass> MySingleton;

int main() {
    MySingleton::instance().print();

    return 0;
}
