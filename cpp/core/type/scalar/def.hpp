#pragma once

#include "core/cmp/eq/def.hpp"
#include "core/convert/as/def.hpp"
#include "core/convert/into/def.hpp"
#include "core/convert/into/trait.hpp"
#include "trait.hpp"

namespace core::type {

    template <trait::Scalar T>
    struct __declspec(empty_bases) Scalar: cmp::Eq, convert::Into<>, convert::As<> {
    public:
        Scalar() = default;

        template <typename U>
        requires convert::trait::Into<U, T>
        constexpr Scalar(const U &value) noexcept;

        [[nodiscard]]
        constexpr explicit operator T &() & noexcept;

        [[nodiscard]]
        constexpr explicit operator const T &() const & noexcept;

        [[nodiscard]]
        constexpr explicit operator T &&() && noexcept;

        [[nodiscard]]
        constexpr explicit operator const T &&() const && noexcept;

    protected:
        T value {};
    };

} // namespace core::type
