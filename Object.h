#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED
#include "Structs.h"
#include "Sprite.h"

class Object: public Sprite
{
    Point center;
public:
    Object(SDL_Renderer *renderer, const char* path, SDL_Rect src_rect, Point cen)
        :Sprite(renderer, path, src_rect), center(cen){}
    virtual ~Object(){}
    virtual void update(SDL_Event ev){}
    virtual void draw(SDL_Renderer *renderer, Vector offset){}
    Point getCenter(){return center;}
};


class Tile: public Object
{
public:
    Tile(SDL_Renderer *renderer, const char* path, SDL_Rect src_rect, Point cen):
        Object(renderer, path, src_rect, cen){}
    ~Tile(){SDL_Log("tile destructor");}
    void draw(SDL_Renderer *renderer, Vector offset);
    void update(SDL_Event ev){}
};


class Entity: public Object
{

};


class Player: public Object
{

};

#endif // OBJECT_H_INCLUDED
