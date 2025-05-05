#ifndef TSP_SOLVER
#define TSP_SOLVER

// for the Lab5, where the solution may be < 2 * optimum, LEAVE IT COMMENTED
//#define CTC12_CHRISTOFIDES // uncomment only IF you are implementing Christofides. (requires 1.5x optimum) 

#include <TspReader.h>
#include <vector>

class TspSolver {
public:
    // you should fill percourse with a permutation that represents the TSP solution
    void solve(TspReader &tr,std::vector<int> &percourse); 

}; 



#endif
