#include <iostream>
using namespace std;

void countsort(int arr[], int n, int exp, int &comp) {
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int get_max(int arr[], int n, int &comp) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        comp++;
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }
    return maxVal;
}

void radixsort(int arr[], int n, int &comp) {
    comp = 0;
    int maxVal = get_max(arr, n, comp);

    // Sort by each digit
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countsort(arr, n, exp, comp);
    }
}

int main() {
    int n;
    cout << "Enter number of elements:\n";
    cin >> n;

    int arr[n];
    cout << "\nEnter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int comparisons;
    radixsort(arr, n, comparisons);

    cout << "\nAfter Radix Sort:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << "\n\nComparisons: " << comparisons << endl;
    return 0;
}
