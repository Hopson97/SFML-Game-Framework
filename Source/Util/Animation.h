#ifndef ANIMATION_H_INCLUDED
#define ANIMATION_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <vector>

class Animation
{
    public:
        struct Frame
        {
            Frame(const sf::IntRect& bnds, sf::Time dly)
            :   bounds  (bnds)
            ,   delay   (dly) {}

            sf::IntRect bounds;
            sf::Time    delay;
        };

        Animation(unsigned frameSize);

        void addFrame(unsigned index, sf::Time delay);

        const sf::IntRect& getFrame();

    private:
        sf::Clock m_timer;

        std::vector<Frame> m_frames;

        unsigned m_framePointer = 0;
        const unsigned FRAME_SIZE;

};

#endif // ANIMATION_H_INCLUDED
