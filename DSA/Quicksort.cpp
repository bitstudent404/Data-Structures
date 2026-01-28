#include <iostream>
using namespace std;

int comparisons = 0;   

int partition(int A[], int P, int R) {
    int x = A[R];
    int i = P - 1;

    for (int j = P; j <= R - 1; j++) {
        comparisons++;              
        if (A[j] <= x) {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[R]);
    return i + 1;
}

void QuickSort(int A[], int P, int R) {
    if (P < R) {
        int q = partition(A, P, R);
        QuickSort(A, P, q - 1);
        QuickSort(A, q + 1, R);
    }
}

void display(int A[], int n) {
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i << ": ";
        cin >> A[i];
    }

    QuickSort(A, 0, n - 1);

    cout << "Sorted array:\n";
    display(A, n);

    cout << "\nNumber of comparisons: " << comparisons << endl;
    return 0;
}
