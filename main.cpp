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
    const int MENU_INDENT = 25;

    char choice;

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

        switch (choice) {
            case '1':
                cout << "Look up player\n\n";
                break;

            case '2':
                cout << "Edit a player\n\n";
                break;

            case '3':
                cout << "Print team roster\n\n";
                break;

            default:
                break;
        }

    } while (choice != '4');

    return 0;
}
