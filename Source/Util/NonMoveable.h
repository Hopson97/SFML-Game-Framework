#ifndef NONMOVEABLE_H_INCLUDED
#define NONMOVEABLE_H_INCLUDED

struct NonMovable
{
    NonMovable() = default;
    NonMovable& operator = (NonCopyable&&) = delete;
    NonMovable(NonCopyable&&) = delete;
};

#endif // NONMOVEABLE_H_INCLUDED
