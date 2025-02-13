#pragma once

#include "trait.hpp"

namespace core::ops {

    struct BitNot {
    public:
        template <typename Self>
        [[nodiscard]]
        constexpr auto bit_not(this const Self &self) noexcept
        requires trait::BitNot<Self>;
    };

} // namespace core::ops
