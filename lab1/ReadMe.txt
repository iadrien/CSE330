========================================================================
    CONSOLE APPLICATION : lab1 Project Overview
	Author: Adrie Xie 10/04/2016
========================================================================

lab1.cpp
    This is the main application source file. The program minics the card game and will 
	execute with exactly one argument which is the name of a file that is to be read. Then 
	the program will call functions to store the input from the file to a vector and then 
	print out the rank of each hand of five cards. All cards then will be sorted and printed. 
	If incorrect number of argument is passed, the program will call 
	a function to print out the correct  example and finishes the program

Card.h
	This is the header file created by Adrien. It declares a stuctuct of Cards type with two
	enumerator member, and defines an operator < for itself. And it declares three functions.

Card.cpp
	This is the source file created by Adrien. It definies functions that will 1. read file 
	and store the input 2. print out the stored input in the vector and 3. print out a help
	message if the program is not started with correct arguments. 4. check the rank of a 
	hand and print out the message. There are also other modular function which are parts
	of the above major functions

/////////////////////////////////////////////////////////////////////////////
Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named lab1.pch and a precompiled types file named StdAfx.obj.

/////////////////////////////////////////////////////////////////////////////
Other notes:

Solved Errors/Warning:
	1. sign/unsigned int mismatch
Unsolved Warning:
	None

Test Case
	1. Command line test
		i. lab1.exe 
			Usage: incorrect arguments!
			Please refer to the help message below
			Program C:\Users\xie.z_000\documents\visual studio 2015\Projects\lab1\Debug\lab1.exe message:
			Please run the program with exactly one additon argument
		
		ii. lab1.exe 1 2
			Usage: incorrect arguments!
			Please refer to the help message below
			Program C:\Users\xie.z_000\documents\visual studio 2015\Projects\lab1\Debug\lab1.exe message:
			Please run the program with exactly one additon argument
		
		iii. lab1.exe hey.txt (hey.txt does not exist)
			Usage: file failed to open

	2. Test with hands.txt
		(Messages such as "Card JD is pushed" will not be documented here)
		(But will be printed out in the program)
		(Starting program)
		
		Success! Ahand of five cards is loaded
		Usage: invalid number of card definitions within the line!
		Success! Ahand of five cards is loaded
		Success! Ahand of five cards is loaded
		Success! Ahand of five cards is loaded
		Success! Ahand of five cards is loaded
		Success! Ahand of five cards is loaded
		Usage: invalid number of card definitions within the line!
		Success! Ahand of five cards is loaded
		Success! Ahand of five cards is loaded
		Success! Ahand of five cards is loaded

		This poker hand rank is NONE OF OTHER RANKS APPLY
		This poker hand rank is a full house
		This poker hand rank is a straight
		This poker hand rank is a three of a kind
		This poker hand rank is a stright flush
		This poker hand rank is a one pair
		This poker hand rank is a four of a kind
		This poker hand rank is a flush
		This poker hand rank is a two pair

		Sorting all cards ...
		(Sorted cards are printed out)
		(Program ending message)

/////////////////////////////////////////////////////////////////////////////
