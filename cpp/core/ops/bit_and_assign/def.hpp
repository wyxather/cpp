#pragma once

#include <type_traits>

#include "trait.hpp"

namespace core::ops {

    template <typename Rhs = void>
    struct BitAndAssign {
    public:
        template <
            typename Self,
            typename Other = std::conditional_t<std::is_void_v<Rhs>, Self, Rhs>>
        requires (!std::is_const_v<std::remove_reference_t<Self>>)
        constexpr auto bit_and_assign(this Self &&self, const Other &other) noexcept
            -> decltype(auto)
        requires trait::BitAndAssign<Self, Other>;
    };

} // namespace core::ops
