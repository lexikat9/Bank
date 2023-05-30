/* Lexi Katramados                                                                                      
   CPSC 1071: 005                                                                                       
   E2: Runtime Terror                                                                                   
   2/26/23 */

// File headers
#include <iostream> // allows us to do input and output (cin and cout)
#include <string> // allows us to use strings
#include "Loan.h" // allows us to implement the loan class
#include "Retirement.h" // allows us to implement the retirement class
#include "Register.h" // allows us to implement the register class
using namespace std;

// Method prototype
void runMenuSystem();

// Declare objects
Loan runLoan;
Retirement runRetire;
Register runReg;

// Main method
int main () {
  cout << "Starting Clementine Financial Bank" << endl;
  runMenuSystem();
  return 0;
}

//Run menu method
void runMenuSystem() {

  // Declare boolean
  bool quit = false;

  // While the user doesn't quit...
  while (!quit) {

    // Print options and read for user input for menu choice
    char userChoice = ' ';
    cout << "******* Welcome to Clementine Financial *******" << endl << endl;
    cout << "Menu:" << endl;
    cout << "\t[E] Estimate how much money at retirement" << endl;
    cout << "\t[L] Loan payoff calculator" << endl;
    cout << "\t[R] Run transaction classifier" << endl;
    cout << "\t[Q] Quit program" << endl << endl;
    cout << " Enter your choice and press enter: ";
    cin >> userChoice;
    cout << endl;

    // Check for valid input
    while (userChoice != 'E' && userChoice != 'e' && userChoice != 'L' && userChoice != 'l' && userChoice != 'Q' && userChoice != 'q' && userChoice != 'R' && userChoice != 'r') {
      cout << "The provided choice was invalid! Please select again." << endl << endl;
      runMenuSystem();
    }

    // If user chooses E...                                                                                 
    if (userChoice == 'E' || userChoice == 'e') {
      runRetire.estimateDriver();
    }
    // else, if  user chooses L...                                                                          
    else if (userChoice == 'L' || userChoice == 'l') {
      runLoan.paymentDriver();
    }

    // else, if user chooses R...
    else if (userChoice == 'R' || userChoice == 'r') {
      runReg.processTransaction();  
    }
    
    // else, if user chooses Q, quit the program
    else {
      exit(0);
    }
  }
}
