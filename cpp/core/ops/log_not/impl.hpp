#pragma once

#include "def.hpp"
#include "trait.hpp"

namespace core::ops {

    template <typename Self>
    constexpr auto LogNot::log_not(this const Self &self) noexcept
    requires trait::LogNot<Self>
    {
        return !self;
    }

} // namespace core::ops
