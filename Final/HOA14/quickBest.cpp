#include <iostream>
#include <vector>
#include <algorithm>

// Partitions the array around the pivot (last element)
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            std::swap(arr[++i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Recursive Quick Sort function
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    // Best-case scenario input for Lomuto partition scheme (pivot always ends up in the exact middle)
    std::vector<int> bestCaseArr = {1, 3, 2, 7, 5, 6, 4}; 
    
    quickSort(bestCaseArr, 0, bestCaseArr.size() - 1);

    for (int x : bestCaseArr) std::cout << x << " ";
    return 0;
}
