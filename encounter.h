#ifndef ENCOUNTER_H
#define ENCOUNTER_H
#include <iostream>
#include <fstream>
using namespace std;

class Encounter {
private:
    string encounter;
    string encounterName;
    int num;

public:
    void populateEncounter(ifstream& tableread);
    void printEncounter();
    string get_encounter();
    string get_encounterName();
    int get_num();
};

#endif