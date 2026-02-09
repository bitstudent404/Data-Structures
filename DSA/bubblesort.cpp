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

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int comparisons;
    bubbleSort(arr, n, comparisons);

    cout << "\nSorted array:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << "\n\nNumber of comparisons: " << comparisons << endl;

    return 0;
}
