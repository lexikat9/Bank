/* Lexi Katramados                                                                                                    
   CPSC 1070: 005                                                                                                    
   E2: Runtime Terror                                                                                                 
   2/26/23 */

// File headers
#include <iostream> // allows us to do input and output (cin and cout)
#include <cmath> // allows us to do mathematical functions
#include <iomanip> // allows us to use manipulor functions (ex:setw)
#include "Retirement.h" // allows us to implement Retirement.h
using namespace std;

// Method to gather user input
void Retirement::estimateDriver() {

  // Print welcome statements
  cout << "Estimate Savings at Retirement" << endl;
  cout << "Disclaimer: This is only a rough estimate!" << endl << endl;
  
  // Declare needed variables
  int currAge, retireAge;
  double amountSaved, monthlyContrib, returnPercent;

  // Prompt and scan for user input and validate
  cout << "\tEnter your current age in years: ";
  cin >> currAge;
  while (currAge < 1) {
    cout << "\tAge cannot be 0 or less." << endl;
    cout << "\tRe-enter your age in years: ";
    cin >> currAge;
  }
  cout << "\tEnter your target retirement age: ";
  cin >> retireAge;
  while (retireAge <= currAge) {
    cout << "\tYour target age cannot be less than or equal your current age." << endl;
    cout << "\tRe-enter your target age in years: ";
    cin >> retireAge;
  }
  cout << "\tHow much have you saved towards retirement?: $";
  cin >> amountSaved;
  while (amountSaved < 0) {
    cout << "\tYour savings cannot be negative." << endl;
    cout << "\tRe-enter your savings: $";
    cin >> amountSaved;
  }
  cout << "\tEnter your monthly contribution to retirement: $";
  cin >> monthlyContrib;
  while (monthlyContrib < 1) {
    cout << "\tYour monthly contribution cannot be less than or equal to zero." << endl;
    cout << "\tRe-enter your monthly contribution: $";
    cin >> monthlyContrib;
  }
  cout << "\tEnter the estimated annual return on investment (in percent): ";
  cin >> returnPercent;
  while (returnPercent < 1) {
    cout << "\tYour rate cannot be less than zero." << endl;
    cout << "\tRe-enter your rate (in percent): ";
    cin >> returnPercent;
  }
  cout << "." << endl;
  cout << "." << endl;
  cout << "...calculating" << endl << endl;

  // Call estimateEarnings method with input received and print
  estimateEarnings(currAge, retireAge, amountSaved, monthlyContrib, returnPercent);

  // Ask user if they want to go again
  string again;
  cout << "Calculate another estimate? (y/n): " << endl;
  cin >> again;
  while (again != "y" && again != "Y" && again != "n" && again != "N") {
    cout << "Invalid Input! Please choose again." << endl;
    cout << "Calculate another estimate? (y/n): " << endl;
    cin >> again;
  }
  if (again == "y" || again == "Y") {
    estimateDriver();
  }

}

// Method to calculate earnings
double Retirement::estimateEarnings(int currAge, int retireAge, double amountSaved, double monthlyContrib, double returnPercent) {

  // Calculate months the time interval will occur over and monthly interest rate
  double totalMonths = (retireAge - currAge) * 12;

  // Declare other variables
  double savedTotal = amountSaved;
  double growth;

  // Calculate retirement savings and growth (for currAge)
  for (int i = 0; i < totalMonths; i++) {
    savedTotal += (savedTotal * ((returnPercent/100.0) / 12.0));
    savedTotal += monthlyContrib;
  }

  growth = savedTotal - (amountSaved + monthlyContrib * totalMonths);

  // Print out statements with calculations (for currAge)
  cout << fixed;
  cout.precision(2);
  cout << "Estimated Retirement Savings: $" << savedTotal << endl;
  cout << "Estimated Retirement Growth: $" << growth << endl << endl;

  return savedTotal;

}
