#pragma once

#include <concepts>

#include "trait.hpp"

namespace core::convert {

    template <typename T = void>
    struct Into {
    public:
        template <std::same_as<T> Other = T, typename Self>
        [[nodiscard]]
        constexpr auto into(this Self &&self) noexcept -> Other
        requires trait::Into<Self, Other>;
    };

    template <>
    struct Into<void> {
    public:
        template <typename Other, typename Self>
        [[nodiscard]]
        constexpr auto into(this Self &&self) noexcept -> Other
        requires trait::Into<Self, Other>;
    };

} // namespace core::convert
