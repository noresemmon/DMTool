#ifndef MAGIC_H
#define MAGIC_H
#include "magictable.h"
#include <fstream>
#include <iostream>
class MagicTable {
private:
    int magic_roll;
    int magic_size;
    MagicItem* magic_arr;
public:
MagicTable();  // Default constructor
MagicTable(int size);  // Parameterized constructor
~MagicTable();  // Destructor
void populate_table(ifstream& tableread,int size);
void print_table(int roll);
};

#endif