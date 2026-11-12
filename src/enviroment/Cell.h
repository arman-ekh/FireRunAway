#ifndef CELL_H
#define CELL_H

enum class CellType{
    Room,
    Wall,
    Corridor,
    Staircase,
    Exit
};


class Cell{
    public:
        bool isWalkable() const;
        Cell(int x, int y, int floor , CellType type);
        
        void setWalkable(bool Walkable);
        void set_x(int x);
        void set_y(int y);


        int get_x();
        int get_y();
        int get_floor_num();
        CellType get_celltype();


    private:
        int x, y;
        int floor;
        CellType type;
        float temperature;
        float smoke;

        bool fire;
        bool blocked;

        
};




#endif