#include "StackMenu.h"

#include "../ResourceManager/ResourceHolder.h"

namespace gui
{

StackMenu::StackMenu(const sf::Vector2f& origin)
:   m_origin    (origin)
{
    m_background.setTexture(&ResourceHolder::get().textures.get("guibg"));
}

void StackMenu::handleEvents(sf::Event e)
{
    for (auto& widget : m_widgets)
    {
        widget->handleEvent(e);
    }
}

void StackMenu::render(sf::RenderTarget& renderer)
{
    renderer.draw(m_background);
    for (auto& widget : m_widgets)
    {
        widget->render(renderer);
    }
}

}
