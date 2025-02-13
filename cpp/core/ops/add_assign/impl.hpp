#pragma once

#include <type_traits>

#include "def.hpp"
#include "trait.hpp"

namespace core::ops {

    template <typename Rhs>
    template <typename Self, typename Other>
    requires (!std::is_const_v<std::remove_reference_t<Self>>)
    constexpr auto AddAssign<Rhs>::add_assign(this Self &&self, const Other &other) noexcept
        -> decltype(auto)
    requires trait::AddAssign<Self, Other>
    {
        return self += other;
    }

} // namespace core::ops
