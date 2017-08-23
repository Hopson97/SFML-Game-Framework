#include "StatePlaying.h"

#include "../GUI/Button.h"
#include "../GUI/StackMenu.h"
#include "../Game.h"

#include <iostream>

gui::StackMenu menu({1280 / 2,
                     200});


StatePlaying::StatePlaying(Game& game)
:   StateBase   (game)
{
    auto b = std::make_unique<gui::Button>();
    b->setText("Button 1");
    b->setFunction([]()
    {
        std::cout << "Button 1 clicked!" << '\n';
    });

    auto b2 = std::make_unique<gui::Button>();
    b2->setText("Button 2");
    b2->setFunction([]()
    {
        std::cout << "Button 2 clicked!" << '\n';
    });

    menu.addWidget(std::move(b));
    menu.addWidget(std::move(b2));
}

void StatePlaying::handleEvent(sf::Event e)
{
    menu.handleEvents(e, m_pGame->getWindow());
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
    menu.render(renderer);
}
