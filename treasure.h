
#ifndef TREASURE_H
#define TREASURE_H

#include <string>
#include <fstream>

using namespace std; // Add this line to use the string and ifstream types

class Treasure {
private:
   int size;
   int min;
   int max;
   int mult;
   int num_die;
   string die;
   int mult2;
   int num_die2;
   string die2;
   string name1;
   string name2;
   string roll1;
   string roll2;




public:

    void populate_table(ifstream& tableread);

    void print_table();

    string get_name();

    int get_min();

    int get_max();

    void set_name(string new_name);

    void set_min(int new_min);

    void set_max(int new_max);
};

#endif