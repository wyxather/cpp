#pragma once

#include "decl.hpp"

namespace core {

    template <typename Rhs = void>
    using ShrAssign = ops::ShrAssign<Rhs>;

} // namespace core
