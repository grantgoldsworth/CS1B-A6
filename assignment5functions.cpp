/*******************************************
 * AUTHOR   : GRANT GOLDSWORTH
 * ID	    : 1164709
 * PROJECT  : A4
 * DUE DATE : 1/27/2020
*******************************************/

#include "functions.h"

/******************************************************************************
 * FUNCTION - tolowerstring
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

string tolowerstring(string str) {

    for (int i = 0; i < str.length(); i ++) {
        str[i] = tolower(str[i]);
    }

    return str;
}

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

void editPlayer(playerType teamRoster[], const int PLAYER_COUNT) {

    const int MENU_SIZE = 40;

    int playerIndex;
    char choice;
    playerType targetPlayer;

    playerIndex  = lookUpPlayer(teamRoster, PLAYER_COUNT);
    targetPlayer = teamRoster[playerIndex];


    cout << left;
    cout << setfill('=') << setw(MENU_SIZE) << '=' << endl;
    cout << setfill(' ');
    cout << setw(MENU_SIZE) << "| "                                   << "| CURRENT VALUES\n";
    cout << setw(MENU_SIZE) << "| [1] Edit name"                      << ": " << targetPlayer.name << endl;
    cout << setw(MENU_SIZE) << "| [2] Edit position"                  << ": " << targetPlayer.position << endl;
    cout << setw(MENU_SIZE) << "| [3] Edit number of touchdowns"      << ": " << targetPlayer.touchdowns << endl;
    cout << setw(MENU_SIZE) << "| [4] Edit number of catches   "      << ": " << targetPlayer.catches << endl;
    cout << setw(MENU_SIZE) << "| [5] Edit number of passing yards"   << ": " << targetPlayer.passingYards << endl;
    cout << setw(MENU_SIZE) << "| [6] Edit number of receiving yards" << ": " << targetPlayer.receivingYards << endl;
    cout << setw(MENU_SIZE) << "| [7] Edit number of rushing yards"   << ": " << targetPlayer.rushingYards << endl;
    cout << setw(MENU_SIZE) << "| [8] Return to Main Menu"            << "|\n";
    cout << setfill('=') << setw(MENU_SIZE) << '=' << endl;

    cout << "Enter option [1-8]: ";
    choice = GetChoice(1, 8);

    switch (choice) {
        case '1':
            cout << "Edit player's name: ";
            getline(cin, targetPlayer.name);
            break;

        case '2':
            cout << "Edit position of " << targetPlayer.name << ": ";
            getline(cin, targetPlayer.position);
            break;

        case '3':
            cout << "Edit touchdowns for " << targetPlayer.name << ": ";
            cin  >> targetPlayer.touchdowns;
            cin.ignore(1000, '\n');

        case '4':
            cout << "Edit catches for " << targetPlayer.name << ": ";
            cin  >> targetPlayer.catches;
            cin.ignore(1000, '\n');

        case '5':
            cout << "Edit passing yards for " << targetPlayer.name << ": ";
            cin  >> targetPlayer.passingYards;
            cin.ignore(1000, '\n');

        case '6':
            cout << "Edit receiving yards for " << targetPlayer.name << ": ";
            cin  >> targetPlayer.receivingYards;
            cin.ignore(1000, '\n');

        case '7':
            cout << "Edit rushing yards for " << targetPlayer.name << ": ";
            cin  >> targetPlayer.rushingYards;
            cin.ignore(1000, '\n');

        default:
            break;
    }
    system("cls");



    system("pause");
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

int lookUpPlayer(const playerType teamRoster[], const int PLAYER_COUNT) {
    int     index;
    string  target;
    bool    found;
    int     i;

    cout << "Who would you like to search for? ";
    getline(cin, target);

    target = tolowerstring(target);
    i = 0;
    found = false;
    index = -1;

    while (i < PLAYER_COUNT && !found) {
        // convert player's name to lowercase to allow for case insensitive searching
        string lowerCaseName = tolowerstring(teamRoster[i].name);

        // if substring target is within name, set found to true and return index of
        //     player location in the team roster array
        if (lowerCaseName.find(target) != string::npos) {
            index = i;
            found = true;
        }
        i ++;
    }

    if (found) {
        cout << "Player found!\n";
    }
    else {
        cout << "Player not found!\n";
    }

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
    system("pause");
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
    system("pause");
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

void readFile(playerType teamRoster[], const int PLAYER_COUNT, const string inputFile) {
    ifstream fin;
    int i;

    fin.open(inputFile.c_str());

    i = 0;
    while (fin && i < PLAYER_COUNT) {
        // get name from file
        getline(fin, teamRoster[i].name);

        // get position from file
        getline(fin, teamRoster[i].position);

        // get touchdowns from file
        fin >> teamRoster[i].touchdowns;

        // get catches from file
        fin >> teamRoster[i].catches;

        // get passing yards
        fin >> teamRoster[i].passingYards;

        // get receiving yards
        fin >> teamRoster[i].receivingYards;

        // get rushing yards
        fin >> teamRoster[i].rushingYards;

        fin.ignore(3, '\n');
        i ++;
    }
    fin.close();
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
    system("pause");
    return;
}
