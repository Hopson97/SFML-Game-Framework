#include "Textbox.h"


namespace gui {

TextBox::TextBox(std::string& modString)
:   m_pModString (&modString)
{
    m_label.setCharacterSize(15);
    m_rect.setFillColor({52, 152, 219});
    m_rect.setSize({256, 64});
}

void TextBox::setLabel(const std::string& str)
{
    m_label.setString(str);
}

void TextBox::handleEvent(sf::Event e, const sf::RenderWindow& window)
{
    handleClick     (e, window);
    handleTextInput (e);
}

void TextBox::render(sf::RenderTarget& renderer)
{
    if (!m_isActive) {
        m_rect.setFillColor({52, 152, 219});
    }
    else {
        m_rect.setFillColor({82, 132, 239});
    }
    renderer.draw(m_rect);
    renderer.draw(m_label);
    renderer.draw(m_text);
}

void TextBox::setPosition(const sf::Vector2f& pos)
{
    m_position = pos;

    m_rect.setPosition(m_position);
    m_label.setPosition(m_position.x,
                        m_position.y + m_label.getGlobalBounds().height -
                                       m_rect.getGlobalBounds().height / 2);
    m_text.setPosition  (m_position);
    m_text.move(5, m_rect.getGlobalBounds().height / 2.5);
}

sf::Vector2f TextBox::getSize() const
{
    return  {m_rect.getSize().x,
             m_rect.getSize().y + m_label.getGlobalBounds().height};
}

void TextBox::handleClick (sf::Event e, const sf::RenderWindow& window)
{
    auto pos = sf::Mouse::getPosition(window);

    if (m_rect.getGlobalBounds().contains(pos.x, pos.y))
    {
        if (e.type == sf::Event::MouseButtonPressed)
        {
            if (e.mouseButton.button == sf::Mouse::Left)
            {
                m_isActive = true;
            }
        }
    }
    else
    {
        if (e.type == sf::Event::MouseButtonPressed)
        {
            if (e.mouseButton.button == sf::Mouse::Left)
            {
                m_isActive = false;
            }
        }
    }
}

void TextBox::handleTextInput (sf::Event e)
{
    switch(e.type) {
        case sf::Event::TextEntered:
            if (m_isActive) {
                //Get the key that was entered
                unsigned char keyCode = e.text.unicode;

                if (isValidCharacter(keyCode)) {
                    m_pModString->push_back(keyCode);
                }
                else if (isBackspace(keyCode)) {
                    //prevents popping back an empty string
                    if (m_pModString->length() > 0)
                        m_pModString->pop_back();
                }
                m_text.setString(*m_pModString);
            }
            break;

        default:
            break;
    }


    if (e.type == sf::Event::TextEntered && m_isActive)
    {
        //Get the key that was entered
        unsigned char keyCode = e.text.unicode;

        //Test if it within the "Type-able keys eg aA to zZ and 0 to 9
        if (isValidCharacter(keyCode))
        {
            m_pModString->push_back(keyCode);
        }
        else if (isBackspace(keyCode))
        {
            //prevents popping back an empty string
            if (m_pModString->length() > 0)
                m_pModString->pop_back();
        }
        m_text.setString(*m_pModString);
    }
}

 //return true if the character is within the valid keys eg aA to zZ and 0 to 9
bool TextBox::isValidCharacter(unsigned char keyCode)
{
    return  keyCode >= 32 &&
            keyCode <= 127;
}

bool TextBox::isBackspace(unsigned char keycode)
{
    return keycode == 8;
}


}
