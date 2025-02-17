#pragma once

#include <concepts>

#include "core/type/arithmetic/def.hpp"
#include "core/type/floating_point/trait.hpp"
#include "trait.hpp"

namespace core::type {

    template <trait::Integral T>
    struct Integral: Arithmetic<T> {
    public:
        using Arithmetic<T>::Arithmetic;

        template <trait::Integral U>
        requires (!std::same_as<T, U>)
        [[nodiscard]]
        constexpr explicit operator U() const noexcept;

        template <trait::FloatingPoint U>
        [[nodiscard]]
        constexpr explicit operator U() const noexcept;
    };

} // namespace core::type
