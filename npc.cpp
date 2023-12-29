#include "npc.h"

void NPC::populate_npc(ifstream& npcgen){
        npcgen >> min;
        npcgen >> max;
        npcgen >> text;
    } 

void NPC::print_npc(){
    cout << this->text;
}

string NPC::get_text(){
    return this->text;
}

int NPC::get_min(){
    return this->min;
}

int NPC::get_max(){
    return this->max;
}

void NPC::set_item(string new_text){
    this->text = new_text;
}

void NPC::set_min(int new_min){
    this->min = new_min;
}

void NPC::set_max(int new_max){
    this->max = new_max;
}