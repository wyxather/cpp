#pragma once

#include <type_traits>

#include "trait.hpp"

namespace core::ops {

    template <typename Rhs = void>
    struct Rem {
    public:
        template <
            typename Self,
            typename Other = std::conditional_t<std::is_void_v<Rhs>, Self, Rhs>>
        [[nodiscard]]
        constexpr auto rem(this const Self &self, const Other &other) noexcept -> decltype(auto)
        requires trait::Rem<decltype(self), decltype(other)>;

    protected:
        Rem() = default;
        ~Rem() = default;
    };

} // namespace core::ops
