#include <iostream>
#include <ctime>
using namespace std;

int comp = 0;

void selection(int arr[],int n){
    for (int i =0;i<n-1;i++)
    {
        int min_idx = i;
        for (int j=i+1;j<n;j++){
            comp++;
            if (arr[j]<arr[min_idx]){
                min_idx = j; 
            }
        }
        swap(arr[i],arr[min_idx]);
    }
}


int display(int arr[],int n){
    cout << "[";
    for (int i=0;i<n;i++){
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

    clock_t start, end;
    start = clock();

    selection(arr,n);

    display(arr,n);

    cout << "Number of comparisons: "<<comp<<endl;

    end = clock();
    double time_taken = double(end-start)/CLOCKS_PER_SEC;
    cout << "Runnning time: " << time_taken << " seconds";

    return 0;
}