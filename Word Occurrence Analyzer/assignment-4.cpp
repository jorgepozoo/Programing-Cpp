/**
*  \file Assigment 4
* \author Jorge Escobar
* \date 2023-11-20
* \todo A modular program that outputs a list of words along with their counts to the screen.
**/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

/* fuctions prototypes*/
int findWordPosition(const vector<string>& words, const string& word);
void addWord(const string& word, vector<string>& words, vector<int>& counts);
void reportToScreen(const vector<string>& words, const vector<int>& counts);
const int COL_WIDTH = 3;


/**
* \brief   The main() function controls the program
* \details - Prompts the user for a file name
*          - Opens the file, reads through it, and counts word occurrences
*          - Closes the file
*          - Outputs the list of words with their counts in 3 columns on the console
* 
* \todo    write the main() function to accomplish the given task
**/
int main() {
    // Vectors to store words and their occurrences
    vector<string> words;
    vector<int> counts;
    string word;
    string filename;

    // Prompt the user for a file to read
    cout << "Enter the name of the file to read: ";
    cin >> filename;

    // Open the file
    ifstream inputFile(filename);

    // Check for file open errors
    if (!inputFile.is_open()) {
        cout << "File not found\n";
        return 1;
    }

    // Read words from the file and count occurrences
    while (inputFile >> word) {
        addWord(word, words, counts);
    }

    // Close the file
    inputFile.close();

    // Output the list of words and their counts to the screen
    reportToScreen(words, counts);

	return 0;
}

/**
* \brief   Finds the position of a word in the vector, ignoring case
* \param   words: The vector of words to search
* \param   word: The word to find
* \return  The position of the word in the vector if found, otherwise -1
**/

int findWordPosition(const vector<string>& words, const string& word) {

    // Loop through the vector of words
    for (size_t i = 0; i < words.size(); ++i) {

        // Check if the first letter of the current word matches the first letter of the target word (ignoring case)
        if (tolower(words[i][0]) == tolower(word[0])) {
            return static_cast<int>(i);// Return the position if found
        }
    }
    return -1;// Word not found
}

/**
* \brief   Adds a word to the vectors or increments the count if the word already exists
* \param   word: The word to add
* \param   words: The vector of words
* \param   counts: The vector of word counts
**/

void addWord(const string& word, vector<string>& words, vector<int>& counts) {
    int position = findWordPosition(words, word);

    if (position != -1) {
        
        // Word already exists, increment count
        counts[position]++;
    }
    else {
        
        // Word does not exist, add to vectors
        words.push_back(word);
        counts.push_back(1);
    }
}

/**
* \brief   Reports words and their occurrences to the screen in a tabular format
* \param   words: The vector of words
* \param   counts: The vector of word counts
**/
void reportToScreen(const vector<string>& words, const vector<int>& counts) {
    size_t maxWordLength = 0;

    // Calculate the size of the largest word
    for (const string& word : words) {
        maxWordLength = max(maxWordLength, word.length());
    }

    // Display the columns of words and their occurrences
    cout << left << setw(5) << "Word" << setw(5) << "Occurrences" << right << setw(8) << "Word" << "  " << setw(10) << "Occurrences" << setw(7) << "Word" << "  " << setw(10) << "Occurrences";
    cout << '\n';

    // Loop through the words vector and display in columns
    for (size_t i = 0; i < words.size(); i += COL_WIDTH) {
        // Display the word and occurrences
        cout << left << setw(maxWordLength) << words[i] << setw(10) << counts[i];
        if (i + 1 < words.size()) {
            cout << setw(maxWordLength) << words[i + 1] << setw(10) << counts[i + 1];
        }
        if (i + 2 < words.size()) {
            cout << setw(maxWordLength) << words[i + 2] << setw(10) << counts[i + 2];
        }
        cout << '\n';
    }
}