#ifndef MAP_H
#define MAP_H

#include <string>

class Map
{
private:
    std::string textureId;
    int scale;
    int tileSize;
    Entity *tileMap;

public:
    Map(std::string textureId, int scale, int tileSize);
    ~Map();
    void LoadMap(std::string filePath, int mapSizeX, int mapSizeY);
    void AddTile(int sourceX, int sourceY, int x, int y);
};

#endif
