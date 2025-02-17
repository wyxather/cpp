#pragma once

#include <concepts>

#include "core/type/scalar/def.hpp"
#include "decl.hpp"

namespace core::type {

    template <std::integral T>
    struct Numeric<T>: Scalar<T> {
    public:
        using Scalar<T>::Scalar;
    };

    template <std::floating_point T>
    struct Numeric<T>: Scalar<T> {
    public:
        using Scalar<T>::Scalar;

        template <typename Self>
        [[nodiscard]]
        consteval auto min_positive(this const Self &) noexcept;

        template <typename Self>
        [[nodiscard]]
        consteval auto epsilon(this const Self &) noexcept;

        template <typename Self>
        [[nodiscard]]
        consteval auto round_error(this const Self &) noexcept;

        template <typename Self>
        [[nodiscard]]
        consteval auto infinity(this const Self &) noexcept;

        template <typename Self>
        [[nodiscard]]
        consteval auto neg_infinity(this const Self &) noexcept;

        template <typename Self>
        [[nodiscard]]
        consteval auto quiet_nan(this const Self &) noexcept;

        template <typename Self>
        [[nodiscard]]
        consteval auto signaling_nan(this const Self &) noexcept;

        template <typename Self>
        [[nodiscard]]
        consteval auto denorm_min(this const Self &) noexcept;

        [[nodiscard]]
        constexpr auto is_finite() const noexcept;

        [[nodiscard]]
        constexpr auto is_infinite() const noexcept;

        [[nodiscard]]
        constexpr auto is_nan() const noexcept;

        [[nodiscard]]
        constexpr auto is_normal() const noexcept;
    };

} // namespace core::type
