#include <iostream>
#include <ctime>
using namespace std;

int comp=0;
int linear(int arr[],int n,int key){
    for(int i=0;i<n;i++){
        comp++;
        if (arr[i] == key){
            return i;
        }
    }
    return -1;
}

int binary(int arr[],int n,int key){
    int low = 0, high = n-1;
    while (low<=high){
        int mid = (low+high)/2;
        comp++;
        if (arr[mid] == key){
            return mid;
        }
        else if (arr[mid]<key){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return -1;  
}

int main(){
    int n;
    cout << "ENter Number of elements:\n";
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        int val;
        cout << "Enter " << i << "th Element: ";
        cin >> val;
        arr[i]=val; 
    }   
    int key;
    cout << "Enter the key to be searched:\n";
    cin >> key; 
    clock_t start, end;
    start = clock();

    int linear_result = linear(arr,n,key);
    int binary_result = binary(arr,n,key);
    cout << "Linear Search Result: " << linear_result << endl;
    cout << "Binary Search Result: " << binary_result << endl;  
    cout << "Number of comparisons: " << comp << endl;

    end = clock();
    double time_taken = double(end-start)/CLOCKS_PER_SEC;
    cout << "Running Time: " << time_taken << " seconds." << endl;
    return 0;
}