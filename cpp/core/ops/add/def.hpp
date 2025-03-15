#pragma once

#include <type_traits>

#include "trait.hpp"

namespace core::ops {

    template <typename Rhs = void>
    struct Add {
    public:
        template <
            typename Self,
            typename Other = std::conditional_t<std::is_void_v<Rhs>, Self, Rhs>>
        [[nodiscard]]
        constexpr auto add(this const Self &self, const Other &other) noexcept -> decltype(auto)
        requires trait::Add<decltype(self), decltype(other)>;

    protected:
        Add() = default;
        ~Add() = default;
    };

} // namespace core::ops
