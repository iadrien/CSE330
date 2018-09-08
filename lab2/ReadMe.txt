========================================================================
    CONSOLE APPLICATION : lab2 Project Overview
	Author: Adrie Xie 11/1/2016
========================================================================

lab2.cpp
    This is the main application source file. The program minics the card game and will 
	execute with one or two argument which most contain the file name. Then 
	the program will create a desk and  store the input from the file to the deck and then 
	deal the card to each hand. All cards then will be sorted and printed. 
	If incorrect number of argument is passed, the program will call 
	a function to print out the correct  example and finishes the program

lab2.h
	This is the header file created by Adrien. Most of the lab2 requirements are implemented
	within this header file.

Card.h
	Code from lab1 assignment. Minor changes.

Card.cpp
	Code from lab1 assignment. Minor changes.

/////////////////////////////////////////////////////////////////////////////
Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named lab1.pch and a precompiled types file named StdAfx.obj.

/////////////////////////////////////////////////////////////////////////////
Other notes:

Warning:
	1. sign/unsigned int mismatch
Unsolved Error:
	None

Test Case
	1. Command line test
		i. lab1.exe 
			Usage: incorrect arguments!
			Please refer to the help message below
			Program C:\Users\xie.z_000\documents\visual studio 2015\Projects\lab1\Debug\lab1.exe message:
			Please run the program with one or two additon argument
		
		ii. lab1.exe -shuffle
			Program C:\Users\xie.z_000\documents\visual studio 2015\Projects\lab1\Debug\lab1.exe message:
			The only argument cannot be -shuffle!
		
		iii. lab1.exe hey.txt (hey.txt does not exist)
			Usage: file failed to open

	2. Test with personalized txt
		txt file content:
		kd qs 6c 6c  9d 7s 4s 9c 9c //
		jd qh 10s 7c  6d 8c 4h 9s qd //
		6s jh 9h 8c  5d 2s 4d 10c 10c //
		5s qc 8s 9c  8d 5h as 10d 10d //
		3c jc 7h 5c  2c 4c jd 9s 10h//  
		(Messages such as "Card JD is pushed" will not be documented here)
		(But will be printed out in the program)
		(Starting program)
		
		
		Success! All card definition are loaded!
		Printing out hand0:
			....
		Printing out hand1:
			....
			....
		Sorting hands by default:
		Printing out hand0:
			....
			....
		Sorting hands by poker hand:
		Printing out hand0:
			....
			....

		(Program ending message)
		The detail of the printed out card definitions are not shown 
		here but it is correct as I have tested.

/////////////////////////////////////////////////////////////////////////////
		EXTRA CREDIT
		A8-A9:	Both guidlines apply to my program. For A8, all exceptions that 
				might be thrown will be catght and an error message will be 
				printed or a non-zero value will be returned. For A9, non of
				the exceptions are used to control the flow.
		A12-15:	A12 does not really apply to my program as I didn't really use
				any pointers (except for argument strings char* argv[]). A13-15
				IS VERY IMPORTANT and I always make sure that index/subscripting 
				is within the size of the container.
		A16:	Debugging is extreamlly important in my programming experience.
				I often debug as I complete certain amount of work. I tried to 
				narrow down where I go wrong and try fixing problems by debugging
				with different values.
		B10-12:	This part of guildlnes are relavant but not a major concern in
				this lab. 
		B18:	This guidline is not followed because this lab requires copy 
				constructor and it is used in the program.
		B31:	This guidline is not a concern in my lab solution. I didn't 
				encounter any headfile mutiple inclusion.
