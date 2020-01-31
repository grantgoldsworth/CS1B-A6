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
 * This function receives a string
 * ===> returns a string with all alphabetical characters converted
 *      to lowercase equivalents
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 * 			str: a string
 *
 * POST-CONDITIONS
 *		This function will return a copy of the input string without modifying
 *		the actual parameter
 ******************************************************************************/

string tolowerstring(string str) { // VALUE - the string to convert to lowercase

    // iterate and convert each alphabet character, if possible
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

char GetChoice(int min,     // VALUE - the minimum choice bound
               int max) {   // VALUE - the max choice bound

    char  input;        // input from user
    int   asciiInput;   // input converted to ASCII integer value
    bool  invalidInput; // if user input is invalid

    // convert boundaries to ascii so they can be compared against non-numeric chars
    int asciiMin = min + 48;
    int asciiMax = max + 48;

    do {
        cout << "Enter a choice [" << min << " - " << max << "]: ";
        cin.get(input);
        cin.ignore(1000, '\n');

        // convert input integer to ASCII
        asciiInput = (int)input;

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
 * This function receives an array of playerType, and an int representing
 * the number of players in the array
 * ===> returns nothing. makes changes to the actual parameter teamRoster
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 * 		    teamRoster   : An array of playerType
 * 		    PLAYER_COUNT : the number of entries in teamRoster
 *
 * POST-CONDITIONS
 *      This function will modify the actual parameter teamRoster
 ******************************************************************************/

void editPlayer(playerType teamRoster[],  // REF   - the array of players, PLAYER_COUNT entries
                const int PLAYER_COUNT) { // VALUE - the number of entires in teamRoster

    const int MENU_SIZE = 40;   // menu formatting constant

    int playerIndex;    // the roster index of the player user wants to edit
    char choice;        // what user wants to choose in edit menu
    string target;      // the target player (substring) to use to search for player

    // get (sub)string from user as search query
    cout << "Who would you like to edit? ";
    getline(cin, target);

    // search for closest match to target and return index, - 1 if no match
    playerIndex  = searchPlayer(teamRoster, PLAYER_COUNT, target);


    if (playerIndex != -1) {
        do { // while (choice != '8')

            // output the menu screen and the information of the target player
            cout << left;
            cout << setfill('=') << setw(MENU_SIZE) << '=' << endl;
            cout << setfill(' ');
            cout << setw(MENU_SIZE) << "| " << "| CURRENT VALUES\n";
            cout << setw(MENU_SIZE) << "| [1] Edit name" << ": "
                 << teamRoster[playerIndex].name
                 << endl;

            cout << setw(MENU_SIZE) << "| [2] Edit position" << ": "
                 << teamRoster[playerIndex].position
                 << endl;

            cout << setw(MENU_SIZE) << "| [3] Edit number of touchdowns" << ": "
                 << teamRoster[playerIndex].touchdowns
                 << endl;

            cout << setw(MENU_SIZE) << "| [4] Edit number of catches   " << ": "
                 << teamRoster[playerIndex].catches
                 << endl;

            cout << setw(MENU_SIZE) << "| [5] Edit number of passing yards" << ": "
                 << teamRoster[playerIndex].passingYards
                 << endl;

            cout << setw(MENU_SIZE) << "| [6] Edit number of receiving yards" << ": "
                 << teamRoster[playerIndex].receivingYards
                 << endl;

            cout << setw(MENU_SIZE) << "| [7] Edit number of rushing yards" << ": "
                 << teamRoster[playerIndex].rushingYards
                 << endl;

            cout << setw(MENU_SIZE) << "| [8] Return to Main Menu" << "|\n";
            cout << setfill('=') << setw(MENU_SIZE) << '=' << endl;

            // obtain edit choice from user
            choice = GetChoice(1, 8);

            // allow user to change specified data
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
            } // end switch (choice)
            system("cls");

        // end do-while
        } while (choice != '8');

    } // end if (playerIndex != -1)

    else {
        // if searchPlayer returns -1 for no match
        cout << "That player was not found. Return to main menu...\n";
        system("pause");
    }

    // reset the output fill constant
    cout << setfill(' ');
    return;
}



/******************************************************************************
 * FUNCTION - lookUpPlayer
 * ____________________________________________________________________________
 * This function receives an array of playerType, and an integer representing
 * the number of entries in teamRoster. It will prompt for a substring to use
 * as a search query, and output all matches (if any). If there are, allow
 * user to select which match they wish to have more information displayed for.
 * ===> returns nothing. outputs data for target
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 * 		    teamRoster   : an array containing playerType entries
 * 		    PLAYER_COUNT : an int representing how many players (entries) there are
 * 		                    in the roster array
 *
 * POST-CONDITIONS
 *      This function does not modify the actual parameters.
 *      This function will output data regarding the target player
 *
 ******************************************************************************/

void lookUpPlayer(const playerType teamRoster[], // REF   - the array of players
                  const int PLAYER_COUNT) {      // VALUE - the number of entries in teamRoster

    string  nameMatches[PLAYER_COUNT];       // array containing matches to substring query
    int     nameMatchIndicies[PLAYER_COUNT]; // array containing indexes of substring matches that
                                             // correspond to the roster array

    int     index;      // teamRoster index of target search player
    string  target;     // the name of the search target
    int     i;          // loop control variable
    int     matchCount; // the number of substring matches
    char    choice;     // user's choice on what match to select

    // initialize the number of matches since no search has been done yet :P
    matchCount = 0;

    // obtain the substring query
    cout << "Who would you like to search for? ";
    getline(cin, target);

    // convert substring to lowercase for case insensitive searching
    target = tolowerstring(target);

    /*****************************************************************************
     * FOR-LOOP
     * Iterate through the teamRoster array and compare (lowercase converted) player
     * names to the substring query provided by the user. If there is a match
     * (substring is within the name), add the name to the nameMatches array, and
     * add the teamRoster index to the array of index matches so information can be
     * displayed later upon user specification.
     *****************************************************************************/
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

    // output all of the matches for the substring
    cout << "\nMatches for <" << target << ">:\n";
    for (int j = 0; j < matchCount; j++) {
        cout << "[" << j + 1 << "] " << nameMatches[j] << endl;
    }

    // if there are matches, allow user to choose who they want to have information
    // displayed for
    if (matchCount != 0) {
        cout << "[0] Cancel and return to menu\n";
        choice = GetChoice(0, matchCount);

        // if user does not want to immediately return to main menu,
        // display information for choice
        if (choice != '0') {
            index = nameMatchIndicies[choice - 49];

            cout << left << endl;
            cout << setw(20) << "Name: "            << teamRoster[index].name << endl;
            cout << setw(20) << "Position: "        << teamRoster[index].position << endl;
            cout << setw(20) << "Touchdowns: "      << teamRoster[index].touchdowns << endl;
            cout << setw(20) << "Catches: "         << teamRoster[index].catches << endl;
            cout << setw(20) << "Passing Yards: "   << teamRoster[index].passingYards << endl;
            cout << setw(20) << "Receiving Yards: " << teamRoster[index].receivingYards << endl;
            cout << setw(20) << "Rushing Yards: "   << teamRoster[index].rushingYards << endl;
            cout << right;
        }
    }
    else {
        // no matches. return to main menu.
        cout << "There were no matches for <" << target << ">.\n";
    }
    system("pause");
}



/******************************************************************************
 * FUNCTION - searchPlayer
 * ____________________________________________________________________________
 * This function receives an array of playerType, and integer for number of entries
 * in the playerType array, and a string for a search target.
 * ===> returns index of search target corresponding to position in teamRoster
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 * 		    teamRoster   : an array containing playerType entries
 * 		    PLAYER_COUNT : an int representing how many players (entries) there are
 * 		                    in the roster array
 *          target       : the search target
 * POST-CONDITIONS
 *      This function does not modify the actual parameters.
 *      This function will return the index of the search target, or -1
 *          if the target is not found in teamRoster
 ******************************************************************************/

int searchPlayer(const playerType teamRoster[], // REF   - the array of players
                 const int PLAYER_COUNT,        // VALUE - the number of entries in teamRoster
                 string target) {               // VALUE - the target to search for

    int index;  // holds teamRoster position of target player
    int i;      // loop control variable

    // convert target to lowercase for case insensitive searching
    target = tolowerstring(target);
    // technically target has not been found, so set index to unfound status
    index = -1;

    /*****************************************************************************
     * FOR-LOOP
     * Iterate through the teamRoster array and compare (lowercase converted) player
     * names to the string target query. If it is a match, set the index equal to the
     * teamRoster name's position. Continue from end of teamRoster to front of teamRoster,
     * setting index to new position if there is a new match.
     *****************************************************************************/
    for (i = PLAYER_COUNT - 1; i >= 0; i -- ) {

        string lowerCaseName = tolowerstring(teamRoster[i].name);

        if ( lowerCaseName.find(target) != string::npos) {
            index = i;
        }
    }

    return index;
}



/******************************************************************************
 * FUNCTION - printPlayer
 * ____________________________________________________________________________
 * This function receives an array of playerType, and integer for data table
 * formatting, and an integer as a target index. This function will print
 * a formatted single row table displaying name and football stats for
 * the (index) targeted player
 * ===> returns nothing.
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 * 		    teamRoster      : the array of players
 * 		    DATA_COL        : the column size for data in the table
 *          index           : the teamRoster index of the player being displayed
 *
 * POST-CONDITIONS
 *      This function does not modify the actual parameters.
 *      just outputs stuff.
 ******************************************************************************/

void printPlayer(const playerType teamRoster[], // REF   - The array of players
                 int DATA_COL, // VALUE - the table column size
                 int index) {  // VALUE - teamRoster location of player being displayed
    const int NAME_COL  = 30;

    playerType target = teamRoster[index];

    // output information of target player
    cout << left  << setw(NAME_COL) <<target.name;
    cout << right << setw(3)  << target.position << setw(DATA_COL) << target.touchdowns << setw(DATA_COL) << target.catches
         << setw(DATA_COL) << target.passingYards << setw(DATA_COL) << target.receivingYards
         << setw(DATA_COL) << target.rushingYards << endl;

    return;
}



/******************************************************************************
 * FUNCTION - printTeam
 * ____________________________________________________________________________
 * This function does the same thing as printTeam but for every player
 * in the teamRoster array.
 * ===> returns nothing
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 * 		    teamRoster      : the array of players
 * 		    DATA_COL        : the column size for data in the table
 *          index           : the teamRoster index of the player being displayed
 *
 * POST-CONDITIONS
 *      This function does not modify the actual parameters
 *
 ******************************************************************************/

void printTeam(const playerType teamRoster[],  // REF   - The array of players
              const int PLAYER_COUNT) {        // VALUE - The number of entr- okay you get it now
              const int COLUMN_SIZE = 9;       // VALUE - fomatting

    system("cls");
    cout << "Team Roster -- Displaying " << PLAYER_COUNT << "players.\n\n";

    // output the stuff. trust me, it looks a lot better once it outputs.
    // formatted output source code is hideous
    cout << left  << setw(30) << "Name";
    cout << right << setw(3)  << "Pos" << setw(COLUMN_SIZE) << "TDs" << setw(COLUMN_SIZE) << "Catches"
         << setw(COLUMN_SIZE) << "Pass" << setw(COLUMN_SIZE) << "Recv" << setw(COLUMN_SIZE + 1) << "Rush\n";
    cout << setw(30 + 3 + 3 * COLUMN_SIZE) << "Yds" << setw(COLUMN_SIZE) << "Yds"
         << setw(COLUMN_SIZE + 1) << "Yds\n";

    for (int i = 0; i < PLAYER_COUNT; i ++) {
        cout << setfill('-') << setw(30 + 6 * COLUMN_SIZE) << "-\n" << setfill(' ');
        printPlayer(teamRoster, COLUMN_SIZE, i);
    }

    system("pause");
    return;
}



/******************************************************************************
 * FUNCTION readFile
 * ____________________________________________________________________________
 * This function receives an array of playerType, an int, and a string for the
 * file to read from
 * ===> returns nothing
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 * 		    playerType   : the array to have information read in to
 * 		    PLAYER_COUNT : the number of players to read in information for
 * 		    inputFile    : the target input file data source thing
 *
 * POST-CONDITIONS
 *      This function will modify the contents of teamRoster
 *
 ******************************************************************************/

void readFile(playerType teamRoster[],   // REF   - the array of players
              const int PLAYER_COUNT,    // VALUE - the number of entries to read in
              const string inputFile) {  // VALUE - the file to read from

    ifstream fin;   // file input stream controller
    int i;          // loop control variable

    // open sesame
    fin.open(inputFile.c_str());

    /*****************************************************************************
     * WHILE-LOOP
     * Runs similar to a for loop but has exit condition set for if the loop
     * reaches the end of the input file before reaching maximum player input.
     *
     * Read in data from input file, and store into playerType entries of teamRoster
     *****************************************************************************/

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
 * FUNCTION writeFile
 * ____________________________________________________________________________
 * This function receives an array of playerType, an int, and a string for the
 * file to save data to
 * ===> returns nothing
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 * 		    playerType    : the array to read information from into the output file
 * 		    PLAYER_COUNT  : the number of players to read out information for
 * 		    outputFile    : the target output file to store new player data to
 *
 * POST-CONDITIONS
 *      This function will not modify the actual parameters.
 *      This function will erase contents of the output file, and store
 *          new player information into it.
 *
 ******************************************************************************/

void writeFile(const playerType teamRoster[], // REF - The array of players
               int PLAYER_COUNT,    // VALUE - the number of entries in teamRoster
               string outputFile) { // VALUE - the output file to save data into

    ofstream fout;  // output file stream control

    // open sesame
    fout.open(outputFile.c_str());

    for (int i = 0; i < PLAYER_COUNT; i ++) {
        fout << teamRoster[i].name << endl;
        fout << teamRoster[i].position << endl;
        fout << teamRoster[i].touchdowns << endl;
        fout << teamRoster[i].catches << endl;
        fout << teamRoster[i].passingYards << endl;
        fout << teamRoster[i].receivingYards << endl;
        fout << teamRoster[i].rushingYards << endl;
    }

    fout.close();

    return;
}
