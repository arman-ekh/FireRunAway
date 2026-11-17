#ifndef RENDERER_H
#define RENDERER_H

#include "../enviroment/Floor.h"
#include <raylib.h>


enum class UserType{
    VOID,
    WALL,
    ROOM,
    STAIR,
    CORRIDOR,
    EXIT
};

class Renderer{
    private:
        Floor* floor;
        UserType user_type;
        Cell* get_cell(float mouse_x , float mouse_y);  
        void draw_wall(Cell* cell);      
        void draw_wall(int x , int y , CellType type , Color color);
        void handle_user_input();
        
    public:
        Renderer();
        void set_floor_ptr(Floor* floor);
        void draw_floor();
        void update_floor();
};




#endif