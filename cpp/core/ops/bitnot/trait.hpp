#pragma once

#include <utility>

namespace core::ops::trait {

    template <typename Self>
    concept BitNot = requires (Self &&self) {
        { ~std::forward<Self>(self) } noexcept;
    };

} // namespace core::ops::trait
