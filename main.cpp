#include <exception>
#include <string>
#include <iostream>
#include <SDL.h>
#include "Scene.h"



int main(int argc, char *argv[])
{
    try
    {
        bool quit = false;
        Scene sdl( SDL_INIT_EVERYTHING);



        while(!quit)
        {
            sdl.update();
            sdl.draw();
            while(SDL_PollEvent(&sdl.ev))
            {
                switch(sdl.ev.type)
                {
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_KEYDOWN:
                    if(sdl.ev.key.keysym.sym==SDLK_UP)
                    {
                        sdl.offset.z += 2;
                        sdl.camera.y -= 2;
                    }
                    else if(sdl.ev.key.keysym.sym==SDLK_DOWN)
                    {
                        sdl.offset.z -= 2;
                        sdl.camera.y += 2;
                    }
                    else if(sdl.ev.key.keysym.sym==SDLK_RIGHT)
                    {
                        sdl.offset.x -= 2;
                        sdl.camera.x += 2;
                    }
                    else if(sdl.ev.key.keysym.sym==SDLK_LEFT)
                    {
                        sdl.offset.x += 2;
                        sdl.camera.x -= 2;
                    }
                }
            }
        }
        return 0;
    }
    catch ( const InitError &err )
    {
        std::cerr << "Error while initializing SDL:  "
                  << err.what()
                  << std::endl;
    }
    return 1;
}
