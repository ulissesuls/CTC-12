
#include <mysortfunctions.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>
#include <iostream>
#include <vector>


void myradixsort(std::vector<int> &v, SortStats &stats) {
    int n = v.size();
    std::vector<int> aux(n);
    for (int shift = 0; shift < 32; shift += 4) {
        int count[16] = {0};
        for (int i = 0; i < n; ++i)
            ++count[(v[i] >> shift) & 15];
        for (int i = 1; i < 16; ++i)
            count[i] += count[i - 1];
        for (int i = n - 1; i >= 0; --i)
            aux[--count[(v[i] >> shift) & 15]] = v[i];
        v.swap(aux);
    }

    //Configura as estatísticas
    stats.recursive_calls = 0; // Não há chamadas recursivas
    stats.depth_recursion_stack = 0; // A profundidade da pilha de recursão é 0
    stats.custom1 = 0; // Não há medida adicional
}
