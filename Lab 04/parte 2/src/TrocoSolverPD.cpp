#include <TrocoSolver.h>
#include <vector>
#include <limits>

// Método solve para Programação Dinâmica
void TrocoSolverPD::solve(const std::vector<unsigned int> &denom, unsigned int value, std::vector<unsigned int> &coins) {
    // Inicializa a tabela dp com valor máximo (representando infinito)
    std::vector<int> dp(value + 1, std::numeric_limits<int>::max());
    // Inicializa a tabela lastCoin para armazenar o índice da última moeda usada
    std::vector<int> lastCoin(value + 1, -1);
    
    dp[0] = 0; // Caso base: 0 moedas para valor 0
    
    // Preenche a tabela dp
    for (unsigned int i = 1; i <= value; ++i) {
        for (size_t j = 0; j < denom.size(); ++j) {
            if (denom[j] <= i && dp[i - denom[j]] != std::numeric_limits<int>::max() && dp[i - denom[j]] + 1 < dp[i]) {
                dp[i] = dp[i - denom[j]] + 1;
                lastCoin[i] = j;
            }
        }
    }
    
    coins.resize(denom.size(), 0); // Redimensiona o vetor coins
    if (dp[value] == std::numeric_limits<int>::max()) {
        return; // Se não há solução, retorna
    }
    
    int current = value;
    // Reconstrói a solução a partir de lastCoin
    while (current > 0) {
        int coinIndex = lastCoin[current];
        coins[coinIndex]++;
        current -= denom[coinIndex];
    }
}