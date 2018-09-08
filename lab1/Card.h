#pragma once
#include <vector>
#include <string>

/*
* Card.h header file created with declaration of sturct of type Card and
* three functions declared that will be definined in srouce file card.cpp
*
* @author Adrien Xie, 9/21/2016
*/

// declare enumeration type veriable with ranges of possible values
enum Suit { clubs, diamond, heart, spade, falseSuit };
enum Rank { two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace, falseRank };

// declare struct of type cards that has two memeber variables
struct Cards
{
	Suit newSuit;
	Rank newRank;

	// declare and define the < operator for struct
	friend bool operator<(const Cards &cardOne, const Cards &cardTwo) {

		if (cardOne.newRank < cardTwo.newRank) {
			return true;
		}
		else if (cardOne.newRank == cardTwo.newRank) {
			if (cardOne.newSuit < cardTwo.newSuit) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
};

// declare function that will 1. read file and store the input
// 2. print out the stored input in the vector and 3. print out 
// a help message if the program is not started with correct arguments
// 4. check the rank of a hand and print out the message
// these functions are defined in source file Card.cpp
int parseFile(std::vector<Cards> & cardSet, char * fileName);
int printCards(const std::vector<Cards> &showCards);
int helpMsg(std::string programName, std::string instruction);
int handRank(const std::vector<Cards> &handSet);
