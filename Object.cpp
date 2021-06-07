#include "Object.h"

void Tile::draw(SDL_Renderer *renderer, Vector offset)
{
    Point off_center = getCenter()+offset;
    int X,Y;
    off_center.get2dCords(X,Y);
    SDL_Rect off_rect = {X,Y,getWidth(),getHeight()};
    SDL_RenderCopy(renderer,getTexture(),getSrcRect(),&off_rect);
}
