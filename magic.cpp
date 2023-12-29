#include "magic.h"
#include <iostream>
using namespace std;

MagicTable::MagicTable() {
    this->magic_size = 0; 
    this->magic_arr = nullptr;
}

MagicTable::MagicTable(int size) {
    this->magic_size = size;
    this->magic_arr = new MagicItem[size];
}

MagicTable::~MagicTable() {
    if (this->magic_arr != nullptr) {
        delete[] this->magic_arr;
        this->magic_arr = nullptr;
    }
}

void MagicTable::populate_table(ifstream& tableread, int size) {
    if (!tableread.is_open()) {
        cout << "Error opening the file." << endl;
        return;
    }
    if (this->magic_arr != nullptr) {
        delete[] this->magic_arr;
        this->magic_arr = nullptr;
    }
    this->magic_size = size; 
    this->magic_arr = new MagicItem[size];
    for (int i = 0; i < this->magic_size; i++) {
        magic_arr[i].populate_magic(tableread);
    }
}

void MagicTable::print_table(int roll) {
    this->magic_roll = roll;
    cout << endl;
    for (int i = 0; i < this->magic_size; i++) {
        if (this->magic_roll >= magic_arr[i].get_min() && this->magic_roll <= magic_arr[i].get_max()) {
            magic_arr[i].print_magic();
        }
    }
}