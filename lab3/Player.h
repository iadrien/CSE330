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

struct Player {

	string name;
	Hand hand;
	unsigned int won;
	unsigned int lost;
	bool isAuto;

	Player(char* filename);
};

ostream& operator<<(ostream& out, const Player& p);
//ofstream& operator<<(ofstream& out, const Player& p);
bool handRankCompare(const shared_ptr<Player>& p1, const shared_ptr<Player>& p2);


#endif //PLAYER_H_