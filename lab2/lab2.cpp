#include "stdafx.h"
#include "Card.h"
#include "lab2.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

/*
* 
* lab2.cpp program created to read cards info from a file
* and store the info into a desk if it is valid and then print out the rank of a hand
* and the sort the cards and print all the cards
*
* @parameter int argc: number of arguments passed
* @parameter char* argv[]: arra stores the program name and arguments
* @author Adrien Xie 11/1/2016
*/
int main(int argc, char * argv[])
{
	// check if one or two arguments are passed
	// if not print out message and calls helpMsg to print out instruction
	if (argc < 2 || argc > 3) {
		cout << "Usage: incorrect arguments!" << endl;
		cout << "Please refer to the help message below" << endl;
		return helpMsg(argv[0],"Please run the program with one or two additional argument!");
	}

	char* filename = "";
	bool shuffle = true;

	// check if the arguments are valid
	if (argc ==2) {
		string temp = argv[1];
		if (temp == "-shuffle") {
			return helpMsg(argv[0], "The only argument cannot be -shuffle!");
		}
		filename = argv[1];
		shuffle = false;
	}
	else {
		string temp1 = argv[1];
		string temp2 = argv[2];
		if (temp1 != "-shuffle") {		
			if (temp2 != "-shuffle") {
				return helpMsg(argv[0], "Two arguments cannot both be -shuffle!");
			}
			filename = argv[1];
		}
		else{
			if (temp2 == "-shuffle") {
				return helpMsg(argv[0], "At least one argument should be -shuffle!");
			}
			filename = argv[2];
		}
	}

	// declare a deck type variable 
	// and try initializing and shuffle 
	deck newdeck;
	try{
		newdeck =  deck(filename);
		if (shuffle) {
			newdeck.shuf();
		}
	}
	catch (int e){
		cout << "Integer Exception  " << e << " is thrown!" << endl;
	}

	// creat vector of hands, 9 hands and each hand 5 cards
	vector<hand> handset;
	const int numHand = 9;
	const int numHandCard = 5;
	for (int i = 0; i < numHand; i++) {
		hand temp = hand();
		handset.push_back(temp);
	}

	// check if there are enough cards so that all 9 hands have 5 cards
	// if not finish execute with non-zero value returned
	if (newdeck.numCards() < numHandCard*numHand) {
		return tooFewCards;
	}

	// cards in the deck are dealt 
	for (int i = 0; i < numHandCard; i++) {
		for (int j = 0; j < numHand; j++) {
			handset[j] << newdeck;
		}
	}

	// print out cards remaining in the deck
	// and cards in each hand before sorting, default sorting and defined sorting
	cout << "\nCards remaining in the deck:" << endl;
	cout << newdeck << endl;
	for (int i = 0; i < numHand; i++) {
		cout << "Printing out hand" << i << ":" << endl;
		cout << handset[i] << endl;
	}

	cout << "\nSorting hands by defualt:" << endl;
	sort(handset.begin(), handset.end());

	for (int i = 0; i < numHand; i++) {
		cout << "Printing out hand" << i << ":" << endl;
		cout << handset[i] << endl;
	}

	cout << "\nSorting hands by poker hand:" << endl;
	sort(handset.begin(), handset.end(), poker_rank);

	cout << "\nSorting hands by poker hand:" << endl;
	for (int i = 0; i < numHand; i++) {
		cout << "Printing out hand" << i << ":" << endl;
		cout << handset[i] << endl;
	}
	
	// execution finishing message
	cout << endl;
	cout << "Program " << argv[0] << " is finishing ... Bye!" << endl;
	return success;
}
