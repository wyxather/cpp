#pragma once

#include <concepts>

#include "core/type/integral/trait.hpp"
#include "core/type/scalar/def.hpp"

namespace core::type {

    template <trait::Integral T>
    struct Character: Scalar<T> {
    public:
        using Scalar<T>::Scalar;

        template <trait::Integral U>
        requires (!std::same_as<T, U>)
        [[nodiscard]]
        constexpr explicit operator U() const noexcept;

        [[nodiscard]]
        constexpr auto is_alphanumeric() const noexcept;

        [[nodiscard]]
        constexpr auto is_alphabetic() const noexcept;

        [[nodiscard]]
        constexpr auto is_lowercase() const noexcept;

        [[nodiscard]]
        constexpr auto is_uppercase() const noexcept;

        [[nodiscard]]
        constexpr auto is_digit() const noexcept;

        [[nodiscard]]
        constexpr auto is_hexadecimal() const noexcept;

        [[nodiscard]]
        constexpr auto is_control() const noexcept;

        [[nodiscard]]
        constexpr auto is_graphical() const noexcept;

        [[nodiscard]]
        constexpr auto is_space() const noexcept;

        [[nodiscard]]
        constexpr auto is_blank() const noexcept;

        [[nodiscard]]
        constexpr auto is_printable() const noexcept;

        [[nodiscard]]
        constexpr auto is_punctuation() const noexcept;
    };

} // namespace core::type
