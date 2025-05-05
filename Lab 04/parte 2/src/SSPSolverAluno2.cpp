/*------------------------------------------------------------------------------------

 SOLUÇÃO ALTERNATIVA DO ALUNO IMPLEMENTADA MEDIANTE A ABORDAGEM "MEET IN THE MIDDLE"

 A abordagem "Meet in the Middle" é uma técnica que divide o problema em duas partes menores, 
 resolve cada parte separadamente e depois combina as soluções. Isso é especialmente útil 
 para problemas de soma de subconjuntos quando o número de elementos é grande, pois reduz 
 a complexidade do problema.

-------------------------------------------------------------------------------------*/

#include <SubsetSumSolver.h>
#include <vector>
#include <unordered_map>
#include <cmath>

bool SSPSolverAluno2::solve(const std::vector<long> &input, long value, std::vector<char> &output) {
    
    // Obtém o tamanho do vetor de entrada
    int n = input.size();
    
    // Divide o vetor de entrada em duas metades
    int mid = n / 2;

    // Redimensiona o vetor de saída para ter o mesmo tamanho que o vetor de entrada e inicializa com false
    output.resize(n, false);

    // Limita o tamanho de 'mid' para evitar estouro de memória
    if (mid > 20) return false;

    // Armazena todas as somas possíveis da primeira metade dos elementos
    std::unordered_map<long, std::vector<bool>> left_half_sums;
    for (int i = 0; i < (1 << mid); i++) {
        long sum = 0;
        std::vector<bool> subset(n, false);
        for (int j = 0; j < mid; j++) {
            // Verifica se o j-ésimo elemento está incluído na combinação atual
            if (i & (1 << j)) {
                sum += input[j]; // Adiciona o peso do j-ésimo elemento à soma
                subset[j] = true; // Marca o j-ésimo elemento como incluído
            }
        }
        left_half_sums[sum] = subset; // Armazena a soma e o subconjunto correspondente
    }

    // Verifica todas as somas possíveis da segunda metade dos elementos
    for (int i = 0; i < (1 << (n - mid)); i++) {
        long sum = 0;
        std::vector<bool> subset(n, false);
        for (int j = 0; j < (n - mid); j++) {
            // Verifica se o j-ésimo elemento está incluído na combinação atual
            if (i & (1 << j)) { 
                sum += input[j + mid]; // Adiciona o peso do j-ésimo elemento à soma
                subset[j + mid] = true; // Marca o j-ésimo elemento como incluído
            }
        }

        // Verifica se existe uma soma complementar na primeira metade que complete o valor desejado
        if (left_half_sums.find(value - sum) != left_half_sums.end()) {
            // Se encontrar uma soma complementar, combina os subconjuntos e retorna true
            std::vector<bool> left_subset = left_half_sums[value - sum];
            for (int k = 0; k < n; k++) {
                output[k] = left_subset[k] || subset[k]; // Marca os elementos incluídos na solução final
            }
            return true; // Solução encontrada
        }
    }
    return false; // Nenhuma solução encontrada
}



