/*******************************************
 * AUTHOR   : GRANT GOLDSWORTH
 * ID	    : 1164709
 * PROJECT  : A4
 * DUE DATE : 1/27/2020
*******************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>
#include <fstream>
using namespace std;

#ifndef CS1B_A6_FUNCTIONS_H
#define CS1B_A6_FUNCTIONS_H

struct playerType
{
    string name;
    string position;
    int    touchdowns;
    int    catches;
    int    passingYards;
    int    receivingYards;
    int    rushingYards;
};

char GetChoice(int, int);

string tolowerstring(string);

void editPlayer(playerType [], int);

int lookUpPlayer(const playerType [], int);

void printPlayer(playerType);

void printTeam(playerType []);

void readFile(playerType [], int, string inputFile);

void writeFile(playerType [], string outputFile);

#endif //CS1B_A6_FUNCTIONS_H
