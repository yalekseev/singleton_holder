#pragma once

#include <mutex>

#include <iostream>

template <typename T>
class MultiThreadedPolicy {
private:
    class PrivateLock {
    public:
        PrivateLock() {
            m_mutex.lock();
        }

        ~PrivateLock() {
            m_mutex.unlock();
        }

        static std::mutex m_mutex;
    };

public:
    typedef PrivateLock Lock;
};

template <typename T>
std::mutex MultiThreadedPolicy<T>::PrivateLock::m_mutex;
