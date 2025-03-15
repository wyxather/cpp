#pragma once

#include <concepts>
#include <utility>

#include "def.hpp"
#include "trait.hpp"

namespace core::convert {

    template <typename T>
    template <std::same_as<T> Other, typename Self>
    constexpr auto Into<T>::into(this Self &&self) noexcept -> Other
    requires trait::Into<decltype(self), Other>
    {
        return static_cast<Other>(std::forward<Self>(self));
    }

    template <typename Other, typename Self>
    constexpr auto Into<void>::into(this Self &&self) noexcept -> Other
    requires trait::Into<decltype(self), Other>
    {
        return static_cast<Other>(std::forward<Self>(self));
    }

} // namespace core::convert
