//Necessary to interact with 'cin' and 'cout' streams
#include <iostream>
// Necessary to interact with files
#include <fstream>
#include <string>
//
using namespace std;

int main() {

	bool lastCard = false; // Flag used to identify if the last card has been encountered or not
	char thisPunch;
	char cardArray[12][80];
	const char EBCDTable[4][10] = { { ' ', '1', '2', '3', '4', '5', '6', '7', '8', '9' },
									{ '&', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I' },
									{ '-', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R' },
									{ '0', '/', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' } };


// Declares an input file stream (ifstream) variable, opens the file stream. Use "\\" instead of just "\"
	ifstream streamReader("F:\\Projects\\00_Teabean\\04_Academics\\UW GCSDD\\CSS501\\Assg01_Punchcards\\UWCSS_501_Assg01\\CSS_501A_Assg01_Punchards\\TestInput.txt");

// Verify that the file was opened
	if (!streamReader) {
		cout << "error!" << endl;
		return(-1);
	}
	else {
// While this is not the last card (lastCard != true) {
		while (lastCard == false) { 
// For all 12 rows...
			for (int row = 0; row < 12; row++) {
// Loads the next line from streamReader to the thisLine variable.
				string thisLine;
				getline(streamReader, thisLine);

// What if the string is empty (not a valid punchcard line)?

				if (thisLine.empty()) {
					getline(streamReader, thisLine);
				}

// With the line loaded, read the next 80 characters
				for (int column = 0; column < 80; column++) {
// Place the current punch in the current row and column of the card array
					thisPunch = thisLine.at(column);
					cardArray[row][column] = thisPunch;
					cout << thisPunch;
				}
				cout << endl;
			}
// Post-condition: The array has been loaded
			cout << "Array loaded with this card!" << endl;

// Testing cardArray contents
			for (int r = 0; r < 12; r++) {
				for (int c = 0; c < 80; c++) {
					cout << cardArray[r][c];
				}
				cout << endl;
			}

// Now we can check to see if this is the last card
// Check the top corner punch. If it's an 'X':
			if (cardArray[0][0] == 'X') {
// Then this has to be the last card in the stack. Set the variable to end the reading loop.
				lastCard = true;
				cout << "This is the last card!" << endl;
			}

// Precondition: Card is loaded to the cardArray
// Begin translation:
			int zonePunch;
			int otherPunch;
			char translatedCard[80];

// Determine the Zone punch
// For each column...
			for (int column = 0; column < 80; column++) {
// Default the other punch to 0
				zonePunch = 0;
// And for each zone punch location in the array...
				for (int thisZone = 0; thisZone < 3; thisZone++) {
// Check to see if the zone has been punched
					if (cardArray[thisZone][column] == 'X') {
						zonePunch = thisZone+1;
					}
				}
// Post-condition: zonePunch is 0-3

// Determine the Other punch
// Default the otherPunch to 0
				otherPunch = 0;
// And for each other punch location in the array...
				for (int thisOther = 3; thisOther < 12; thisOther++) {
// Check to see if the other has been punched
					if (cardArray[thisOther][column] == 'X') {
						otherPunch = thisOther - 2;
					}
				}
// Special case to check for multiple zone punches
				if (cardArray[0][column] == 'X' && cardArray[2][column] == 'X') {
					otherPunch = 0; // Coordinate for whitespace character on EBCD table
				}
// Post-condition: otherPunch is 0-9

// Special case to check for multiple zone punches
				if (cardArray[0][column] == 'X' && cardArray[2][column] == 'X') {
					zonePunch = 0; // Coordinate for whitespace character on EBCD table
					otherPunch = 0; // Coordinate for whitespace character on EBCD table
				}
// Post-condition: zonePunch and otherPunch are within valid ranges *and* correct.

				cout << zonePunch << " " << otherPunch << " , "; // Debug check

// With the zone- and other-punch in hand, look up its value on the EBCD table and load to array
				translatedCard[column] = EBCDTable[zonePunch][otherPunch];
			} // Closing for loop over columns

// Test to see if translatedCard was loaded properly
			for (int i = 0; i < 80; i++) {
				cout << translatedCard[i];
			}
			cout << endl;
		} // Closing while loop (while not the lastCard)
	}

// Awaits input from cin.
// Use with Visual Studio to pause the closure of the console window.
	cin.get();
}