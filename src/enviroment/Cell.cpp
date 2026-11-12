#include "Cell.h"

#define NORMAL_TEMP 30

Cell::Cell(){}

Cell::Cell(int x , int y , int floor , CellType type){
    
    this->x = x;
    this->y = y;
    this->floor = floor;
    this->type = type;

    this->smoke = false;
    this->fire = false;
    this->blocked = false;
    this->temperature = NORMAL_TEMP;
}

bool Cell::isWalkable()const{

    return (CellType::Wall != type && !blocked);
}

void Cell::set_x(int x){

    this->x = x;
}

void Cell::set_y(int y){

    this->y = y;
}

int Cell::get_x(){

    return x;
}

int Cell::get_y(){

    return y;
}

int Cell::get_floor_num(){

    return floor;
}

CellType Cell::get_celltype(){

    return type;
}