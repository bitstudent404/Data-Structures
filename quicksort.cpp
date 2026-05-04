#include <iostream>
#include <ctime>
using namespace std;

int comp = 0;

// -------- Partition --------
int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++){
        comp++;
        if (arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;  // pivot index
}

// -------- Quick Sort --------
void quick(int arr[], int low, int high){
    if (low < high){
        int p = partition(arr, low, high);

        quick(arr, low, p - 1);   // left part
        quick(arr, p + 1, high);  // right part
    }
}

int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];

    cout << "Enter the elements:\n";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    clock_t start = clock();

    quick(arr, 0, n - 1);

    clock_t end = clock();

    double time_taken = double(end - start) / CLOCKS_PER_SEC;

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    cout << "\nNumber of comparisons: " << comp;
    cout << "\nTime taken: " << time_taken << " seconds";

    return 0;
}
