#include <iostream>
#include <fstream>
#include <ctime>
#include <cmath>
#include <limits>
#include "table.h"
#include "magic.h"
#include "npcgenerator.h"
#include "randomencounter.h"

using namespace std;

int main() {
    int replay = 3;
    ifstream tableread;
    ifstream pickpocket;
    ifstream npcgen;
    ifstream exotic;
    int select;
    srand(time(NULL));
    TreasureTable s;
    MagicTable m;
    NpcGenerator n;
    RandomEncounter r;
    char choice;

    cout << "Hello DM! Welcome to DM Tool" << endl;
    do {
        cout << "Please select a option" << endl;
        cout << "1. Individual Treasure" << endl;
        cout << "2. Magic Items" << endl;
        cout << "3. XP Level 3 Magic Items" << endl;
        cout << "4. Dice Roller" << endl;
        cout << "5. NPC Generator" << endl;
        cout << "6. Currency Conveter" << endl;
        cout << "7. Random Enounter Generator" << endl;
        cout << "8. Quit Program" << endl;
        cout << "Select: ";
        cin >> select;

         choice = 'y';
        switch (select) {
    case 1:
    char choice;
    do {
        // Open pickpocket file
        ifstream pickpocket("pickpockettable.txt");
        if (!pickpocket.is_open()) {
            cout << "Error opening the pickpocket file." << endl;
            return 1; 
        }

        // Get challenge rating
        int challengeRating;
        cout << "Enter Challenge Rating: ";
        while (!(cin >> challengeRating) || challengeRating < 1 || challengeRating > 100) {
            cout << "Invalid input. Please enter a number between 1 and 100." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter Challenge Rating: ";
        }

        // Open tableread file based on challenge rating
        ifstream tableread;
        if (challengeRating <= 4 && challengeRating >= 0) {
            tableread.open("challenge0-4.txt");
        } else if (challengeRating <= 10 && challengeRating >= 5) {
            tableread.open("challenge5-10.txt");
        } else if (challengeRating <= 16 && challengeRating >= 11) {
            tableread.open("challenge11-16.txt");
        } else {
            tableread.open("challenge17+.txt");
        }

        // Check if tableread file is opened successfully
        if (!tableread.is_open()) {
            cout << "Error opening the tableread file." << endl;
            return 1; // Exit the program with an error code
        }

        // Get size and pick_size
        int treasureSize;
        int pickpocketSize;
        tableread >> treasureSize;
        pickpocket >> pickpocketSize;

        // Get roll
        int roll;
        cout << "Enter Roll (1-100): ";
        while (!(cin >> roll) || roll < 1 || roll > 100) {
            cout << "Invalid input. Please enter a number between 1 and 100." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter Roll (1-100): ";
        }

        // Populate and print treasure table
        TreasureTable treasureTable;
        treasureTable.populate_table(tableread, treasureSize);
        treasureTable.print_table(roll);

        // Populate and print pickpocket table
        treasureTable.pickpocket(pickpocket, pickpocketSize);
        treasureTable.print_pickpocket();

        // Close files
        pickpocket.close();
        tableread.close();

        // Ask if user wants to search again
        cout << "Search again?: y/n ";
        cin >> choice;
    } while (choice != 'n');
    break;
            
    case 2:
    do {
        char tableOption = ' ';
        cout << "|||-Please Choose a magic table-|||" << endl;
        cout << "Table A: a" << endl;
        cout << "Table B: b" << endl;
        cout << "Table C: c" << endl;
        cout << "Table D: d" << endl;
        cout << "Table E: e" << endl;
        cout << "Table F: f" << endl;
        cout << "Table G: g" << endl;
        cout << "Table H: h" << endl;
        cout << "Table I: i" << endl;
        cout << "Common Magic Table: j" << endl;
        cout << "Enter option: ";
        
        while (!(cin >> tableOption) || (tableOption < 'a' || tableOption > 'j')) {
            cout << "Invalid input. Please enter a valid option (a to j)." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        string filename;
        if (tableOption >= 'a' && tableOption <= 'i') {
            filename = "table" + string(1, tableOption) + ".txt";
        } else {
            filename = "commonmagictable.txt";
        }

        tableread.open(filename);
        if (!tableread.is_open()) {
            cout << "Error opening the tableread file." << endl;
            return 1; 
        }

        int magicSize;
        tableread >> magicSize;
        cout << "Enter Roll: ";
        int magicRoll;
        if (!(cin >> magicRoll)) {
            cout << "Invalid input. Please enter a valid number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cout << endl;

        m.populate_table(tableread, magicSize);
        m.print_table(magicRoll);
        tableread.close();

        cout << "Search Again?: y/n ";
        cin >> choice;
    } while (choice != 'n');
    break; 
    
    case 3:
    int table_size;
    do {
        char option = ' ';
        cout << "|||-Please Choose a magic table-|||" << endl;
        cout << "Table A lvl 1-3: a" << endl;
        cout << "Table B lvl 4-6: b" << endl;
        cout << "Table C lvl 7-9: c" << endl;
        cout << "Table D lvl 10-12: d" << endl;
        cout << "Table E lvl 13-15: e" << endl;
        cout << "Table F lvl 16-18: f" << endl;
        cout << "Table G lvl 19-20: g" << endl;
        cout << "Enter option: ";

        // Validate and get user input
        while (!(cin >> option) || (option < 'a' || option > 'g')) {
            cout << "Invalid input. Please enter a valid option (a to g)." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // Open the corresponding table file
        ifstream tableread;
        string filename;

        if (option == 'a' || option == 'A') {
            filename = "lvl1-3.txt";
        } else if (option == 'b' || option == 'B') {
            filename = "lvl4-6.txt";
        } else if (option == 'c' || option == 'C') {
            filename = "lvl7-9.txt";
        } else if (option == 'd' || option == 'D') {
            filename = "lvl10-12.txt";
        } else if (option == 'e' || option == 'E') {
            filename = "lvl13-15.txt";
        } else if (option == 'f' || option == 'F') {
            filename = "lvl16-18.txt";
        } else {
            filename = "lvl19-20.txt";
        }

        tableread.open(filename);

        if (!tableread.is_open()) {
            cout << "Error opening the tableread file." << endl;
            return 1;
        }

        // Get table size and user input
        tableread >> table_size;
        int roll;
        cout << "Enter Roll: ";
        if (!(cin >> roll)) {
            cout << "Invalid input. Please enter a valid number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        // Populate and print the table
        m.populate_table(tableread, roll);
        m.print_table(roll);

        tableread.close();
        cout << "Search Again?: y/n ";
        cin >> choice;

    } while (choice != 'n');
    break;

    case 4:
    choice = 'y';
    int dieType;
    int numDice;
    int temp;
    int total;
    do {
        temp = 0;
        total = 0;

        cout << "Choose a die type (4, 6, 8, 10, 12, 20, 100): ";
        if (!(cin >> dieType)) {
            cout << "Invalid input. Please enter a valid number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (dieType != 4 && dieType != 6 && dieType != 8 && dieType != 10 && dieType != 12 && dieType != 20 &&
            dieType != 100) {
            cout << "Invalid die type. Please choose from 4, 6, 8, 10, 12, 20, 100." << endl;
            continue;
        }

        cout << "Enter the number of dice to roll: ";
        if (!(cin >> numDice)) {
            cout << "Invalid input. Please enter a valid number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (numDice <= 0) {
            cout << "Number of dice must be greater than 0." << endl;
            continue;
        }

        cout << "Rolling " << numDice << "d" << dieType << ": ";
        for (int i = 0; i < numDice; ++i) {
            temp = rand() % dieType + 1;
            total += temp;
            cout << temp << " ";
        }
        cout << "Total Roll: " << total << endl;

        cout << "Roll again? (y/n): ";
        cin >> choice;
    } while (choice != 'n');
    break;

    case 5:
    choice = 'y';
    do {
        int size;
        cout << "|||-GENERATING NPC-|||" << endl;

        n.gender();

        ifstream exotic("exotic.txt");
        exotic >> size;
        n.populateExotic(exotic, size);
        exotic.close();

        ifstream npcgen("race.txt");
        npcgen >> size;
        n.populateRace(npcgen, size);
        n.printRace();
        npcgen.close();

        ifstream personality("personality.txt");
        personality >> size;
        n.populatePersonaility(personality, size);
        n.printPersonality();
        personality.close();

        ifstream speech("speech.txt");
        speech >> size;
        n.populateSpeech(speech, size);
        n.printSpeech();
        speech.close();

        ifstream physicalFeatures("physicalfeatures.txt");
        physicalFeatures >> size;
        n.populatePhysicalFeatures(physicalFeatures, size);
        n.printPhysicalFeatures();
        physicalFeatures.close();

        cout << endl;
        cout << "Generate again? (y/n): ";
        cin >> choice;
    } while (choice != 'n');
    break;

    case 6:
    choice = 'y';

    do {
        double conversionRates[5][5] = {
            {1, 1.0 / 10, 1.0 / 50, 1.0 / 100, 1.0 / 1000},
            {10, 1, 1.0 / 5, 1.0 / 10, 1.0 / 100},
            {50, 5, 1, 1.0 / 2, 1.0 / 20},
            {100, 10, 2, 1, 1.0 / 10},
            {1000, 100, 20, 10, 1}
        };

        double amount;
        string sourceUnit, targetUnit;

        // Get input and validate
        while (true) {
            cout << "Enter amount: ";
            if (!(cin >> amount)) {
                cout << "Invalid input. Please enter a valid number." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            break;
        }

        // Get source unit and validate
        while (true) {
            cout << "Enter source unit (cp, sp, ep, gp, pp): ";
            cin >> sourceUnit;

            if (cin.fail() || (sourceUnit != "cp" && sourceUnit != "sp" && sourceUnit != "ep" && sourceUnit != "gp" && sourceUnit != "pp")) {
                cout << "Invalid source unit. Please enter a valid unit." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            break;
        }

        // Get target unit and validate
        while (true) {
            cout << "Enter target unit (cp, sp, ep, gp, pp): ";
            cin >> targetUnit;

            if (cin.fail() || (targetUnit != "cp" && targetUnit != "sp" && targetUnit != "ep" && targetUnit != "gp" && targetUnit != "pp")) {
                cout << "Invalid target unit. Please enter a valid unit." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            break;
        }

        // Find indices of units
        int sourceIndex = -1, targetIndex = -1;
        const string units[5] = {"cp", "sp", "ep", "gp", "pp"};

        for (int i = 0; i < 5; ++i) {
            if (sourceUnit == units[i]) {
                sourceIndex = i;
            }

            if (targetUnit == units[i]) {
                targetIndex = i;
            }
        }

        // Check if units are valid
        if (sourceIndex == -1 || targetIndex == -1) {
            cout << "Invalid units specified!" << endl;
            break;
        }

        // Perform conversion
        double result = amount * conversionRates[sourceIndex][targetIndex];
        int wholePart = static_cast<int>(result);
        double leftoverPart = amount - wholePart / conversionRates[sourceIndex][targetIndex];

        // Display result
        cout << amount << " " << sourceUnit << " is equal to " << wholePart << " " << targetUnit << " and " << leftoverPart << " " << sourceUnit << "." << endl;
        cout << "Roll again? (y/n): ";
        cin >> choice;
        } while (choice != 'n');
        break;
    case 7:
    choice = 'y';
    do{
      int size;  
      cout << endl;
      cout << "|||-GENERATING ENCOUNTER-|||" << endl;
      tableread.open("encounter.txt");
      tableread >> size;
      r.populateEncounter(tableread, size);
      r.printEncounter();
      tableread.close();
      cout << "Generate again? (y/n): ";
      cin >> choice;
    } while(choice != 'n');
    break;
        }
    } while (select != 8);
    cout << "Thank You For Using This DM Tool" << endl;
    cout << "Goodbye!" << endl;
    return 0; 
}