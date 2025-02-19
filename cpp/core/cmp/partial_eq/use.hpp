#pragma once

#include "decl.hpp"

namespace core {

    template <typename Rhs = void>
    using PartialEq = cmp::PartialEq<Rhs>;

} // namespace core
