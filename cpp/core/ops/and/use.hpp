#pragma once

#include "decl.hpp"

namespace core {

    template <typename Rhs = void>
    using And = ops::And<Rhs>;

} // namespace core
