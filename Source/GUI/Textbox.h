#pragma once

#include <functional>

#include "Widget.h"

namespace gui
{
    /**
        Represents an area of the screen that can be typed onto
    */
    class TextBox : public gui::Widget
    {
        public:
            TextBox(std::string& modString);

            void setLabel       (const std::string& str);
            void setTexture     (const sf::Texture& tex);

            void handleEvent    (sf::Event e, const sf::RenderWindow& window) override;
            void render         (sf::RenderTarget& renderer)    override;
            void setPosition    (const sf::Vector2f& pos)       override;
            sf::Vector2f getSize() const                        override;

        private:
            void handleClick    (sf::Event e, const sf::RenderWindow& window);
            void handleTextInput(sf::Event e);

            bool isValidCharacter   (unsigned char keyCode);
            bool isBackspace        (unsigned char keycode);

            sf::Vector2f    m_position;

            Rectangle       m_rect;
            Text            m_text;
            Text            m_label;
            std::string*    m_pModString;

            bool m_isActive = false;

    };
}
