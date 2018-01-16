#include "FPSCounter.h"

#include "../ResourceManager/ResourceHolder.h"

#include <iostream>

FPSCounter::FPSCounter()
{
    m_text.move(10, 10);
    m_text.setOutlineColor (sf::Color::Black);
    m_text.setFillColor({255,255,255});
    m_text.setOutlineThickness  (2);
    m_text.setFont(ResourceHolder::get().fonts.get("arial"));
    m_text.setCharacterSize(25);
}

//updates the FPS variable
void FPSCounter::update()
{
    m_frameCount++;

    if (m_delayTimer.getElapsedTime().asSeconds() > 0.2) {
        m_fps = m_frameCount / m_fpsTimer.restart().asSeconds();
        m_frameCount = 0;
        m_delayTimer.restart();
    }
}

//Draws the FPS display to the window
void FPSCounter::draw(sf::RenderTarget& renderer)
{
    m_text.setString("FPS: " + std::to_string((int)m_fps));
    renderer.draw(m_text);
}
