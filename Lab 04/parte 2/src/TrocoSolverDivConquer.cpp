#include <TrocoSolver.h>
#include <limits>
#include <algorithm>

// Método solve para Divisão e Conquista
void TrocoSolverDivConquer::solve(const std::vector<unsigned int> &denom, unsigned int value, std::vector<unsigned int> &coins) {
    // Redimensiona o vetor coins para ter o mesmo tamanho que denom e inicializa com 0
    coins.resize(denom.size(), 0);
    // Inicializa o contador de chamadas recursivas
    recursivecalls = 0;
    int q = std::numeric_limits<int>::max();
    // Chama a função recursiva para resolver o problema
    solveRecursive(denom, value, coins, q);
}

// Função recursiva para resolver o problema de troco usando Divisão e Conquista
void TrocoSolverDivConquer::solveRecursive(const std::vector<unsigned int> &denom, unsigned int value, std::vector<unsigned int> &coins, int &q) {
    recursivecalls++; // Incrementa o contador de chamadas recursivas
    if (value == 0) {
        q = 0; // Base da recursão: se o valor é 0, não há necessidade de mais moedas
        return;
    }
    
    int minCoins = std::numeric_limits<int>::max();
    std::vector<unsigned int> minCoinsVec(coins.size(), 0);
    
    // Itera sobre cada denominação de moeda
    for (size_t i = 0; i < denom.size(); ++i) {
        if (denom[i] <= value) { // Se a denominação é menor ou igual ao valor atual
            std::vector<unsigned int> subCoins(coins.size(), 0);
            int subQ = q;
            // Chama recursivamente para o valor reduzido
            solveRecursive(denom, value - denom[i], subCoins, subQ);
            // Se a solução é válida e melhor que a encontrada até agora, atualiza
            if (subQ != std::numeric_limits<int>::max() && subQ + 1 < minCoins) {
                minCoins = subQ + 1;
                subCoins[i]++;
                minCoinsVec = subCoins;
            }
        }
    }
    
    if (minCoins != std::numeric_limits<int>::max()) {
        coins = minCoinsVec; // Atualiza o vetor de moedas
        q = minCoins; // Atualiza o número mínimo de moedas
    }
}