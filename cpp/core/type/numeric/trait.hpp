#pragma once

#include <concepts>

namespace core::type::trait {

    template <typename T>
    concept Numeric = std::integral<T> || std::floating_point<T>;

} // namespace core::type::trait
