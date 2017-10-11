// Tim Lum
// twhlum@gmail.com
// 2017.10.10
// For the University of Washington Bothell CSS 501A
// Autumn 2017, Graduate Certificate in Software Design & Development (GCSDD)
//
// File Description:
// This file is the driver program for Assignment 01 - PunchCards
//
// Program Description:
// Program to accept virtual punchcard inputs via 'cin' and output ASCII text equivalent to 'cout'
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

//Necessary to interact with 'cin' and 'cout' streams
#include <iostream>

// Necessary for string operations
#include <string>

// Includes the PunchCard header file so the compiler has all function signatures
#include "PunchCard.h"

// ---- NAMESPACE STATEMENTS ----

// Using the standard namespace (prevents us from having to be explicit everywhere with standard namespace definitions)
using namespace std;

// ---- GLOBAL VARIABLES ----
// - PROHIBITED FOR THIS COURSE -

// ---- MAIN ----

// Driver class
int main() {

// EBCDTable: Defines the decoding schema as a 2-dimensional array.
// Invariant information: Accepts only ASCII chars. Size of array cannot be altered.
//                           Other:    0    1    2    3    4    5    6    7    8    9
   const char EBCDTable[4][10] = {  { ' ', '1', '2', '3', '4', '5', '6', '7', '8', '9' },    // Zone 0
                                    { '&', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I' },    // Zone 1
                                    { '-', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R' },    // Zone 2
                                    { '0', '/', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' }  }; // Zone 3

// Instantiate a punchcard object named 'omniCard'
   PunchCard omniCard;

// While the currently loaded card is not the last card (and if there's only one card, it's false by default so we'll execute at least once)
// Loop Invariant Before: omniCard.isLastCard() returns false
// Loop Invariant After: omniCard.isLastCard() returns false
   while (omniCard.isLastCard() == false) {

// Overloaded insertion operator (>>) handles advancing to valid data, parsing, and loading of the card's inputArray.
      cin >> omniCard;

// omniCard translates the input using the decoding schema defined above
      omniCard.translate(EBCDTable);

// omniCard will report back to main whether the last card was hit on the latest loop.
      cout << omniCard.toString();
   }

   return(0);

}