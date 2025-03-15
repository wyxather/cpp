#pragma once

#include "def.hpp"
#include "trait.hpp"

namespace core::ops {

    template <typename Idx>
    template <typename Self>
    constexpr auto Index<Idx>::index(this Self &&self, const Idx &index) noexcept -> decltype(auto)
    requires trait::Index<decltype(self), decltype(index)>
    {
        return std::forward<Self>(self)[index];
    }

} // namespace core::ops
