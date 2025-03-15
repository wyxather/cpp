#pragma once

#include "def.hpp"
#include "trait.hpp"

namespace core::ops {

    template <typename Rhs>
    template <typename Self, typename Other>
    constexpr auto Shl<Rhs>::shl(this const Self &self, const Other &other) noexcept
        -> decltype(auto)
    requires trait::Shl<decltype(self), decltype(other)>
    {
        return self << other;
    }

} // namespace core::ops
