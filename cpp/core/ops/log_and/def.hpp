#pragma once

#include <type_traits>

#include "trait.hpp"

namespace core::ops {

    template <typename Rhs = void>
    struct LogAnd {
    public:
        template <
            typename Self,
            typename Other = std::conditional_t<std::is_void_v<Rhs>, Self, Rhs>>
        [[nodiscard]]
        constexpr auto log_and(this const Self &self, const Other &other) noexcept
        requires trait::LogAnd<Self, Other>;
    };

} // namespace core::ops
