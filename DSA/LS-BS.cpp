#include <iostream>
using namespace std;

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

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements (sorted for binary search):\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int key;
    cout << "Enter key to search: ";
    cin >> key;

    int compLinear, compBinary;

    int pos1 = linearSearch(arr, n, key, compLinear);
    int pos2 = binarySearch(arr, n, key, compBinary);

    cout << "\nLinear Search:";
    if (pos1 != -1)
        cout << " Found at index " << pos1;
    else
        cout << " Not found";
    cout << "\nComparisons: " << compLinear << endl;

    cout << "\nBinary Search:";
    if (pos2 != -1)
        cout << " Found at index " << pos2;
    else
        cout << " Not found";
    cout << "\nComparisons: " << compBinary << endl;

    return 0;
}
