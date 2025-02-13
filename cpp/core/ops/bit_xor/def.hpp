#pragma once

#include <type_traits>

#include "trait.hpp"

namespace core::ops {

    template <typename Rhs = void>
    struct BitXor {
    public:
        template <
            typename Self,
            typename Other = std::conditional_t<std::is_void_v<Rhs>, Self, Rhs>>
        [[nodiscard]]
        constexpr auto bit_xor(this const Self &self, const Other &other) noexcept
        requires trait::BitXor<Self, Other>;
    };

} // namespace core::ops
