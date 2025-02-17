#pragma once

#include <concepts>

namespace core::type::trait {

    template <typename T>
    concept FloatingPoint = std::floating_point<T>;

} // namespace core::type::trait
