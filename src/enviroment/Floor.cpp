#include "Floor.h"


Cell* Floor::get_cell_ptr(int row_index , int colum_index){
    Cell* cell = (
        row_index >= this->room_row ||
         row_index < 0 ||
          colum_index >= this->room_column ||
           colum_index < 0
        ) ? nullptr : &cells[room_row][room_column];
    return cell;
}

int Floor::get_floor_num(){
    return floor_num;
}

Floor::Floor(int floor_num , int room_row , int room_column){
    this->floor_num = floor_num;
    this->cells = new Cell*[room_row];
    for (int i = 0; i < room_row; i++) {
        this->cells[i] = new Cell[room_column];
    }
    this->room_count = room_row * room_column; 
}