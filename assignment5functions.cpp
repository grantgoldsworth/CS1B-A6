/*******************************************
 * AUTHOR   : GRANT GOLDSWORTH
 * ID	    : 1164709
 * PROJECT  : A4
 * DUE DATE : 1/27/2020
*******************************************/

#include "functions.h"

/******************************************************************************
 * FUNCTION - GetChoice
 * ____________________________________________________________________________
 * This function receives two integers representing a min and a max bound
 * ===> returns a character that holds an integer
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 * 			min: the integer to represent the minimum choice for a menu
 * 			max: the integer to represent the maximum choice for a menu
 *
 * POST-CONDITIONS
 *		This function will return a character representing the user's choice,
 *		once it has been error-checked
 ******************************************************************************/

char GetChoice(int min, int max) {
    char  input;
    int   asciiInput;
    bool  invalidInput;

    // convert boundaries to ascii so they can be compared against non-numeric chars
    int asciiMin = min + 48;
    int asciiMax = max + 48;

    do {
        cout << "Enter a choice [" << min << " - " << max << "]: ";
        cin.get(input);
        cin.ignore(1000, '\n');

        // convert input integer to ASCII
        asciiInput = input - 0;

        // determine if input is out of bounds specified in input
        invalidInput = (asciiInput > asciiMax || asciiInput < asciiMin);

        // output error message for out of bounds choice
        if (invalidInput) {
            cout << "*** Invalid Input - Please enter a valid choice. *** \n";
        }

    } while (invalidInput);

    system("cls");
    return input;
}



/******************************************************************************
 * FUNCTION - editPlayer
 * ____________________________________________________________________________
 * This function receives
 * ===> returns
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 *
 * POST-CONDITIONS
 *
 ******************************************************************************/

void editPlayer(playerType []) {
    cout << "Edit player\n\n";
    return;
}



/******************************************************************************
 * FUNCTION - lookUpPlayer
 * ____________________________________________________________________________
 * This function receives
 * ===> returns
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 *
 * POST-CONDITIONS
 *
 ******************************************************************************/

int lookUpPlayer(playerType []) {
    int index = -1;
    cout << "Look up player\n\n";
    return index;
}



/******************************************************************************
 * FUNCTION - printPlayer
 * ____________________________________________________________________________
 * This function receives
 * ===> returns
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 *
 * POST-CONDITIONS
 *
 ******************************************************************************/

void printPlayer(playerType) {
    cout << "Print player\n\n";
    return;
}



/******************************************************************************
 * FUNCTION - printTeam
 * ____________________________________________________________________________
 * This function receives
 * ===> returns
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 *
 * POST-CONDITIONS
 *
 ******************************************************************************/

void printTeam(playerType []) {
    cout << "Print team\n\n";
    return;
}



/******************************************************************************
 * FUNCTION readFile
 * ____________________________________________________________________________
 * This function receives
 * ===> returns
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 *
 * POST-CONDITIONS
 *
 ******************************************************************************/

void readFile(playerType [], string inputFile) {
    cout << "Read file input\n\n";
    return;
}



/******************************************************************************
 * FUNCTION - writeFile
 * ____________________________________________________________________________
 * This function receives
 * ===> returns
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 *
 * POST-CONDITIONS
 *
 ******************************************************************************/

void writeFile(playerType [], string outputFile) {
    cout << "Read file output\n\n";
    return;
}
