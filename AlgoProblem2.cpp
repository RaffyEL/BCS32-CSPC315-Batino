#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm> 
#include <random>    

// Bubble Sort Implementation
std::vector<int> bubble_sort(std::vector<int> arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
    return arr;
}

// Merge Sort Implementation
void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// Time measurement for Bubble Sort
std::pair<std::vector<int>, double> time_taken_bubble_sort(const std::vector<int>& arr) {
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<int> sorted_arr = bubble_sort(arr);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    return {sorted_arr, elapsed.count()};
}

// Time measurement for Merge Sort
std::pair<std::vector<int>, double> time_taken_merge_sort(const std::vector<int>& arr) {
    std::vector<int> sorted_arr = arr;
    auto start = std::chrono::high_resolution_clock::now();
    merge_sort(sorted_arr, 0, sorted_arr.size() - 1);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    return {sorted_arr, elapsed.count()};
}

int main() {
    // Test inputs
    std::vector<int> small_input = {100, 50, 95, 45, 90, 40, 85, 35, 70, 30, 65, 25, 60, 20, 55, 15, 50, 10, 45, 5};
    std::vector<int> medium_input(1000);
    std::vector<int> large_input(10000);
    
    for (int i = 0; i < 1000; i++) medium_input[i] = 1000 - i;
    for (int i = 0; i < 10000; i++) large_input[i] = 10000 - i;

    // Shuffle inputs
    std::random_device rd;
    std::default_random_engine rng(rd());
    std::shuffle(small_input.begin(), small_input.end(), rng);
    std::shuffle(medium_input.begin(), medium_input.end(), rng);
    std::shuffle(large_input.begin(), large_input.end(), rng);

    // Measure time and output for small input
    auto [sorted_bubble_small, time_bubble_small] = time_taken_bubble_sort(small_input);
    auto [sorted_merge_small, time_merge_small] = time_taken_merge_sort(small_input);

    // Measure time and output for medium input
    auto [sorted_bubble_medium, time_bubble_medium] = time_taken_bubble_sort(medium_input);
    auto [sorted_merge_medium, time_merge_medium] = time_taken_merge_sort(medium_input);

    // Measure time and output for large input
    auto [sorted_bubble_large, time_bubble_large] = time_taken_bubble_sort(large_input);
    auto [sorted_merge_large, time_merge_large] = time_taken_merge_sort(large_input);

    // Print the results
    std::cout << "Small Input: " << sorted_bubble_small.size() << "\n";
    std::cout << "Bubble Sort Time: " << time_bubble_small << " s\n";
    std::cout << "Merge Sort Time: " << time_merge_small << " s\n";

    std::cout << std::string(40, '=') << "\n";

    std::cout << "Medium Input: " << sorted_bubble_medium.size() << "\n";
    std::cout << "Bubble Sort Time: " << time_bubble_medium << " s\n";
    std::cout << "Merge Sort Time: " << time_merge_medium << " s\n";

    std::cout << std::string(40, '=') << "\n";

    std::cout << "Large Input: " << sorted_bubble_large.size() << "\n";
    std::cout << "Bubble Sort Time: " << time_bubble_large << " s\n";
    std::cout << "Merge Sort Time: " << time_merge_large << " s\n";

    std::cout << std::string(40, '=') << "\n";

    std::cout << "Bubble Sort Time Complexity of 'O(n^2)'" << "\n";
    std::cout << "Merge Sort Time Complexity of 'O(n log n)'" << "\n";

    return 0;
}
