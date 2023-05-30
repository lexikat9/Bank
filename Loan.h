/* Lexi Katramados                                                                                                    
   CPSC 1070: 005                                                                                                     
   E2: Runtime Terror                                                                                                
   2/26/23 */ 

#ifndef LOAN_H // used to prevent a header file from being inlcuded twice
#define LOAN_H

class Loan {
 public:
  void paymentDriver();
 private:
  int paymentMonths(double, double, double);
};
#endif
