#include "Building.h"
#include <vector>

void Building::add_floor(Floor* floor){
    floors_ptr.push_back(floor);
}

Building::Building(){};

int Building::get_floor_num(){
    return floors_ptr.size();
}