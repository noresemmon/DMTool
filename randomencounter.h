#ifndef RANDOMENCOUNTER_H
#define RANDOMENCOUNTER_H
#include <iostream>
#include "encounter.h"

class RandomEncounter {
private:
    int encounter_size;
    Encounter* encounter_arr;
public:
RandomEncounter();  // Default constructor
RandomEncounter(int size);  // Parameterized constructor
~RandomEncounter();  // Destructor
void populateEncounter(ifstream& tableread,int size);
void printEncounter();


};

#endif