#ifndef ANIMATION_H_INCLUDED
#define ANIMATION_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <vector>

/**
    Class for creating an animation.
    Use Animation::getFrame() with the .setTextureRect of SFML drawable objects to
    create the animation
*/
class Animation
{
    public:
        struct Frame
        {
            Frame(const sf::IntRect& bnds, sf::Time dly)
            :   bounds  (bnds)
            ,   delay   (dly) {}

            sf::IntRect bounds; //The area in a texture of the frame
            sf::Time    delay;  //Time delay to next frame
        };

        Animation(unsigned frameSize);

        void addFrame(unsigned index, sf::Time delay);

        const sf::IntRect& getFrame();

    private:
        sf::Clock m_timer;              //Timer for progressing the animation

        std::vector<Frame> m_frames;    //List of animation frames

        unsigned m_framePointer = 0;    //The index of the current active frame
        const unsigned FRAME_SIZE;      //Size of frame in pixels height/width

};

#endif // ANIMATION_H_INCLUDED
