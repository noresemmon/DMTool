#ifndef MAGICITEM_H
#define MAGICITEM_H
#include <iostream>
#include <fstream>
using namespace std;

class MagicItem {
private:
    int roll;
    string item;
    int min;
    int max;

public:
    void populate_magic(ifstream& tableread);
    void print_magic();
    string get_item();
    int get_min();
    int get_max();

    void set_item(string new_name);

    void set_min(int new_min);

    void set_max(int new_max);
};

#endif