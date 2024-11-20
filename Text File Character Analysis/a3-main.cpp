/**
* \file		a3-main.cpp
* \author   Jorge Escobar
* \date     2023/10/30
* \todo	    A program that reads a text file one character at a time and write a "stats.txt" file
**/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <array>

using namespace std;

//Function declaretions
void counting(const string &file, array<int, 6>& count, int& total);
void print(const array<int, 6>& count, int total, ofstream& outF);

int main() {
	//variables
	string filename;//Stores user's input file
	ofstream outF("stats.txt");//Opens an output file named "stats.txt"
	array<int, 6> count = { 0 };//Initialize an array to count character types
	int total = 0; // Initialize a variable to count total characters
	
	// Prompt the user for the file to process
	cout << "Enter the name of the file to process: ";
	cin >> filename;
	// Call the counting function to count characters in the file
	counting(filename, count, total);
	// Call the print function to print the statistics to "stats.txt"
	print(count, total, outF);

	return 0;
}
// Function to count characters and types of characters
void counting(const string& file, array<int, 6>& count, int& total) {

	ifstream inF(file);
	char read;

	if (!inF) {
		cout << "File not found" << endl;// Display an error message if the file cannot be opened
	}

	while (inF.get(read)) {
		total++;// Increment the total character count
		// Check the type of character and update the corresponding count
		if (isalpha(read)) count[0]++;// Count alphabetic characters
		if (isdigit(read)) count[1]++;// Count numeric characters
		if (iscntrl(read)) count[2]++;// Count control characters
		if (isupper(read)) count[3]++;// Count uppercase characters
		if (islower(read)) count[4]++;// Count lowercase characters
		if (ispunct(read)) count[5]++;// Count punctuation characters
	}
	inF.close();// Close the input file

}

// Function to print statistics to an output file
void print(const array<int, 6>& count, int total, ofstream& outF) {
	
	double percentage;// Variable to store the percentage
	string category[] = { "Alphabetic", "Numeric", "Control", "Upper", "Lower", "Punctuation" };// Character categories
	// Write the header for the output file
	outF << left << setw(15) << "Category" << right << setw(15) << "Count" << setw(25) << "Percent" << endl;
	for (int i = 0; i < 6; i++) {
		percentage = (static_cast<double>(count[i]) / total) * 100;// Calculate the percentage
		// Write the category, count, and percentage to the output file with appropriate formatting
		outF << left << setw(15) << category[i] << right << setw(15) << count[i] << fixed << setprecision(1) << setw(15) << percentage << endl;
	}
	// Write the total character count to the output file
	outF << left << setw(15) << "Total " << right << setw(15) << total << endl;
	outF.close();// Close the output file
}

