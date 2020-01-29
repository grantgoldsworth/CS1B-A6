/*******************************************
 * AUTHOR   : GRANT GOLDSWORTH
 * ID	    : 1164709
 * PROJECT  : A4
 * DUE DATE : 1/27/2020
*******************************************/

#include "functions.h"

int main() {
    /*******************************************************************************
     * CONSTANTS
     * -----------------------------------------------------------------------------
     * MENU_INDENT  : CALC -  Used to format the main menu of serendipity
     *******************************************************************************/
    const int MENU_INDENT  = 25;
    const int PLAYER_COUNT = 10;

    playerType roster[PLAYER_COUNT];
    char choice;
    int  index;

    readFile(roster, PLAYER_COUNT,"teamRoster.txt");

    cout << "\n\n OUTPUTING THE CONTENTS OF TEAM ROSTER ARRAY\n\n";
    for (int j = 0; j < PLAYER_COUNT; j ++) {
        cout << roster[j].name << endl;
        cout << roster[j].position << endl;
        cout << roster[j].catches << endl;
        cout << roster[j].touchdowns << endl;
        cout << roster[j].passingYards << endl;
        cout << roster[j].receivingYards << endl;
        cout << roster[j].rushingYards << endl << endl;
    }
    cout << endl;
    system("pause");
    system("cls");


    do {
        // main menu screen output
        cout << right;
        cout << setw(45) << "==[ Team Manager ]==\n";
        cout << setw(45) << "--- Main Menu ---\n\n";

        cout << left;
        cout << setw(MENU_INDENT) << " " << "[1] Look up a player\n";
        cout << setw(MENU_INDENT) << " " << "[2] Edit a player\n";
        cout << setw(MENU_INDENT) << " " << "[3] Print team roster\n";
        cout << setw(MENU_INDENT) << " " << "[4] Exit...\n";
        cout << right;

        choice = GetChoice(1, 4);
        system("cls");

        switch (choice) {
            case '1':
                index = lookUpPlayer(roster, PLAYER_COUNT);
                break;

            case '2':
                editPlayer(roster, PLAYER_COUNT);
                break;

            case '3':
                printTeam(roster);
                break;

            default:
                break;
        } // end switch (choice)
        system("cls");

    } while (choice != '4');
    return 0;
}
