#pragma once

#include "def.hpp"
#include "trait.hpp"

namespace core::ops {

    template <typename Rhs>
        template <typename Self, typename Other>
        constexpr auto Or<Rhs>::
            or (this const Self &self, const Other &other) noexcept -> decltype(auto)
        requires trait::Or<decltype(self), decltype(other)>
    {
        return self || other;
    }

} // namespace core::ops
