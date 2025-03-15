#pragma once

#include <concepts>
#include <type_traits>

#include "trait.hpp"

namespace core::convert {

    template <typename T = void>
    struct As {
    public:
        template <std::same_as<T> Other = T, typename Self>
        [[nodiscard]]
        constexpr auto as(this Self &&self) noexcept -> decltype(auto)
        requires trait::As<
            std::add_lvalue_reference_t<std::remove_reference_t<decltype(self)>>,
            std::conditional_t<
                std::is_lvalue_reference_v<decltype(self)>,
                std::add_lvalue_reference_t<Other>,
                std::add_rvalue_reference_t<Other>>>;

    protected:
        As() = default;
        ~As() = default;
    };

    template <>
    struct As<void> {
    public:
        template <typename Other, typename Self>
        [[nodiscard]]
        constexpr auto as(this Self &&self) noexcept -> decltype(auto)
        requires trait::As<
            std::add_lvalue_reference_t<std::remove_reference_t<decltype(self)>>,
            std::conditional_t<
                std::is_lvalue_reference_v<decltype(self)>,
                std::add_lvalue_reference_t<Other>,
                std::add_rvalue_reference_t<Other>>>;

    protected:
        As() = default;
        ~As() = default;
    };

} // namespace core::convert
