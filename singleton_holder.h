#pragma once

#include "new_memory_policy.h"
#include "cpp_lifetime_policy.h"
#include "multi_threaded_policy.h"

#include <cassert>

namespace singleton {

template <
    typename T,
    template <class> class MP = NewMemoryPolicy,
    template <class> class LP = CppLifetimePolicy,
    template <class> class TP = MultiThreadedPolicy>
class SingletonHolder {
public:
    static T & instance();

private:
    static void destroy();

    static bool m_destroyed;

    static T * m_instance;
};

template <typename T, template <class> class MP, template <class> class LP, template <class> class TP>
T & SingletonHolder<T, MP, LP, TP>::instance() {
    if (!m_instance) {
        typename TP<T>::Lock lock;
        if (!m_instance) {
            if (m_destroyed) {
                LP<T>::on_dead_reference();
                m_destroyed = false;
            }

            m_instance = MP<T>::create();
            LP<T>::schedule_destruction(&SingletonHolder<T, MP, LP, TP>::destroy);
        }
    }

    return *m_instance;
}

template <typename T, template <class> class MP, template <class> class LP, template <class> class TP>
void SingletonHolder<T, MP, LP, TP>::destroy() {
    assert(!m_destroyed);
    MP<T>::destroy(m_instance);
    m_instance = 0;
    m_destroyed = true;
}


/* Initialization of static members */

template <typename T, template <class> class MP, template <class> class LP, template <class> class TP>
bool SingletonHolder<T, MP, LP, TP>::m_destroyed(false);

template <typename T, template <class> class MP, template <class> class LP, template <class> class TP>
T * SingletonHolder<T, MP, LP, TP>::m_instance(0);

} // namespace singleton
