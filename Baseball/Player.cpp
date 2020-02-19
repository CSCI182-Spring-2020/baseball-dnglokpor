#pragma once

#include <iostream>
#include "Player.h"

using namespace std;

/// <summary>
/// Instantiate an default noname zero-ed Player
/// </summary>
Player::Player() {
	name = "";
	nHits = 0;
	nWalks = 0;
	nOuts = 0;
	batAverage = 0.0f;
}

/// <summary>
/// Instantiate a Player with the passed name, hits, walks and outs.
/// Plus compute its batting average and add them to the object.
/// </summary>
/// <param name="initName"></param>
/// <param name="initHits"></param>
/// <param name="initWalks"></param>
/// <param name="initOuts"></param>
Player::Player(string initName, int initHits, int initWalks, int initOuts) {
	name = initName;
	nHits = initHits;
	nWalks = initWalks;
	nOuts = initOuts;
	batAverage = static_cast<float>(nHits) / static_cast<float>(nHits + nOuts); // how to get only two decimals?
}

/// <summary>
/// Destroy any instance of Player object
/// </summary>
Player::~Player() {}; 

/// <summary>
/// Print inline all the informations of a Player instance
/// </summary>
void Player::inlinePlayerDat() {
	cout << name << "\t" << nHits << " " << nWalks << " " << nOuts << " "
		<< batAverage << endl;
}