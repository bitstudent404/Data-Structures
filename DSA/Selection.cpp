#include <iostream>
using namespace std;

int comparisons = 0;

void Slsort(int A[],int n){
    for (int i=0;i<n-1;i++){
        comparisons++;
        int min_index=i;
        for (int j=i+1;j<n;j++){
            if (A[j]<A[min_index]){
                min_index = j;
            }
        }
        swap(A[min_index],A[i]) ;
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

    Slsort(A,n);

    cout << "Sorted array:\n";
    display(A, n);

    cout << "\nNumber of comparisons: " << comparisons << endl;
    return 0;
}