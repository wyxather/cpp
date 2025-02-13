#pragma once

#include "trait.hpp"

namespace core::ops {

    struct Neg {
    public:
        template <typename Self>
        [[nodiscard]]
        constexpr auto neg(this const Self &self) noexcept
        requires trait::Neg<Self>;
    };

} // namespace core::ops
