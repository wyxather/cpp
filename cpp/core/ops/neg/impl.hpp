#pragma once

#include "def.hpp"
#include "trait.hpp"

namespace core::ops {

    template <typename Self>
    constexpr auto Neg::neg(this const Self &self) noexcept
    requires trait::Neg<Self>
    {
        return -self;
    }

} // namespace core::ops
