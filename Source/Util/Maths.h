#pragma once

constexpr float PI = 3.14159265f;
constexpr float MIN_PI = 3.14f;

template <typename T>
T toRadians(T degrees)
{
    return degrees * PI / 180;
}

template <typename T>
T toDegrees(T radians)
{
    return (radians * 180) / PI;
}
