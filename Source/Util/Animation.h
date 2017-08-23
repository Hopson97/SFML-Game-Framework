#ifndef ANIMATION_H_INCLUDED
#define ANIMATION_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <vector>

class Animation
{
    public:
        struct Frame
        {
            sf::IntRect bounds;
            sf::Time    delay;
        };

        Animation() = default;
        Animation(const std::initializer_list<Animation::Frame>& frames);

        const sf::IntRect& getFrame();

    private:
        sf::Clock m_timer;

        std::vector<Frame> m_frames;

        unsigned m_framePointer = 0;

};

#endif // ANIMATION_H_INCLUDED
