#pragma once

#include <stdexcept>
#include <cstdlib>

template <typename T>
class CppLifetimePolicy {
public:
    static void on_dead_reference() {
        throw std::runtime_error("Trying to reference destroyed singleton.");
    }

    static void schedule_destruction(void (*func)(void)) {
        if (std::atexit(func) != 0) {
            throw std::runtime_error("Failed to schedule destruction of singleton.");
        }
    }
};
