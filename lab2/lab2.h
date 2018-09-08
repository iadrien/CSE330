#include "stdafx.h"
#include "Card.h"
#include <vector>
#include <cstdlib>
#include <random>
#include <algorithm>

using namespace std;

string showCard(Cards printCards);

/*
* lab2 header file implementing classes with required constructors/deconstructors
* and other methods/operators to present deck and hand in card game
*
* lab2 requirements are mostly implemented in this header file. Some minor changes
* are made to previous code.
*
* @author Adrien Xie, 11/1/2016
*/

class deck {
private:
	vector<Cards> deckCards;

public:
	deck() {
	}

	deck(char* filename) {
		try {
			load(filename);
		}
		catch (int e) {
			throw fileFailtoOpen;
		}
	}

	~deck() {
	}

	// reusing the parsefile method from previous lab
	int load(char* filename) {
		return parseFile(deckCards, filename);
	}

	// shuffle the deck with random int as seed
	void shuf() {
		int seed = rand() % 10;
		shuffle(deckCards.begin(), deckCards.end(), std::default_random_engine(seed));
	}

	// size method
	const int numCards() {
		return deckCards.size();
	}

	// method used for card dealing: the last card is poped and return to hand
	Cards getEnd() {
		Cards temp = deckCards[numCards()-1];
		deckCards.pop_back();
		return temp;
	}

	friend ostream& operator<<(ostream& os, deck& d);
};

// non-member operator to print out cards
ostream& operator<<(ostream& os, deck& d)
{
	for(int i =0;i<d.numCards();i++){
		os << showCard(d.deckCards[i]);
		os << "\n";
	}
	return os;
}

class hand {
private:
	vector<Cards> handCards;
public:
	hand() {
		handCards.clear();
	}

	hand(const hand& copyHand) {
		handCards.clear();
		handCards = copyHand.handCards;
	}

	~hand() {
	}

	// size method
	const int numCards() {
		return handCards.size();
	}

	// as string method that print out space-seperated (and comma) cards
	const string asString() {
		string handInfo = "";
		for (int i = 0; i < numCards(); i++) {
			handInfo = handInfo + " " + showCard(handCards[i]) + ",";
		}
		return handInfo;
	}

	// method declared to access private object
	vector<Cards> getCards() const {
		return handCards;
	}

	// assignment operator
	void operator = (const hand &handAssign) {
		if (handCards != handAssign.handCards) {
			handCards.clear();
			handCards = handAssign.handCards;
		}
	}

	// equal operator
	bool operator == (const hand &handCompare) {
		if (handCards.size() == handCompare.handCards.size()) {
			for (int i = 0; i < handCards.size(); i++) {
				if (handCards[i] == handCompare.handCards[i]) {

				}
				else {
					return false;
				}
			}
		}
	}

	// less than operator
	bool operator <(const hand&handCompare) {
		for (int i = 0; i < handCards.size(); i++) {
			if (handCards[i] < handCompare.handCards[i]) {
				return true;
			}
			else {
				return false;
			}
		}
	}

	friend ostream& operator<<(ostream& os, hand& h);

	friend hand operator << (hand& h, deck& d);
};

// non-member operator that prints out the cards
ostream& operator<<(ostream& os, hand& h)
{
	os << h.asString();
	return os;
}

// non-member insertion operator from deck to hand
hand operator << (hand& h, deck& d)
{
	h.handCards.push_back(d.getEnd());
	sortCards(h.handCards);
	return h;
}

// method used to compare two hadns according to their type
bool compare(const hand& h1, const hand& h2, int rankType) {
	
	switch (rankType)
	{
	case 0:
		// straight flush
		return h1.getCards()[4] < h2.getCards()[4];
		break;
	case 1:
		// four of a kind
		Rank temp1, temp2;
		if (h1.getCards()[0].newRank == h1.getCards()[1].newRank) {
			temp1 = h1.getCards()[0].newRank;
		}
		else {
			temp1 = h1.getCards()[4].newRank;
		}
		if (h2.getCards()[0].newRank == h2.getCards()[1].newRank) {
			temp2 = h2.getCards()[0].newRank;
		}
		else {
			temp2 = h1.getCards()[4].newRank;
		}
		return temp1 < temp2;
		break;
	case 2:
		//full house
		Rank temp13, temp23, temp12, temp22;
		if (h1.getCards()[1].newRank == h1.getCards()[2].newRank) {
			temp13 = h1.getCards()[0].newRank;
			temp12 = h1.getCards()[4].newRank;
		}
		else {
			temp13 = h1.getCards()[4].newRank;
			temp12 = h1.getCards()[0].newRank;
		}
		if (h2.getCards()[1].newRank == h2.getCards()[2].newRank) {
			temp23 = h2.getCards()[0].newRank;
			temp22 = h2.getCards()[4].newRank;
		}
		else {
			temp23 = h2.getCards()[4].newRank;
			temp22 = h2.getCards()[0].newRank;
		}
		if (temp13 == temp23) {
			return temp12 < temp22;
		}
		else {
			return temp13 < temp23;
		}
		break;
	case 3:
		//flush
		temp1 = h1.getCards()[4].newRank;
		temp2 = h2.getCards()[4].newRank;
		if (temp1 == temp2) {
			temp1 = h1.getCards()[3].newRank;
			temp2 = h2.getCards()[3].newRank;
			if (temp1 == temp2) {
				temp1 = h1.getCards()[2].newRank;
				temp2 = h2.getCards()[2].newRank;
				if (temp1 == temp2) {
					temp1 = h1.getCards()[1].newRank;
					temp2 = h2.getCards()[1].newRank;
					if (temp1 == temp2) {
						temp1 = h1.getCards()[0].newRank;
						temp2 = h2.getCards()[0].newRank;
						return temp1 < temp2;
					}
					return temp1 < temp2;
				}
				return temp1 < temp2;
			}
			return temp1 < temp2;
		}
		return temp1 < temp2;
		break;
	case 4:
		//stright
		return h1.getCards()[4] < h2.getCards()[4];
		break;
	case 5:
		//three of a kind
		for (int i = 1; i < 5; i++) {
			if (h1.getCards()[i - 1].newRank == h1.getCards()[i].newRank) {
				temp1 = h1.getCards()[i - 1].newRank;
			}
			if (h2.getCards()[i - 1].newRank == h2.getCards()[i].newRank) {
				temp2 = h2.getCards()[i - 1].newRank;
			}
		}
		return temp1 < temp2;
		break;
	case 6:
		//two pair
		Rank fp1, tp1, fp2, tp2, fifth1, fifth2;
		if (h1.getCards()[0].newRank != h1.getCards()[1].newRank) {
			fifth1 = h1.getCards()[0].newRank;
			fp1 = h1.getCards()[4].newRank;
			tp1 = h1.getCards()[2].newRank;
		}
		else if (h1.getCards()[3].newRank != h1.getCards()[4].newRank) {
			fifth1 = h1.getCards()[4].newRank;
			fp1 = h1.getCards()[3].newRank;
			tp1 = h1.getCards()[1].newRank;
		}
		else {
			fifth1 = h1.getCards()[2].newRank;
			fp1 = h1.getCards()[4].newRank;
			tp1 = h1.getCards()[1].newRank;
		}

		if (h2.getCards()[0].newRank != h2.getCards()[1].newRank) {
			fifth2 = h2.getCards()[0].newRank;
			fp2 = h2.getCards()[4].newRank;
			tp2 = h2.getCards()[2].newRank;
		}
		else if (h1.getCards()[3].newRank != h1.getCards()[4].newRank) {
			fifth2 = h2.getCards()[4].newRank;
			fp2 = h2.getCards()[3].newRank;
			tp2 = h2.getCards()[1].newRank;
		}
		else {
			fifth2 = h2.getCards()[2].newRank;
			fp2 = h2.getCards()[4].newRank;
			tp2 = h2.getCards()[1].newRank;
		}

		if (fp1 == fp2) {
			if (tp1 == tp2) {
				return fifth1 < fifth2;
			}
			return tp1 < tp2;
		}
		return fp1 < fp2;
		break;
	case 7:
		//one pair
		int p11, p12, p21, p22;
		for (int i = 1; i < 5; i++) {
			if (h1.getCards()[i - 1].newRank == h1.getCards()[i].newRank) {
				temp1 = h1.getCards()[i - 1].newRank;
				p11 = i - 1;
				p12 = i;
			}
			if (h2.getCards()[i - 1].newRank == h2.getCards()[i].newRank) {
				temp2 = h2.getCards()[i - 1].newRank;
				p21 = i - 1;
				p22 = i;
			}
		}
		if (temp1 == temp2) {
			vector<Cards> tempCard1 = h1.getCards();
			tempCard1.erase(tempCard1.begin() + p11, tempCard1.begin()+p12);

			vector<Cards> tempCard2 = h2.getCards();
			tempCard2.erase(tempCard2.begin() + p11, tempCard2.begin() + p22);
			return tempCard1 < tempCard2;
		}
		return temp1 < temp2;
		break;
	default:
		// default for non above applies
		temp1 = h1.getCards()[4].newRank;
		temp2 = h2.getCards()[4].newRank;
		if (temp1 == temp2) {
			temp1 = h1.getCards()[3].newRank;
			temp2 = h2.getCards()[3].newRank;
			if (temp1 == temp2) {
				temp1 = h1.getCards()[2].newRank;
				temp2 = h2.getCards()[2].newRank;
				if (temp1 == temp2) {
					temp1 = h1.getCards()[1].newRank;
					temp2 = h2.getCards()[1].newRank;
					if (temp1 == temp2) {
						temp1 = h1.getCards()[0].newRank;
						temp2 = h2.getCards()[0].newRank;
						return temp1 < temp2;
					}
					return temp1 < temp2;
				}
				return temp1 < temp2;
			}
			return temp1 < temp2;
		}
		return temp1 < temp2;
		break;
	}
}

// poker rank method used to compare two hands 
bool poker_rank(const hand & h1, const hand & h2) {
	// vector of integer, each elements records whether 
	// the associated hand is of a certain hand rank
	vector<int> h1rank;
	vector<int> h2rank;

	handRank(h1.getCards(), h1rank);
	handRank(h2.getCards(), h2rank);
	
	int rank1 = 10;
	int rank2 = 10;

	// check if any specific hand rank applies
	for (int i = h1rank.size() - 1; i >= 0; i--) {
		if (h1rank[i] != 0) {
			rank1 = i;
		}
		if (h2rank[i] != 0) {
			rank2 = i;
		}
	}

	// compare two hands
	if (rank1==rank2) {
		return compare(h1, h2, rank1);
	}
	else {
		if (rank1 < rank2) {
			return false;
		}
		else {
			return true;
		}
	}
}

string showCard(Cards printCards) {
	string info = "";
		// try to print out the rank and suit of a card
		try {

			// print out the suit case by case
			info = info + suitString[printCards.newSuit];
			info = info + rankString[printCards.newRank];
		}
		catch (...) {

			// if any exception is caught, an error is printed
			info = "\n An error occured while printing! \n";
		}
		return info;
	
}

