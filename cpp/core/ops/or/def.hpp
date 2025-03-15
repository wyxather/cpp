#pragma once

#include <type_traits>

#include "trait.hpp"

namespace core::ops {

    template <typename Rhs = void>
    struct Or {
    public:
        template <
            typename Self,
            typename Other = std::conditional_t<std::is_void_v<Rhs>, Self, Rhs>>
            [[nodiscard]]
            constexpr auto
            or (this const Self &self, const Other &other) noexcept -> decltype(auto)
            requires trait::Or<decltype(self), decltype(other)>;

    protected:
        Or() = default;
        ~Or() = default;
    };

} // namespace core::ops
