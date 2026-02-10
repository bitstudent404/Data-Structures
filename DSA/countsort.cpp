#include <iostream>
using namespace std;

void countsort(int arr[],int n,int &comp){
    comp = 0;
    int maxVal = arr[0];
    for (int i=1;i<n;i++){
        comp++;
        if (arr[i] > maxVal){
            maxVal = arr[i];
        }
    }

    int count[maxVal+1];
    for (int i=0;i<=maxVal;i++){
        count[i] = 0;
    }
    for (int i=0;i<n;i++){
        count[arr[i]]++;
    }
    int index = 0;
    for (int i=0;i<= maxVal;i++){
        while (count[i]>0){
            arr[index++] = i;
            count[i]--;
        }
    } 
}

int main(){
    int n;
    cout << "Enter number of elements:\n";
    cin >> n;

    int arr[n];
    cout << "\nEnter elements\n";
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    int comparisons;
    countsort(arr,n,comparisons);
    cout << "\nAfter Count Sort:\n";
    for (int i=0; i<n ;i++)
        cout << arr[i] << " ";
    cout << endl;
    cout << "\nComparisons: "<<comparisons<<endl;
    return 0;
}