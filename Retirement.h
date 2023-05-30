/* Lexi Katramados                                                                                                    
   CPSC 1070: 005                                                                                                     
   E2: Runtime Terror                                                                                                
   2/26/23 */

#ifndef RETIRE_H // used to prevent a header file from being inlcuded twice
#define RETIRE_H

class Retirement{
 public:
    void estimateDriver();
 private:
    double estimateEarnings (int, int, double, double, double);   
};
#endif
