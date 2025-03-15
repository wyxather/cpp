#pragma once

#include <concepts>
#include <type_traits>

#include "def.hpp"
#include "trait.hpp"

namespace core::convert {

    template <typename T>
    template <std::same_as<T> Other, typename Self>
    constexpr auto As<T>::as(this Self &&self) noexcept -> decltype(auto)
    requires trait::As<
        std::add_lvalue_reference_t<std::remove_reference_t<decltype(self)>>,
        std::conditional_t<
            std::is_lvalue_reference_v<decltype(self)>,
            std::add_lvalue_reference_t<Other>,
            std::add_rvalue_reference_t<Other>>>
    {
        return reinterpret_cast<std::conditional_t<
            std::is_lvalue_reference_v<decltype(self)>,
            std::add_lvalue_reference_t<Other>,
            std::add_rvalue_reference_t<Other>>>(self);
    }

    template <typename Other, typename Self>
    constexpr auto As<void>::as(this Self &&self) noexcept -> decltype(auto)
    requires trait::As<
        std::add_lvalue_reference_t<std::remove_reference_t<decltype(self)>>,
        std::conditional_t<
            std::is_lvalue_reference_v<decltype(self)>,
            std::add_lvalue_reference_t<Other>,
            std::add_rvalue_reference_t<Other>>>
    {
        return reinterpret_cast<std::conditional_t<
            std::is_lvalue_reference_v<decltype(self)>,
            std::add_lvalue_reference_t<Other>,
            std::add_rvalue_reference_t<Other>>>(self);
    }

} // namespace core::convert
