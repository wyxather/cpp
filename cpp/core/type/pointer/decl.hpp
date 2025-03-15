#pragma once

#include <type_traits>

namespace core::type {

    template <typename T>
    requires (!std::is_reference_v<T>)
    struct Pointer;

} // namespace core::type
