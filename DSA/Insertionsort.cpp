#include <iostream>
using namespace std;


void insertionsort(int arr[],int n){
   for(int i=1;i<n;i++){
       int key = arr[i];
       int j = i-1;
       while(j>=0 && arr[j]>key){
           arr[j+1] = arr[j];
           j--;
       }
       arr[j+1] = key;
   }
}


int main(){
   int n;
   cout <<"Enter the Number of Elements: \n";
   cin >> n;
   int arr[n];
   for (int i=0;i<n;i++){
       int val;
       cout << "Enter " << i << "th element:";
       cin >> val;
       arr[i] = val;
   }
   // int arr[] = {12,3,7,2,1,8,0,11};
   // int n = sizeof(arr)/sizeof(arr[0]);
   insertionsort(arr,n);


   cout<<"[";
   for (int i=0;i<n;i++){
       cout << arr[i] <<", ";
   }
   cout<<"]"<<endl;
   return 0;
}
