#pragma once

#include <iostream>

using namespace std;

class Player
{
private:
	string name;
	int nHits;
	int nWalks;
	int nOuts;
	float batAverage;
public:
	// constructors
	Player();
	Player(string initName, int initHits, int initWalks, int initOuts);

	// destructor
	~Player();

	// member function
	void inlinePlayerDat();

};

