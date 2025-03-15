#pragma once

#include <cstddef>
#include <type_traits>

#include "core/convert/as/def.hpp"
#include "core/ops/add/def.hpp"
#include "core/ops/add_assign/def.hpp"
#include "core/ops/deref/def.hpp"
#include "core/ops/sub/def.hpp"
#include "core/ops/sub_assign/def.hpp"
#include "core/type/scalar/def.hpp"
#include "trait.hpp"

namespace core::type {

    template <typename T>
    requires (!std::is_reference_v<T>)
    struct Pointer:
        Scalar<std::add_pointer_t<T>>,
        convert::As<>,
        ops::Deref,
        ops::Add<std::uintptr_t>,
        ops::Sub<std::uintptr_t>,
        ops::AddAssign<std::uintptr_t>,
        ops::SubAssign<std::uintptr_t> {
    public:
        using Scalar<std::add_pointer_t<T>>::Scalar;

        [[nodiscard]]
        constexpr auto operator*() const noexcept -> auto &;

        [[nodiscard]]
        constexpr auto operator*() const noexcept
        requires trait::Pointer<T>;

        [[nodiscard]]
        constexpr auto operator+(std::uintptr_t count) const noexcept;

        [[nodiscard]]
        constexpr auto operator-(std::uintptr_t count) const noexcept;

        template <typename Self>
        constexpr auto operator+=(this Self &&self, std::uintptr_t count) noexcept -> auto &&;

        template <typename Self>
        constexpr auto operator-=(this Self &&self, std::uintptr_t count) noexcept -> auto &&;

        [[nodiscard]]
        constexpr auto byte_add(std::uintptr_t count) const noexcept;

        [[nodiscard]]
        constexpr auto byte_sub(std::uintptr_t count) const noexcept;

        template <typename Self>
        constexpr auto byte_add_assign(this Self &&self, std::uintptr_t count) noexcept -> auto &&;

        template <typename Self>
        constexpr auto byte_sub_assign(this Self &&self, std::uintptr_t count) noexcept -> auto &&;
    };

} // namespace core::type
