#ifndef NONCOPYABLE_H_INCLUDED
#define NONCOPYABLE_H_INCLUDED

struct NonCopyable
{
    NonCopyable() = default;
    NonCopyable& operator = (const NonCopyable&) = delete;
    NonCopyable(const NonCopyable&) = delete;
};

#endif // NONCOPYABLE_H_INCLUDED
