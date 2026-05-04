#include <iostream>
#include <ctime>
using namespace std;

int comp = 0;

// -------- Merge Function --------
void merge(int arr[], int Left, int Mid, int Right){
    int n1 = Mid - Left + 1;
    int n2 = Right - Mid;

    int Larr[n1], Rarr[n2];

    for (int i = 0; i < n1; i++){
        Larr[i] = arr[Left + i];
    }
    for (int j = 0; j < n2; j++){
        Rarr[j] = arr[Mid + 1 + j];
    }

    int i = 0, j = 0, k = Left;

    // Merge two sorted arrays
    while (i < n1 && j < n2){
        comp++;
        if (Larr[i] <= Rarr[j]){
            arr[k] = Larr[i];
            i++;
        }
        else{
            arr[k] = Rarr[j];
            j++;
        }
        k++;  // ✅ FIXED
    }

    // Copy remaining elements
    while (i < n1){
        arr[k] = Larr[i];
        i++;
        k++;
    }

    while (j < n2){
        arr[k] = Rarr[j];
        j++;
        k++;
    }
}

// -------- Merge Sort --------
void mergesort(int arr[], int Left, int Right){
    if (Left < Right){
        int Mid = (Left + Right) / 2;

        mergesort(arr, Left, Mid);
        mergesort(arr, Mid + 1, Right);

        merge(arr, Left, Mid, Right);
    }
}

// -------- Display --------
void display(int arr[], int n){
    cout << "[";
    for (int i = 0; i < n; i++){
        cout << arr[i];
        if (i != n - 1){
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

// -------- Main --------
int main(){
    int n;
    cout << "Enter the Number of elements:\n";
    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++){
        cout << "Enter " << i << "th Element: ";
        cin >> arr[i];
    }

    clock_t start, end;
    start = clock();

    mergesort(arr, 0, n - 1);

    end = clock();

    display(arr, n);

    cout << "Number of comparisons: " << comp << endl;

    double time_taken = double(end - start) / CLOCKS_PER_SEC;
    cout << "Running time: " << time_taken << " seconds";

    return 0;
}
