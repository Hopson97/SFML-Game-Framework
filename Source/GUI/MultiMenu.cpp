#include "MultiMenu.h"

constexpr int BASEY = 95;

namespace gui {

MultiMenu::MultiMenu(const sf::RenderWindow& window)
:   m_basePosition  (window.getSize().x / 2, BASEY)
,   m_baseSize      (605, 20)
{
    m_background.setFillColor({100, 100, 100, 128});
    m_background.setSize(m_baseSize);
    m_background.setPosition(m_basePosition.x - m_baseSize.x / 2, BASEY - 30);
}

void MultiMenu::addWidget(unsigned tab, std::unique_ptr<Widget> w)
{
    m_tabs.at(tab).second.addWidget(std::move(w));
}


void MultiMenu::addTab(const std::string& buttonText)
{
    Button b(ButtonSize::Small);
    b.setText(buttonText);
    b.setFunction([&]() {
        m_activeTab = m_tabs.size();
    });
    b.setPosition({m_background.getPosition().x + 5,
                  BASEY + 10 + m_tabs.size() * b.getSize().y});

    StackMenu m({m_background.getPosition().x + b.getSize().x + 10,
                BASEY + 10});

    m_tabs.push_back(std::make_pair(std::move(b), std::move(m)));
}

void MultiMenu::handleEvent(sf::Event e, const sf::RenderWindow& window)
{
    if (m_tabs.empty())
        return;

    m_tabs[m_activeTab].second.handleEvent(e, window);
    for (auto& tab : m_tabs)
    {
        tab.first.handleEvent(e, window);
    }
}

void MultiMenu::render(sf::RenderTarget& renderer)
{
    renderer.draw(m_background);
    if (m_tabs.empty())
        return;

    m_tabs[m_activeTab].second.render(renderer);
    for (auto& tab : m_tabs)
    {
        tab.first.render(renderer);
    }
}

}
