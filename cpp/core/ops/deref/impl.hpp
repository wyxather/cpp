#pragma once

#include "def.hpp"
#include "trait.hpp"

namespace core::ops {

    template <typename Self>
    constexpr auto Deref::deref(this Self &&self) noexcept -> decltype(auto)
    requires trait::Deref<decltype(self)>
    {
        return *std::forward<Self>(self);
    }

} // namespace core::ops
