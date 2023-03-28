#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void quickSort(vector<int>& arr, int left, int right);
int partition(vector<int>& arr, int left, int right, int pivotIndex);
void printArray(vector<int>& arr, int size);
double findMedian(vector<int>& arr);

int main()
{
    vector<int> arr;
    int n;

    // Get the size of the array from the user
    cout << "Enter the size of the array: ";
    cin >> n;

    // Get the array elements from the user one by one
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        // Add the new element to the end of the array
        arr.push_back(x);

        // Sort the array so far
        quickSort(arr, 0, i);

        // Print the sorted array so far
        cout << "Sorted array so far: ";
        printArray(arr, i+1);

        // Find the running median of the array so far
        double median = findMedian(arr);

        // Print the running median
        cout << "Running median: " << median << endl;
    }

    return 0;
}

void quickSort(vector<int>& arr, int left, int right)
{
    // Base case: If the subarray has fewer than two elements, it's already sorted
    if (left >= right) {
        return;
    }

    // Choose a pivot element
    int pivotIndex = left + (right - left) / 2;
    int pivotValue = arr[pivotIndex];

    // Partition the subarray around the pivot
    int storeIndex = partition(arr, left, right, pivotIndex);

    // Recursively sort the subarrays to the left and right of the pivot
    quickSort(arr, left, storeIndex - 1);
    quickSort(arr, storeIndex + 1, right);
}

int partition(vector<int>& arr, int left, int right, int pivotIndex)
{
    // Move the pivot element to the end of the subarray
    int pivotValue = arr[pivotIndex];
    swap(arr[pivotIndex], arr[right]);

    // Partition the subarray around the pivot element
    int storeIndex = left;
    for (int i = left; i < right; i++) {
        if (arr[i] < pivotValue) {
            swap(arr[i], arr[storeIndex]);
            storeIndex++;
        }
    }
    swap(arr[storeIndex], arr[right]);

    return storeIndex;
}

void printArray(vector<int>& arr, int size)
{
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

double findMedian(vector<int>& arr)
{
    int n = arr.size();
    if (n % 2 == 0) {
        return (double)(arr[n / 2 - 1] + arr[n / 2]) / 2.0;
    }
    else {
        return (double)arr[n / 2];
    }
}