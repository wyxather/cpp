#pragma once

#include <cmath>
#include <concepts>
#include <limits>

#include "decl.hpp"
#include "def.hpp"
#include "trait.hpp"

namespace core::type {

    template <trait::Numeric T>
    Numeric(T) -> Numeric<T>;

    template <std::floating_point T>
    template <typename Self>
    consteval auto Numeric<T>::min_positive(this const Self &) noexcept {
        return Self { std::numeric_limits<T>::min() };
    }

    template <std::floating_point T>
    template <typename Self>
    consteval auto Numeric<T>::epsilon(this const Self &) noexcept {
        return Self { std::numeric_limits<T>::epsilon() };
    }

    template <std::floating_point T>
    template <typename Self>
    consteval auto Numeric<T>::round_error(this const Self &) noexcept {
        return Self { std::numeric_limits<T>::round_error() };
    }

    template <std::floating_point T>
    template <typename Self>
    consteval auto Numeric<T>::infinity(this const Self &) noexcept {
        return Self { std::numeric_limits<T>::infinity() };
    }

    template <std::floating_point T>
    template <typename Self>
    consteval auto Numeric<T>::neg_infinity(this const Self &) noexcept {
        return Self { -std::numeric_limits<T>::infinity() };
    }

    template <std::floating_point T>
    template <typename Self>
    consteval auto Numeric<T>::quiet_nan(this const Self &) noexcept {
        return Self { std::numeric_limits<T>::quiet_NaN() };
    }

    template <std::floating_point T>
    template <typename Self>
    consteval auto Numeric<T>::signaling_nan(this const Self &) noexcept {
        return Self { std::numeric_limits<T>::signaling_NaN() };
    }

    template <std::floating_point T>
    template <typename Self>
    consteval auto Numeric<T>::denorm_min(this const Self &) noexcept {
        return Self { std::numeric_limits<T>::denorm_min() };
    }

    template <std::floating_point T>
    constexpr auto Numeric<T>::is_finite() const noexcept {
        return std::isfinite(this->value);
    }

    template <std::floating_point T>
    constexpr auto Numeric<T>::is_infinite() const noexcept {
        return std::isinf(this->value);
    }

    template <std::floating_point T>
    constexpr auto Numeric<T>::is_nan() const noexcept {
        return std::isnan(this->value);
    }

    template <std::floating_point T>
    constexpr auto Numeric<T>::is_normal() const noexcept {
        return std::isnormal(this->value);
    }

} // namespace core::type

#include "core/type/scalar/impl.hpp"
