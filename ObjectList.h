#ifndef OBJECTLIST_H_INCLUDED
#define OBJECTLIST_H_INCLUDED
#include "Object.h"

class ObjectList
{
    Object *ob;
public:
    ObjectList *next;
    ObjectList *prev;

    ObjectList(Object *object);
    ~ObjectList();

    ObjectList* operator+(ObjectList *obl);

    bool operator>(ObjectList *obl);
    bool operator<(ObjectList *obl);
    bool reorganized();
    ObjectList* findFirst();

    void draw(SDL_Renderer *renderer, Vector offset);
    void update(SDL_Event ev);
};

#endif // OBJECTLIST_H_INCLUDED
