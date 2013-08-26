#pragma once

#include <stdexcept>

namespace singleton {

template <typename T>
class ImmortalLifetimePolicy {
public:
    static void on_dead_reference() {
        throw std::logic_error("on_dead_reference() should never be called for ImmortalLifetimePolicy.");
    }

    static void schedule_destruction(void (*func)(void)) {
    }
};

} // namespace singleton
