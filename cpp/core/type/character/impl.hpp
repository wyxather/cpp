#pragma once

#include <cctype>

#include "core/type/integral/trait.hpp"
#include "def.hpp"

namespace core::type {

    template <trait::Integral T>
    constexpr auto Character<T>::is_alphanumeric() const noexcept {
        return std::isalnum(this->value) != 0;
    }

    template <trait::Integral T>
    constexpr auto Character<T>::is_alphabetic() const noexcept {
        return std::isalpha(this->value) != 0;
    }

    template <trait::Integral T>
    constexpr auto Character<T>::is_lowercase() const noexcept {
        return std::islower(this->value) != 0;
    }

    template <trait::Integral T>
    constexpr auto Character<T>::is_uppercase() const noexcept {
        return std::isupper(this->value) != 0;
    }

    template <trait::Integral T>
    constexpr auto Character<T>::is_digit() const noexcept {
        return std::isdigit(this->value) != 0;
    }

    template <trait::Integral T>
    constexpr auto Character<T>::is_hexadecimal() const noexcept {
        return std::isxdigit(this->value) != 0;
    }

    template <trait::Integral T>
    constexpr auto Character<T>::is_control() const noexcept {
        return std::iscntrl(this->value) != 0;
    }

    template <trait::Integral T>
    constexpr auto Character<T>::is_graphical() const noexcept {
        return std::isgraph(this->value) != 0;
    }

    template <trait::Integral T>
    constexpr auto Character<T>::is_space() const noexcept {
        return std::isspace(this->value) != 0;
    }

    template <trait::Integral T>
    constexpr auto Character<T>::is_blank() const noexcept {
        return std::isblank(this->value) != 0;
    }

    template <trait::Integral T>
    constexpr auto Character<T>::is_printable() const noexcept {
        return std::isprint(this->value) != 0;
    }

    template <trait::Integral T>
    constexpr auto Character<T>::is_punctuation() const noexcept {
        return std::ispunct(this->value) != 0;
    }

} // namespace core::type

#include "core/type/integral/impl.hpp"
