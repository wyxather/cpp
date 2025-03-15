#pragma once

#include "trait.hpp"

namespace core::ops {

    struct BitNot {
    public:
        template <typename Self>
        [[nodiscard]]
        constexpr auto bitnot(this const Self &self) noexcept -> decltype(auto)
        requires trait::BitNot<decltype(self)>;

    protected:
        BitNot() = default;
        ~BitNot() = default;
    };

} // namespace core::ops
