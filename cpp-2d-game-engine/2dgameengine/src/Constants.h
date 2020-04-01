#ifndef CONSTANTS_H
#define CONSTANTS_H

const unsigned int WINDOW_WIDTH = 800;
const unsigned int WINDOW_HEIGHT = 600;

const unsigned int FPS = 60;
const unsigned int FRAME_TARGET_TIME = 1000 / FPS;

enum LayerType
{
    DEFAULT = 0,
    TILEMAP_LAYER = 1,
    VEGETATION_LAYER = 2,
    ENEMY_LAYER = 3,
    PLAYER_LAYER = 4,
    PROJECTILE_LAYER = 5,
    UI_LAYER = 6
};

const unsigned int NUM_LAYERS = 7;

#endif