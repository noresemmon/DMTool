#ifndef NPCGENERATOR_H
#define NPCGENERATOR_H

#include "npc.h"
#include <iostream>
#include <fstream>
using namespace std;

class NpcGenerator {
private:
NPC* per_arr;
NPC* race_arr;
NPC* speech_arr;
NPC* exotic_arr;
NPC* phy_arr;

int per_size;
int race_size;
int speech_size;
int exotic_size;
int phy_size;

public:

NpcGenerator();

~NpcGenerator();

void populatePersonaility(ifstream& npcgen, int size);

void populateRace(ifstream& npcgen, int size);

void populateSpeech(ifstream& npcgen, int size);

void populateExotic(ifstream& exotic, int size);

void populatePhysicalFeatures(ifstream& npcgen, int size);


void printSpeech();

void printRace();

void printPersonality();

void printPhysicalFeatures();

void gender();


};

#endif