#pragma once

namespace singleton {

template <typename T>
class SingleThreadedPolicy {
public:
    typedef char Lock;
};

} // namespace singleton
