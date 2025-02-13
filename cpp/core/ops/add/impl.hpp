#pragma once

#include "def.hpp"
#include "trait.hpp"

namespace core::ops {

    template <typename Rhs>
    template <typename Self, typename Other>
    constexpr auto Add<Rhs>::add(this const Self &self, const Other &other) noexcept
    requires trait::Add<Self, Other>
    {
        return self + other;
    }

} // namespace core::ops
