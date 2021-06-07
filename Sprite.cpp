#include "Sprite.h"
#include <SDL_image.h>

Sprite::Sprite(SDL_Renderer *renderer, const char* path, SDL_Rect src_rect) : src_rect(src_rect)
{
    surface = IMG_Load(path);
    if(surface == NULL)
        throw path;
    SDL_SetColorKey(surface,SDL_TRUE,SDL_MapRGB(surface->format,255,0,255));
    texture = SDL_CreateTextureFromSurface(renderer,surface);
    if(texture == NULL)
        throw path;
}

Sprite::~Sprite()
{
    SDL_Log("Sprite_destructor");
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}

int Sprite::getWidth()
{
    return src_rect.w;
}

int Sprite::getHeight()
{
    return src_rect.h;
}

SDL_Rect* Sprite::getSrcRect()
{
    return &src_rect;
}

SDL_Texture* Sprite::getTexture()
{
    return texture;
}








