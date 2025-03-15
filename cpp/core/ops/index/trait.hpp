#pragma once

#include <utility>

namespace core::ops::trait {

    template <typename Self, typename Idx>
    concept Index = requires (Self &&self, Idx &&index) {
        { std::forward<Self>(self)[std::forward<Idx>(index)] } noexcept;
    };

} // namespace core::ops::trait
