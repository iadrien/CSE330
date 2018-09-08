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

	// declare a string varaible to store temporary input
	// declare a string variable to store temporay line input
	// declare a string variable to store the card definition
	// declare a vector of cards type to store temporary cards
	string read = "Defualt";
	string readLine = "Default";
	string definition = "";
	vector<Cards> tempCardSet;

	// check if the file is opened
	// if not print out usage message and return -1
	if (!ifs.is_open()) {
		cout << "Usage: file failed to open!" << endl;
		return -1;
	}

	// use while loop to keep reading lines from the file
	// and store the inputs into the vector
	getline(ifs, readLine);
	while (!ifs.eof()) {

		// check and skip if the line only consist of white space
		if (readLine.find_first_not_of(' ') != readLine.npos) {

			// keep reading definitions from the line until // is reached
			int index = 0;
			while (definition != "//") {

				// check if the char is a whitespace
				// then keep reading in char to the definition
				// else the definition is complete and 
				// try to store the card by definition
				if (!isspace(readLine[index])) {
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

						// try to store the input into the cards variable
						// and store the cards variable to the vector
						// Exception thrown when input is only partial valid
						try {

							// call the function to pust the input and 
							// store the returned cards to temp
							Cards temp = cardRankSuit(read);

							// store the temp variable to the vector
							tempCardSet.push_back(temp);

							// printout the message to indicate successful input
							cout << "Input " << read << " is pushed" << endl;
						}
						catch (...) {

							//print out the usage message indicate failure
							cout << "Usage: Invalid card" << endl;
						}
					}

				}

				index = index + 1;
			}

			// After all the vaild definitions in the line 
			// are stored as cards. Check if the cards store is exactly five,
			// proceed to store the tempary card set to a peranant card vector
			// else print out a usage message and skip the line
			if (tempCardSet.size() != 5) {
				cout << "Usage: invalid number of card definitions within the line!" << endl;		
			}
			else {
				// copy the temporary card set to the permanont card set
				cardSet.insert(cardSet.end(), tempCardSet.begin(), tempCardSet.end());
				
				// print out a sucess message
				cout << "Success! A hand of five cards is loaded!" << endl;
				cout << endl;
			}

			// clear temparry variables
			tempCardSet.clear();
			definition = "";

		}

		// read in another line
		getline(ifs, readLine);
	}

	return 0;

}

/*
* function used to interpret the input definiton and store
* the input into two parts: rank and suit
*
* @parameter string: file input that is the defition for a cards
* @return Cards: a Cards variable represnt a card
*/
Cards cardRankSuit(string definition) {

	// declare the string to record the input for card rank
	// declare the char to record the input for card Suit
	string newRank = "";
	char newSuit;

	// check whether the input string is of length 2 or 3
	if (definition.length() == 2) {

		// if input string is of lenght two
		// newRank will record the first char of the defition
		// newSuit will record the last char of the defition
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

	// check if the rank defition is valid
	if (rankCheck(newRank) == falseRank) {

		// print out usage message indicate invalid definiton
		cout << "Usage: An invalid card definition found: " << definition << endl;
	}

	// check if the suit defition is valid 
	if (suitCheck(newSuit) == falseSuit) {

		// print out usage message indicate invalid defnition
		cout << "Usage: An invalid card definition found: " << definition << endl;
	}

	// decared a Cards variable
	Cards card;

	// check if the rank and suit is both valid, 
	if (rankCheck(newRank) != falseRank && suitCheck(newSuit) != falseSuit) {

		// if both definition are both vaild, sore them to the 
		// cards variable and return the avariable
		card.newRank = rankCheck(newRank);
		card.newSuit = suitCheck(newSuit);
		return card;
	}
	else {
		// if not both definitons are vaild, throw an exception
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

			// return a valid suit value if the string is valid
			return ten;
		}
		else {

			//return falseRank indicate the definition is invalid
			return falseRank;
		}
	}

}

/*
* Method used to print out each cards in the cards vector
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

			// if any exception is caught, an error is printed
			cout << "Caught an error!" << endl;
		}
	}

	//return 0 indicate success if no exception is thrwon
	return 0;
}

/*
* helMsg method used toprint out helpful message that
* shows the user how they should run from the program from the command line
*
* @return int: -1 indicate that program was executed with incorrect aurguments
*/
int helpMsg(string programName, string instruction) {

	// print out the instruction of how to run the program in cmd
	// print out the correct example
	cout << "Program " << programName << " message: " << endl;
	cout << instruction << endl;

	return -1;
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

	// print out message if all checks are passed
	cout << "a straight flush, ";
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

	// print out message if all checks are passed
	cout << "a four of a kind, ";
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
	if (cardSet[0].newRank == cardSet[1].newRank) {
		if (cardSet[2].newRank == cardSet[3].newRank && cardSet[3].newRank == cardSet[4].newRank) {
		}
		else {
			return 0;
		}
	}
	else if (cardSet[0].newRank == cardSet[1].newRank && cardSet[1].newRank == cardSet[2].newRank) {
		if (cardSet[3].newRank == cardSet[4].newRank) {
		}
		else {
			return 0;
		}
	}
	else {
		return 0;
	}

	// print out message if all check is passed
	cout << "a full house, ";
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

	// print out message if all check is passed
	cout << "a flush, ";
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

	// print out message if passed all checks
	cout << "a straight, ";
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

	// print out message if all check is passed
	cout << "a three of a kind, ";
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
			cout << "a one pair, ";
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

	// print out message if check is passed
	cout << "a two pair, ";
	return 1;
}

/*
* Function used to print out the rank of a hand
*
* @parameter cardSet, const vector of cards type
* @return int, 1 if it has any rank, 0 if it does not
*/
int handRank(const vector<Cards> &handSet) {

	// create a temp vector of cards type
	// create a temp cards type 
	vector<Cards> temp;
	Cards tempCard;

	// create int for later use
	int rankCheck = 0;

	
	for (rsize_t i = 0; i < handSet.size(); i = i + 5) {
		// copy five cards a time from the all cards to temp card vector
		for (rsize_t k = i; k < i + 5; k++) {
			tempCard = handSet[k];
			temp.push_back(tempCard);
		}
		
		// sort the hand cards
		sortCards(temp);

		// print out the rank
		cout << "This poker hand rank is ";
		
		// call the functions to check the rank of the hand
		rankCheck = rankCheck + checkSF(temp);
		rankCheck = rankCheck + checkFK(temp);
		rankCheck = rankCheck + checkFH(temp);
		rankCheck = rankCheck + checkFL(temp);
		rankCheck = rankCheck + checkSTR(temp);
		rankCheck = rankCheck + checkTK(temp);
		rankCheck = rankCheck + checkOP(temp);
		rankCheck = rankCheck + checkTP(temp);
		
		// if none of the rank above apply
		// print out the message
		if (rankCheck==0) {
			cout << "NONE OF OTHER RANKS APPLY";
		}
		cout << endl;

		// clear the tempary card set
		temp.clear();
	}

	return 0;

}