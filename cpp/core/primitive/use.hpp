#pragma once

#include <vadefs.h>

#include <cmath>
#include <cstdint>

#include "core/type/character/decl.hpp"
#include "core/type/floating_point/decl.hpp"
#include "core/type/integral/decl.hpp"

namespace core {

    using Float = type::FloatingPoint<std::float_t>;
    using Double = type::FloatingPoint<std::double_t>;

    using Int8 = type::Integral<std::int8_t>;
    using Int16 = type::Integral<std::int16_t>;
    using Int32 = type::Integral<std::int32_t>;
    using Int64 = type::Integral<std::int64_t>;
    using IntPtr = type::Integral<std::intptr_t>;

    using PtrDiff = type::Integral<std::ptrdiff_t>;

    using UInt8 = type::Integral<std::uint8_t>;
    using UInt16 = type::Integral<std::uint16_t>;
    using UInt32 = type::Integral<std::uint32_t>;
    using UInt64 = type::Integral<std::uint64_t>;
    using UIntPtr = type::Integral<std::uintptr_t>;

    using Size = type::Integral<std::size_t>;

    using Char = type::Character<char>;
    using Char8 = type::Character<char8_t>;
    using Char16 = type::Character<char16_t>;
    using Char32 = type::Character<char32_t>;
    using UChar = type::Character<unsigned char>;
    using WChar = type::Character<wchar_t>;

} // namespace core
