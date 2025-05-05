#include <TrocoSolver.h>

// Método solve para abordagem Gulosa (Greedy)
void TrocoSolverGreedy::solve(const std::vector<unsigned int> &denom, unsigned int value, std::vector<unsigned int> &coins) {
    coins.resize(denom.size(), 0); // Redimensiona o vetor coins
    
    // Itera sobre as denominações de trás para frente (maior para menor)
    for (int i = denom.size() - 1; i >= 0; --i) {
        // Enquanto a denominação atual puder ser usada, subtrai do valor e incrementa a contagem de moedas
        while (value >= denom[i]) {
            value -= denom[i];
            coins[i]++;
        }
    }
}

// dica: iterar um vetor de tras pra frente
//https://stackoverflow.com/questions/3610933/iterating-c-vector-from-the-end-to-the-begin
//http://www.cplusplus.com/reference/vector/vector/rbegin/
