#pragma once

#include "trait.hpp"

namespace core::ops {

    struct Neg {
    public:
        template <typename Self>
        [[nodiscard]]
        constexpr auto neg(this const Self &self) noexcept -> decltype(auto)
        requires trait::Neg<decltype(self)>;

    protected:
        Neg() = default;
        ~Neg() = default;
    };

} // namespace core::ops
