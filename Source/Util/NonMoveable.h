#pragma once

/**
    Anything that inherits from this is non-moveable
*/
struct NonMovable
{
    NonMovable() = default;
    NonMovable& operator = (NonCopyable&&) = delete;
    NonMovable(NonCopyable&&) = delete;
};