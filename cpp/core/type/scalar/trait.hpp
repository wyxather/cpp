#pragma once

#include <type_traits>

namespace core::type::trait {

    template <typename T>
    concept Scalar = std::is_scalar_v<T>;

} // namespace core::type::trait
