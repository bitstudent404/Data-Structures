#include <iostream>
#include <ctime>
using namespace std;

int comp = 0;

void insertion(int arr[],int n){
    for (int i=1;i<n;i++){
        int key = arr[i];
        int j=i-1;
        while (j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
            comp++;
        }
        arr[j+1] = key;
    }
}

void display(int arr[],int n){
    cout <<"[";
    for (int i=0;i<n;i++){
        cout << arr[i] <<", ";
    }
    cout<<"]"<< endl;
}
int main(){
    clock_t start, end;
    start = clock();

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
    insertion(arr,n);

    display(arr,n);

    cout << "Number of comparisons: "<<comp<<endl;

    end = clock();
    double time_taken = double(end-start)/CLOCKS_PER_SEC;
    cout << "Runnning time: " << time_taken << "seconds";
    return 0;
}