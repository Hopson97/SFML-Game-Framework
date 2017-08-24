#include "StackMenu.h"

#include "../ResourceManager/ResourceHolder.h"

namespace gui
{

StackMenu::StackMenu(const sf::RenderWindow& window)
:   m_basePosition  (window.getSize().x / 2, 100)
,   m_baseSize      (300, 20)
{
    m_background.setFillColor({100, 100, 100, 128});
    m_background.setSize(m_baseSize);
    m_background.setPosition(m_basePosition.x - m_baseSize.x / 2, 185);
}

void StackMenu::addWidget(std::unique_ptr<Widget> w)
{
    initWidget(*w);
    m_widgets.push_back(std::move(w));
}

void StackMenu::initWidget(Widget& widget)
{
    widget.setPosition({m_basePosition.x - widget.getSize().x / 2,
                       m_basePosition.y});


    m_basePosition.y    += widget.getSize().y + 25;
    m_baseSize.y        += widget.getSize().y + 25;
    m_background.setSize(m_baseSize);
}

void StackMenu::handleEvents(sf::Event e, const sf::RenderWindow& window)
{
    for (auto& widget : m_widgets)
    {
        widget->handleEvent(e, window);
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
