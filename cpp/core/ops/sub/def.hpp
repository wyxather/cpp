#pragma once

#include <type_traits>

#include "trait.hpp"

namespace core::ops {

    template <typename Rhs = void>
    struct Sub {
    public:
        template <
            typename Self,
            typename Other = std::conditional_t<std::is_void_v<Rhs>, Self, Rhs>>
        [[nodiscard]]
        constexpr auto sub(this const Self &self, const Other &other) noexcept -> decltype(auto)
        requires trait::Sub<decltype(self), decltype(other)>;

    protected:
        Sub() = default;
        ~Sub() = default;
    };

} // namespace core::ops
