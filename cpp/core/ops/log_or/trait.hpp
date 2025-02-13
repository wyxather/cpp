#pragma once

namespace core::ops::trait {

    template <typename Lhs, typename Rhs>
    concept LogOr = requires (Lhs lhs, Rhs rhs) {
        { lhs || rhs };
    };

} // namespace core::ops::trait
