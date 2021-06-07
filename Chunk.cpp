#include "Chunk.h"

Chunk::Chunk(SDL_Renderer *renderer, double x, double z)
{
    SDL_Rect src_rect = {0,0,64,64};
    Point p = {32*(x+1),10,32*(z+1)};
    p.printPoint();
    first = new ObjectList(new Tile(renderer, "tile.png", src_rect, p));
    center = p;
}

Chunk::~Chunk()
{
    ObjectList *temp = first;
    while(temp->next != nullptr)
    {
        ObjectList *temp2 = temp->next;
        delete temp;
        temp = temp2;
    }
    delete temp;
}

void Chunk::draw(SDL_Renderer *renderer, Vector offset)
{
    for(ObjectList *temp = first; temp != nullptr; temp = temp->next)
    {
        temp->draw(renderer, offset);
    }
}

void Chunk::update(SDL_Event ev)
{
    for(ObjectList *temp = first; temp != nullptr; temp = temp->next)
    {
        temp->update(ev);
    }
}
