#pragma once
#include <vector>
#include <string>

/*
* Card.h header file created with declaration of sturct of type Card and
* three functions declared that will be definined in srouce file card.cpp
*
* @author Adrien Xie, 1/11/2016
*/

// enumeration type veriable 
enum Suit { clubs, diamond, heart, spade, falseSuit };
enum Rank { two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace, falseRank };
enum returnCode {success=0, fileFailtoOpen, failPrint, tooFewCards, endWithHelp};

// declare static field for enum name strings
static const char * suitString[] = { "clubs ","diamond ","heart ","spade "};
static const char * rankString[] = { "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "jack", "queen", "king", "ace" };

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

	// equal operator, return ture only if two cards have same rank and suit
	friend bool operator==(const Cards &cardOne, const Cards &cardTwo) {
		if (cardOne.newRank == cardTwo.newRank&&cardOne.newSuit == cardTwo.newSuit) {
			return true;
		}
		else {
			return false;
		}
	}
};

// declare functions that will be implemented in card.cpp
int parseFile(std::vector<Cards> & cardSet, char * fileName);
int printCards(const std::vector<Cards> &showCards);
int helpMsg(std::string programName, std::string instruction);
void sortCards(std::vector<Cards> &cardSet);
void handRank(std::vector<Cards> &handSet, std::vector<int> &ranks);

