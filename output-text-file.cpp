/*****************************************************************//**
 * \file   CS10B Scratch Paper.cpp
 * \brief  
 * Dummy project for testing random bits of code
 * \author aidanfish
 * \date   January 2024
 *********************************************************************/

#include <iostream>
//! step 1
//  
#include <fstream>
// uncomment to disable assert()
// #define NDEBUG
#include <cassert>
using namespace std;




const char CHAR_FOR_ROW_DIVIDER = '*';
const int NUM_TO_PRINT_IN_ROW_DIVIDER = 96;




/// <summary>
/// Prompts the user for the file they wish to read from, and
/// returns an ifstream corresponding to the requested file.
/// </summary>
/// <remarks> test </remarks>
/// <returns></returns>
ifstream getUserInput() {
	string fileName;
	ifstream returnStream;
	cout << "Input file to read, including file extension name (e.g. lorem-ipsum.txt): ";
	cin >> fileName;



	cout << "Attempting to read file..." << endl;
	returnStream.open(fileName);


	
	if (!returnStream) {
		cout << "Unable to read file :C Did you put in the right name?" << endl;
		cout << "Inputted file name was: \"" << fileName << "\"" << endl;
	}
	else {
		cout << "Successfully read from file (filename \"" << fileName << "\")" << endl << endl;
	}

	return returnStream;
}




/// <summary>
/// Returns a string containg X number of desired character. (e.g. if inputted
/// char is '*' and inputted number is 5, the return string would be "*****")
/// </summary>
/// <param name="charToPrint">The desired character you wish to use</param>
/// <param name="numToPrint">How many of this character should be generated</param>
/// <returns></returns>
string generateRowOfCharacters(char charToPrint, int numToPrint) {
	string returnString;


	for (int i = 0; i < numToPrint; i++) {
		returnString += charToPrint;
	}


	return returnString;
}




int main()
{
	ifstream inputFile;
	string lineSeparator = generateRowOfCharacters(CHAR_FOR_ROW_DIVIDER, NUM_TO_PRINT_IN_ROW_DIVIDER);



	// Prompts user for the desired text file to read until file is successfully "acquired"
	do {
		inputFile = getUserInput();
	}
	while (!inputFile);


	// Print the line divider to make output easier to read...
	cout << lineSeparator << endl;


	char ch;
	// Reading first char from inputFile PRIOR to while loop in order to avoid
	// off-by-one error as well as to avoid attempting to print ch before it is
	// initialized (which would result in an error :C)
	inputFile.get(ch);
	while (inputFile) {
		cout << ch;
		inputFile.get(ch);
	}


	// Inserting a new line because the end of the file will NOT contain a
	// newline - we must manually go onto a new line if we dont want our next
	// cout to print to the same row as the text file output
	cout << endl;


	// Print the line divider to make output easier to read... again
	cout << lineSeparator << endl;


	cout << endl << endl << "File has been read successfully! C: Closing file and ending program..." << endl << endl;
	inputFile.close();
}
