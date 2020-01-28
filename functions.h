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

void editPlayer(playerType []);

int lookUpPlayer(playerType []);

void printPlayer(playerType);

void printTeam(playerType []);

void readFile(playerType [], string inputFile);

void writeFile(playerType [], string outputFile);

#endif //CS1B_A6_FUNCTIONS_H
