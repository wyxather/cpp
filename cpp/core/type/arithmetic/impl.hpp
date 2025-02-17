#pragma once

#include <cmath>
#include <concepts>

#include "def.hpp"
#include "trait.hpp"

namespace core::type {

    template <trait::Arithmetic T>
    Arithmetic(T) -> Arithmetic<T>;

    template <trait::Arithmetic T>
    template <typename Self>
    constexpr auto Arithmetic<T>::operator+(
        this const Self &self,
        const Arithmetic &other
    ) noexcept {
        return Self { static_cast<T>(self.value + other.value) };
    }

    template <trait::Arithmetic T>
    template <typename Self>
    constexpr auto Arithmetic<T>::operator+=(this Self &self, const Arithmetic &other) noexcept
        -> auto & {
        self.value += other.value;
        return self;
    }

    template <trait::Arithmetic T>
    template <typename Self>
    constexpr auto Arithmetic<T>::operator-(
        this const Self &self,
        const Arithmetic &other
    ) noexcept {
        return Self { static_cast<T>(self.value - other.value) };
    }

    template <trait::Arithmetic T>
    template <typename Self>
    constexpr auto Arithmetic<T>::operator-=(this Self &self, const Arithmetic &other) noexcept
        -> auto & {
        self.value -= other.value;
        return self;
    }

    template <trait::Arithmetic T>
    template <typename Self>
    constexpr auto Arithmetic<T>::operator*(
        this const Self &self,
        const Arithmetic &other
    ) noexcept {
        return Self { static_cast<T>(self.value * other.value) };
    }

    template <trait::Arithmetic T>
    template <typename Self>
    constexpr auto Arithmetic<T>::operator*=(this Self &self, const Arithmetic &other) noexcept
        -> auto & {
        self.value *= other.value;
        return self;
    }

    template <trait::Arithmetic T>
    template <typename Self>
    constexpr auto Arithmetic<T>::operator/(
        this const Self &self,
        const Arithmetic &other
    ) noexcept {
        return Self { static_cast<T>(self.value / other.value) };
    }

    template <trait::Arithmetic T>
    template <typename Self>
    constexpr auto Arithmetic<T>::operator/=(this Self &self, const Arithmetic &other) noexcept
        -> auto & {
        self.value /= other.value;
        return self;
    }

    template <trait::Arithmetic T>
    template <typename Self>
    constexpr auto Arithmetic<T>::operator%(this const Self &self, const Arithmetic &other) noexcept
    requires std::integral<T>
    {
        return Self { static_cast<T>(self.value % other.value) };
    }

    template <trait::Arithmetic T>
    template <typename Self>
    constexpr auto Arithmetic<T>::operator%=(this Self &self, const Arithmetic &other) noexcept
        -> auto &
    requires std::integral<T>
    {
        self.value %= other.value;
        return self;
    }

    template <trait::Arithmetic T>
    template <typename Self>
    constexpr auto Arithmetic<T>::operator%(this const Self &self, const Arithmetic &other) noexcept
    requires std::floating_point<T>
    {
        return Self { std::remainder<T, T>(self.value, other.value) };
    }

    template <trait::Arithmetic T>
    template <typename Self>
    constexpr auto Arithmetic<T>::operator%=(this Self &self, const Arithmetic &other) noexcept
        -> auto &
    requires std::floating_point<T>
    {
        self.value = std::remainder<T, T>(self.value, other.value);
        return self;
    }

} // namespace core::type

#include "core/ops/add/impl.hpp"
#include "core/ops/add_assign/impl.hpp"
#include "core/ops/div/impl.hpp"
#include "core/ops/div_assign/impl.hpp"
#include "core/ops/mul/impl.hpp"
#include "core/ops/mul_assign/impl.hpp"
#include "core/ops/rem/impl.hpp"
#include "core/ops/rem_assign/impl.hpp"
#include "core/ops/sub/impl.hpp"
#include "core/ops/sub_assign/impl.hpp"
#include "core/type/numeric/impl.hpp"
