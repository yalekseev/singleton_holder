#pragma once

#include <cstdlib>
#include <new>

template <typename T>
class MallocMemoryPolicy {
public:
    static T * create() {
        T * p = static_cast<T *>(std::malloc(sizeof(T)));
        if (0 == p) {
            throw std::bad_alloc();
        }

        try {
            new (p) T;
        } catch (...) {
            free(p);
            throw;
        }

        return p;
    }

    static void destroy(T * p) {
        p->~T();
        free(p);
    }
};
