#pragma once

#include "core/type/integral/def.hpp"
#include "core/type/integral/trait.hpp"

namespace core::type {

    template <trait::Integral T>
    struct Character: Integral<T> {
    public:
        using Integral<T>::Integral;

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
