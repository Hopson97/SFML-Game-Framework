#include "StatePlaying.h"

#include "../ResourceManager/ResourceHolder.h"
#include "../Util/Animation.h"

Animation anim;
sf::RectangleShape m_rect;

StatePlaying::StatePlaying(Game& game)
:   StateBase   (game)
{
    m_rect.setSize({64, 256});
    m_rect.setTexture(&ResourceHolder::get().textures.get("test"));

    Animation anim()
}

void StatePlaying::handleEvent(sf::Event e)
{

}

void StatePlaying::handleInput()
{

}

void StatePlaying::update(sf::Time deltaTime)
{

}

void StatePlaying::fixedUpdate(sf::Time deltaTime)
{

}

void StatePlaying::render(sf::RenderTarget& renderer)
{

}
