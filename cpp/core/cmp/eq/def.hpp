#pragma once

#include "core/cmp/partial_eq/def.hpp"

namespace core::cmp {

    struct Eq: PartialEq<> {
    protected:
        Eq() = default;
        ~Eq() = default;
    };

} // namespace core::cmp
