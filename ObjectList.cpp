#include "ObjectList.h"


ObjectList::ObjectList(Object *object): ob(object), next(nullptr), prev(nullptr)
{

}

ObjectList::~ObjectList()
{
    delete ob;
    ObjectList *temp_p = prev;
    if(next!= nullptr)
        next->prev = prev;
    if(temp_p != nullptr)
        temp_p->next = next;
}

ObjectList* ObjectList::operator+(ObjectList *obl)
{
    ObjectList *temp = this;
    while(temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = obl;
    obl->prev = temp;
    while(!this->reorganized());
    return findFirst();
}

bool ObjectList::operator>(ObjectList *obl)
{
    if(obl != nullptr)
    {
        return ob->getCenter()>obl->ob->getCenter();
    }
    return false;
}

bool ObjectList::operator<(ObjectList *obl)
{
    if(obl != nullptr)
    {
        return ob->getCenter()<obl->ob->getCenter();
    }
    return false;
}

bool ObjectList::reorganized()
{
    if(this>next)
    {
        ObjectList *tempN = next;
        ObjectList *tempP = prev;
        this->next = tempN->next;
        this->prev = tempN;
        tempN->next = this;
        tempN->prev = tempP;
        return false;
    }
    if(this<prev)
    {
        ObjectList *tempN = next;
        ObjectList *tempP = prev;
        this->next = tempP;
        this->prev = tempP->prev;
        tempP->next = tempN;
        tempP->prev = this;
        return false;
    }
    return true;
}

ObjectList* ObjectList::findFirst()
{
    ObjectList *temp = this;
    while(temp->prev != nullptr)
    {
        temp = temp->prev;
    }
    return temp;
}

void ObjectList::draw(SDL_Renderer *renderer, Vector offset)
{
    ob->draw(renderer, offset);
}

void ObjectList::update(SDL_Event ev)
{
    ob->update(ev);
}
