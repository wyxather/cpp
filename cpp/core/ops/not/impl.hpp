#pragma once

#include "def.hpp"
#include "trait.hpp"

namespace core::ops {

    template <typename Self>
    constexpr auto Not::not(this const Self &self) noexcept -> decltype(auto)
    requires trait::Not<decltype(self)>
    {
        return !self;
    }

} // namespace core::ops
