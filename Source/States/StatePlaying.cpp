#include "StatePlaying.h"

#include "../GUI/Button.h"
#include "../GUI/Textbox.h"
#include "../Game.h"

#include <iostream>

std::string test;

StatePlaying::StatePlaying(Game& game)
:   StateBase   (game)
,   m_TestMenu  (game.getWindow())
{/*
    gui::StackMenu testTab();
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


    testTab.addWidget(std::move(b));
    testTab.addWidget(std::move(b2));

    m_TestMenu.addTab("Tab One", std::move(testTab));

    auto textBox = std::make_unique<gui::TextBox>(test);
    textBox->setLabel("TestBox");

    m_TestMenu.addWidget(std::move(textBox));*/
}

void StatePlaying::handleEvent(sf::Event e)
{
    m_TestMenu.handleEvent(e, m_pGame->getWindow());
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
    m_TestMenu.render(renderer);
}
