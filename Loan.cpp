/* Lexi Katramados                                                                                                   
   CPSC 1070: 005                                                                                                     
   E2: Runtime Terror                                                                                                 
   2/26/23 */

// File headers
#include <iostream> // allows us to do input and output (cin and cout)
#include <cmath> // allows us to do mathematical functions
#include <iomanip> // allows us to use manipulor functions (ex:setw)
#include "Loan.h" // allows us to implement Loan.h
using namespace std;

// Method for paymentDriver
void Loan::paymentDriver() {

  // Print open statement
  cout << "Loan Payment Calculator" << endl;
  
  // Declare needed variables
  double prinAmount, interestRate, monthlyPay;

  // Prompt user for input and gather in variables
  cout << "\nEnter the principal amount: $";
  cin >> prinAmount;
  cout << "Enter the annual interest rate (in percent): ";
  cin >> interestRate;
  cout << "Enter the monthly payment: $";
  cin >> monthlyPay;
  cout << "\nCalculating..." << endl << endl;

  // Call paymentMonths method
  paymentMonths(prinAmount, interestRate, monthlyPay);

  // Ask user if they want to go again
  string again;
  cout << "Calculate another loan payoff? (y/n): " << endl;
  cin >> again;
  while (again != "y" && again != "Y" && again != "n" && again != "N") {
    cout << "Invalid Input! Please choose again." << endl;
    cout << "Calculate another loan payoff? (y/n): ";
    cin >> again;
  }
  if (again == "y" || again == "Y") {
    paymentDriver();
  }

}

// Method to calculate loan payoff
int Loan::paymentMonths (double prinAmount, double interestRate, double monthlyPay) {

  // Declare variables needed for calculations
  double months, calc1, calc2, calc3, years;

  // Calculate each part of formula
  calc1 = log(monthlyPay);
  calc2 = log(monthlyPay-((interestRate/1200.0)*prinAmount));
  calc3 = log((interestRate/1200.0)+1.0);

  // Put the calculations together
  months = (calc1 - calc2)/calc3;

  // Calculate number of years
  years = months/12;
  years = round(years * 10)/10;

  // Print number of months and years
  cout << static_cast<int>(round(months)) << " months (" << years << " years) are needed to pay your loan off." << endl << endl;

  // Declare variables for $15 more a month calculations
  double monthlyPayment2, calc4, calc5, calc6, newMonths;

  // Calculate if it was $15 more a month
  monthlyPayment2 = monthlyPay + 15;
  calc4 = log(monthlyPayment2);
  calc5 = log((monthlyPayment2-(interestRate/1200.0)*prinAmount));
  calc6 = log(((interestRate/1200.0)+1.0));
  newMonths = (months - ((calc4 - calc5)/calc6));

  // Print out the $15 more a month statement
  cout << "Did you know if you paid an additional $15 per month, you would pay off your loan " << static_cast<int>(round(newMonths)) << " months earlier?" << endl << endl;

  // Round months to return
  int monthsUpdated = static_cast<int>(round(months));

  // Return months
  return monthsUpdated;
}
