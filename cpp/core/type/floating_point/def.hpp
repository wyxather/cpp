#pragma once

#include <concepts>

#include "core/type/arithmetic/def.hpp"
#include "core/type/integral/trait.hpp"
#include "trait.hpp"

namespace core::type {

    template <trait::FloatingPoint T>
    struct FloatingPoint: Arithmetic<T> {
    public:
        using Arithmetic<T>::Arithmetic;

        template <trait::FloatingPoint U>
        requires (!std::same_as<T, U>)
        [[nodiscard]]
        constexpr explicit operator U() const noexcept;

        template <trait::Integral U>
        [[nodiscard]]
        constexpr explicit operator U() const noexcept;

        template <typename Self>
        [[nodiscard]]
        constexpr auto sin(this const Self &self) noexcept;

        template <typename Self>
        [[nodiscard]]
        constexpr auto cos(this const Self &self) noexcept;

        template <typename Self>
        [[nodiscard]]
        constexpr auto tan(this const Self &self) noexcept;

        template <typename Self>
        [[nodiscard]]
        constexpr auto asin(this const Self &self) noexcept;

        template <typename Self>
        [[nodiscard]]
        constexpr auto acos(this const Self &self) noexcept;

        template <typename Self>
        [[nodiscard]]
        constexpr auto atan(this const Self &self) noexcept;

        template <typename Self>
        [[nodiscard]]
        constexpr auto atan(this const Self &self, const FloatingPoint &other) noexcept;

        template <typename Self>
        [[nodiscard]]
        constexpr auto sinh(this const Self &self) noexcept;

        template <typename Self>
        [[nodiscard]]
        constexpr auto cosh(this const Self &self) noexcept;

        template <typename Self>
        [[nodiscard]]
        constexpr auto tanh(this const Self &self) noexcept;

        template <typename Self>
        [[nodiscard]]
        constexpr auto asinh(this const Self &self) noexcept;

        template <typename Self>
        [[nodiscard]]
        constexpr auto acosh(this const Self &self) noexcept;

        template <typename Self>
        [[nodiscard]]
        constexpr auto atanh(this const Self &self) noexcept;

        template <typename Self>
        [[nodiscard]]
        constexpr auto pow(this const Self &self, const FloatingPoint &other) noexcept;

        template <typename Self>
        [[nodiscard]]
        constexpr auto sqrt(this const Self &self) noexcept;

        template <typename Self>
        [[nodiscard]]
        constexpr auto cbrt(this const Self &self) noexcept;

        template <typename Self>
        [[nodiscard]]
        constexpr auto hypot(this const Self &self, const FloatingPoint &other) noexcept;

        template <typename Self>
        [[nodiscard]]
        constexpr auto ceil(this const Self &self) noexcept;

        template <typename Self>
        [[nodiscard]]
        constexpr auto floor(this const Self &self) noexcept;

        template <typename Self>
        [[nodiscard]]
        constexpr auto trunc(this const Self &self) noexcept;

        template <typename Self>
        [[nodiscard]]
        constexpr auto round(this const Self &self) noexcept;
    };

} // namespace core::type
