#include "randomencounter.h"
#include <iostream>
using namespace std;

RandomEncounter::RandomEncounter() {
    this->encounter_size = 0; 
    this->encounter_arr = nullptr;
}

RandomEncounter::RandomEncounter(int size) {
    this->encounter_size = size;
    this->encounter_arr = new Encounter[size];
}

RandomEncounter::~RandomEncounter() {
    if (this->encounter_arr != nullptr) {
        delete[] this->encounter_arr;
        this->encounter_arr = nullptr;
    }
}

void RandomEncounter::populateEncounter(ifstream& tableread, int size) {
    if (!tableread.is_open()) {
        cout << "Error opening the file." << endl;
        return;
    }
    if (this->encounter_arr != nullptr) {
        delete[] this->encounter_arr;
        this->encounter_arr = nullptr;
    }
    this->encounter_size = size; 
    this->encounter_arr = new Encounter[size];
    for (int i = 0; i < this->encounter_size; i++) {
        encounter_arr[i].populateEncounter(tableread);
    }
}

void RandomEncounter::printEncounter() {
    int random = rand() % this->encounter_size + 1;
    cout << endl;
    for (int i = 0; i < this->encounter_size; i++) {
        if (random == encounter_arr[i].get_num()) {
            encounter_arr[i].printEncounter();
        }
    }
    cout << endl;
}