#include "renderer.h"
#include <raylib.h>

#define cube_size 50

Renderer::Renderer(){
    this->floor = nullptr;
};

void Renderer::set_floor_ptr(Floor* floor){
    this->floor = floor;
}

void Renderer::draw_floor(){
    int floor_width = floor->get_floor_column_count();
    int floor_height = floor->get_floor_row_count();
    
    for(int i = 0; i < floor_height ; i++){
        for(int j = 0 ; j < floor_width ; j++){
            
            Cell* cell = floor->get_cell_ptr(i, j);
            
            if(cell == nullptr){
                continue;
            }
            CellType type =  cell->get_celltype();
            Rectangle rec = (Rectangle){static_cast<float>(i*cube_size) , static_cast<float>(j*cube_size) , cube_size , cube_size};

            if(type== CellType::Void){
                DrawRectangle( i * cube_size , j * cube_size, cube_size,cube_size, GRAY);
            }else if (type == CellType::Exit) {
                DrawRectangle( i * cube_size , j * cube_size, cube_size, cube_size, RED);
            }else if (type == CellType::Room) {
                DrawRectangle( i * cube_size , j * cube_size, cube_size, cube_size, BLUE);
            }else if (type == CellType::Staircase) {
                DrawRectangle( i * cube_size , j * cube_size, cube_size, cube_size, GREEN);
            }else if (type == CellType::Wall) {
                DrawRectangle( i * cube_size , j * cube_size, cube_size, cube_size, BROWN);
            }else if(type == CellType::Corridor){
                DrawRectangle( i * cube_size , j * cube_size, cube_size, cube_size, DARKBROWN);
            }
            DrawRectangleLinesEx(rec, 2, WHITE);

        }
    }
}