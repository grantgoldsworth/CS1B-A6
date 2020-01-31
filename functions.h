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

void lookUpPlayer(const playerType [], int);

int searchPlayer(const playerType [], int, string);

void editPlayer(playerType [], int);

void printPlayer(const playerType [], int, int);

void printTeam(const playerType [], int);

void readFile(playerType [], int, string);

void writeFile(const playerType [], int, string);

#endif //CS1B_A6_FUNCTIONS_H
