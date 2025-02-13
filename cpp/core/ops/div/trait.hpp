#pragma once

namespace core::ops::trait {

    template <typename Lhs, typename Rhs>
    concept Div = requires (Lhs lhs, Rhs rhs) {
        { lhs / rhs };
    };

} // namespace core::ops::trait
