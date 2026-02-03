#include <iostream>
using namespace std;

// Bubble Sort with comparison count
void bubbleSort(int arr[], int n, int &comparisons) {
    comparisons = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++; // comparison between arr[j] and arr[j+1]
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Linear Search with comparison count
int linearSearch(int arr[], int n, int key, int &comparisons) {
    comparisons = 0;
    for (int i = 0; i < n; i++) {
        comparisons++; // comparison with key
        if (arr[i] == key)
            return i;
    }
    return -1;
}

// Binary Search with comparison count (array must be sorted)
int binarySearch(int arr[], int n, int key, int &comparisons) {
    int low = 0, high = n - 1;
    comparisons = 0;

    while (low <= high) {
        int mid = (low + high) / 2;
        comparisons++; // comparison with mid element

        if (arr[mid] == key)
            return mid;
        else if (key < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100]; // fixed-size array (no STL)
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int key;
    cout << "Enter element to search: ";
    cin >> key;

    int bubbleComparisons, linearComparisons, binaryComparisons;

    // Linear Search (before sorting)
    int linIndex = linearSearch(arr, n, key, linearComparisons);

    // Bubble Sort
    bubbleSort(arr, n, bubbleComparisons);

    // Binary Search (after sorting)
    int binIndex = binarySearch(arr, n, key, binaryComparisons);

    cout << "\nSorted Array:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << "\n\n--- Results ---\n";

    if (linIndex != -1)
        cout << "Linear Search: Found at index " << linIndex << endl;
    else
        cout << "Linear Search: Not Found\n";

    cout << "Linear Search Comparisons: " << linearComparisons << endl;

    if (binIndex != -1)
        cout << "Binary Search: Found at index " << binIndex << endl;
    else
        cout << "Binary Search: Not Found\n";

    cout << "Binary Search Comparisons: " << binaryComparisons << endl;
    cout << "Bubble Sort Comparisons: " << bubbleComparisons << endl;

    return 0;
}