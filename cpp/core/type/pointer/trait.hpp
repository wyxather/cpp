#pragma once

#include <type_traits>

namespace core::type::trait {

    template <typename T>
    concept Pointer = std::is_pointer_v<T>;

} // namespace core::type::trait
