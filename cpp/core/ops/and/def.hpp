#pragma once

#include <type_traits>

#include "trait.hpp"

namespace core::ops {

    template <typename Rhs = void>
    struct And {
    public:
        template <
            typename Self,
            typename Other = std::conditional_t<std::is_void_v<Rhs>, Self, Rhs>>
            [[nodiscard]]
            constexpr auto
            and (this const Self &self, const Other &other) noexcept -> decltype(auto)
            requires trait::And<decltype(self), decltype(other)>;

    protected:
        And() = default;
        ~And() = default;
    };

} // namespace core::ops
