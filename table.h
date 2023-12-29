#ifndef TABLE_H
#define TABLE_H
#include <iostream>
#include "treasure.h"
#include "pickpocket.h"

class TreasureTable {
private:
    int roll;
    int table_size;
    int pick_size;
    Treasure* treasure_arr;
    PickpocketTable* pickpocket_arr;
public:
TreasureTable();  // Default constructor
TreasureTable(int size);  // Parameterized constructor
~TreasureTable();  // Destructor
void pickpocket(ifstream& pickpocket,int pick_size);
void populate_table(ifstream& tableread,int size);
void print_table(int roll);
void print_pickpocket();

};

#endif
