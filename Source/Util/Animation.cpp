#include "Animation.h"


Animation::Animation(const std::initializer_list<Animation::Frame>& frames)
:   m_frames {frames}
{ }

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
