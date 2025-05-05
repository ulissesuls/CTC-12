#include <TspSolver.h>

void TspSolver::solve(TspReader &tr,std::vector<int> &percourse) {
        // here it is filling the vector with  1,2,3,...n
        // you should fill it with a permutation that represents the TSP solution
        for (int i = 1; i <= tr.getNumCities() ; i++)
            percourse.push_back(i);
        
        //percourse[3] = 100;
}//solve
