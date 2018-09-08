#include "stdafx.h"
#include "Card.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

/*
* Card.cpp source file created to define functions declared in Card.h header file
* with the facilitateion of extra modular functions
*
* @author Adrien Xie, 10/04/2016
*/

//forward declared of modular functions as compiler needs to 
// know function prototype when function call is compiled.
Cards cardRankSuit(string definition);
Rank rankCheck(string checkRank);
Suit suitCheck(char checkSuit);

void sortCards(vector<Cards> &cardSet);
int checkSF(const vector<Cards> cardSet);
int checkFK(const vector<Cards> cardSet);
int checkFH(const vector<Cards> cardSet);
int checkFL(const vector<Cards> cardSet);
int checkSTR(const vector<Cards> cardSet);
int checkTK(const vector<Cards> cardSet);
int checkOP(const vector<Cards> cardSet);
int checkTP(const vector<Cards> cardSet);
int handRank(const vector<Cards> &handSet);
/*
* parseFile function is used to read strings from a file
* save the input if the string is valid. When the input string is
* invalid, will printout error message
*
* @parameter cardSet: reference to vector of Cards type that stores cards
* @parameter fileName: C style string represent name of the file to open
* @return int: 0 indicate success; -1 indicate failure
*/
int parseFile(vector<Cards> & cardSet, char * fileName) {

	// use ifstream to read file
	// declare an ifstream variable and open the file
	ifstream ifs;
	ifs.open(fileName);

	string read = "Defualt";
	string readLine = "Default";
	string definition = "";
	vector<Cards> tempCardSet;


	if (!ifs.is_open()) {
		cout << "Usage: file failed to open!" << endl;
		return -1;
	}


	
	while (!ifs.eof()) {
		getline(ifs, readLine);

		// check and skip if the line only consist of white space
		if (readLine.find_first_not_of(' ') != readLine.npos) {

			// keep reading definitions from the line until // is reached
			int index = 0;
			while (definition != "//") {

				if (!isspace(readLine[index])&& index<readLine.size()) {
					definition = definition + readLine[index];
				}
				else {

					// store the definition and clear the temp definiton
					// variable in order for later use
					read = definition;
					definition = "";

					// check if the input from file is of valid length
					// if not then just skipp
					if (read.length() <= 3 && read.length() >= 2) {

						try {

							Cards temp = cardRankSuit(read);
							tempCardSet.push_back(temp);

							// printout the message to indicate successful input
							cout << "Input " << read << " is pushed" << endl;
						}
						catch (...) {
							cout << "Usage: Invalid card" << endl;
						}
					}
				}

				index = index + 1;
			}

			cardSet.insert(cardSet.end(), tempCardSet.begin(), tempCardSet.end());
			tempCardSet.clear();
			definition = "";
		}
	}

	cout << "Success! All card definitions are loaded!" << endl;
	return success;
}

/*
* function used to interpret the input definiton and store
* the input into two parts: rank and suit
*
* @parameter string: file input that is the defition for a cards
* @return Cards: a Cards variable represnt a card
*/
Cards cardRankSuit(string definition) {

	string newRank = "";
	char newSuit;

	// check whether the input string is of length 2 or 3
	if (definition.length() == 2) {

		newRank = definition[0];
		newSuit = definition[1];
	}
	else {

		// if input string is of length three
		// newRank will record the frist two char of the definiton
		// newSuit will record the last char of the definiton
		newRank = std::string() + definition[0] + definition[1];
		newSuit = definition[2];
	}

	if (rankCheck(newRank) == falseRank) {

		cout << "Usage: An invalid card definition found: " << definition << endl;
	}

	if (suitCheck(newSuit) == falseSuit) {

		cout << "Usage: An invalid card definition found: " << definition << endl;
	}

	Cards card;

	// check if the rank and suit is both valid, 
	if (rankCheck(newRank) != falseRank && suitCheck(newSuit) != falseSuit) {

		card.newRank = rankCheck(newRank);
		card.newSuit = suitCheck(newSuit);
		return card;
	}
	else {
		throw "Usage: Invalid definiton!";
	}

}

/*
* function used to check the validity of the suit defition
* if it is invalid, a falseSuit will be returned,
* otherwise a correct suit value will be returned
*
* @paramter char checkSuit: a char contains the suit definition
* @return Suit: a value of numeration type Suit
*/
Suit suitCheck(char checkSuit) {

	//return the suit value case by case
	switch (checkSuit) {
	case 'c': case 'C':
		return clubs;
		break;
	case 'd': case 'D':
		return diamond;
		break;
	case 'h': case 'H':
		return heart;
		break;
	case 's': case 'S':
		return spade;
		break;
	default:
		return falseSuit;
	}
}

/*
* function used to check the validity of the rank defition
* if it is invalid, a falseRank will be returned,
* otherwise a correct rank value will be returned
*
* @paramter char checkRank: a string contains the rank definition
* @return Rank: a value of numeration type Rank
*/
Rank rankCheck(string checkRank) {

	//check if the rank definition string length is of 1
	if (checkRank.length() == 1) {

		//return the suit value case by case
		switch (checkRank[0]) {
		case '2':
			return two;
			break;
		case '3':
			return three;
			break;
		case '4':
			return four;
			break;
		case '5':
			return five;
			break;
		case '6':
			return six;
			break;
		case '7':
			return seven;
			break;
		case '8':
			return eight;
			break;
		case '9':
			return nine;
			break;
		case 'j': case 'J':
			return jack;
			break;
		case 'q': case 'Q':
			return queen;
			break;
		case 'k': case 'K':
			return king;
			break;
		case 'a': case 'A':
			return ace;
			break;
		default:
			return falseRank;
		}
	}
	else {

		// check if the two-char string is valid
		if (checkRank == "10") {

			return ten;
		}
		else {

			return falseRank;
		}
	}

}

/*
* Method used to print out each cards in the cards vector
* Method from lab1: NOT USED but will work as
*
* @parameter const vector<Cards> &printCards: a vector of Cards type
* @return int: 0 indicate success; -1 indicate failure
*/

int printCards(const vector<Cards> &printCards) {

	// use a for loop to run through each cards in the vector
	for (size_t i = 0; i < printCards.size(); i++) {

		// try to print out the rank and suit of a card
		try {
			cout << "The card is ";

			// print out the suit case by case
			switch (printCards[i].newSuit) {
			case clubs:
				cout << "club ";
				break;
			case diamond:
				cout << "diamond ";
				break;
			case heart:
				cout << "heart ";
				break;
			case spade:
				cout << "spade ";
				break;
			default:
				throw "Usage: Error occurred while printing out suit!";
				return -1;
			}

			//print out the rank case by case
			switch (printCards[i].newRank) {
			case two:
				cout << '2';
				break;
			case three:
				cout << '3';
				break;
			case four:
				cout << '4';
				break;
			case five:
				cout << '5';
				break;
			case six:
				cout << '6';
				break;
			case seven:
				cout << '7';
				break;
			case eight:
				cout << '8';
				break;
			case nine:
				cout << '9';
				break;
			case ten:
				cout << "10";
				break;
			case jack:
				cout << "jack";
				break;
			case queen:
				cout << "queen";
				break;
			case king:
				cout << "king";
				break;
			case ace:
				cout << "ace";
				break;
			default:
				throw "Usage: Error occurred while printing out rank!";
				return -1;
			}
			cout << endl;
		}
		catch (...) {

			cout << "Caught an error!" << endl;
		}
	}

	return success;
}

/*
* helMsg method used toprint out helpful message that
* shows the user how they should run from the program from the command line
*
* @return int: endWithHelp indicate that program was executed with incorrect aurguments
*/
int helpMsg(string programName, string instruction) {

	cout << "Program " << programName << " message: " << endl;
	cout << instruction << endl;

	return endWithHelp;
}

/*
* sortCards function used to sort the cards in the vector
* first by rank and secondarily by suit
*
* @parameter cardSet, reference to a vector of cards type
* @return void
*/
void sortCards(vector<Cards> &cardSet) {
	
	// use buble sort to sort the cards in the array
	// start from the beginning, move the swap the bigger
	// one to the end
	for (rsize_t i = 1; i < cardSet.size(); i++) {
		for (rsize_t k = 1; k < cardSet.size()-i+1; k++) {
			if (cardSet[k - 1] < cardSet[k]) {
				
			}
			else {
				swap(cardSet[k - 1], cardSet[k]);
			}
		}
	}

}

/*
* fucntion used to check if the hand rank is straight flush
* 
* @parameter cardSet, constant vector of cards type
* @return int, 1 if it is, 0 if it is not
*/
int checkSF(const vector<Cards> cardSet) {

	// check if the suit is all the same for all cards
	for (int i = 1; i < 5; i++) {
		if (cardSet[i - 1].newSuit != cardSet[i].newSuit) {
			return 0;
		}
	}

	// check if the rank is in executive order
	for (int i = 1; i < 5; i++) {
		if (cardSet[i - 1].newRank != cardSet[i].newRank - 1) {
			return 0;
		}
	}
	
	return 1;
}

/*
* Function used to check if the hand rank is four of a kind
*
* @parameter cardSet, const vector of cards type
* @return int, 1 if it is a four of kind, 0 if it is not
*/
int checkFK(const vector<Cards> cardSet) {

	// check if the first four cards rank are same or
	// check if the last four cards rank are same
	// return 0 if not
	if (cardSet[1].newRank == cardSet[2].newRank && cardSet[2].newRank == cardSet[3].newRank && cardSet[3].newRank == cardSet[4].newRank) {
	}
	else if (cardSet[0].newRank == cardSet[1].newRank && cardSet[1].newRank == cardSet[2].newRank && cardSet[2].newRank == cardSet[3].newRank) {
	}
	else {
		return 0;
	}
	
	return 1;
}

/*
* Function used to check if the hand rank is full house
*
* @parameter cardSet, const vector of cards type
* @return int, 1 if it is a full house, 0 if it is not
*/
int checkFH(const vector<Cards> cardSet) {
	
	// check if fist two rank is the same, if so check if the remaining three rank is same
	// else check if first three rank is the same, if so check if the remaing two is same
	if (cardSet[0].newRank == cardSet[1].newRank&&cardSet[01].newRank == cardSet[2].newRank) {
		if (cardSet[2].newRank != cardSet[3].newRank && cardSet[3].newRank == cardSet[4].newRank) {
		}
		else {
			return 0;
		}
	}
	else if (cardSet[0].newRank == cardSet[1].newRank && cardSet[1].newRank != cardSet[2].newRank) {
		if (cardSet[2].newRank == cardSet[3].newRank&&cardSet[3].newRank == cardSet[4].newRank) {
		}
		else {
			return 0;
		}
	}
	else {
		return 0;
	}

	return 1;
}

/*
* Function used to check if the hand rank is fluch
*
* @parameter cardSet, const vector of cards type
* @return int, 1 if it is a flush, 0 if it is not
*/
int checkFL(const vector<Cards> cardSet) {

	// check if all the suit is the same
	for (int i = 1; i < 5; i++) {
		if (cardSet[i - 1].newSuit != cardSet[i].newSuit) {
			return 0;
		}
	}

	// check if all rank is in the same consective order
	// if so return 0
	bool straight = true;
	for (int i = 1; i < 5; i++) {

		if (cardSet[i - 1].newRank != cardSet[i].newRank - 1) {
			straight = false;
		}
	}
	if (straight) {
		return 0;
	}
	
	return 1;
}

/*
* Function used to check if the hand rank is straight
*
* @parameter cardSet, const vector of cards type
* @return int, 1 if it is a straight, 0 if it is not
*/
int checkSTR(const vector<Cards> cardSet) {

	// check if all the rank is in consetive order
	for (int i = 1; i < 5; i++) {
		if (cardSet[i - 1].newRank != cardSet[i].newRank - 1) {
			return 0;
		}
	}

	// check if all the suit is the same
	bool sameSuit = true;
	for (int i = 1; i < 5; i++) {
		if (cardSet[i - 1].newSuit != cardSet[i].newSuit) {
			sameSuit=false;
		}
	}
	if (sameSuit) {
		return 0;
	}

	return 1;
}

/*
* Function used to check if the hand rank is three of a kind
*
* @parameter cardSet, const vector of cards type
* @return int, 1 if it is a three of kind, 0 if it is not
*/
int checkTK(const vector<Cards> cardSet) {

	// check if first three is the same, then if then the first three rank is deffrent from the fourth
	// and the fourth rank is different from the fifth
	// else check if the middle three is the same, then if the first rank is differenrt from the middle 
	// three ranks and different from the fifth rank, and middle three rank is differen from the fifth
	// else check if the last three rank is the same, then if the first rank is different from the second
	// rank and second rank is different from the remaining three ranks
	if (cardSet[0].newRank == cardSet[1].newRank && cardSet[1].newRank == cardSet[2].newRank) {
		if (cardSet[2].newRank != cardSet[3].newRank && cardSet[3].newRank != cardSet[4].newRank) {
		}
		else {
			return 0;
		}
	}
	else if (cardSet[1].newRank == cardSet[2].newRank && cardSet[2].newRank == cardSet[3].newRank) {
		if (cardSet[0].newRank != cardSet[1].newRank && cardSet[3].newRank != cardSet[4].newRank) {
		}
		else {
			return 0;
		}
	}
	else if (cardSet[2].newRank == cardSet[3].newRank && cardSet[3].newRank == cardSet[4].newRank) {
		if (cardSet[0].newRank != cardSet[1].newRank && cardSet[1].newRank != cardSet[2].newRank) {
		}
		else {
			return 0;
		}
	}
	else {
		return 0;
	}

	return 1;
}

/*
* Function used to check if the hand rank is one pair
*
* @parameter cardSet, const vector of cards type
* @return int, 1 if it is a one pair, 0 if it is not
*/
int checkOP(const vector<Cards> cardSet) {

	// check if there is two same rank card
	// if so check the cards afterwards are the same
	// if same return 0, if all cards afterwards are different
	// the cards is one pair
	for (int i = 1; i < 5; i++) {
		if (cardSet[i - 1].newRank == cardSet[i].newRank) {
			for (int k = i + 1; k < 5; k++) {
				if (cardSet[k - 1].newRank == cardSet[k].newRank) {
					return 0;
				}
			}
			return 1;
		}
	}
	return 0;
}

/*
* Function used to check if the hand rank is two pair
*
* @parameter cardSet, const vector of cards type
* @return int, 1 if it is a two pair, 0 if it is not
*/
int checkTP(const vector<Cards> cardSet) {

	// check by three cases since areds are ordered
	// case one: card1, pair1, pair1, pair2, pair2
	// case two: pair1, pair1, card1, pair2, pair2
	// case three: pair1, pair1, pair2, pair2, card
	// if non case applies return 0
	if (cardSet[0].newRank != cardSet[1].newRank) {
		if (cardSet[1].newRank != cardSet[2].newRank) {
			return 0;
		}
		else if (cardSet[3].newRank != cardSet[4].newRank) {
			return 0;
		}
		else {
			if (cardSet[2].newRank == cardSet[3].newRank){
			return 0;
			}
		}
	}
	else if (cardSet[1].newRank != cardSet[2].newRank&&cardSet[2].newRank != cardSet[3].newRank) {
		if (cardSet[0].newRank != cardSet[1].newRank) {
			return 0;
		}
		else  {
			if (cardSet[3].newRank != cardSet[4].newRank) {
				return 0;
			}
		}

	}
	else {
		if (cardSet[4].newRank != cardSet[3].newRank) {
			if (cardSet[0].newRank != cardSet[1].newRank) {
				return 0;
			}
			else if (cardSet[2].newRank != cardSet[3].newRank) {
				return 0;
			}
			else {
				if (cardSet[1].newRank == cardSet[2].newRank) {
					return 0;
				}
			}
		}
		else {
			return 0;
		}
	}

	return 1;
}

/*
* Method used to record the hand rank
*
* parameter vector of cards: represent hand of cards
*	vector of int: record the hand rank
*/
void handRank(vector<Cards> &handSet, vector<int> &ranks) {

		// sort the hand cards
		sortCards(handSet);

		// call the functions to check the rank of the hand
		ranks.push_back(checkSF(handSet));
		ranks.push_back(checkFK(handSet));
		ranks.push_back(checkFH(handSet));
		ranks.push_back(checkFL(handSet));
		ranks.push_back(checkSTR(handSet));
		ranks.push_back(checkTK(handSet));
		ranks.push_back(checkTP(handSet));
		ranks.push_back(checkOP(handSet));
	
	return;
}