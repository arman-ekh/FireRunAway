#ifndef BUILDING_H
#define BUILDING_H

#include "Floor.h"
#include <vector>

class Building{
    private:
        std::vector<Floor* > floors_ptr;

    public:
        Building();
        void add_floor(Floor* floor_ptr);
        int get_floor_num();


};


#endif