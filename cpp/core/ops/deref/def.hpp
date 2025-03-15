#pragma once

#include "trait.hpp"

namespace core::ops {

    struct Deref {
    public:
        template <typename Self>
        [[nodiscard]]
        constexpr auto deref(this Self &&self) noexcept -> decltype(auto)
        requires trait::Deref<decltype(self)>;

    protected:
        Deref() = default;
        ~Deref() = default;
    };

} // namespace core::ops
