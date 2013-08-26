#pragma once

namespace singleton {

template <typename T>
class NewMemoryPolicy {
public:
    static T * create() {
        return new T;
    }

    static void destroy(T * p) {
        delete p;
    }
};

} // namespace singleton
