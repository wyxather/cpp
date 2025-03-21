#pragma once

#include <type_traits>

#include "trait.hpp"

namespace core::ops {

    template <typename Rhs = void>
    struct Div {
    public:
        template <
            typename Self,
            typename Other = std::conditional_t<std::is_void_v<Rhs>, Self, Rhs>>
        [[nodiscard]]
        constexpr auto div(this const Self &self, const Other &other) noexcept -> decltype(auto)
        requires trait::Div<decltype(self), decltype(other)>;

    protected:
        Div() = default;
        ~Div() = default;
    };

} // namespace core::ops
