#pragma once

#include <type_traits>

namespace core::convert::trait {

    template <typename Self, typename Other>
    concept As = requires (Self &&self) {
        { reinterpret_cast<Other>(std::forward<Self>(self)) };
    };

} // namespace core::convert::trait
