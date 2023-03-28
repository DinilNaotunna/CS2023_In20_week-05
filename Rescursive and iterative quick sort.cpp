#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quick_sort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}
void quicksort_iterative(vector<int>& arr, int n) {
    stack<int> s;
    s.push(0);
    s.push(n - 1);

    while (!s.empty()) {
        int high = s.top();
        s.pop();
        int low = s.top();
        s.pop();

        int p = partition(arr, low, high);

        if (p - 1 > low) {
            s.push(low);
            s.push(p - 1);
        }

        if (p + 1 < high) {
            s.push(p + 1);
            s.push(high);
        }
    }
}





int main() {
    // Generate a random seed based on the current time
    srand(time(nullptr));

    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    // Declare and initialize the vector with random values between 1 and 100
    vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100 + 1;
    }

    // Measure the time elapsed for sorting the array
    auto start = high_resolution_clock::now();
    quick_sort(arr, 0, size - 1);
    auto end = high_resolution_clock::now();
     // Calculate the elapsed time and print it out
    auto duration = duration_cast<microseconds>(end - start);
    cout << "Time elapsed to recursive quick sort: " << duration.count() << " microseconds" << endl;
    
     // Measure the time elapsed for sorting the array
    auto start1 = high_resolution_clock::now();
    quicksort_iterative(arr, size );
    auto end1 = high_resolution_clock::now();
    
      // Calculate the elapsed time and print it out
    auto duration1 = duration_cast<microseconds>(end1 - start1);
    cout << "Time elapsed to iterative quick sort: " << duration1.count() << " microseconds" << endl;
    return 0;


}




