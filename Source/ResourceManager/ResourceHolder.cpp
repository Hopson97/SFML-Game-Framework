#include "ResourceHolder.h"

ResourceHolder& ResourceHolder::get()
{
    static ResourceHolder holder;
    return holder;
}

ResourceHolder::ResourceHolder()
:   fonts           ("fonts", "ttf")
,   textures        ("txrs", "png")
//,   soundBuffers    ("sfx", "ogg") Commented because of a linux error on SFML 2.5.0
{

}
