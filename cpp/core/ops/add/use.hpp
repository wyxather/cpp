#pragma once

#include "decl.hpp"

namespace core {

    template <typename Rhs = void>
    using Add = ops::Add<Rhs>;

} // namespace core
