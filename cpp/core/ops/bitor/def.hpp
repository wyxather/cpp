#pragma once

#include <type_traits>

#include "trait.hpp"

namespace core::ops {

    template <typename Rhs = void>
    struct BitOr {
    public:
        template <
            typename Self,
            typename Other = std::conditional_t<std::is_void_v<Rhs>, Self, Rhs>>
            [[nodiscard]]
            constexpr auto
            bitor (this const Self &self, const Other &other) noexcept -> decltype(auto)
            requires trait::BitOr<decltype(self), decltype(other)>;

    protected:
        BitOr() = default;
        ~BitOr() = default;
    };

} // namespace core::ops
