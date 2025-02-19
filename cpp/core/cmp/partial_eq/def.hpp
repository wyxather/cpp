#pragma once

#include <compare>
#include <type_traits>

#include "trait.hpp"

namespace core::cmp {

    template <typename Rhs = void>
    struct PartialEq {
    public:
        [[nodiscard]]
        auto operator<=>(const PartialEq &) const = default;

        template <
            typename Self,
            typename Other = std::conditional_t<std::is_void_v<Rhs>, Self, Rhs>>
        [[nodiscard]]
        constexpr auto eq(this const Self &self, const Other &other) noexcept
        requires trait::PartialEq<Self, Other>;

        template <
            typename Self,
            typename Other = std::conditional_t<std::is_void_v<Rhs>, Self, Rhs>>
        [[nodiscard]]
        constexpr auto ne(this const Self &self, const Other &other) noexcept
        requires trait::PartialEq<Self, Other>;
    };

} // namespace core::cmp
