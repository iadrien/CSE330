/*
Card.cpp created by Cindy Le (lex@wustl.edu)
*/

#include "stdafx.h"
#include "Card.h"

using namespace std;

//struct

bool Card::operator<(const Card& c) const {
	//compares for by rank then suit
	return rank * 4 + suit < c.rank * 4 + c.suit;
}

bool Card::operator==(const Card& c) const {
	//compares for by rank then suit
	return rank * 4 + suit == c.rank * 4 + c.suit;
}

