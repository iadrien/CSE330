/*
FiveCardDraw.h created by Cindy Le, Adrien Xie, and Yanni Yang
*/

#pragma once
#ifndef FiveCardDraw_H_
#define FiveCardDraw_H_


#include "Game.h"
#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "Hand.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector> 
#include <string>

using namespace std;

class FiveCardDraw : public Game {
		void autoPlayerLeave();
		vector<int> FiveCardDraw::findAuto();
		//void autoDiscard();
		//void discard(int handRank);
	public:
		FiveCardDraw();
		virtual int before_turn(Player& p);
	    virtual int turn(Player& p);
		virtual int after_turn(Player& p);
		virtual int before_round();
		virtual int round();
		virtual int after_round();
		
	protected:
		size_t dealer;
		Deck discardDeck;
};

#endif  //FiveCardDraw_H_
