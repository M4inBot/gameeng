#include "Scene.h"


Scene::Scene(Uint32 flags, int w, int h)
    :SDL(flags,w,h), offset(0,0,0)
{
    for(int x = 0; x < un; x++)
    {
        for(int z = 0; z < un; z++)
        {
            all_chunks[x][z] = new Chunk(renderer, x, z);
        }
    }

    for(int x = 0; x < vn; x++)
    {
        for(int z = 0; z < vn; z++)
        {
            visible_chunks[x][z] = nullptr;
        }
    }
    SDL_Rect r = {32,32,64,64};
    camera = r;
    visibleChunkUpdate();
}

Scene::~Scene()
{
    for(int x = 0; x < un; x++)
    {
        for(int z = 0; z < un; z++)
        {
            delete all_chunks[x][z];
        }
    }
}

void Scene::draw()
{
    SDL_SetRenderDrawColor(getRenderer(), 0, 0, 0, 255);
    SDL_RenderClear(getRenderer());
    for(int x = 0; x < un; x++)
    {
        for(int z = 0; z < un; z++)
        {
            all_chunks[x][z]->draw(renderer, offset);
        }
    }

    for(int x = 0; x < vn; x++)
    {
        for(int z = 0; z < vn; z++)
        {
            if(visible_chunks[x][z]!=nullptr)
            {
                visible_chunks[x][z]->draw(renderer, offset);
                visible_chunks[x][z]->getCenter().printPoint();
            }
        }
    }


    SDL_RenderPresent(getRenderer());
}

void Scene::update()
{
    visibleChunkUpdate();
    for(int x = 0; x < vn; x++)
    {
        for(int z = 0; z < vn; z++)
        {
            if(visible_chunks[x][z]!=nullptr)
                visible_chunks[x][z]->update(ev);
        }
    }
}


void Scene::visibleChunkUpdate()
{
    int VX = 0,VZ = 0;
    for(int x = 0; x < vn; x++)
    {
        for(int z = 0; z < vn; z++)
        {
            visible_chunks[x][z] = nullptr;
        }
    }
    for(int x = 0; x < un; x++)
    {
        for(int z = 0; z < un; z++)
        {
            if(all_chunks[x][z]->getCenter().inRect(camera))
            {
                visible_chunks[VX][VZ] = all_chunks[x][z];
                VZ++;
            }
        }
        VZ = 0;
        VX++;
        if(VX>4)
            VX=0;
    }
}

