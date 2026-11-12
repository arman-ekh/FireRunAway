#include "Floor.h"


Cell* Floor::get_cell_ptr(int row_index, int colum_index) {
    if (row_index >= room_row || row_index < 0 ||
        colum_index >= room_column || colum_index < 0) {
        return nullptr;
    }

    return &cells[row_index][colum_index];
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
    this->room_row = room_row;
    this->room_column = room_column;
}

int Floor::get_floor_column_count(){
    return room_column;
}

int Floor::get_floor_row_count(){
    return room_row;
}