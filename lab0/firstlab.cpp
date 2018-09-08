#include "stdafx.h"
#include "Card.h"
#include <vector>
#include <iostream>
using namespace std;

/*
* firstlab.cpp program created to read cards info from a file 
* and store the info if it is valid and then print out the cards
*
* @parameter int argc: number of arguments passed 
* @parameter char* argv[]: arra stores the program name and arguments
* @author Adrien Xie 9/21/2016
*/
int main(int argc, char * argv[])
{
	// check if the argument passed in is exactly 1
	// if not print out message and calls helpMsg to print out instruction
	if (argc != 2) {
		cout << "Usage: incorrect arguments!" << endl;
		cout << "Please refer to the help message below" << endl;
		return helpMsg();
	}

	// declare a vector of Cards type
	vector<Cards> cardSet;
	
	// call the function parsefile to open file passed in argv[1]
	// and read inputs to the vector
	// and stores the integer of returned
	int exec = parseFile(cardSet, argv[1]);

	// check if the parsefile runs corretly
	// if not return the int
	if (exec != 0) {
		return exec;
	}

	// call the fucntion to print out each card
	// in the vector and record the int returned
	// by the function
	exec = printCards(cardSet);

	// check if the function is executed correctly
	// if not return the int returned by the function
	if (exec != 0) {
		return exec;
	}
	
	//end of the program
	return 0;
}
