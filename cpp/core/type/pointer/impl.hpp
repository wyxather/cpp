#pragma once

#include <cstddef>
#include <type_traits>

#include "def.hpp"
#include "trait.hpp"

namespace core::type {

    template <trait::Pointer T>
    Pointer(T) -> Pointer<std::remove_pointer_t<T>>;

    template <typename T>
    requires (!std::is_reference_v<T>)
    constexpr auto Pointer<T>::operator*() const noexcept -> auto & {
        return *this->value;
    }

    template <typename T>
    requires (!std::is_reference_v<T>)
    constexpr auto Pointer<T>::operator*() const noexcept
    requires trait::Pointer<T>
    {
        return Pointer<std::remove_pointer_t<T>> { *this->value };
    }

    template <typename T>
    requires (!std::is_reference_v<T>)
    constexpr auto Pointer<T>::operator+(const std::uintptr_t count) const noexcept {
        return Pointer { this->value + count };
    }

    template <typename T>
    requires (!std::is_reference_v<T>)
    constexpr auto Pointer<T>::operator-(const std::uintptr_t count) const noexcept {
        return Pointer { this->value - count };
    }

    template <typename T>
    requires (!std::is_reference_v<T>)
    template <typename Self>
    constexpr auto Pointer<T>::operator+=(this Self &&self, const std::uintptr_t count) noexcept
        -> auto && {
        self.value += count;
        return std::forward<Self>(self);
    }

    template <typename T>
    requires (!std::is_reference_v<T>)
    template <typename Self>
    constexpr auto Pointer<T>::operator-=(this Self &&self, const std::uintptr_t count) noexcept
        -> auto && {
        self.value -= count;
        return std::forward<Self>(self);
    }

    template <typename T>
    requires (!std::is_reference_v<T>)
    constexpr auto Pointer<T>::byte_add(const std::uintptr_t count) const noexcept {
        return this->template as<const Pointer<std::byte>>().add(count).template as<Pointer>();
    }

    template <typename T>
    requires (!std::is_reference_v<T>)
    constexpr auto Pointer<T>::byte_sub(const std::uintptr_t count) const noexcept {
        return this->template as<const Pointer<std::byte>>().sub(count).template as<Pointer>();
    }

    template <typename T>
    requires (!std::is_reference_v<T>)
    template <typename Self>
    constexpr auto Pointer<T>::byte_add_assign(
        this Self &&self,
        const std::uintptr_t count
    ) noexcept -> auto && {
        return std::forward<Self>(self)
            .template as<Pointer<std::byte>>()
            .add_assign(count)
            .template as<Pointer>();
    }

    template <typename T>
    requires (!std::is_reference_v<T>)
    template <typename Self>
    constexpr auto Pointer<T>::byte_sub_assign(
        this Self &&self,
        const std::uintptr_t count
    ) noexcept -> auto && {
        return std::forward<Self>(self)
            .template as<Pointer<std::byte>>()
            .sub_assign(count)
            .template as<Pointer>();
    }

} // namespace core::type

#include "core/convert/as/impl.hpp"
#include "core/ops/add/impl.hpp"
#include "core/ops/add_assign/impl.hpp"
#include "core/ops/deref/impl.hpp"
#include "core/ops/sub/impl.hpp"
#include "core/ops/sub_assign/impl.hpp"
#include "core/type/scalar/impl.hpp"
