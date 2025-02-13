#pragma once

namespace core::ops::trait {

    template <typename Self>
    concept LogNot = requires (Self self) {
        { !self };
    };

} // namespace core::ops::trait
