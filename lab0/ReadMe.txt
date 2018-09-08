========================================================================
    CONSOLE APPLICATION : firstlab Project Overview
				Author: Adrien Xie 9/21/2016
========================================================================


firstlab.cpp
    This is the main application source file. The program minics the card game and will 
	execute with exactly one argument which is the name of a file that is to be read. Then 
	the program will call functions to store the input from the file to a vector and then 
	print out the vector. If incorrect number of argument is passed, the program will call 
	a function to print out the correct  example and finishes the program

Card.h
	This is the header file created by Adrien. It declares a stuctuct of Cards type with two
	enumerator member. And it declares three functions.

Card.cpp
	This is the source file created by Adrien. It definies functions that will 1. read file 
	and store the input 2. print out the stored input in the vector and 3. print out a help
	message if the program is not started with correct arguments 

/////////////////////////////////////////////////////////////////////////////
Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named firstlab.pch and a precompiled types file named StdAfx.obj.

/////////////////////////////////////////////////////////////////////////////
Other notes:

Solved Errors/Warning:
	1. strncp method cosidered not safe
	2. Right shif operator (>>) from ifstream to C-string crashed the program

Unsolved Errors/Bug:
	None

Test Case
	1. Command line test
		i. firstlab.exe 
			Usage: incorrect arguments!
			Please refer to the help message below
			Use the command line with an argument to run the program.
			i.e firstlab.exe cards.txt
		
		ii. firstlab.exe 1 2
			Usage: incorrect arguments!
			Please refer to the help message below
			Use the command line with an argument to run the program.
			i.e firstlab.exe cards.txt

		iii. firstlab.exe hey.txt (hey.txt does not exist)
			Usage: file failed to open

	2. String tests
card.txt:	Output:
ah			input ah is pushed
4d			input 4d is pushed
1h			Usage: An invalid card definition found
			Usage: Invalid card
1h			Usage: An invalid card definition found
			Usage: Invalid card
22			Usage: An invalid card definition found
			Usage: Invalid card
3q			Usage: An invalid card definition found
			Usage: Invalid card
4c			input 4c is pushed
5s			input 5s is pushed
			The card is heart ace
			The card is diamond 4	
			The card is club 4
			The card is spade 5
				
/////////////////////////////////////////////////////////////////////////////
