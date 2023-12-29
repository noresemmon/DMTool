#include "pickpocket.h"

void PickpocketTable::pick_table(ifstream& pickpocket){
pickpocket >> pick_roll;
pickpocket >> item;
}

void PickpocketTable::print_pick(){
    cout << this->pick_roll << " ";
    cout << "You found " << this->item << endl;
}

int PickpocketTable::get_pick_roll(){
    return this->pick_roll;
}