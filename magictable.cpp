#include "magictable.h"
#include <iostream>
#include <fstream>
using namespace std;

void MagicItem::populate_magic(ifstream& tableread){
        tableread >> min;
        tableread >> max;
        tableread >> item;
    } 

void MagicItem::print_magic(){
    cout << this->item << endl;
    cout << endl;
}

string MagicItem::get_item(){
    return this->item;
}

int MagicItem::get_min(){
    return this->min;
}

int MagicItem::get_max(){
    return this->max;
}

void MagicItem::set_item(string new_name){
    this->item = new_name;
}

void MagicItem::set_min(int new_min){
    this->min = new_min;
}

void MagicItem::set_max(int new_max){
    this->max = new_max;
}