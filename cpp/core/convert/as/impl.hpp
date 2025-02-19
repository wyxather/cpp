#pragma once

#include <concepts>

#include "def.hpp"
#include "trait.hpp"

namespace core::convert {

    template <typename T>
    template <std::same_as<T> Other, typename Self>
    constexpr auto As<T>::as(this Self &&self) noexcept -> Other
    requires trait::As<Self, Other>
    {
        return reinterpret_cast<Other>(std::forward<Self>(self));
    }

    template <typename Other, typename Self>
    constexpr auto As<void>::as(this Self &&self) noexcept -> Other
    requires trait::As<Self, Other>
    {
        return reinterpret_cast<Other>(std::forward<Self>(self));
    }

} // namespace core::convert
