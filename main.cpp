/*******************************************
 * AUTHOR   : GRANT GOLDSWORTH
 * ID	    : 1164709
 * PROJECT  : A4
 * DUE DATE : 1/27/2020
*******************************************/

#include "functions.h"

/*******************************************************************************
 * A6 - STRUCTS
 * -----------------------------------------------------------------------------
 * This program will allow the user to navigate a simple database of
 * football players, view the roster, and manage their stats.
 * Input will be read from a file, and changes will be saved to a different
 * output file.
 *
 * INPUT
 *      - This program reads information from a txt input file, with data stored
 *        in the format:
 *              Lastname, firstname
 *              Position
 *              Touchdowns
 *              Catches
 *              Passing Yards
 *              Receiving Yards
 *              Rushing Yards
 *
 *         This program will receive input from the user on where they
 *         wish to navigate in the program's menus.
 *
 * OUTPUT
 *      - This program will output menus, as well as (upon prompt) information
 *      for a single player, or the entire team roster. The program will save changes
 *      made to the roster to a new output txt file, saved in the same format
 *      as the input file.
 *******************************************************************************/

int main() {
    /*******************************************************************************
     * CONSTANTS
     * -----------------------------------------------------------------------------
     * MENU_INDENT  : CALC -  Used to format the main menu
     * PLAYER_COUNT : CALC - The number of players in the roster and thus the size of
     *                          the database array
     *******************************************************************************/
    const int MENU_INDENT  = 25;
    const int PLAYER_COUNT = 10;

    playerType roster[PLAYER_COUNT];    // IN CALC OUT - The array containing players and their information
    char choice;                        // IN CALC     - the user's navigation choice in menus

    // INPUT - Obtain information from input file and store it into roster array
    readFile(roster, PLAYER_COUNT,"teamRoster.txt");

    system("cls");


    /*******************************************************************************
     * DO-WHILE LOOP
     * -----------------------------------------------------------------------------
     * Hold user in a menu and prompt for choice. Allow navigation to modules
     * for looking up a player, editing a player, and outputing the entire roster
     *******************************************************************************/

    do { // while (choice != '4')
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
            // look up a player in the database
            case '1':
                lookUpPlayer(roster, PLAYER_COUNT);
                break;

            // edit a player
            case '2':
                editPlayer(roster, PLAYER_COUNT);
                break;

            // print the entire team roster with info for each player
            case '3':
                printTeam(roster, PLAYER_COUNT);
                break;

            default:
                break;
        } // end switch (choice)
        system("cls");

        // save changes after every menu module
        writeFile(roster, PLAYER_COUNT, "output.txt");

    } while (choice != '4');
    return 0;
}
