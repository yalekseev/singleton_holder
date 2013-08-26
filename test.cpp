#include "singleton_holder.h"

#include "static_memory_policy.h"
#include "immortal_lifetime_policy.h"

#include <iostream>

class MyClass {
public:
    MyClass() {
        std::cout << "MyClass::MyClass()" << std::endl;
    }

    ~MyClass() {
        std::cout << "MyClass::~MyClass()" << std::endl;
    }

    void print() const {
        std::cout << "Hi there!" << std::endl;
    }
};

typedef singleton::SingletonHolder<MyClass, singleton::StaticMemoryPolicy, singleton::ImmortalLifetimePolicy> MySingleton;

int main() {
    MyClass & obj = MySingleton::instance();

    obj.print();

    return 0;
}
