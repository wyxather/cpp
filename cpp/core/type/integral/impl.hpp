#pragma once

#include <concepts>

#include "core/type/floating_point/trait.hpp"
#include "def.hpp"
#include "trait.hpp"

namespace core::type {

    template <trait::Integral T>
    Integral(T) -> Integral<T>;

    template <trait::Integral T>
    template <trait::Integral U>
    requires (!std::same_as<T, U>)
    constexpr Integral<T>::operator U() const noexcept {
        return this->value;
    }

    template <trait::Integral T>
    template <trait::FloatingPoint U>
    constexpr Integral<T>::operator U() const noexcept {
        return this->value;
    }

} // namespace core::type

#include "core/type/arithmetic/impl.hpp"
