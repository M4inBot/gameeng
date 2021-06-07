#ifndef SCENE_H_INCLUDED
#define SCENE_H_INCLUDED
#include "SDL_Basics.h"
#include "Chunk.h"

enum num{vn = 5, un = 11};
class Scene:public SDL
{
    Chunk* visible_chunks[vn][vn];
    Chunk* all_chunks[un][un];
public:
    SDL_Rect camera;
    SDL_Event ev;
    Vector offset;
    Scene(Uint32 flags = 0, int w = 640, int h = 480);
    ~Scene();
    void draw();
    void update();
    void visibleChunkUpdate();
};

#endif // SCENE_H_INCLUDED
