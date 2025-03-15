#pragma once

#include <type_traits>

#include "trait.hpp"

namespace core::ops {

    template <typename Rhs = void>
    struct BitAnd {
    public:
        template <
            typename Self,
            typename Other = std::conditional_t<std::is_void_v<Rhs>, Self, Rhs>>
        [[nodiscard]]
        constexpr auto bitand(this const Self &self, const Other &other) noexcept -> decltype(auto)
        requires trait::BitAnd<decltype(self), decltype(other)>;

    protected:
        BitAnd() = default;
        ~BitAnd() = default;
    };

} // namespace core::ops
