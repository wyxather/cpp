#pragma once

#include <concepts>

namespace core::type::trait {

    template <typename T>
    concept Integral = std::integral<T>;

} // namespace core::type::trait
