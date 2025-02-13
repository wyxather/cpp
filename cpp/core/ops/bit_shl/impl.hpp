#pragma once

#include "def.hpp"
#include "trait.hpp"

namespace core::ops {

    template <typename Rhs>
    template <typename Self, typename Other>
    constexpr auto BitShl<Rhs>::bit_shl(this const Self &self, const Other &other) noexcept
    requires trait::BitShl<Self, Other>
    {
        return self << other;
    }

} // namespace core::ops
