#include "encounter.h"
#include <iostream>
#include <fstream>
using namespace std;

void Encounter::populateEncounter(ifstream& tableread){
        tableread >> num;
        tableread >> encounterName;
        tableread >> encounter;
    } 

void Encounter::printEncounter(){
    cout << this->num << " " << this->encounterName << endl;
    cout << this->encounter << endl;
}

string Encounter::get_encounter(){
    return this->encounter;
}

string Encounter::get_encounterName(){
    return this->encounterName;
}
int Encounter::get_num(){
    return this->num;
}

