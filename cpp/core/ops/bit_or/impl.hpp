#pragma once

#include "def.hpp"
#include "trait.hpp"

namespace core::ops {

    template <typename Rhs>
    template <typename Self, typename Other>
    constexpr auto BitOr<Rhs>::bit_or(this const Self &self, const Other &other) noexcept
    requires trait::BitOr<Self, Other>
    {
        return self | other;
    }

} // namespace core::ops
