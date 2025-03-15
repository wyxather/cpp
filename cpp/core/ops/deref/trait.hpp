#pragma once

#include <type_traits>
#include <utility>

namespace core::ops::trait {

    template <typename T>
    concept DerefResult = (!std::is_void_v<T>);

    template <typename Self>
    concept Deref = requires (Self &&self) {
        { *std::forward<Self>(self) } noexcept -> DerefResult;
    };

} // namespace core::ops::trait
