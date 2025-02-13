#pragma once

#include "trait.hpp"

namespace core::ops {

    struct LogNot {
    public:
        template <typename Self>
        [[nodiscard]]
        constexpr auto log_not(this const Self &self) noexcept
        requires trait::LogNot<Self>;
    };

} // namespace core::ops
