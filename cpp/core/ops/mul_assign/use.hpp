#pragma once

#include "decl.hpp"

namespace core {

    template <typename Rhs = void>
    using MulAssign = ops::MulAssign<Rhs>;

} // namespace core
