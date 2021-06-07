#ifndef CHUNK_H_INCLUDED
#define CHUNK_H_INCLUDED
#include <SDL.h>
#include "ObjectList.h"


class Chunk
{
    ObjectList *first;
    Point center;
public:
    Chunk(SDL_Renderer *renderer, double x, double z);
    ~Chunk();
    void draw(SDL_Renderer *renderer, Vector offset);
    void update(SDL_Event ev);
    Point getCenter(){return center;}
};

#endif // CHUNK_H_INCLUDED
