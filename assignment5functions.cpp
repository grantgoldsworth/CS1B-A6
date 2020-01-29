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

    playerIndex  = lookUpPlayer(teamRoster, PLAYER_COUNT);
    cout << "\nPLAYER INDEX: " << playerIndex << endl;

    if (playerIndex != -1) {
        do {
            cout << left;
            cout << setfill('=') << setw(MENU_SIZE) << '=' << endl;
            cout << setfill(' ');
            cout << setw(MENU_SIZE) << "| " << "| CURRENT VALUES\n";
            cout << setw(MENU_SIZE) << "| [1] Edit name" << ": " << teamRoster[playerIndex].name << endl;
            cout << setw(MENU_SIZE) << "| [2] Edit position" << ": " << teamRoster[playerIndex].position << endl;
            cout << setw(MENU_SIZE) << "| [3] Edit number of touchdowns" << ": " << teamRoster[playerIndex].touchdowns
                 << endl;
            cout << setw(MENU_SIZE) << "| [4] Edit number of catches   " << ": " << teamRoster[playerIndex].catches
                 << endl;
            cout << setw(MENU_SIZE) << "| [5] Edit number of passing yards" << ": "
                 << teamRoster[playerIndex].passingYards
                 << endl;
            cout << setw(MENU_SIZE) << "| [6] Edit number of receiving yards" << ": "
                 << teamRoster[playerIndex].receivingYards << endl;
            cout << setw(MENU_SIZE) << "| [7] Edit number of rushing yards" << ": "
                 << teamRoster[playerIndex].rushingYards
                 << endl;
            cout << setw(MENU_SIZE) << "| [8] Return to Main Menu" << "|\n";
            cout << setfill('=') << setw(MENU_SIZE) << '=' << endl;

            choice = GetChoice(1, 8);

            switch (choice) {
                case '1':
                    cout << "Edit player's name: ";
                    getline(cin, teamRoster[playerIndex].name);
                    break;

                case '2':
                    cout << "Edit position of " << teamRoster[playerIndex].name << ": ";
                    getline(cin, teamRoster[playerIndex].position);
                    break;

                case '3':
                    cout << "Edit touchdowns for " << teamRoster[playerIndex].name << ": ";
                    cin >> teamRoster[playerIndex].touchdowns;
                    cin.ignore(1000, '\n');
                    break;

                case '4':
                    cout << "Edit catches for " << teamRoster[playerIndex].name << ": ";
                    cin >> teamRoster[playerIndex].catches;
                    cin.ignore(1000, '\n');
                    break;

                case '5':
                    cout << "Edit passing yards for " << teamRoster[playerIndex].name << ": ";
                    cin >> teamRoster[playerIndex].passingYards;
                    cin.ignore(1000, '\n');
                    break;

                case '6':
                    cout << "Edit receiving yards for " << teamRoster[playerIndex].name << ": ";
                    cin >> teamRoster[playerIndex].receivingYards;
                    cin.ignore(1000, '\n');
                    break;

                case '7':
                    cout << "Edit rushing yards for " << teamRoster[playerIndex].name << ": ";
                    cin >> teamRoster[playerIndex].rushingYards;
                    cin.ignore(1000, '\n');
                    break;

                default:
                    break;
            }
            system("cls");

        } while (choice != '8');
    } // end if (playerIndex != -1)

    cout << setfill(' ');
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
    int index;
    string target;
    bool found;
    int i;
    int matchCount;
    char choice;
    string nameMatches[PLAYER_COUNT];
    int nameMatchIndicies[PLAYER_COUNT];

    matchCount = 0;
    index      = -1;

    cout << "Who would you like to search for? ";
    getline(cin, target);
    target = tolowerstring(target);


    for (i = 0; i < PLAYER_COUNT; i++) {

        // convert player's name to lowercase to allow for case insensitive searching
        string lowerCaseName = tolowerstring(teamRoster[i].name);

        // if there is a match of any kind, add it to list of matches
        // record the index of each match for when user selects which one they want.
        if (lowerCaseName.find(target) != string::npos) {
            nameMatches[matchCount] = teamRoster[i].name;
            nameMatchIndicies[matchCount] = i;
            matchCount++;
        }
    } // end for (i = 0; i < PLAYER_COUNT; i ++)

    cout << "Matches for <" << target << ">:\n";
    for (int j = 0; j < matchCount; j++) {
        cout << "[" << j + 1 << "] " << nameMatches[j] << " with roster index " << nameMatchIndicies[j] << endl;
    }

    if (matchCount != 0) {
        cout << "[0] Cancel and return to menu\n";
        choice = GetChoice(0, matchCount + 1);

        if (tolower(choice) != '0') {
            index = nameMatchIndicies[choice - 49];
        }
    }
    else {
        cout << "There were no matches for <" << target << ">.\n";
    }

    system("pause");
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
