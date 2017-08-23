#ifndef RESOURCEHOLDER_H_INCLUDED
#define RESOURCEHOLDER_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "ResourceManager.h"
#include "../Util/NonCopyable.h"
#include "../Util/NonMoveable.h"

class ResourceHolder : public NonCopyable, public NonMovable
{
    public:
        static ResourceHolder& get();

        ResourceManager<sf::Font>           fonts;
        ResourceManager<sf::Texture>        textures;
        ResourceManager<sf::SoundBuffer>    soundBuffers;

    private:
        ResourceHolder();
};

#endif // RESOURCEHOLDER_H_INCLUDED
