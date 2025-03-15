#pragma once

#include "decl.hpp"

namespace core {

    template <typename Rhs = void>
    using ShlAssign = ops::ShlAssign<Rhs>;

} // namespace core
