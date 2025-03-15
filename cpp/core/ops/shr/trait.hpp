#pragma once

#include <utility>

namespace core::ops::trait {

    template <typename Lhs, typename Rhs>
    concept Shr = requires (Lhs &&lhs, Rhs &&rhs) {
        { std::forward<Lhs>(lhs) >> std::forward<Rhs>(rhs) } noexcept;
    };

} // namespace core::ops::trait
