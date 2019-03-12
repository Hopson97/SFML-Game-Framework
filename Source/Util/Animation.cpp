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
  //Get the elapsed time since last getFrame() call
  //+ add the overlappedTime left from the previous getFrame() call
  sf::Time totalElapsed = m_timer.getElapsedTime() + m_overlappedTime;

  //Run while the elapsed time is greater than the current frames delay.
  //This means that we may skip one or more frames if the elapsed time is 
  //greater than the total delay of the skipped frames.
  //
  //(Previously we just incremented the framePoiner once if the elapsed time 
  // was greater than the first frames delay time)
  while( totalElapsed >= m_frames[m_framePointer].delay )
  {
    //Subtract the frames delay time from the totalElapsed time
    totalElapsed -= m_frames[m_framePointer].delay;

    //Increment framepointer
    m_framePointer++;

    //Reset framepointer if it reaches end of vector
    if(m_framePointer == m_frames.size())
      m_framePointer = 0;

  }

  //Restart timer
  m_timer.restart();

  //Save overlapped time 
  //(ie. what is left of 'totalElapsed' after subtracting all the frame delays)
  m_overlappedTime = totalElapsed;


  //Return the frame at the framepointer we ended up at
  return m_frames[m_framePointer].bounds;
}
