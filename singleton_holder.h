#pragma once

#include "new_memory_policy.h"

#include "cpp_lifetime_policy.h"

#include <cassert>

namespace singleton {

template <
    typename T,
    template <class> class MP = NewMemoryPolicy,
    template <class> class LP = CppLifetimePolicy>
class SingletonHolder {
public:
    static T & instance();

private:
    static void destroy();

    static bool m_destroyed;

    static T * m_instance;
};

template <typename T, template <class> class MP, template <class> class LP>
T & SingletonHolder<T, MP, LP>::instance() {
    if (!m_instance) {
        if (!m_instance) {
            if (m_destroyed) {
                LP<T>::on_dead_reference();
                m_destroyed = false;
            }

            m_instance = MP<T>::create();
            LP<T>::schedule_destruction(&SingletonHolder<T, MP, LP>::destroy);
        }
    }

    return *m_instance;
}

template <typename T, template <class> class MP, template <class> class LP>
void SingletonHolder<T, MP, LP>::destroy() {
    assert(!m_destroyed);
    MP<T>::destroy(m_instance);
    m_instance = 0;
    m_destroyed = true;
}


/* Initialization of static members */

template <typename T, template <class> class MP, template <class> class LP>
bool SingletonHolder<T, MP, LP>::m_destroyed(false);

template <typename T, template <class> class MP, template <class> class LP>
T * SingletonHolder<T, MP, LP>::m_instance(0);

} // namespace singleton
