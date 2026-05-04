#include <iostream>
#include <ctime>
using namespace std;

int comp=0;

void countsort(int arr[],int n){
    int max = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }

    int count[max+1];
    for(int i=0;i<=max;i++){
        count[i]=0;
    }
    for(int i=0;i<n;i++){
        count[arr[i]]++;
        comp++;
    }
    for(int i=1;i<=max;i++){
        count[i]+=count[i-1];
    }   

}
int display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
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
    countsort(arr,n);
    clock_t end = clock();
    cout<<"Sorted array: ";
    display(arr,n);
    cout<<"Number of comparisons: "<<comp<<endl;
    double time_taken = double(end-start)/CLOCKS_PER_SEC;
    cout << "Running time: " << time_taken << " seconds" << endl;

    return 0;
}
