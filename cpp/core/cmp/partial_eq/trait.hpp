#pragma once

#include <concepts>
#include <utility>

namespace core::cmp::trait {

    template <typename Lhs, typename Rhs>
    concept PartialEq = requires (Lhs &&lhs, Rhs &&rhs) {
        { std::forward<Lhs>(lhs) == std::forward<Rhs>(rhs) } noexcept -> std::convertible_to<bool>;
        { std::forward<Lhs>(lhs) != std::forward<Rhs>(rhs) } noexcept -> std::convertible_to<bool>;
    };

} // namespace core::cmp::trait
