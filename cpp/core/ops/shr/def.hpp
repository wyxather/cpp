#pragma once

#include <type_traits>

#include "trait.hpp"

namespace core::ops {

    template <typename Rhs = void>
    struct Shr {
    public:
        template <
            typename Self,
            typename Other = std::conditional_t<std::is_void_v<Rhs>, Self, Rhs>>
        [[nodiscard]]
        constexpr auto shr(this const Self &self, const Other &other) noexcept -> decltype(auto)
        requires trait::Shr<decltype(self), decltype(other)>;

    protected:
        Shr() = default;
        ~Shr() = default;
    };

} // namespace core::ops
