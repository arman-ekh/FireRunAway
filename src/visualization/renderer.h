#ifndef RENDERER_H
#define RENDERER_H

#include "../enviroment/Floor.h"

class Renderer{
    private:
        Floor* floor;
        

    public:
        Renderer();
        void set_floor_ptr(Floor* floor);
        void draw_floor();
};




#endif