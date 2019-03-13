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
  //Add the elapsed time since last getFrame() call to m_overlappedTime
  m_overlappedTime += m_timer.getElapsedTime();

  //Run while the m_overlappedTime is greater than the current frames delay.
  //This means that we may skip one or more frames if the m_overlappedTime is 
  //greater than the total delay of the skipped frames.
  //
  //(Previously we just incremented the framePoiner once if the elapsed time 
  // was greater than the first frames delay time)
  while( m_overlappedTime >= m_frames[m_framePointer].delay )
  {
    //Subtract the frames delay time from the totalElapsed time
    m_overlappedTime -= m_frames[m_framePointer].delay;

    //Increment framepointer
    m_framePointer++;
  }

  //Restart timer
  m_timer.restart();

  return m_frames[ m_framePointer % m_frames.size() ].bounds;
}
