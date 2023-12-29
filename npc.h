#ifndef NPC_H
#define NPC_H
#include <iostream>
#include <fstream>
using namespace std;

class NPC {
private:
int max;
int min;
string text;

public:
void populate_npc(ifstream& npcgen);

void print_npc();

string get_text();

int get_min();

int get_max();

void set_item(string new_text);

void set_min(int new_min);

void set_max(int new_max);


};

#endif