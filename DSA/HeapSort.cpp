#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i, int &comp) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n) {
        comp++;
        if (arr[l] > arr[largest])
            largest = l;
    }

    if (r < n) {
        comp++;
        if (arr[r] > arr[largest])
            largest = r;
    }

    if (largest != i) {
        int t = arr[i];
        arr[i] = arr[largest];
        arr[largest] = t;
        heapify(arr, n, largest, comp);
    }
}

void heapSort(int arr[], int n, int &comp) {
    comp = 0;

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, comp);

    for (int i = n - 1; i > 0; i--) {
        int t = arr[0];
        arr[0] = arr[i];
        arr[i] = t;
        heapify(arr, i, 0, comp);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int comparisons;
    heapSort(arr, n, comparisons);

    cout << "\nSorted array:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << "\n\nNumber of comparisons: " << comparisons << endl;

    return 0;
}
