// Tim Lum
// twhlum@gmail.com
// 2017.10.10
// For the University of Washington Bothell CSS 501A
// Autumn 2017, Graduate Certificate in Software Design & Development (GCSDD)
//
// File Description:
// This file is the header (definitions) of the PunchCard class.
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

using namespace std;

class PunchCard {

// --- PRIVATE REGION --- PRIVATE REGION --- PRIVATE REGION ---
private:

// PRIVATE FIELDS:

// inputArray: A 2-Dimensional array, 80-wide, 12 deep. Used to store inputs from 'cin'
// Invariant information: Accepts only ASCII chars. Size of array cannot be altered.
   char inputArray[12][80];

   // outputArray - The decoded ASCII sequence
   char outputArray[80];

   // EBCDTable - Encoded values
   char EBCDTable[4][10];

   // zonePunch - Integer representing the zone punch (from 0 to 3)
   int zonePunch = 0;

   // otherPunch - Integer representing the other punch (from 0 to 9)
   int otherPunch = 0;

// PRIVATE METHODS:


// --- PUBLIC REGION --- PUBLIC REGION --- PUBLIC REGION ---
public:

// PUBLIC FIELDS:

// PUBLIC METHODS:


// ---- CONSTRUCTOR ----
   PunchCard();

   // const <return type> <method name>( <arguments> );
   // e.g. const bool checkIfLastCard();

   // isLastCard() - To declare whether the first column of the current card is fully punched out or not.
   // Parameters: No internal fields
   // Preconditions: None
   // Postconditions: None
   // Return value: boolean, representing whether this is the "last" card in a stack (true) or not (false).
   // Functions called: None
   const bool isLastCard();

   // translate() - To translate the inputArray based upon a received decoding table.
   // Parameters: No internal fields
   // Preconditions: inputArray must be an 80 x 12 array. decodeTable must by a 4 x 10 array.
   // Postconditions: outputArray must be loaded with values limited to those in the decodeTable.
   // Return value: Not applicable
   // Functions called: None
   const void translate(const char[4][10]);

   // toString() - To return a string representation of the decoded PunchCard.
   // Parameters: returnString - Used to concatenate successive characters from the outputArray.
   // Preconditions: None
   // Postconditions: returnString is 80 characters in length, plus a newline character at its end.
   // Return value: A string, 80 characters in length, with a newline character at its end.
   // Functions called: None
   const string toString();

// >> - Custom behavior for the insertion operator when dealing with an istream object (left) and a PunchCard object (right)
// Parameters: thisLine - Used to store successive lines of data from cin.
// Preconditions: Content must be loaded to cin, terminated by newline characters.
// Postconditions: inputArray will be loaded with the first 80 characters of the first 12 lines of input from cin.
// Return value: None
// Functions called: getline - Pulls the first line of data from cin
// If it's in the class definition, include 'friend'
   friend istream& operator>>(istream& cinData, PunchCard& someCard);
//        inputStream (by reference) operator-named->> ( <left argument type>(by reference) <left argument name>, <right argument type>(by reference) <right argument name>);

// ---- DESTRUCTOR -----
//   ~PunchCard(); // Can be ignored for this assignment.
};