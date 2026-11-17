#include "renderer.h"
#include <raylib.h>



#define cube_size 50

Renderer::Renderer(){
    this->floor = nullptr;
    user_type = UserType::VOID;
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
            Rectangle rec = (Rectangle){static_cast<float>(j*cube_size) , static_cast<float>(i*cube_size) , cube_size , cube_size};

            if(type== CellType::Void){
                DrawRectangle( j * cube_size , i * cube_size, cube_size,cube_size, GRAY);
            }else if (type == CellType::Exit) {
                DrawRectangle( j * cube_size , i * cube_size, cube_size, cube_size, RED);
            }else if (type == CellType::Room) {
                DrawRectangle( j * cube_size , i * cube_size, cube_size, cube_size, BLUE);
            }else if (type == CellType::Staircase) {
                DrawRectangle( j * cube_size , i * cube_size, cube_size, cube_size, GREEN);
            }else if (type == CellType::Wall) {
                DrawRectangle( j * cube_size , i * cube_size, cube_size, cube_size, BROWN);
                draw_wall(j , i);
            }else if(type == CellType::Corridor){
                DrawRectangle( j * cube_size , i * cube_size, cube_size, cube_size, DARKBROWN);
            }
            if(type != CellType::Wall){
                DrawRectangleLinesEx(rec, 2, WHITE);
            }
            

        }
    }
}

void Renderer::handle_user_input(){
    if (IsKeyPressed(KEY_Q)) {
        user_type = UserType::VOID;
    }
    else if (IsKeyPressed(KEY_W)) {
        user_type = UserType::WALL;
    }
    else if (IsKeyPressed(KEY_E)) {
        user_type = UserType::ROOM;
    }
    else if (IsKeyPressed(KEY_R)) {
        user_type = UserType::STAIR;
    }
    else if (IsKeyPressed(KEY_T)) {
        user_type = UserType::EXIT;
    }else if (IsKeyPressed(KEY_Y)) {
        user_type = UserType::CORRIDOR;
    }
}

void Renderer::update_floor() {
    if (floor == nullptr) {
        return;
    }

    handle_user_input();

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        Cell* cell = get_cell(GetMouseX(), GetMouseY());

        if (cell == nullptr) {
            return;
        }

        if (user_type == UserType::VOID) {
            cell->set_cell_type(CellType::Void);
        }
        else if (user_type == UserType::EXIT) {
            cell->set_cell_type(CellType::Exit);
        }
        else if (user_type == UserType::ROOM) {
            cell->set_cell_type(CellType::Room);
        }
        else if (user_type == UserType::STAIR) {
            cell->set_cell_type(CellType::Staircase);
        }
        else if (user_type == UserType::WALL) {
            cell->set_cell_type(CellType::Wall);
        }else if (user_type == UserType::CORRIDOR) {
            cell->set_cell_type(CellType::Corridor);
        }
    }
}


Cell* Renderer::get_cell(float mouse_x , float mouse_y){
    if (floor == nullptr) {
        return nullptr;
    }
    
    int col = mouse_x / cube_size;
    int row = mouse_y / cube_size;

    return floor->get_cell_ptr(row, col);
}


bool is_valid_cordinate(int x ,int y , int floor_width ,int floor_height){
    if(x < 0 || x >=floor_width || y < 0 || y >= floor_height) return false;
    else return true;
}


void Renderer::draw_wall(int x , int y){
    int floor_width = floor->get_floor_column_count();
    int floor_height = floor->get_floor_row_count();
    
    if(!is_valid_cordinate(x, y,floor_width , floor_height)){
        return;
    }

    bool neighbours_map[4] = {false , false , false , false};
    /*
        0 = north wall 
        1 = south wall 
        2 = wesr wall
        3 = east wall
    */
    int neighbour_num = 0;
    
    for(int j = -1 ; j < 2 ; j+=2 ){
        // north and south wall
        int new_x = x ;            
        int new_y = y + j;
        if(is_valid_cordinate(new_x, new_y, floor_width,  floor_height)){
            CellType type = floor->get_cell_ptr(new_y, new_x)->get_celltype();
            bool is_wall = (type == CellType::Wall) ? true : false;
            neighbours_map[(j+1)/2] = is_wall;
            if(is_wall) neighbour_num++;
        }
        
        //east and west wall
        new_x = x + j;
        new_y = y ;
        if(is_valid_cordinate(new_x, new_y, floor_width,  floor_height)){
            CellType type = floor->get_cell_ptr(new_y, new_x)->get_celltype();
            bool is_wall = (type == CellType::Wall) ? true : false;
            neighbours_map[((j+1)/2) + 2] = is_wall;
            if(is_wall) neighbour_num++;
        }
    }
      
    DrawText(TextFormat("%d", neighbour_num),x * cube_size + 17,y * cube_size + 15,20,BLACK);
    
    if(!neighbours_map[0]){   
        DrawRectangle(x*cube_size, y * cube_size  , cube_size, cube_size/5, BLACK);
    }
    if(!neighbours_map[1]){
        DrawRectangle(x*cube_size, y * cube_size + cube_size - cube_size/5 , cube_size, cube_size/5, BLACK);
    }
    if(!neighbours_map[2]){
        DrawRectangle(x*cube_size, y * cube_size  , cube_size/5, cube_size, BLACK);
    }
    if(!neighbours_map[3]){
        DrawRectangle(x*cube_size + cube_size - cube_size/5, y * cube_size  , cube_size/5, cube_size, BLACK);
    }    
}


