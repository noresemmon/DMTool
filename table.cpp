#include "table.h"
#include <iostream>

TreasureTable::TreasureTable() {
    this->table_size = 0;
    this->treasure_arr = NULL;
    this->pick_size = 0;
    this->pickpocket_arr = NULL;
}

/* Non-Default Constructor*/
TreasureTable::TreasureTable(int size) {
    this->table_size = size;
    this->treasure_arr = new Treasure[size];
}

/* Deconstructor*/
TreasureTable::~TreasureTable() {
    if (this->treasure_arr != NULL) {
        delete[] this->treasure_arr;
        this->treasure_arr = NULL;
    }
    if (this->pickpocket_arr != NULL) {
        delete[] this->pickpocket_arr;
        this->pickpocket_arr = NULL;
    }
}

void TreasureTable::populate_table(ifstream& tableread, int size) {
     if (!tableread.is_open()) {
        cout << "Error opening the file." << endl;
        return;
    }
    if (this->treasure_arr != NULL) {
        delete[] this->treasure_arr;
        this->treasure_arr = NULL;
    }
    this->table_size = size;
    this->treasure_arr = new Treasure[size];
    for (int i = 0; i < size; i++) {
        treasure_arr[i].populate_table(tableread);
    }
}

  void TreasureTable::print_table(int roll){
    cout << endl;
    for (int i = 0; i < this->table_size; i++){
        if (roll >= treasure_arr[i].get_min() && roll <= treasure_arr[i].get_max())
            treasure_arr[i].print_table();
    }
}

void TreasureTable::pickpocket(ifstream& pickpocket, int pick_size){
     if (!pickpocket.is_open()) {
        cout << "Error opening the file." << endl;
        return;
    }
    if (this->pickpocket_arr != NULL) {
        delete[] this->pickpocket_arr ;
        this->pickpocket_arr  = NULL;
    }
    this->pick_size = pick_size;
    this->pickpocket_arr = new PickpocketTable[pick_size];
    for (int i = 0; i < pick_size; i++) {
        pickpocket_arr[i].pick_table(pickpocket);
    }
}

void TreasureTable::print_pickpocket(){
    int paramter = this->pick_size;
    int random = rand() % paramter + 1; 
     for (int i = 0; i < this->pick_size; i++){
        if (random == pickpocket_arr[i].get_pick_roll()){
            pickpocket_arr[i].print_pick();
        }
    }
}
