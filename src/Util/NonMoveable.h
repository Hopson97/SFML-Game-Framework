#pragma once

struct NonMovable {
    NonMovable() = default;
    NonMovable& operator=(NonCopyable&&) = delete;
    NonMovable(NonCopyable&&) = delete;
};