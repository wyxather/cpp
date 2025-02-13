#pragma once

#include "def.hpp"
#include "trait.hpp"

namespace core::ops {

    template <typename Rhs>
    template <typename Self, typename Other>
    constexpr auto Rem<Rhs>::rem(this const Self &self, const Other &other) noexcept
    requires trait::Rem<Self, Other>
    {
        return self % other;
    }

} // namespace core::ops
