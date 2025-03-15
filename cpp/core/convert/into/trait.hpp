#pragma once

#include <concepts>
#include <utility>

namespace core::convert::trait {

    template <typename From, typename To>
    concept Into = requires (From &&from) {
        { static_cast<To>(std::forward<From>(from)) } noexcept -> std::same_as<To>;
    };

} // namespace core::convert::trait
