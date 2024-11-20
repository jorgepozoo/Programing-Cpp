#pragma once
//Class definition
class Position {
public:
    // Constructors
    Position();// Initializes the position to (0, 0) and sets the default grid size to 10x10
    Position(int x, int y);//Initializes the position to the specified (x, y) and uses the default grid size
    Position(int x, int y, int xMax, int yMax);//Initializes the position and grid size based on the provided values

    // Accessors
    int getX() const;//Returns the current x-coordinate
    int getY() const;//Returns the current y-coordinate
    int getXMax() const;//Returns the maximum x - coordinate of the grid
    int getYMax() const;//Returns the maximum y-coordinate of the grid

    // Mutators
    void move(int direction);//Moves the position based on the provided direction
    void reset();//Resets the position to its home position
    void rehome();//Updates the home position to the current position

    // Equality operator, //Compares if two positions are equal in terms of their coordinates
    bool operator==(const Position& other) const;

    // Display method, // Displays a visual representation of the grid and shows the home position
    void display() const;

private:
    int x, y;   // Current position coordinates
    int xMax, yMax; // Maximum Grid size
    int homeX, homeY; // Home position

    // Helper method for moving, // Private helper used to update the home position based on the current position
    void updateHome();
};