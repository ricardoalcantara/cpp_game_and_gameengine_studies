#include "Animation.h"

Animation::Animation()
{
}

Animation::Animation(unsigned int index, unsigned int numFrames, float animationSpeed)
{
    this->index = index;
    this->numFrames = numFrames;
    this->animationSpeed = animationSpeed;
}
