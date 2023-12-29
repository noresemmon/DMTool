#include "npcgenerator.h"

NpcGenerator::NpcGenerator() {
    this->per_arr = NULL;
    this->race_arr = NULL;
    this->speech_arr = NULL;
    this->exotic_arr = NULL;
    this->phy_arr = NULL;

    this->per_size = 0;
    this->race_size = 0;
    this->speech_size = 0;
    this->exotic_size = 0;
    this->phy_size = 0;
}

NpcGenerator::~NpcGenerator() {
    if (this->per_arr != nullptr) {
        delete[] this->per_arr;
        this->per_arr = nullptr;
    }
    if (this->race_arr != nullptr) {
        delete[] this->race_arr;
        this->race_arr = nullptr;
    }
    if (this->speech_arr != nullptr) {
        delete[] this->speech_arr;
        this->speech_arr = nullptr;
    }
    if (this->exotic_arr != nullptr) {
        delete[] this->exotic_arr;
        this->exotic_arr = nullptr;
    }
    if (this->phy_arr != nullptr) {
        delete[] this->phy_arr;
        this->phy_arr = nullptr;
    }
}

void NpcGenerator::populatePersonaility(ifstream& npcgen, int size) {
     if (!npcgen.is_open()) {
        cout << "Error opening the file." << endl;
        return;
    }
        if (this->per_arr != nullptr) {
        delete[] this->per_arr;
        this->per_arr = nullptr;
    }
    this->per_size = size; 
    this->per_arr = new NPC[size];
    for (int i = 0; i < this->per_size; i++) {
        per_arr[i].populate_npc(npcgen);
    }
}

void NpcGenerator::populateRace(ifstream& npcgen, int size) {
     if (!npcgen.is_open()) {
        cout << "Error opening the file." << endl;
        return;
    }
        if (this->race_arr != nullptr) {
            delete[] this->race_arr;
            this->race_arr = nullptr;
    }
        this->race_size = size; 
        this->race_arr = new NPC[size];
    for (int i = 0; i < this->race_size; i++) {
        race_arr[i].populate_npc(npcgen);
    }
}

void NpcGenerator::populateSpeech(ifstream& npcgen, int size) {
     if (!npcgen.is_open()) {
        cout << "Error opening the file." << endl;
        return;
    }
        if (this->speech_arr != nullptr) {
        delete[] this->speech_arr;
        this->speech_arr = nullptr;
    }
    this->speech_size = size; 
    this->speech_arr = new NPC[size];
    for (int i = 0; i < this->speech_size; i++) {
        speech_arr[i].populate_npc(npcgen);
    }
}
void NpcGenerator::populateExotic(ifstream& exotic, int size) {
      if (!exotic.is_open()) {
         cout << "Error opening the file." << endl;
         return;
     }
     if (this->exotic_arr != nullptr) {
         delete[] this->exotic_arr;
         this->exotic_arr = nullptr;
     }
     this->exotic_size = size; 
     this->exotic_arr = new NPC[size];
     for (int i = 0; i < this->exotic_size; i++) {
         exotic_arr[i].populate_npc(exotic);
     }
 }

void NpcGenerator::populatePhysicalFeatures(ifstream& npcgen, int size) {
     if (!npcgen.is_open()) {
        cout << "Error opening the file." << endl;
        return;
    }
        if (this->phy_arr != nullptr) {
        delete[] this->phy_arr;
        this->phy_arr = nullptr;
    }
    this->phy_size = size; 
    this->phy_arr = new NPC[size];
    for (int i = 0; i < this->phy_size; i++) {
        phy_arr[i].populate_npc(npcgen);
    }
}

void NpcGenerator::printSpeech() {
    int rand_num = rand() % 8 + 1;
    cout << "Speech: ";
    for (int i = 0; i < this->speech_size; i++) {
        if (rand_num >= speech_arr[i].get_min() && rand_num <= speech_arr[i].get_max()) {
            speech_arr[i].print_npc();
        }
    }
    cout << endl;
}

void NpcGenerator::printRace() {
    int rand_num = rand() % 100 + 1;
     cout << "Race: ";
     for (int i = 0; i < this->race_size; i++) {
         if (rand_num >= race_arr[i].get_min() && rand_num <= race_arr[i].get_max()) {
             race_arr[i].print_npc();
             if (rand_num >= 96  && this->exotic_size > 0) {
                 // Ensure that there are entries in exotic_arr
                 int exotic_rand_num = rand() % 8 + 1;
                 cout << " ";
                 exotic_arr[exotic_rand_num].print_npc();
             }
         }
     }
     cout << endl;
 }

void NpcGenerator::printPhysicalFeatures(){
    int rand_num = rand() % 6 + 1;
    cout << "Physical Feature: ";
    for (int i = 0; i < this->phy_size; i++) {
        if (rand_num >= phy_arr[i].get_min() && rand_num <= phy_arr[i].get_max()) {
            phy_arr[i].print_npc();
        }
    }
    cout << endl;
}

void NpcGenerator::printPersonality(){
    int rand_num = rand() % 9 + 1;
    cout << "Personaility: ";
    for (int i = 0; i < this->per_size; i++) {
        if (rand_num >= per_arr[i].get_min() && rand_num <= per_arr[i].get_max()) {
            per_arr[i].print_npc();
        }
    }
    cout << endl;
}

void NpcGenerator::gender(){
    int randomNum = rand() % 20 + 1; // Generates a random number between 1 and 20
    cout << "Gender: ";
    if (randomNum <= 10) {
        cout << "Female" << endl;
    } else if (randomNum <= 19) {
        cout << "Male" << endl;
    } else {
        cout << "Ambiguous" << endl; // Ambiguous
    }
}