#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n, int &comp) {
    comp = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comp++;
            if (arr[j] > arr[j + 1]) {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }
}

int linearSearch(int arr[], int n, int key, int &comp) {
    comp = 0;
    for (int i = 0; i < n; i++) {
        comp++;
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int binarySearch(int arr[], int n, int key, int &comp) {
    int low = 0, high = n - 1;
    comp = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        comp++;
        if (arr[mid] == key)
            return mid;
        else if (key < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

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
    cin >> n;

    int arr1[100], arr2[100];
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
        arr2[i] = arr1[i];
    }

    int key;
    cin >> key;

    int linComp, binComp, bubComp, heapComp;

    int linIdx = linearSearch(arr1, n, key, linComp);

    bubbleSort(arr1, n, bubComp);
    int binIdx = binarySearch(arr1, n, key, binComp);

    heapSort(arr2, n, heapComp);

    cout << "Linear Search Index: " << linIdx << endl;
    cout << "Linear Search Comparisons: " << linComp << endl;

    cout << "Binary Search Index: " << binIdx << endl;
    cout << "Binary Search Comparisons: " << binComp << endl;

    cout << "Bubble Sort Comparisons: " << bubComp << endl;
    cout << "Heap Sort Comparisons: " << heapComp << endl;

    return 0;
}