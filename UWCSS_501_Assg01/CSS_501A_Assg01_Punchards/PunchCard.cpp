// Tim Lum
// twhlum@gmail.com
// 2017.10.10
// For the University of Washington Bothell CSS 501A
// Autumn 2017, Graduate Certificate in Software Design & Development (GCSDD)
//
// File Description:
// This file is the implementation of the PunchCard class as defined by PunchCard.h
//
// Package files:
// Assg01_Driver_PunchCards.cpp
// PunchCard.cpp
// PunchCard.h
//
// Acknowledgements:
// Source material from:
// University of Washington Bothell
// CSS 501A Data Structures And Object-Oriented Programming I
// "Design and Coding Standards"
// Michael Stiber
//
// Template author:
// Tim Lum (twhlum@gmail.com)
//
// License: (Note to student, the following is optional)
// This software is published under the GNU general license which guarantees
// end users the freedom to run, study, share and modify the software.
// https://www.gnu.org/licenses/gpl.html
//
// Code Standards:
// I. Comment at beginning of file (above) stating (at a minimum):
//    A. File Name
//    B. Author Name
//    C. Date
//    D. Description of code purpose 
// II. Indentation:
//    A. 3 whitespaces ("   ")
//    B. May vary depending on language and instructor
// III. Variables:
//    A. Descriptive, legible name
//    B. Comment over any variable declaration describing:
//       0. Its use in the algorithm
//       1. Invariant information such as legal ranges of values
// IV. Class Files:
//    A. Separate *.cpp and *.h files should be used for each class.
//    B. Files names must exactly match class names (case-sensitive)
// V. Includes:
//    A. Calls for content ("#include") from the Standard Template Library (STL) should be formatted as follows:
//       0. DO type:     #include <vector>
//       1. Do NOT type: #include <vector.h>
//    B. You may use the directive "using namespace std;"
//       0. ??? (?CONFIRM?)
// VI. Classes:
//    A. Return values:
//       0. Do NOT return references to internal class structures.
//       1. Do NOT return pointers to internal class structures.
//    B. Do NOT expose any details of the internal implementation.
// VII. Functions + Methods:
//    A. Functions should be used for appropriate operations.
//    B. Reference arguments should be used only when necessary.
//    C. The (return?CONFIRM?) type of each function must be declared
//       0. Use 'void' when necessary
//    D. Declare as 'const' (unalterable) when no modification is made to the object state
//       0. UML 'query' property (?CONFIRM?)
// VIII. Function Comments:
//    A. DO include a comment prior to each function which includes the function's:
//       0. Purpose - Why does the function exist?
//       1. Parameters - What fields does the function contain?
//       2. Preconditions - What conditions must be true prior to the function call?
//       3. Postconditions - What conditions must be true after the function call?
//       4. Return value - What is the nature and range of the value returned by the function?
//       5. Functions called - What other functions are called by this function?
// IX. Loop invariants
//    A. Each loop should be commented with 'invariant' information (?CONFIRM?)
// X. Assertions:
//    A. May be comments or the 'assert()' feature.
//    B. Insert where useful to explain important features or subtle logic.
//    C. What, exactly, is an assertion (?CONFIRM?)
// XI. Prohibited (unless justified):
//    A. Global variables
//    B. "Gotos" (?CONFIRM?)
//
// Special instructions:
// To update Linux:
// sudo apt-get update && sudo apt-get install
// sudo apt-get update
//
// To make a new .cpp file in Linux:
// nano <file name>.cpp
//
// To make a new .h file in Linux:
// nano <file name>.h
//
// To make a new .txt file in Linux:
// nano <file name>.txt
//
// To compile in g++:
// g++ -std=c++11 PunchCard.cpp main.cpp
//
// To run with test input:
// ./a.out < TestInput.txt
//
// ---- BEGIN STUDENT CODE ----

// ---- IMPORT STATEMENTS ----

#pragma once

//Necessary to interact with 'cin' and 'cout' streams
#include <iostream>

// Necessary for string operations
#include <string>

// Includes the PunchCard header file so the compiler has all function signatures
#include "PunchCard.h"

// ---- NAMESPACE STATEMENTS ----
// None

// ---- GLOBAL VARIABLES ----
// - PROHIBITED FOR THIS COURSE -

// ---- CONSTRUCTORS ----
// Do not need an explicit constructor; can use the implicit one.

// Note: Fields can be initialized in EITHER the .h or the .cpp
PunchCard::PunchCard() {

// ---- FIELDS ----

// inputArray: A 2-Dimensional array, 80-wide, 12 deep. Used to store inputs from 'cin'
// Invariant information: Accepts only ASCII chars. Size of array cannot be altered.
   char inputArray[80][12];

// outputArray: An array, 80-long. Used to store interpreted text from translate() and queried by toString() for output.
// Invariant information: Accepts only ASCII chars. Size of array cannot be altered.
   char outputArray[80];

// zonePunch: An integer representing the state of the EBCD zone punch, from positions 1-3. 0 represents unpunched.
// Invariant information: Values range from 0 to 3.
   int zonePunch;

// zonePunch: An integer representing the state of the EBCD other punch, from positions 1-9. 0 represents unpunched.
// Invariant information: Values range from 0 to 9.
   int otherPunch;
}

// ---- METHODS ----

// translate() - To translate the inputArray based upon a received decoding table.
// Parameters: No internal fields
// Preconditions: inputArray must be an 80 x 12 array. decodeTable must by a 4 x 10 array.
// Postconditions: outputArray must be loaded with values limited to those in the decodeTable.
// Return value: Not applicable
// Functions called: None
const void PunchCard::translate(const char decodeTable[4][10]) {
// Begin translation:

// For each column...
// Loop Invariant Before: none
// Loop Invariant After: column variable has iterated to 79.
   for (int column = 0; column < 80; column++) {
// Determine the Zone punch
// Default the zone punch to 0
      zonePunch = 0;

// And for each zone punch location in the array...
// Loop Invariant Before: none
// Loop Invariant After: thisZone has iterated to 2
      for (int thisZone = 0; thisZone < 3; thisZone++) {
// Check to see if the zone has been punched
         if (inputArray[thisZone][column] == 'X') {
            zonePunch = thisZone + 1;
         }
      }
// zonePunch is now set to a value from 0-3

// Determine the Other punch
// Default the otherPunch to 0
      otherPunch = 0;
// And for each other punch location in the array...
// Loop Invariant Before: none
// Loop Invariant After: thisOther variable has iterated to 11.
      for (int thisOther = 3; thisOther < 12; thisOther++) {
// Check to see if the other has been punched
         if (inputArray[thisOther][column] == 'X') {
            otherPunch = thisOther - 2;
         }
      }
// otherPunch is now set to a value from 0-9

// Special case to check for multiple zone punches. If more than one zone punch is punched (arbitrarily position 0 and 2)...
// Loop Invariant Before: More than one zone punch must exist in the first column of a card.
// Loop Invariant After: The zone and other punches are keyed to the whitespace value of the EBCD table
      if (inputArray[0][column] == 'X' && inputArray[2][column] == 'X') {
// Override the coordinate back to the whitespace character on the EBCD table
         otherPunch = 0;
         zonePunch = 0;
      }
// Current condition: otherPunch is 0-9, zonePunch is 0-3, but now both are definitely correct

// With the zone- and other-punch in hand, look up its value on the EBCD table and load to array
      outputArray[column] = decodeTable[zonePunch][otherPunch];
   }
// End behavior for each column
}

// isLastCard() - To declare whether the first column of the current card is fully punched out or not.
// Parameters: No internal fields
// Preconditions: None
// Postconditions: None
// Return value: boolean, representing whether this is the "last" card in a stack (true) or not (false).
// Functions called: None
const bool PunchCard::isLastCard() {
// Check the uppermost corner. If it's punched out...
// Loop Invariant Before: The first location of a card is punched
// Loop Invariant After: Not applicable. Loop would be exited via a return value.
   if (inputArray[0][0] == 'X') {
// Then this is the last card.
      return(true);
   }
// Otherwise, this is not the last card.
   return(false);
}


// toString() - To return a string representation of the decoded PunchCard.
// Parameters: returnString - Used to concatenate successive characters from the outputArray.
// Preconditions: None
// Postconditions: returnString is 80 characters in length, plus a newline character at its end.
// Return value: A string, 80 characters in length, with a newline character at its end.
// Functions called: None
const string PunchCard::toString() {
//	cout << "Begin toString()" << endl; // DEBUG
   string returnString = "";
// For each of 80 array positions...
   for (int i = 0; i < 80; i++) {
// Append the character at that index to the returnString.
      returnString = returnString + outputArray[i];
   }
// Append the newline character.
   returnString = returnString + '\n';
// Send the concatenated string back.
   return(returnString);
}




// ----OVERLOADS----

// >> - Custom behavior for the insertion operator when dealing with an istream object (left) and a PunchCard object (right)
// Parameters: thisLine - Used to store successive lines of data from cin.
// Preconditions: Content must be loaded to cin, terminated by newline characters.
// Postconditions: inputArray will be loaded with the first 80 characters of the first 12 lines of input from cin.
// Return value: None
// Functions called: getline - Pulls the first line of data from cin
istream& operator>>(istream& cinData, PunchCard& someCard) { // where 'cinData' is the input variable and 'card' is the PunchCard object
   string thisLine = "";
   char thisPunch;
// For all 12 rows...
   for (int row = 0; row < 12; row++) {
// Loads the next line from streamReader to the thisLine variable.
      getline(cinData, thisLine);

// If the string is empty... (as in, valid data is preceded by blank lines)

      while (thisLine.empty()) {
         // ... advance over it to the next line.
         getline(cinData, thisLine);
      }

      // With the line loaded, read the next 80 characters
      for (int column = 0; column < 80; column++) {
         // Place the current punch in the current row and column of the card array
         thisPunch = thisLine.at(column);
         someCard.inputArray[row][column] = thisPunch;
      }
//		cout << endl; // DEBUG
   }
   // Post-condition: The array has been loaded
//	cout << "The array is loaded!"; // DEBUG
   return (cinData);
}

// Can omit the destructor
// PunchCard::~PunchCard() {
//	<Destructor implementation goes here>
// }