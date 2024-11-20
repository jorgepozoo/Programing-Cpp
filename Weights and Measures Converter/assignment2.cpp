/**
* \file assignment-2.cpp
* \author Jorge Escobar Pozo (s0549027)
* \date 2023-10-2023
* \todo A program that computes the cost of a long-distance phone call
**/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// function declarations (prototype)
void welcomeBanner();// Function to display a welcome banner
void getDay(string& day, string& dayName);// Function to obtain the day code and its corresponding name
int getTime();// Function to obtain the time in 24-hour format
void getDuration(float& duration);// Function to obtain the duration of the call in minutes
double calculation(string day, int time, float duration);// Function to calculate the cost of the call according to the day, time and duration
void printCallDetails(string& dayName, int time, float duration, double callCost);// Function to print call details, including the name of the day


int main() {
	// variables to store user input and calculation values
	string day,dayName;
	int time;
	float duration;
	char another_calc;
	// Welcome message
	welcomeBanner();
	do {
		//get the day, time and duration of the user's call
		getDay(day,dayName);
		time=getTime();
		getDuration(duration);

		//call cost calculation
		double callCost = calculation(day,time, duration);

		//print all the call details
		printCallDetails( dayName,time,duration,callCost);

		// Ask if the user wants to calculate another call
		cout << "\nWould you like to calculate another call? (Y/N): ";
		cin >> another_calc;
		// Clear the variable 'day' for the next user input.
		day.clear();
		
	} while (another_calc != 'n' && another_calc != 'N');


	return 0;
}
//welcome function
void welcomeBanner(){
	cout << "\tWelcome to the Phone Call Calculation Program by Jorge Escobar" << endl;
}
//Function for obtaining the day and assigning its full name
void getDay(string& day, string& dayName) {
	
	bool validInput = false;
	
	while (!validInput) {
		cout << "\nEnter the day code (first 2 letters e.g., 'Mo'): ";
		cin >> day;
		// Check if user input is valid
		if (day == "Mo" || day == "Tu" || day == "We" || day == "Th" || day == "Fr" || day == "Sa" || day == "Su" ||
			day == "MO" || day == "TU" || day == "WE" || day == "TH" || day == "FR" || day == "SA" || day == "SU" ||
			day == "mo" || day == "tu" || day == "we" || day == "th" || day == "fr" || day == "sa" || day == "su" ||
			day == "mO" || day == "tU" || day == "wE" || day == "tH" || day == "fR" || day == "sA" || day == "sU") {
			break;
		}
		else {

		cout << "\nPlease enter a valid code (e.g., Mo, Tu, We, Th, Fr, Sa, Su)" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	}
	// Assigns the corresponding day name
	if (day == "Mo" || day == "MO" || day == "mO" || day == "mo") {
		dayName = "Monday";
	}
	else if (day == "Tu" || day == "TU" || day == "tU" || day == "tu") {
		dayName = "Tuesday";
	}
	else if (day == "We" || day == "WE" || day == "wE" || day == "we") {
		dayName = "Wednesday";
	}
	else if (day == "Th" || day == "TH" || day == "tH" || day == "th") {
		dayName = "Thursday";
	}
	else if (day == "Fr" || day == "FR" || day == "fR" || day == "fr") {
		dayName = "Friday";
	}
	else if (day == "Sa" || day == "SA" || day == "sA" || day == "sa") {
		dayName = "Saturday";
	}
	else if (day == "Su" || day == "SU" || day == "sU" || day == "su") {
		dayName = "Sunday";

	}
}
// Function to get the call start time
int getTime() {
	int time;
	bool validInput = false;
	while (!validInput) {
		cout << "\nEnter the time the call started (24-hour, hh mm): ";
		cin >> time;
		if (time >= 0 && time <= 2359) {
			return time;
		}
		cout << "\nEnter the time the call started (24-hour, hh mm e.g., 1300) "<<endl;
	}
}
// Function to get the call length
void getDuration(float& duration) {
	do {
		cout << "\nEnter the length of the call (in minutes): ";
		cin >> duration;
	} while (duration < 0);
}
// Function to calculate the call cost
double calculation(string day, int time, float duration) {
	if ((day == "Mo" || day == "Tu" || day == "We" || day == "Th" || day == "Fr" ||
		day == "MO" || day == "TU" || day == "WE" || day == "TH" || day == "FR" ||
		day == "mO" || day == "tU" || day == "wE" || day == "tH" || day == "fR" ||
		day == "mo" || day == "tu" || day == "we" || day == "th" || day == "fr")&&(time>=700 && time<=1759)) {
		return duration * 0.30;
	}
	else if ((day == "Mo" || day == "Tu" || day == "We" || day == "Th" || day == "Fr" ||
		day == "MO" || day == "TU" || day == "WE" || day == "TH" || day == "FR" ||
		day == "mO" || day == "tU" || day == "wE" || day == "tH" || day == "fR" ||
		day == "mo" || day == "tu" || day == "we" || day == "th" || day == "fr") && (time < 700 && time > 1759)) {
		return duration * 0.15;
	}
	else {
		return duration * 0.10;
	}

}
// Function to print the call details
void printCallDetails(string& dayName,int time, float duration, double callCost) {
	
	cout << "\nCall details:\n" << endl;
	cout << "Day: "<< dayName << endl;
	cout << "Time: " << setw(2) << setfill('0') << (time / 100) << ":" << setw(2) << setfill('0') << (time % 100) << endl;
	cout << "Call Length: " << duration <<" minutes"<< endl;
	cout << "Call Cost: $"<< fixed<<setprecision(2)<<callCost << endl;
	
}


	





