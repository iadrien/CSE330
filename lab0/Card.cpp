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
* @author Adrien Xie, 9/21/2016
*/

//forward declared of modular functions as compiler needs to 
// know function prototype when function call is compiled.
Cards cardRankSuit(string definition);
Rank rankCheck(string checkRank);
Suit suitCheck(char checkSuit);

/*
* parseFile function is used to read strings from a file
* save the input if the string is valid. When the input string is
* invalid, will printout error message
*
* @parameter cardSet: vector of Cards type that stores cards
* @parameter fileName: C style string represent name of the file to open
* @return int: 0 indicate success; -1 indicate failure
*/
int parseFile(vector<Cards> & cardSet, char * fileName) {

	// use ifstream to read file
	// declare an ifstream variable and open the file
	ifstream ifs;
	ifs.open(fileName);

	// declare a string variable to store temporay input
	string read = "Defualt";

	// check if the file is opened
	// if not print out usage message and return -1
	if (!ifs.is_open()) {
		cout << "Usage: file failed to open!" << endl;
		return -1;
	}
	
	// use while loop to keep reading inputs from the file
	// and store the inputs into the vector
	while (ifs >> read) {

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
				cardSet.push_back(temp);

				// printout the message to indicate successful input
				cout << "Input " << read << " is pushed" << endl;
			}
			catch (...) {

				//print out the usage message indicate failure
				cout << "Usage: Invalid card" << endl;
			}
		}
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
		newRank = definition[0]+definition[1];
		newSuit = definition[2];
	}

	// check if the rank defition is valid
	if (rankCheck(newRank) == falseRank ) {

		// print out usage message indicate invalid definiton
		cout << "Usage: An invalid card definition found: " << &definition << endl;
	}

	// check if the suit defition is valid 
	if (suitCheck(newSuit) == falseSuit) {
		
		// print out usage message indicate invalid defnition
		cout << "Usage: An invalid card definition found: " << &definition << endl;
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
int helpMsg() {

	// print out the instruction of how to run the program in cmd
	// print out the correct example
	cout << "Use the command line with an argument to run the program." << endl;
	cout << "i.e firstlab.exe card.txt" << endl;
	
	return -1;
}


