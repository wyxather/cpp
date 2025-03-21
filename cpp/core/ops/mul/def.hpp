#pragma once

#include <type_traits>

#include "trait.hpp"

namespace core::ops {

    template <typename Rhs = void>
    struct Mul {
    public:
        template <
            typename Self,
            typename Other = std::conditional_t<std::is_void_v<Rhs>, Self, Rhs>>
        [[nodiscard]]
        constexpr auto mul(this const Self &self, const Other &other) noexcept -> decltype(auto)
        requires trait::Mul<decltype(self), decltype(other)>;

    protected:
        Mul() = default;
        ~Mul() = default;
    };

} // namespace core::ops
