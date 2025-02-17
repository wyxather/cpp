#pragma once

#include <cmath>
#include <concepts>

#include "core/type/integral/trait.hpp"
#include "def.hpp"
#include "trait.hpp"

namespace core::type {

    template <trait::FloatingPoint T>
    template <trait::FloatingPoint U>
    requires (!std::same_as<T, U>)
    constexpr FloatingPoint<T>::operator U() const noexcept {
        return this->value;
    }

    template <trait::FloatingPoint T>
    template <trait::Integral U>
    constexpr FloatingPoint<T>::operator U() const noexcept {
        return this->value;
    }

    template <trait::FloatingPoint T>
    FloatingPoint(T) -> FloatingPoint<T>;

    template <trait::FloatingPoint T>
    template <typename Self>
    constexpr auto FloatingPoint<T>::sin(this const Self &self) noexcept {
        return Self { std::sin(self.value) };
    }

    template <trait::FloatingPoint T>
    template <typename Self>
    constexpr auto FloatingPoint<T>::cos(this const Self &self) noexcept {
        return Self { std::cos(self.value) };
    }

    template <trait::FloatingPoint T>
    template <typename Self>
    constexpr auto FloatingPoint<T>::tan(this const Self &self) noexcept {
        return Self { std::tan(self.value) };
    }

    template <trait::FloatingPoint T>
    template <typename Self>
    constexpr auto FloatingPoint<T>::asin(this const Self &self) noexcept {
        return Self { std::asin(self.value) };
    }

    template <trait::FloatingPoint T>
    template <typename Self>
    constexpr auto FloatingPoint<T>::acos(this const Self &self) noexcept {
        return Self { std::acos(self.value) };
    }

    template <trait::FloatingPoint T>
    template <typename Self>
    constexpr auto FloatingPoint<T>::atan(this const Self &self) noexcept {
        return Self { std::atan(self.value) };
    }

    template <trait::FloatingPoint T>
    template <typename Self>
    constexpr auto FloatingPoint<T>::atan(
        this const Self &self,
        const FloatingPoint &other
    ) noexcept {
        return Self { std::atan2(self.value, other.value) };
    }

    template <trait::FloatingPoint T>
    template <typename Self>
    constexpr auto FloatingPoint<T>::sinh(this const Self &self) noexcept {
        return Self { std::sinh(self.value) };
    }

    template <trait::FloatingPoint T>
    template <typename Self>
    constexpr auto FloatingPoint<T>::cosh(this const Self &self) noexcept {
        return Self { std::cosh(self.value) };
    }

    template <trait::FloatingPoint T>
    template <typename Self>
    constexpr auto FloatingPoint<T>::tanh(this const Self &self) noexcept {
        return Self { std::tanh(self.value) };
    }

    template <trait::FloatingPoint T>
    template <typename Self>
    constexpr auto FloatingPoint<T>::asinh(this const Self &self) noexcept {
        return Self { std::asinh(self.value) };
    }

    template <trait::FloatingPoint T>
    template <typename Self>
    constexpr auto FloatingPoint<T>::acosh(this const Self &self) noexcept {
        return Self { std::acosh(self.value) };
    }

    template <trait::FloatingPoint T>
    template <typename Self>
    constexpr auto FloatingPoint<T>::atanh(this const Self &self) noexcept {
        return Self { std::atanh(self.value) };
    }

    template <trait::FloatingPoint T>
    template <typename Self>
    constexpr auto FloatingPoint<T>::pow(
        this const Self &self,
        const FloatingPoint &other
    ) noexcept {
        return Self { std::pow(self.value, other.value) };
    }

    template <trait::FloatingPoint T>
    template <typename Self>
    constexpr auto FloatingPoint<T>::sqrt(this const Self &self) noexcept {
        return Self { std::sqrt(self.value) };
    }

    template <trait::FloatingPoint T>
    template <typename Self>
    constexpr auto FloatingPoint<T>::cbrt(this const Self &self) noexcept {
        return Self { std::cbrt(self.value) };
    }

    template <trait::FloatingPoint T>
    template <typename Self>
    constexpr auto FloatingPoint<T>::hypot(
        this const Self &self,
        const FloatingPoint &other
    ) noexcept {
        return Self { std::hypot(self.value, other.value) };
    }

    template <trait::FloatingPoint T>
    template <typename Self>
    constexpr auto FloatingPoint<T>::ceil(this const Self &self) noexcept {
        return Self { std::ceil(self.value) };
    }

    template <trait::FloatingPoint T>
    template <typename Self>
    constexpr auto FloatingPoint<T>::floor(this const Self &self) noexcept {
        return Self { std::floor(self.value) };
    }

    template <trait::FloatingPoint T>
    template <typename Self>
    constexpr auto FloatingPoint<T>::trunc(this const Self &self) noexcept {
        return Self { std::trunc(self.value) };
    }

    template <trait::FloatingPoint T>
    template <typename Self>
    constexpr auto FloatingPoint<T>::round(this const Self &self) noexcept {
        return Self { std::round(self.value) };
    }

} // namespace core::type

#include "core/type/arithmetic/impl.hpp"
