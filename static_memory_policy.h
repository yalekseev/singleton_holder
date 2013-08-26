#pragma once

namespace singleton {

template <typename T>
class StaticMemoryPolicy {
public:
    static T * create() {
        new (m_chunk) T;
    }

    static void destroy(T * p) {
        (reinterpret_cast<T *>(m_chunk))->~T();
    }

private:
    static char m_chunk[sizeof(T)];
};

template <typename T>
char StaticMemoryPolicy<T>::m_chunk[sizeof(T)];

} // namespace singleton
