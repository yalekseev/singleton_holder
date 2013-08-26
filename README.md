singleton_holder
================

A holder for singleton object.

Usage
=====

````cpp

#include "singleton_holder.h"

class MyClass {
    /* ... */
};

typedef singleton::SingletonHolder<MyClass> MySingleton;

int main() {
    MyClass & obj = MySingleton::instance();

    /* ... */

    return 0;
}

```
