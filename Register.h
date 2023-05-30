/* Lexi Katramados
   CPSC 1070: 005
   E2: Runtime Terror
   2/26/23 */

#ifndef REGISTER_H // Prevents a header file from being included twice
#define REGISTER_H
#include <string> // allows us to use strings
#include <vector> // allows us to use vectors
using namespace std;

class Register {
 public:
  string getFileName();
  bool processTransaction();
 private:
  string fileName = "";
  enum Transactions {RESTAURANT, MERCHANDISE, UTILITY, COFFEESHOP, AUTOMOTIVE, DEPOSIT, OTHER};
  vector<string> date;
  vector<Transactions> transaction;
  vector<string> source;
  vector<double> amount;
  void setFileName(string);
  void printFile();
  bool readFromFile();
};
#endif
