#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED
#include "math.h"
#include <iostream>
#include <SDL.h>

struct Point
{
    double x,y,z;
    bool operator==(Point &p1){return(x==p1.x&&y==p1.y&&y==p1.y);}
    Point operator+(Point &p1){return {x+p1.x,y+p1.y,z+p1.z};}
    Point operator*(double n){return {x*n,y*n,z*n};}
    void get2dCords(int &X, int &Y){X=round((x-z)); Y=round((x+2*y+z)/2);}
    bool operator>(Point p2){
        bool ret = false;
        if(y > p2.y)
            ret = true;
        else
            if(z > p2.z)
                ret = true;
            else
                if(x > p2.x)
                    ret = true;
        return ret;
    }
    bool operator<(Point p2){
        bool ret = false;
        if(x < p2.x)
            ret = true;
        else
            if(z < p2.z)
                ret = true;
            else
                if(y < p2.y)
                    ret = true;
        return ret;
    }
    void printPoint(){std::cout<<"x:"<<x<<" ,y:"<<y<<" ,z:"<<z<<std::endl;}
    bool inRect(SDL_Rect r){return r.x>=x && x<=r.x+r.w && z>=r.y && z<=r.y+r.h;}
};

struct Vector:public Point
{
    Vector(double x, double y, double z):Point({x,y,z}){}
    Vector operator+(Vector &p1){return {x+p1.x,y+p1.y,z+p1.z};}
    Vector operator*(double n){return {x*n,y*n,z*n};}
};


#endif // STRUCTS_H_INCLUDED
