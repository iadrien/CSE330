#include "stdafx.h"
#include "Card.h"
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
* lab1.cpp program created to read cards info from a file
* and store the info if it is valid and then print out the rank of a hand
* and the sort the cards and print all the cards
*
* @parameter int argc: number of arguments passed
* @parameter char* argv[]: arra stores the program name and arguments
* @author Adrien Xie 10/4/2016
*/
int main(int argc, char * argv[])
{
	// check if the argument passed in is exactly 1
	// if not print out message and calls helpMsg to print out instruction
	if (argc != 2) {
		cout << "Usage: incorrect arguments!" << endl;
		cout << "Please refer to the help message below" << endl;
		return helpMsg(argv[0],"Please run the program with exactly one addition argument!");
	}

	// declare a vector of Cards type
	vector<Cards> cardSet;

	// call the function parsefile to open file passed in argv[1]
	// and read inputs to the vector
	// and stores the integer of returned
	int exec = parseFile(cardSet, argv[1]);

	// check if the parsefile runs corretly
	// if not print out msg and return the int
	if (exec != 0) {
		helpMsg(argv[0], "Failed to parse file! Terminating program ....");
		return exec;
	}

	// call the function to print out the rank of each hand
	// each hand consist of five cards
	handRank(cardSet);
	cout << endl;

	// print out the message that all the cards are being sorted
	cout << "Soring all cards ..." << endl;

	// sort the card from the beginning to the end
	sort(cardSet.begin(),cardSet.end());

	// call the fucntion to print out each card
	// in the vector and record the int returned
	// by the function
	exec = printCards(cardSet);

	// check if the function is executed correctly
	// if not print out the message and
	// return the int returned by the function
	if (exec != 0) {
		helpMsg(argv[0], "Cards failded to print! Terminating program ...");
		return exec;
	}
	
	//end of the program
	//print out the ending message
	cout << endl;
	cout << "Program " << argv[0] << " is finishing ... Bye!" << endl;
	return 0;
}
