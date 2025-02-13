#pragma once

#include "decl.hpp"

namespace core {

    template <typename Rhs = void>
    using AddAssign = ops::AddAssign<Rhs>;

} // namespace core
