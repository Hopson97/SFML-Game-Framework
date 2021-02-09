#pragma once

#include <SFML/Graphics.hpp>

class FPSCounter {
  public:
    FPSCounter();

    void update();

    void draw(sf::RenderTarget& renderer);

  private:
    sf::Text m_text;
    sf::Font m_font;

    sf::Clock m_delayTimer;
    sf::Clock m_fpsTimer;

    float m_fps = 0;

    int m_frameCount = 0;
};