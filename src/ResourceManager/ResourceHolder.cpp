#include "ResourceHolder.h"

ResourceHolder& ResourceHolder::get()
{
    static ResourceHolder holder;
    return holder;
}

ResourceHolder::ResourceHolder()
    : fonts("fonts", "ttf")
    , textures("txrs", "png")
    , soundBuffers("sfx", "ogg")
{
}
