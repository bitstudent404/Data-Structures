#include <iostream>
using namespace std;

void insertionsort(int arr[],int n){
    for(int i=1;i<=n;i++){
        int key = arr[i];
        int j = i-1;
        while(j>0 && arr[j]>key){
            arr[j+1] = arr[j];
            j = j+1;
        }
        arr[j+1] = key;
    }
}

int main(){
    int n = 8;
    int arr[n] = {12,3,7,2,1,8,0,11};
    insertionsort(arr[n],n)
    for (int i=0;i<=n;i++){
        cout << arr[i] << endl;
    }
    return 1;
}