#pragma once

#include <type_traits>

#include "core/convert/into/trait.hpp"
#include "def.hpp"
#include "trait.hpp"

namespace core::type {

    template <trait::Scalar T>
    Scalar(T) -> Scalar<T>;

    template <trait::Scalar T>
    template <typename U>
    constexpr Scalar<T>::Scalar(const U &value) noexcept
    requires convert::trait::Into<decltype(value), T>
        : value { static_cast<T>(value) } {}

    template <trait::Scalar T>
    constexpr Scalar<T>::operator T &() & noexcept {
        return value;
    }

    template <trait::Scalar T>
    constexpr Scalar<T>::operator const T &() const & noexcept {
        return value;
    }

    template <trait::Scalar T>
    constexpr Scalar<T>::operator T &&() && noexcept {
        return std::move(value);
    }

    template <trait::Scalar T>
    constexpr Scalar<T>::operator const T &&() const && noexcept {
        return std::move(value);
    }

} // namespace core::type

#include "core/cmp/eq/impl.hpp"
#include "core/convert/into/impl.hpp"
