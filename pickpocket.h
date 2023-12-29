#ifndef PICKPOCKET_H
#define PICKPOCKET_H
#include <iostream>
#include <fstream>
using namespace std;


class PickpocketTable {
private:
    int pick_roll;
    string item;   
public:
void pick_table(ifstream& pickpocket);
void print_pick();
int get_pick_roll();
};
#endif
