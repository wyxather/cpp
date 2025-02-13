#pragma once

#include "def.hpp"
#include "trait.hpp"

namespace core::ops {

    template <typename Self>
    constexpr auto BitNot::bit_not(this const Self &self) noexcept
    requires trait::BitNot<Self>
    {
        return ~self;
    }

} // namespace core::ops
