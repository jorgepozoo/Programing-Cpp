/*****************************************************************//**
 * \file   main.cpp
 * \brief  Testing program for Assignment 5 - DO NOT MODIFY THIS FILE!
 * 
 * \author Stephen Graham
 * \date   November 2022
 * 
 * This file has been constructed to use the Position class which you
 * will define and implement. You can observe in this program the various
 * constructors and methods used. See the instruction assignments for
 * the guarantees that must be met by the Position class.
 * DO NOT MODIFY THIS FILE!
 *********************************************************************/
#include <iostream>
#include <limits>      // numeric_limits
#include "Position.h"  // the entire Position class
using namespace std;


/**
 * Get a direction from the user and return it.
 * 7 8 9
 *  \|/
 * 4-+-6
 *  /|\
 * 1 2 3
 * 5 is valid for resetting the home position to the current
 * 0 is valid for returning the bot to its home position
 * 
 * \return int the selected direction
 */
int getDirection();

/**
 * Perform "bot navigation" with he provided bot.
 * 
 * \param	Position& the position object representing the bot to be moved
 * \post	the provided bot has updated position and origin information
 */
void botNavigation(Position& bot);

int main() {

/// test constructors	
	cout << "Construct two, default Position objects (bot1, bot2) at 0,0 on 10x10 grid... ";
	Position bot1, bot2;
	cout << "success" << endl;

	cout << "Construct one Position object (bot3) at 5,5 on a default 10x10 grid... ";
	Position bot3(5, 5);
	cout << "success" << endl;

	cout << "Construct one Position object (bot4) at 10,10 on a 20x20 grid... ";
	Position bot4(10, 10, 20, 20);
	cout << "success" << endl;

// test comparison operator
	cout << "bot1 and bot 2 are at the same location on a matching grid (bot1 == bot2) (should be true)...";
	cout << ((bot1 == bot2) ? "true\n" : "false\n") << endl;

	cout << "bot1 and bot 3 are at the same location on a matching grid (bot1 == bot3) (should be false)...";
	cout << ((bot1 == bot3) ? "true\n" : "false\n") << endl;

// show bot1 position
	cout << "Bot1 map:" << endl;
	bot1.display();

// show bot4 position
	cout << "Bot4 map:" << endl;
	bot4.display();

// test bot movement
	cout << "\nTesting navigation with bot1" << endl;
	botNavigation(bot1);
	cout << "Bot1 navigation complete" << endl;

	cout << "All tests complete";
	return 0;
}

int getDirection() {
	int d = 10;
	while (d > 9) {
		// display instructions
		cout << "\n7 8 9\n \\|/\n4-+-6\n /|\\\n1 2 3\n";
		cout << "5 - set the current position as 'home'\n";
		cout << "0 - return to 'home' position\n";
		cout << "Enter a number for a direction (negative to stop): ";
		
		// attempt to get a valid integer
		cin >> d;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			d = 10;
		}
	}
	return d;
}

void botNavigation(Position& bot){
	// take commands and move the bot1 around
	int direction;

	// show the initial position
	cout << "\n\n" << endl;
	bot.display(); 

	// Get a direction from the user until the direction is less than 0
	while ((direction = getDirection()) >= 0) {
		switch (direction) {
		case 0: // reset to origin
			bot.reset(); break;
		case 5: // move the origin location to current
			bot.rehome(); break;
		default: // perform a move
			bot.move(direction);
		}
		cout << "\n\n" << endl;
		bot.display();
	}
}
