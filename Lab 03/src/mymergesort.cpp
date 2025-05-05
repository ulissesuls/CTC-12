
#include <mysortfunctions.h>
#include <algorithm>

void merge(std::vector<int>& v, int left, int middle, int right, SortStats& stats) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Create temporary arrays
    std::vector<int> L(n1), R(n2);

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = v[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = v[middle + 1 + j];

    // Merge the temporary arrays back into v[left..right]
    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = left; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            v[k] = L[i];
            i++;
        } else {
            v[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        v[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        v[k] = R[j];
        j++;
        k++;
    }
}

void mergeSortRecursive(std::vector<int>& v, int left, int right, SortStats& stats, int depth = 1) {
    if (left < right) {

        // Atualizando os stats
/**/    stats.recursive_calls++; // Incrementa o número de chamadas recursivas
/**/    stats.depth_recursion_stack = std::max(stats.depth_recursion_stack, (float) depth); // Atualiza a profundidade máxima da pilha de recursão

        // Same as (left+right)/2, but avoids overflow
        int middle = left + (right - left) / 2;

        // Sort first and second halves
        mergeSortRecursive(v, left, middle, stats, depth + 1);
        mergeSortRecursive(v, middle + 1, right, stats, depth + 1);

        // Merge the sorted halves
        merge(v, left, middle, right, stats);
    }
}

// Merge Sort iterativo: contar stats.recursive_calls e stats.depth_recursion_stack
void mymergesort_iterative(std::vector<int> &v, SortStats &stats) {

    // you need to set the counting of recursive recursive_calls
    stats.recursive_calls = 1;
    // you need to set the depth = the maximum height of the tree of recursion calls. 
    stats.depth_recursion_stack = 1;
    // the tester already knows the size of v and the algorithm name, it already measures time
    // you may set custom1 field if you want to measure anything else.
    stats.custom1 = 0;

    int n = v.size();
    for (int curr_size = 1; curr_size <= n - 1; curr_size *= 2) {
        for (int left_start = 0; left_start < n - 1; left_start += 2 * curr_size) {
            int middle = std::min(left_start + curr_size - 1, n - 1);
            int right_end = std::min(left_start + 2 * curr_size - 1, n - 1);

            // Merge subarrays v[left_start..middle] and v[middle+1..right_end]
            merge(v, left_start, middle, right_end, stats);
        }
    }    
}

// Merge Sort recursivo: contar stats.recursive_calls e stats.depth_recursion_stack
void mymergesort_recursive(std::vector<int> &v, SortStats &stats) {
 
    int n = v.size();
    mergeSortRecursive(v, 0, n - 1, stats);

}