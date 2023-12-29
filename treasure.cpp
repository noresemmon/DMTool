#include "treasure.h"
#include <iostream>
#include <fstream>

using namespace std;

void Treasure::populate_table(ifstream& tableread){
    tableread >> size;
    if (size == 2) { 
        tableread >> name1;
        tableread >> num_die;
        tableread >> die;
        tableread >> mult;
        tableread >> name2;
        tableread >> num_die2;
        tableread >> die2;
        tableread >> mult2;
        tableread >> min;
        tableread >> max;
    } else {
        tableread >> name1;
        tableread >> num_die;
        tableread >> die;
        tableread >> mult;
        tableread >> min;
        tableread >> max;
    }
}

void Treasure::print_table(){
    int dice_roll = 0;  
    int dice_roll2 = 0; 
    int temp2;
    int temp;

    if (this->die == "d6") {
        for (int i = 0; i < this->num_die; i++) {
            temp = rand() % 6 + 1;
            dice_roll += temp;
        }
    }

    cout << dice_roll << "x" << this->mult << endl;
    int total = dice_roll * this->mult;
    cout << this->name1 << " " << total << endl;
    cout << this->num_die << this->die << "x" << this->mult << endl;

    if (this->size == 2) {
        if (this->die2 == "d6") {
            for (int i = 0; i < this->num_die2; i++) {
                temp2 = rand() % 6 + 1;
                dice_roll2 += temp2;
            }
        }
        cout << dice_roll2 << "x" << this->mult2 << endl;
        int total2 = dice_roll2 * this->mult2; 
        cout << this->name2 << " " << total2 << endl;
        cout << this->num_die2 << this->die2 << "x" << this->mult2 << endl;
    }
    cout << endl;
}

string Treasure::get_name(){
    return this->name1;
}

int Treasure::get_min(){
    return this->min;
}

int Treasure::get_max(){
    return this->max;
}

void Treasure::set_name(string new_name){
    this->name1 = new_name;
}

void Treasure::set_min(int new_min){
    this->min = new_min;
}

void Treasure::set_max(int new_max){
    this->max = new_max;
}