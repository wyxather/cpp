#pragma once

#include "trait.hpp"

namespace core::ops {

    struct Not {
    public:
        template <typename Self>
        [[nodiscard]]
        constexpr auto not(this const Self &self) noexcept -> decltype(auto)
        requires trait::Not<decltype(self)>;

    protected:
        Not() = default;
        ~Not() = default;
    };

} // namespace core::ops
