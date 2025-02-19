#pragma once

#include <concepts>

namespace core::cmp::trait {

    template <typename Lhs, typename Rhs>
    concept PartialEq = std::_Half_equality_comparable<Lhs, Rhs>;

} // namespace core::cmp::trait
