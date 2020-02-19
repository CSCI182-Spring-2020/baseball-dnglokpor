/*
CSCI 182 - Assignment 7
Baseball.cpp
create a baseball player class, get data of that type and print it.

Brett Huffman
v1.0 2/16/2020
*/

#include <iostream>
#include <iomanip>
#include<fstream>
#include "Player.h" // created class

using namespace std;

// fore declarations
void listTeamData(string teamName, Player team[], int teamSize);
void fortyStarsLine();


int main()
{
    const int MAX_NUM_PLAYER = 15;

    // file management 
    ifstream inFile;

    // opening file
    inFile.open("BoxScore.txt");
    
    if (!inFile) { // making sure the file can be accessed
        cout << "Can't find file or file already being used";
        exit(1);
    }

    // array of players
    Player localTeam[MAX_NUM_PLAYER];

    // data reading from file
    int importCount = 0;
    string tempN;
    int tempH, tempW, tempO; // for reading before record

    while (!inFile.eof() && importCount < MAX_NUM_PLAYER) {
        // read in file
        inFile >> tempN >> tempH >> tempW >> tempO;
        // storing in array
        localTeam[importCount] = Player(tempN, tempH, tempW, tempO);
        importCount++;
    }
    // close file
    inFile.close();

    // printing team data
    listTeamData("Local Team", localTeam, MAX_NUM_PLAYER);
}

// external functions
/// <summary>
/// Pretty print the list of the team players and their data on screen
/// </summary>
/// <param name="team"></param>
/// <param name="teamSize"></param>
void listTeamData(string teamName, Player team[], int teamSize) {
    
    fortyStarsLine();
    cout << teamName << " Lineup" << endl;
    fortyStarsLine();
    cout << "\t" << "H W O Bat Average" << endl;
    for (int i = 0; i < teamSize; i++)
        team[i].inlinePlayerDat();
    fortyStarsLine();
}

/// <summary>
/// Draw a line of 40 "*" characters
/// </summary>
void fortyStarsLine() {

    for (int i = 0; i < 40; i++)
        cout << "*";
    cout << endl;
}