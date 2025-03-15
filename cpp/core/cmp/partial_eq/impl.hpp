#pragma once

#include "def.hpp"
#include "trait.hpp"

namespace core::cmp {

    template <typename Rhs>
    template <typename Self, typename Other>
    constexpr auto PartialEq<Rhs>::eq(this const Self &self, const Other &other) noexcept
    requires trait::PartialEq<decltype(self), decltype(other)>
    {
        return self == other;
    }

    template <typename Rhs>
    template <typename Self, typename Other>
    constexpr auto PartialEq<Rhs>::ne(this const Self &self, const Other &other) noexcept
    requires trait::PartialEq<decltype(self), decltype(other)>
    {
        return self != other;
    }

} // namespace core::cmp
