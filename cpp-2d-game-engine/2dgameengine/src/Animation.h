#ifndef ANIMATION_H
#define ANIMATION_H
class Animation
{
public:
    unsigned int index;
    unsigned int numFrames;
    float animationSpeed;

public:
    Animation();
    Animation(unsigned int index, unsigned int numFrames, float animationSpeed);
};
#endif