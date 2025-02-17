#pragma once

#include <type_traits>

namespace core::type::trait {

    template <typename T>
    concept Arithmetic = std::is_arithmetic_v<T>;

} // namespace core::type::trait
