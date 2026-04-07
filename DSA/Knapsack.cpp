#include <iostream>
#include <vector>
using namespace std;

int knapsack(int n, int W, vector<int>& wt, vector<int>& val) {
    vector<int> dp(W + 1, 0);

    for (int i = 0; i < n; i++) {
        // Traverse backwards to avoid overwriting needed values
        for (int w = W; w >= wt[i]; w--) {
            dp[w] = max(dp[w], val[i] + dp[w - wt[i]]);
        }
    }

    return dp[W];
}

int main() {
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    vector<int> wt(n), val(n);

    cout << "Enter weights:\n";
    for (int i = 0; i < n; i++) cin >> wt[i];

    cout << "Enter values:\n";
    for (int i = 0; i < n; i++) cin >> val[i];

    cout << "Enter knapsack capacity: ";
    cin >> W;

    cout << "Maximum Profit: " << knapsack(n, W, wt, val) << endl;

    return 0;
}