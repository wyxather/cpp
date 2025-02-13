#pragma once

#include "def.hpp"
#include "trait.hpp"

namespace core::ops {

    template <typename Rhs>
    template <typename Self, typename Other>
    constexpr auto Sub<Rhs>::sub(this const Self &self, const Other &other) noexcept
    requires trait::Sub<Self, Other>
    {
        return self - other;
    }

} // namespace core::ops
