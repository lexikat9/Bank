/* Lexi Katramados                                                                                                    
   CPSC 1070: 005                                                                                                    
   E2: Runtime Terror                                                                                                
   2/26/23 */

#include <iostream> // allows us to do input and output (cin and cout)
#include <cmath> // allows us to do mathematical functions
#include <string> // allows us to use strings
#include <vector> // allows us to use vectors
#include <fstream> // allows us to read in files
#include <iomanip> // allows us to use manipulor functions (ex:setw)
#include "Register.h" // allows us to implement the Register.h class
using namespace std;

// Method to get file name
string Register::getFileName() {

  // Declare needed variables (including file stream object)
  string tempName;
  ifstream inFile;
  bool valid = false;
  
  while (!valid) {
    // Prompt user for file name and put in variable
    cout << "\tPlease enter the filename: ";
    cin >> tempName;
    cout << "\tOpening the file <" << tempName << ">" << endl;

    // Open file
    inFile.open(tempName);

    // Testing file for validity (if it has info in it)
    if (inFile) {
      valid = true;
    }
    else {
      cout << "Error opening file. Please retry." << endl;
    }

    // Close the file
    inFile.close();
  }

  // Return fileName
  return tempName;
}

// Method to set file name
void Register::setFileName (string tempName) {
  fileName = tempName;
}

// Method to read from file
bool Register::readFromFile() {

  // Declare variables (excluding defining and open file stream object with the user file)
  ifstream inFile(fileName);
  string thing;
  bool complete = true;
  
  // Read in the information to the appropriate arrays
  while (inFile >> thing) {
    date.push_back(thing);
    inFile >> thing;
    if (thing == "RESTAURANT") {
      transaction.push_back(RESTAURANT);
    }
    else if (thing == "MERCHANDISE") {
      transaction.push_back(MERCHANDISE);
    }
    else if (thing == "UTILITY") {
      transaction.push_back(UTILITY);
    }
    else if (thing == "COFFEESHOP") {
      transaction.push_back(COFFEESHOP);
    }
    else if (thing == "AUTOMOTIVE") {
      transaction.push_back(AUTOMOTIVE);
    }
    else if (thing == "DEPOSIT") {
      transaction.push_back(DEPOSIT);
    }
    else {
      transaction.push_back(OTHER);
    }
    inFile >> thing;
    source.push_back(thing);
    inFile >> thing;
    amount.push_back(stod(thing)); // Put thing into amount vector as a double type
  }

  //Close file
  inFile.close();
  
  return complete = true;
}

// Method to print the file
void Register::printFile() {

  // Print printing statement
  cout << "Printing Transaction Ledger" << endl;

  // Ensure all numbers printed are 2 decimal places
  cout << fixed << setprecision(2);

  //For loop to run through all info in the arrays and print
  int size = date.size();
  for (int i = 0; i < size; i++) {
    cout << setw(8) << date[i] << " |";
    cout << setw(16) << source[i] << " |";
    cout << setw(10) << amount[i] << " |";
    cout << setw(20);
    if (transaction[i] == 0) {
      cout << "RESTAURANT" << endl; 
    }
    else if (transaction[i] == 1) {
      cout << "MERCHANDISE" << endl;
    }
    else if (transaction[i] == 2) {
      cout << "UTILITY" << endl;
    }
    else if (transaction[i] == 3) {
      cout << "COFFEESHOP" << endl;
    }
    else if (transaction[i] == 4) {
      cout << "AUTOMOTIVE" << endl;
    }
    else if (transaction[i] == 5) {
      cout << "DEPOSIT" << endl;
    }
    else if (transaction[i] == 6) {
      cout << "OTHER" << endl;
    }
    cout << endl;
  }
}

// Method to process transaction
bool Register::processTransaction () {

  // Declare variables
  bool complete = true;
  string choice;

  // Call all methods (use getFileName as a parameter for setFileName)
  setFileName(getFileName());
  readFromFile();
  printFile();

  // Ask user if they want to go again
  string again;
  cout << "Would you like to process another transaction register? (y/n): " << endl;
  cin >> again;
  while (again != "y" && again != "Y" && again != "n" && again != "N") {
    cout << "Invalid Input! Please choose again." << endl;
    cout << "Would you like to process another transaction register? (y/n): ";
    cin >> again;
  }
  if (again == "y" || again == "Y") {
    processTransaction();
  }

  return complete = true;

}
