#pragma once

#include <concepts>

namespace core::convert::trait {

    template <typename From, typename To>
    concept Into = std::constructible_from<To, From>;

} // namespace core::convert::trait
