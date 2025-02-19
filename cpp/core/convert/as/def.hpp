#pragma once

#include <concepts>

#include "trait.hpp"

namespace core::convert {

    template <typename T = void>
    struct As {
    public:
        template <std::same_as<T> Other = T, typename Self>
        [[nodiscard]]
        constexpr auto as(this Self &&self) noexcept -> Other
        requires trait::As<Self, Other>;
    };

    template <>
    struct As<void> {
    public:
        template <typename Other, typename Self>
        [[nodiscard]]
        constexpr auto as(this Self &&self) noexcept -> Other
        requires trait::As<Self, Other>;
    };

} // namespace core::convert
