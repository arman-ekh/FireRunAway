#ifndef FLOOR_H
#define FLOOR_H

#include "Cell.h"

class Floor{
    /*
        Each floor contains data about each and every cell,
        in its floor.
    */

    private:
        int floor_num;
        int room_count;
        int room_row;
        int room_column;
        Cell** cells;

    public:
        Floor(int floor_num , int room_row , int room_column);
        int get_floor_num();
        Cell* get_cell_ptr(int row_index , int colum_index);
        int get_floor_row_count();
        int get_floor_column_count();
};

#endif