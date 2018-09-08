/*
Player.h created by Cindy Le, Adrien Xie, and Yanni Yang
*/

#pragma once
#ifndef PLAYER_H_
#define PLAYER_H_

#include "stdafx.h"
#include "Card.h"
#include "Hand.h"
#include "lab.h"

#include <iostream>
#include <fstream>
#include <string>
#include <mutex>

using namespace std;

//A class that represents player who can join a game with chips.
struct Player {

	string name;
	Hand hand;

	bool isAuto; //whether program autoplays for the player
	bool isFold; //whether the player has decided to fold
	unsigned int bet; //the recorded cumulative chips to bet

	// variables to be saved to file
	unsigned int won;
	unsigned int lost;
	unsigned int chip;

	Player(string filename, bool aut);
	string toString(AccessMode mode) const;
	int reset();
};

ostream& operator<<(ostream& out, const Player& p);
bool playerRank(const shared_ptr<Player>& p1, const shared_ptr<Player>& p2);

#endif //PLAYER_H_