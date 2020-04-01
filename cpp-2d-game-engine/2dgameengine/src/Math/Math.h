#ifndef MATH_H
#define MATH_H

template <class T>
static float clamp(const T &v, const T &lo, const T &hi)
{
    return (v < lo) ? lo : (hi < v) ? hi : v;
}

#endif
