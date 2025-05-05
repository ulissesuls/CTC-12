#ifndef TSP_SOLVER
#define TSP_SOLVER

#include <TspReader.h>
#include <vector>
#include <queue>
#include <functional>

class TspSolver {
public:
    void solve(TspReader &tr, std::vector<int> &percourse);
}; 

#endif
