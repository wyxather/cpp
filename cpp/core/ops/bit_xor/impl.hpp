#pragma once

#include "def.hpp"
#include "trait.hpp"

namespace core::ops {

    template <typename Rhs>
    template <typename Self, typename Other>
    constexpr auto BitXor<Rhs>::bit_xor(this const Self &self, const Other &other) noexcept
    requires trait::BitXor<Self, Other>
    {
        return self ^ other;
    }

} // namespace core::ops
