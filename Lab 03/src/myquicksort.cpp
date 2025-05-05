
#include <mysortfunctions.h>
#include <algorithm>

// Function to swap elements at two indices in the vector
void swap(std::vector<int>& v, int i, int j) {
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

// Function to find median of three elements in the vector
int medianOfThree(std::vector<int>& v, int low, int high) {
    int mid = low + (high - low) / 2;
    if (v[low] > v[mid]) {
        if (v[mid] > v[high])
            return mid;
        else if (v[low] > v[high])
            return high;
        else
            return low;
    } else {
        if (v[low] > v[high])
            return low;
        else if (v[mid] > v[high])
            return high;
        else
            return mid;
    }
}

// Function to perform partitioning
int partition(std::vector<int>& v, int low, int high, SortStats& stats) {
    int pivotIndex = medianOfThree(v, low, high);
    int pivot = v[pivotIndex];
    swap(v, pivotIndex, high); // Move pivot to end
    int i = low - 1; // Index of smaller element

    for (int j = low; j < high; j++) {
        if (v[j] < pivot) {
            i++;
            swap(v, i, j);
        }
    }
    swap(v, i + 1, high); // Move pivot to its correct position
    return i + 1;
}

// Recursive function for 2 recursion QuickSort
void quickSort2rec(std::vector<int>& v, int low, int high, SortStats& stats, int depth = 1) {
    if (low < high) {

        // Increment recursive calls
        stats.recursive_calls++;

        // Update depth of recursion stack
        stats.depth_recursion_stack = std::max(stats.depth_recursion_stack, (float)depth);

        int pi = partition(v, low, high, stats);
        quickSort2rec(v, low, pi - 1, stats, depth + 1); // Sort left subarray
        quickSort2rec(v, pi + 1, high, stats, depth + 1); // Sort right subarray
    }
}

// Recursive function for QuickSort with 1 recursive call
void quickSort1rec(std::vector<int>& v, int low, int high, SortStats& stats, int depth = 1) {
    while (low < high) {
        // Increment recursive calls
        stats.recursive_calls++;

        // Update depth of recursion stack
        stats.depth_recursion_stack = std::max(stats.depth_recursion_stack, (float)depth);

        int pi = partition(v, low, high, stats);
        // If left part has smaller elements, recur for left part and handle right part iteratively
        if (pi - low < high - pi) {
            quickSort1rec(v, low, pi - 1, stats, depth + 1);
            low = pi + 1;
        } else { // Else recur for right part
            quickSort1rec(v, pi + 1, high, stats, depth + 1);
            high = pi - 1;
        }
    }
}

// Function for QuickSort with fixed pivot
void quickSort_fixedPivot(std::vector<int>& v, int low, int high, SortStats& stats, int depth = 1) {
    if (low < high) {
        // Increment recursive calls
        stats.recursive_calls++;

        // Update depth of recursion stack
        stats.depth_recursion_stack = std::max(stats.depth_recursion_stack, (float)depth);

        // Always choose last element as pivot
        int pivot = v[high];
        int i = low - 1; // Index of smaller element

        // Partition the array around the pivot
        for (int j = low; j < high; j++) {
            if (v[j] < pivot) {
                i++;
                swap(v, i, j);
            }
        }
        swap(v, i + 1, high); // Move pivot to its correct position
        int pi = i + 1;

        // Recur for the two halves
        quickSort_fixedPivot(v, low, pi - 1, stats, depth + 1);
        quickSort_fixedPivot(v, pi + 1, high, stats, depth + 1);
    }
}


// you only need to mantain the headers. You can create aux funcs, objects, or create a generic quicksort that can work with different functions to select the pivot.

/// the most comon quicksort, with 2 recursive calls
// Quick Sort 2 recursões, mediana de 3: contar stats.recursive_calls e stats.depth_recursion_stack
void myquicksort_2recursion_medianOf3(std::vector<int> &v, SortStats &stats) {

    int n = v.size();
    quickSort2rec(v, 0, n - 1, stats);

}// function myquicksort_2recursion_medianOf3

/// quicksort with one recursive call
// Quick Sort 1 recursão, mediana de 3: contar stats.recursive_calls e stats.depth_recursion_stack
void myquicksort_1recursion_medianOf3(std::vector<int> &v, SortStats &stats) {

    int n = v.size();
    quickSort1rec(v, 0, n - 1, stats);

} // function myquicksort_1recursion_medianOf3

/// quicksort with fixed pivot 
/// be sure to compare with equivalent implementation 
/// e.g., if you do 1 recursive call, compare with the 1recursion version
// Quick Sort fixed Pivot: contar stats.recursive_calls e stats.depth_recursion_stack
void myquicksort_fixedPivot(std::vector<int> &v, SortStats &stats) {

    int n = v.size();
    quickSort_fixedPivot(v, 0, n - 1, stats);

} // myquicksort_fixedPivot