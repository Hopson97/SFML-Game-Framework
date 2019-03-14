#pragma once

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
        //ResourceManager<sf::SoundBuffer>    soundBuffers; //Commented out because of Linux(possibly) error in sfml 2.5.0 with a std::pair error

    private:
        ResourceHolder();
};
