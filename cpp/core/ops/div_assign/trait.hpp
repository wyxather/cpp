#pragma once

namespace core::ops::trait {

    template <typename Lhs, typename Rhs>
    concept DivAssign = requires (Lhs lhs, Rhs rhs) {
        { lhs /= rhs };
    };

} // namespace core::ops::trait
