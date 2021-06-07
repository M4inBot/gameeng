#ifndef SDL_BASICS_H_INCLUDED
#define SDL_BASICS_H_INCLUDED
#include "Sprite.h"
#include <string>


class InitError : public std::exception
{
    std::string msg;
public:
    InitError();
    InitError(const std::string&);
    virtual ~InitError() throw();
    virtual const char *what() const throw();
};

class SDL
{
public:
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Renderer *getRenderer(){return renderer;};
    SDL(Uint32 flags = 0, int w = 640, int h = 480);
    virtual ~SDL();
    virtual void draw();
};



#endif // SDL_BASICS_H_INCLUDED
