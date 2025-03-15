#pragma once

#include <type_traits>

#include "def.hpp"
#include "trait.hpp"

namespace core::ops {

    template <typename Rhs>
    template <typename Self, typename Other>
    requires (!std::is_const_v<std::remove_reference_t<Self>>)
    constexpr auto ShrAssign<Rhs>::shr_assign(this Self &&self, const Other &other) noexcept
        -> decltype(auto)
    requires trait::ShrAssign<decltype(self), decltype(other)>
    {
        return std::forward<Self>(self) >>= other;
    }

} // namespace core::ops
