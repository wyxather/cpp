#pragma once

#include "def.hpp"
#include "trait.hpp"

namespace core::ops {

    template <typename Self>
    constexpr auto BitNot::bitnot(this const Self &self) noexcept -> decltype(auto)
    requires trait::BitNot<decltype(self)>
    {
        return ~self;
    }

} // namespace core::ops
