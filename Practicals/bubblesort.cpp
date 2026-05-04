#include <iostream>
#include <ctime>
using namespace std;

int comp = 0;

void bubble(int arr[],int n,int &comp){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            comp++;
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    clock_t start = clock();
    bubble(arr,n,comp);
    clock_t end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout<<"Sorted array: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\nNumber of comparisons: "<<comp;
    cout<<"\nTime taken: "<<time_taken<<" seconds";
    return 0;
}