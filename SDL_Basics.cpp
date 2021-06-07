#include <exception>
#include <string>
#include <iostream>
#include <SDL.h>
#include "SDL_Basics.h"
#include <SDL_image.h>

SDL::SDL( Uint32 flags, int w, int h)
{
    if (SDL_Init(flags) != 0)
        throw InitError();
    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
    window = SDL_CreateWindow("Hello World", 400, 200, w, h, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    if (window == NULL || renderer == NULL)
        throw InitError();
}

SDL::~SDL()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

void SDL::draw()
{
    // Clear the window with a black background
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);
}

InitError::InitError() :
    exception(),
    msg( SDL_GetError() )
{
}

InitError::InitError(const std::string &m) :
    exception(),
    msg(m)
{
}

InitError::~InitError() throw()
{
}

const char * InitError::what() const throw()
{
    return msg.c_str();
}
