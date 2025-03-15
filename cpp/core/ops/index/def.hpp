#pragma once

#include <type_traits>

#include "trait.hpp"

namespace core::ops {

    template <typename Idx = int>
    struct Index {
    public:
        template <typename Self>
        [[nodiscard]]
        constexpr auto index(this Self &&self, const Idx &index) noexcept -> decltype(auto)
        requires trait::Index<decltype(self), decltype(index)>;

    protected:
        Index() = default;
        ~Index() = default;
    };

} // namespace core::ops
