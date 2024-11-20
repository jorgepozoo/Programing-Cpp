#include "Position.h"
#include <iostream>
using namespace std;
// Constructors, //Initializes the member variables with default values
Position::Position() : x(0), y(0), xMax(10), yMax(10), homeX(0), homeY(0) {}

Position::Position(int x, int y) : x(x), y(y), xMax(10), yMax(10), homeX(x), homeY(y) {}

Position::Position(int x, int y, int xMax, int yMax) : x(x), y(y), xMax(xMax), yMax(yMax), homeX(x), homeY(y) {}

// Accessors, //Recover the values of the private member variables.

int Position::getX() const { return x; }

int Position::getY() const { return y; }

int Position::getXMax() const { return xMax; }

int Position::getYMax() const { return yMax; }

// Mutators, // Modifies the x and y coordinates based on the provided direction
void Position::move(int direction) {
    switch (direction) {
    case 1: y--; break;
    case 2: y--; x++; break;
    case 3: x++; break;
    case 4: x++; y++; break;
    case 6: x--; y++; break;
    case 7: y++; break;
    case 8: y++; x--; break;
    case 9: x--; break;
    default: break;
    }
    updateHome();
}
//Resets the current position to the home position 
void Position::reset() {
    x = homeX;
    y = homeY;
}
//updates the home position to the current position
void Position::rehome() {
    homeX = x;
    homeY = y;
}

// Equality operator
bool Position::operator==(const Position& other) const {
    return (x == other.x) && (y == other.y) && (xMax == other.xMax) && (yMax == other.yMax);
}

// Display method, // Prints a visual representation of the grid 
void Position::display() const {
    for (int i = yMax - 1; i >= 0; i--) {
        for (int j = 0; j < xMax; j++) {
            if (i == y && j == x) {
                cout << "*";
            }
            else {
                cout << ".";
            }
        }
         cout << endl;
    }
    cout << "Home position: (" << homeX << "," << homeY << ")" << endl;
}

// Helper method for moving, //checks if the current position is outside the grid, and if so, it updates the home position
void Position::updateHome() {
    if (x < 0 || x >= xMax || y < 0 || y >= yMax) {
        // If moved outside the grid, reset home position
        homeX = x;
        homeY = y;
    }
}