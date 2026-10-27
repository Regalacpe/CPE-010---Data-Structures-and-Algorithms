#include <iostream>
#include <vector>
#include <algorithm>

// Lomuto partition scheme using the last element as the pivot
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high]; 
    int i = low - 1;       
    
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            std::swap(arr[++i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    // WORST CASE TRIGGER: Already sorted data with a fixed endpoints pivot strategy
    std::vector<int> worst_case_input = {1, 2, 3, 4, 5, 6, 7};
    
    quickSort(worst_case_input, 0, worst_case_input.size() - 1);
    
    for (int x : worst_case_input) std::cout << x << " ";
    return 0;
}
