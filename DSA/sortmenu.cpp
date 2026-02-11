#include <iostream>
using namespace std;

#include "countsort.cpp"
#include "Heapsort.cpp"
#include "insertionSort.cpp"
#include "Quicksort.cpp"
#include "radixdort.cpp"
#include "Selection.cpp"

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n, choice;
    int comp = 0;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    do {
        cout << "\n------ SORTING MENU ------\n";
        cout << "1. Bubble Sort\n";
        cout << "2. Selection Sort\n";
        cout << "3. Insertion Sort\n";
        cout << "4. Merge Sort\n";
        cout << "5. Quick Sort\n";
        cout << "6. Radix Sort\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        comp = 0;

        switch (choice) {
            case 1:
                countsort(arr, n, comp);
                break;

            case 2:
                selectionsort(arr, n, comp);
                break;

            case 3:
                insertionsort(arr, n, comp);
                break;

            case 4:
                mergesort(arr, 0, n - 1, comp);
                break;

            case 5:
                quicksort(arr, 0, n - 1, comp);
                break;

            case 6:
                radixsort(arr, n, comp);
                break;

            case 0:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice!\n";
                continue;
        }

        cout << "\nSorted Array:\n";
        printArray(arr, n);
        cout << "Comparisons: " << comp << endl;

    } while (choice != 0);

    return 0;
}
