CSE 332 Lab 3: Game: Five Card Draw
-------------------------------------
Team members: Cindy Le, Yanni Yang and Adrien Xie
443231 - lex@wustl.edu
=====================================

In this lab we extended previous lab classes and implemented new struct 
Player and two new classes Game and FiveCardDraw. We also rewrote most 
of the main function in lab.cpp.

The main function initializes an instance of the FiveCardDraw and starts
the game with player names passed by command line arguments. Then  it keeps 
running the game until there are less then two players in the current game.

Header/Source Files From lab 2 With Minor Modifications:
Card.h          Card.cpp
Deck.h          Deck.cpp
Hand.h          Hand.cpp

Header/Source Files Newly Created or With Significant Modifications:
Game.h          Game.cpp
FiveCardDraw.h  FiveCardDraw.cpp
lab.h           lab.cpp

For more information, please see comments in the .h and .cpp files.

-------------------------------------

While building the file, we got the following errors:

C2440 'initializing': cannot convert from 'int' to 'CardRank'
C2440 'initializing': cannot convert from 'int' to 'CardRank'
C2440 'initializing': cannot convert from 'int' to 'CardSuit'
Caused by int and enum type mismatch.
Fixed by static cast from int type to enum type. 

C2504 'Game': base class undefined
C2039 'instance': is not a member of 'FiveCardDraw'
C3861 'instance': identifier not found
C2504 'Game': base class undefined
C2039 'name': is not a member of 'std::shared+ptr<Player>'
Caused by circular dependency of Game.h, Game.cpp, FiveCardDraw.h and FiveCardDraw.cpp.
Fixed by removing duplicate and circular inclusions of the header files.

--------------------------------------

Once built successfully, we got the following errors:

Game already started exception.
Caused by incorrect check on game condition.
Fixed the check for game condition.

User input is skipped for the first player at the second round.
Caused by \n left in cin buffer.
Fixed by reading until a nonempty line.

Number of cards in the main decreases by ten after each round.
Caused by dropping the cards from player without adding them back to the discard deck.
Fixed by adding the removed cards from players to the discard deck.

---------------------------------------

Then the program runs and outputs as expected without errors or warnings. 
Some trial results are appended at the end of this file. 

=======================================
NOTES

1. Users should give two or more valid player names as command line arguments.

2. Player names “NO” “No” “nO” “no” either followed or not followed by “*” are not allowed.

3. Player names that consist of merely ‘*’ or have ‘*’ in the middle are not allowed.

4. When indicating whether players leave or join, enter “NO” “No” “nO” “no” for nobody.

5. When reading in the card indices to discard, all integers should be in the same line.

6. User data are stored as local files with three lines that contains name, wins and losses
respectively. Username is always stored without a ‘*’. 

7. When asking an auto player to leave, input should include a ‘*’ at the end.

=======================================
Error Code

0 Successful run. 
1 An unknown error has occurred. 
2 No Sufficient command line arguments are given. 
3 Too many command line arguments are given. 
4 More than five cards are in the hand. 
5 The deck has nothing to pop up. 
6 Hand's index is out of range.
7 The hand contains less than five cards.
8 Instance is not available! 
9 Game is already started!
10 Unknown game! 
11 No game is currently in process! 
12 The player is already playing! 
13 The decks have no cards to deal.

=======================================
Extra Credit

We defined a bool variable, isAuto, for every Player instance that takes true if and only if the read-
in detects a ‘*’ at the end of a new player’s name. 

At the before_turn phase, the program will decide which cards to discard if the player has a true for 
isAuto. 

At the after_round phase, the program will find all auto players along the list and decide whether to 
leave for each of them. 

When saving the file, ‘*’ will be simply discarded.

=======================================
Trial Results

Input 1: 
Command Line Arguments: lab3.exe

Output 1:
Program's name: C:\Users\xie.z_000\documents\visual studio 2015\Projects\lab3.exe\Debug\lab3.exe
Error 4: No Sufficient command line arguments are giving.

--------------------------------------

Input 2: 
Command Line Arguments: lab3.exe * ** no No nO* mid*dle

Output 2:
Program's name: C:\Users\xie.z_000\documents\visual studio 2015\Projects\lab3.exe\Debug\lab3.exe
Error 4: No Sufficient command line arguments are giving.

--------------------------------------

Input 3: 
Command Line Arguments: lab3.exe adrien cindy

Output 3:
Player adrien has 3D 5D 6S jC jH	<One Pair>
Card to discard? Enter the indices separated by space in a line.
1 2 3 45 <- user input

Player cindy has 8S 8S 9H jD qD		<One Pair>
Card to discard? Enter the indices separated by space in a line.
3 4 5 12 66 <- user input

Player adrien has 2H 5C 6C jC jH	<One Pair>
Player cindy has 3S 8D 8S qS kS		<One Pair>

Player adrien has 2H 5C 6C jC jH	<One Pair>
Player cindy has 3S 8D 8S qS kS		<One Pair>

Any player leaving? Enter 'No' for nobody.
Players' name:
no*

Any player joining? Enter 'No' for nobody.
Player's name:
nO

Game continues with 2 players.

Player adrien has 10S jD qH kH aS	<Straight>
Card to discard? Enter the indices separated by space in a line.
NO <- user input

Player cindy has 3H 6D 10C qC kD	<No Rank>
Card to discard? Enter the indices separated by space in a line.
		<- enter
3 2 4 1 5	<- user input

Player adrien has 10s jD qH kH aS	<Straight>
Player cindy has 2D 3C 4D kC aH		<No Rank>

Player adrien has 10s jD qH kH aS	<Straight>
Player cindy has 2D 3C 4D kC aH		<No Rank>

Any player leaving? Enter 'No' for nobody.
Player's name:
yanni <- user input
The player yanni is not currently playing!

Any player leaving? Enter 'No' for nobody.
nO* <- user input

Any player joining? Enter 'No' for nobody.
Players name:
ano <- user input

Any player joining? Enter 'No' for nobody.
Players name:
no <- user input

Game continues with 3 players.

Player adrien has 2S 3H 9C 9D aD	<One Pair>
Card to discard? Enter the indices separated by space in a line.
no <- user input

Player cindy has 3D 6C 6H 9s 10D	<One Pair>
Card to discard? Enter the indices separated by space in a line.
no <- user input

Player ano has 2C 2H 5S 5S 10H		<One Pair>
Card to discard? Enter the indices separated by space in a line.
5 <- user input

Player adrien has 2S 3H 9C 9D aD	<One Pair>
Player cindy has 3D 6C 6H 9S 10D	<One Pair>
Player ano has 2C 2H 3S 5D 5S 		<Two Pairs>

Player ano has 2C 2H 3S 5D 5S 		<Two Pairs>
Player adrien has 2S 3H 9C 9D aD	<One Pair>
Player cindy has 3D 6C 6H 9S 10D	<One Pair>

Any player leaving? Enter 'No' for nobody.
Player's name:
ano <-user input

Any player leaving? Enter 'No' for nobody.
Player's name:
adrien <-user input

Any player leaving? Enter 'No' for nobody.
Player's name:
cindy <-user input

Game ends with 0 players.

--------------------------------------

Input 4:

C:\Users\xie.z_000\Documents\Visual Studio 2015\Projects\ConsoleApplication4\Deb
ug>ConsoleApplication4.exe auto1* auto2* auto3* auto4* auto5* auto6* auto7* auto
9* auto10*

Output 4:

Player auto1* has 2S  4C  4H  8S  kC     (One Pair)
Card to discard? Enter the indices separated by space in a line.

Player auto2* has 5D  6D  7S  8D  aS     (No Rank)
Card to discard? Enter the indices separated by space in a line.

Player auto3* has 2D  6C  6H  6S  10H     (Three of a Kind)
Card to discard? Enter the indices separated by space in a line.

Player auto4* has 5C  7D  10C  10D  qD     (One Pair)
Card to discard? Enter the indices separated by space in a line.

Player auto5* has 2H  8C  jC  jS  kH     (One Pair)
Card to discard? Enter the indices separated by space in a line.

Player auto6* has 3H  4D  jD  qH  qS     (One Pair)
Card to discard? Enter the indices separated by space in a line.

Player auto7* has 5H  7H  9D  jH  kS     (No Rank)
Card to discard? Enter the indices separated by space in a line.

Player auto9* has 3S  7C  9H  qC  aD     (No Rank)
Card to discard? Enter the indices separated by space in a line.

Player auto10* has 3D  5S  9C  10S  aC     (No Rank)
Card to discard? Enter the indices separated by space in a line.

Player auto1* has 4C  4H  9S  kD  aH     (One Pair)
Player auto2* has 2C  3C  4S  8H  aS     (No Rank)
Player auto3* has 5D  6C  6H  6S  10S     (Three of a Kind)
Player auto4* has 5C  7C  8D  10C  10D     (One Pair)
Player auto5* has 3D  7D  9C  jC  jS     (One Pair)
Player auto6* has 3H  9D  jH  qH  qS     (One Pair)
Player auto7* has 3S  5H  7H  jD  kS     (No Rank)
Player auto9* has 2D  5S  9H  qC  aD     (No Rank)
Player auto10* has 2S  7S  qD  kH  aC     (No Rank)

Player auto3* has 5D  6C  6H  6S  10S     (Three of a Kind)
Player auto6* has 3H  9D  jH  qH  qS     (One Pair)
Player auto5* has 3D  7D  9C  jC  jS     (One Pair)
Player auto4* has 5C  7C  8D  10C  10D     (One Pair)
Player auto1* has 4C  4H  9S  kD  aH     (One Pair)
Player auto10* has 2S  7S  qD  kH  aC     (No Rank)
Player auto9* has 2D  5S  9H  qC  aD     (No Rank)
Player auto2* has 2C  3C  4S  8H  aS     (No Rank)
Player auto7* has 3S  5H  7H  jD  kS     (No Rank)

Any player leaving? Enter 'No' for nobody.
Player's name:
no

Any player joining? Enter 'No' for nobody.
Player's name:
no

Game continues with 3 players.

Player auto6* has 4S  7D  8H  9C  aC     (No Rank)
Card to discard? Enter the indices separated by space in a line.

Player auto10* has 7H  7S  qC  qD  aH     (Two Pairs)
Card to discard? Enter the indices separated by space in a line.

Player auto7* has 5C  6D  jC  kD  aS     (No Rank)
Card to discard? Enter the indices separated by space in a line.

Player auto6* has 3D  9S  10S  aC  aD     (One Pair)
Player auto10* has 3S  7H  7S  qC  qD     (Two Pairs)
Player auto7* has 2C  5D  kC  kH  aS     (One Pair)

Player auto10* has 3S  7H  7S  qC  qD     (Two Pairs)
Player auto6* has 3D  9S  10S  aC  aD     (One Pair)
Player auto7* has 2C  5D  kC  kH  aS     (One Pair)

Any player leaving? Enter 'No' for nobody.
Player's name:
no

Any player joining? Enter 'No' for nobody.
Player's name:
no

Game ends with 0 players.
