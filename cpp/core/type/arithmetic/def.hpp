#pragma once

#include <concepts>

#include "core/ops/add/def.hpp"
#include "core/ops/add_assign/def.hpp"
#include "core/ops/div/def.hpp"
#include "core/ops/div_assign/def.hpp"
#include "core/ops/mul/def.hpp"
#include "core/ops/mul_assign/def.hpp"
#include "core/ops/rem/def.hpp"
#include "core/ops/rem_assign/def.hpp"
#include "core/ops/sub/def.hpp"
#include "core/ops/sub_assign/def.hpp"
#include "core/type/scalar/def.hpp"
#include "trait.hpp"

namespace core::type {

    template <trait::Arithmetic T>
    struct Arithmetic:
        Scalar<T>,
        ops::Add<>,
        ops::AddAssign<>,
        ops::Sub<>,
        ops::SubAssign<>,
        ops::Mul<>,
        ops::MulAssign<>,
        ops::Div<>,
        ops::DivAssign<>,
        ops::Rem<>,
        ops::RemAssign<> {
    public:
        using Scalar<T>::Scalar;

        template <typename Self>
        [[nodiscard]]
        constexpr auto operator+(this const Self &self, const Arithmetic &other) noexcept;

        template <typename Self>
        constexpr auto operator+=(this Self &self, const Arithmetic &other) noexcept -> auto &;

        template <typename Self>
        [[nodiscard]]
        constexpr auto operator-(this const Self &self, const Arithmetic &other) noexcept;

        template <typename Self>
        constexpr auto operator-=(this Self &self, const Arithmetic &other) noexcept -> auto &;

        template <typename Self>
        [[nodiscard]]
        constexpr auto operator*(this const Self &self, const Arithmetic &other) noexcept;

        template <typename Self>
        constexpr auto operator*=(this Self &self, const Arithmetic &other) noexcept -> auto &;

        template <typename Self>
        [[nodiscard]]
        constexpr auto operator/(this const Self &self, const Arithmetic &other) noexcept;

        template <typename Self>
        constexpr auto operator/=(this Self &self, const Arithmetic &other) noexcept -> auto &;

        template <typename Self>
        [[nodiscard]]
        constexpr auto operator%(this const Self &self, const Arithmetic &other) noexcept
        requires std::integral<T>;

        template <typename Self>
        constexpr auto operator%=(this Self &self, const Arithmetic &other) noexcept -> auto &
        requires std::integral<T>;

        template <typename Self>
        [[nodiscard]]
        constexpr auto operator%(this const Self &self, const Arithmetic &other) noexcept
        requires std::floating_point<T>;

        template <typename Self>
        constexpr auto operator%=(this Self &self, const Arithmetic &other) noexcept -> auto &
        requires std::floating_point<T>;
    };

} // namespace core::type
