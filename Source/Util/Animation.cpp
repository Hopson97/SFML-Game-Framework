#include "Animation.h"


Animation::Animation(unsigned frameWidth, unsigned frameHeight)
: FRAME_WIDTH   (frameWidth)
, FRAME_HEIGHT (frameHeight)
{ }

//Adds a frame...
void Animation::addFrame(unsigned index, sf::Time delay)
{
    sf::IntRect bounds;
    bounds.top = 0;
    bounds.height = FRAME_HEIGHT;
    bounds.width  = FRAME_WIDTH;
    bounds.left   = index * FRAME_WIDTH;

    m_frames.emplace_back(bounds, delay);
}

//Returns the current/active frame of the animation
const sf::IntRect& Animation::getFrame()
{
    if (m_timer.getElapsedTime() >= m_frames[m_framePointer].delay) {
        m_timer.restart();
        m_framePointer++;
        if (m_framePointer == m_frames.size())
            m_framePointer = 0;
    }

    return m_frames[m_framePointer].bounds;
}
