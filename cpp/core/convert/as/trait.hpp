#pragma once

#include <concepts>
#include <utility>

namespace core::convert::trait {

    template <typename Self, typename Other>
    concept As = requires (Self &&self) {
        { reinterpret_cast<Other>(std::forward<Self>(self)) } noexcept -> std::same_as<Other>;
    };

} // namespace core::convert::trait
