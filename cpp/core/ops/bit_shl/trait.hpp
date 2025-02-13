#pragma once

namespace core::ops::trait {

    template <typename Lhs, typename Rhs>
    concept BitShl = requires (Lhs lhs, Rhs rhs) {
        { lhs << rhs };
    };

} // namespace core::ops::trait
