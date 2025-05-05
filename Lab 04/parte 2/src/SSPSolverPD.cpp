#include <SubsetSumSolver.h>
#include <vector>

bool SSPSolverPD::solve(const std::vector<long> &input, long value, std::vector<char> &output) {
    
    // Obtém o tamanho do vetor de entrada
    int n = input.size();

    // Redimensiona o vetor de saída para ter o mesmo tamanho que o vetor de entrada e inicializa com false
    output.resize(n, false);

    // Se o valor alvo é negativo, não há solução possível
    if (value < 0) return false;

     // Cria uma matriz dp de tamanho (n+1) x (value+1) inicializada com false
    // dp[i][j] será true se for possível obter uma soma j usando os primeiros i elementos
    std::vector<std::vector<bool>> dp(n + 1, std::vector<bool>(value + 1, false));
    
    // É sempre possível obter uma soma de 0 usando 0 elementos
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    
    // Preenche a matriz dp usando a abordagem de programação dinâmica
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= value; j++) {
            if (j < input[i - 1])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - input[i - 1]];
        }
    }

    // Se não é possível obter a soma desejada value usando todos os n itens, retorna false
    if (!dp[n][value])
        return false;

    // Reconstrói a solução rastreando os itens usados
    int i = n, j = value;
    while (i > 0 && j > 0) {
        if (dp[i - 1][j])
            // Se podemos obter a soma j sem o item i-1, movemos para o item anterior
            i--;
        else {
            // Caso contrário, incluímos o item i-1 na solução
            output[i - 1] = true;
            j -= input[i - 1]; // Subtrai o peso do item i-1 da soma restante
            i--; // Move para o item anterior
        }
    }

    // Retorna true, indicando que uma solução foi encontrada
    return true;
}


