#ifndef SPRITE_H
#define SPRITE_H
#include <SDL.h>
#include "math.h"
#include "Structs.h"


class Sprite
{
    SDL_Texture *texture;
    SDL_Surface *surface;
    SDL_Rect src_rect;
    public:
        Sprite(SDL_Renderer *renderer, const char* path, SDL_Rect src_rect);
        virtual ~Sprite();
        int getWidth();
        int getHeight();
        SDL_Rect* getSrcRect();
        SDL_Texture* getTexture();
};



#endif // SPRITE_H
