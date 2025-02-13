#pragma once

namespace core::ops::trait {

    template <typename Self>
    concept BitNot = requires (Self self) {
        { ~self };
    };

} // namespace core::ops::trait
