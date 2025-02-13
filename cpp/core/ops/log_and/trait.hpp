#pragma once

namespace core::ops::trait {

    template <typename Lhs, typename Rhs>
    concept LogAnd = requires (Lhs lhs, Rhs rhs) {
        { lhs &&rhs };
    };

} // namespace core::ops::trait
