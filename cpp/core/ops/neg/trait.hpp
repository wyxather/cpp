#pragma once

namespace core::ops::trait {

    template <typename Self>
    concept Neg = requires (Self self) {
        { -self };
    };

} // namespace core::ops::trait
