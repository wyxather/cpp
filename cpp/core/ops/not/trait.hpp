#pragma once

#include <utility>

namespace core::ops::trait {

    template <typename Self>
    concept Not = requires (Self &&self) {
        { !std::forward<Self>(self) } noexcept;
    };

} // namespace core::ops::trait
