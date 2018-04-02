#pragma once

/**
    Anything that inherits from this is non-copyable
*/
struct NonCopyable
{
    NonCopyable() = default;
    NonCopyable& operator = (const NonCopyable&) = delete;
    NonCopyable(const NonCopyable&) = delete;
};
