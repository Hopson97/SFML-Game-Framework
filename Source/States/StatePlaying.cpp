#include "StatePlaying.h"

#include "../ResourceManager/ResourceHolder.h"
#include "../Util/Animation.h"

Animation anim(32);
sf::RectangleShape m_rect;

StatePlaying::StatePlaying(Game& game)
:   StateBase   (game)
{
    m_rect.setSize({256, 256});
    m_rect.setTexture(&ResourceHolder::get().textures.get("test"));

    sf::Time delay = sf::seconds(0.2);
    anim.addFrame(0, delay);
    anim.addFrame(1, delay);
    anim.addFrame(2, delay);
    anim.addFrame(3, delay);
    anim.addFrame(2, delay);
    anim.addFrame(1, delay);
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
    m_rect.setTextureRect(anim.getFrame());
    renderer.draw(m_rect);
}
