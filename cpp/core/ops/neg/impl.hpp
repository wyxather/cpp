#pragma once

#include "def.hpp"
#include "trait.hpp"

namespace core::ops {

    template <typename Self>
    constexpr auto Neg::neg(this const Self &self) noexcept -> decltype(auto)
    requires trait::Neg<decltype(self)>
    {
        return -self;
    }

} // namespace core::ops
