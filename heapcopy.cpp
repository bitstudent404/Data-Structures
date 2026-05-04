#include <iostream>
#include <chrono>
using namespace std::chrono;
using namespace std;

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] > arr[largest]){
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]){
        largest = right;
    }
    if (largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapsort(int arr[], int n){
    for (int i = n/2 - 1; i >= 0; i--){
        heapify(arr, n, i);
    }
    for (int i = n-1; i > 0; i--){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void display(int arr[], int n){
    cout << "[";
    for (int i = 0; i < n; i++){
        cout << arr[i] << ", ";
    }
    cout << "]" << endl;
}

int main(){
    int n;
    cout << "Enter the Number of elements:\n";
    cin >> n;   
    int arr[n];
    for(int i=0;i<n;i++){
        int val;
        cout << "Enter " << i << "th Element: ";
        cin >> val;
        arr[i]=val;
    }
    auto start = high_resolution_clock::now();   
    heapsort(arr, n);
     
    display(arr, n);
    auto end = high_resolution_clock::now(); 

    auto duration = duration_cast<seconds>(end - start);
    cout << "Running time: " << duration.count() << " seconds";
    return 0;
}