#include "Animation.h"


Animation::Animation(unsigned frameSize)
:   FRAME_SIZE  (frameSize)
{ }

void Animation::addFrame(unsigned index, sf::Time delay)
{
    sf::IntRect bounds;
    bounds.top = 0;
    bounds.height = FRAME_SIZE;
    bounds.width  = FRAME_SIZE;
    bounds.left   = index * FRAME_SIZE;

    m_frames.emplace_back(bounds, delay);
}


const sf::IntRect& Animation::getFrame()
{
    if (m_timer.getElapsedTime() >= m_frames[m_framePointer].delay)
    {
        m_timer.restart();
        m_framePointer++;
        if (m_framePointer == m_frames.size())
            m_framePointer = 0;
    }

    return m_frames[m_framePointer].bounds;
}
