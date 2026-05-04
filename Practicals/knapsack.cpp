#include <iostream>
#include <ctime>
using namespace std;

int max(int a,int b){
    return (a>b) ? a:b;
}

int knapsack(int C,int wt[],int val[],int n){
    if(n==0 || C==0){
        return 0;
    }
    if(wt[n-1]>C){
        return knapsack(C,wt,val,n-1);
    }
    else{
        return max(val[n-1]+knapsack(C-wt[n-1],wt,val,n-1),knapsack(C,wt,val,n-1));
    }

}

int main(){
    int val[] = {60,100,120};
    int wt[] = {10,20,30};
    int C = 50;
    int n = sizeof(val)/sizeof(val[0]);
    clock_t start,end;
    start = clock();
    cout<<knapsack(W,wt,val,n)<<endl;
    end = clock();
    double time_taken = double(end-start)/double(CLOCKS_PER_SEC);
    cout<<"Time taken by program is : "<<time_taken<<" seconds"<<endl;
    return 0;
}